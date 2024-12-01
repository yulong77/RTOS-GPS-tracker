/*
 * gps_data_format.c
 *
 *  Created on: Nov 25, 2024
 *      Author: Yulong
 */

#include <string.h>
#include <stdio.h>
#include "gps_data_processing.h"
#include "gps_data_processing_opts.h"


/**
 * \brief           GPS data float -> string
 *
 * \note
 */
void float_to_string(float value, char* str)
{
    // Handle negative numbers
    if (value < 0) {
        *str++ = '-';
        value = -value; // Get the absolute value
    }

    // Get the integer part
    int int_part = (int)value;
    value -= int_part; // Get the fractional part

    // Convert the integer part to a string
    char* int_str = str;
    do {
        *str++ = (int_part % 10) + '0';
        int_part /= 10;
    } while (int_part > 0);

    // Reverse the integer part string
    char* start = int_str;
    char* end = str - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Handle the fractional part: keep 6 decimal places
    *str++ = '.'; // Decimal point
    for (int i = 0; i < 6; i++) {
        value *= 10; // Get each digit of the fractional part
        int digit = (int)value; // Get the integer part
        *str++ = digit + '0'; // Convert to character and store
        value -= digit; // Remove the integer part, keep the new fractional part
    }

    // End the string
    *str = '\0';
}


/**
 * \brief           Keep 6 decimal places
 *
 * \note
 */
void truncate_to_6_decimal_places(char* str)
{
    // Find the position of the decimal point
    char* dot_pos = strchr(str, '.');
    if (dot_pos) {
        // Keep only 6 decimal places
    	// Start deleting from the 7th character after the decimal point
        char* decimal_pos = dot_pos + 7;
        *decimal_pos = '\0';  // Set the string terminator
    }
}


/**
 * \brief           Format GPS data
 *
 * \note
 */
void format_message(char* gps_field, char* data)
{
    // Determine the lengths of gps_field and data
    int data_len = strlen(data);
    int gps_field_len = strlen(gps_field);

    // Calculate how many spaces are needed between gps_field and data
    int space_count = 15 - (data_len + gps_field_len);

    // Ensure space_count is not negative
    if (space_count < 0) {
        space_count = 0; // If the combined length of gps_field and data exceeds 15, no spaces in between
    }

    // Create a buffer to hold the final formatted message
    char buffer[100]; // Assuming the buffer size is sufficient
    int index = 0;

    // Copy gps_field to the buffer
    while (*gps_field) {
        buffer[index++] = *gps_field++;
    }

    // Add spaces between gps_field and data
    for (int i = 0; i < space_count; i++) {
        buffer[index++] = ' ';
    }

    // Copy the original data into the rest of the buffer
    while (*data) {
        buffer[index++] = *data++;
    }

    // Null-terminate the final string
    buffer[index] = '\0';

    // Copy the formatted message back to the original data array
    strcpy(data - data_len, buffer);

}


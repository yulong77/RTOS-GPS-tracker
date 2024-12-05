/*
 * gps_data_extraction.c
 *
 *  Created on: Nov 20, 2024
 *      Author: Yulong
 */

#include <string.h>
#include <stdio.h>
#include "gps_data_processing.h"
#include "gps_data_processing_opts.h"

/*
 *  GPS test mode switch:
 *  1 for testing example GPS data,
 *  0 for testing real GPS data.
 */
#define TESTMODE_SWITCH 1

/* GPS handler */
lwgps_t hgps;


const char* gps_rx_data_test;

void gps_data_extrac(struct gps_data_output *gps_data, char* gps_rx_data)
{
	/* Initialize GPS data handler*/
	lwgps_init(&hgps);

    /* Process all input data */
#if TESTMODE_SWITCH

    // Select GPS data example
	gps_rx_data_test = gps_rx_data_example_4;

	/* Use example data when TESTMODE is enabled */
    lwgps_process(&hgps, gps_rx_data_test, strlen(gps_rx_data_test));

#else
    /* Use the real gps_rx_data when TESTMODE is disabled */
    lwgps_process(&hgps, gps_rx_data, strlen(gps_rx_data));

#endif

    /* Pass the data to gps_data */
    gps_data->valid_status = hgps.is_valid;

    float_to_string(hgps.longitude, gps_data->longitude);
    float_to_string(hgps.latitude, gps_data->latitude);
    float_to_string(hgps.altitude, gps_data->altitude);

    truncate_to_6_decimal_places(gps_data->longitude);
    truncate_to_6_decimal_places(gps_data->latitude);
    truncate_to_6_decimal_places(gps_data->altitude);

    format_message("Lon", gps_data->longitude);
    format_message("Lat", gps_data->latitude);
    format_message("Alt", gps_data->altitude);

}


/*
 * gps_data_processing_opts.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Yulong
 */

#ifndef LWGPS_OPTS_HDR_H
#define LWGPS_OPTS_HDR_H


/* GPS data structure */
typedef struct gps_data_output {
	int valid_status;
	char latitude[16];
	char longitude[16];
	char altitude[16];
} gps_data_struct;


/* Private function prototypes */
void gps_data_extrac(struct gps_data_output *gps_data_ret, char* gps_rx_data);
void float_to_string(float value, char* str);
void truncate_to_6_decimal_places(char* str);
void format_message(char* heading, char* data);
void clear_GPS_buffer(void);

/* GPS data example */
extern const char gps_rx_data_example_1[];
extern const char gps_rx_data_example_2[];
extern const char gps_rx_data_example_3[];
extern const char gps_rx_data_example_4[];

#endif /* LWGPS_OPTS_HDR_H */

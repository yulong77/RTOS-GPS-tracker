/*
 * gps_test_data.c
 *
 *  Created on: Nov 20, 2024
 *      Author: Yulong
 *
 *  GPS data for test.
 */

#include "gps_data_processing_opts.h"


/* GPS data example 1 */
const char gps_rx_data_example_1[] =

	    ""
        "$GPRMC,183729,A,3907.356,N,12102.482,W,000.0,360.0,080301,015.5,E*6F\r\n"
        "$GPRMB,A,,,,,,,,,,,,V*71\r\n"
        "$GPGGA,183730,3907.356,N,12102.482,W,1,05,1.6,646.4,M,-24.1,M,,*75\r\n"
        "$GPGSA,A,3,02,,,07,,09,24,26,,,,,1.6,1.6,1.0*3D\r\n"
        "$GPGSV,2,1,08,02,43,088,38,04,42,145,00,05,11,291,00,07,60,043,35*71\r\n"
        "$GPGSV,2,2,08,08,02,145,00,09,46,303,47,24,16,178,32,26,18,231,43*77\r\n"
        "$PGRME,22.0,M,52.9,M,51.0,M*14\r\n"
        "$GPGLL,3907.360,N,12102.481,W,183730,A*33\r\n"
        "$PGRMZ,2062,f,3*2D\r\n"
        "$PGRMM,WGS84*06\r\n"
        "$GPBOD,,T,,M,,*47\r\n"
        "$GPRTE,1,1,c,0*07\r\n"
          ;

/* GPS data example 1's brief */
const char gps_rx_data_example_2[] =

	    ""
        "$GPRMC,183729,A,3907.356,N,12102.482,W,000.0,360.0,080301,015.5,E*6F\r\n"
        "$GPGGA,183730,3907.356,N,12102.482,W,1,05,1.6,646.4,M,-24.1,M,,*75\r\n"
          ;

/* GPS data example 3 */
const char gps_rx_data_example_3[] =

        ""
        "$GPRMC,,V,,,,,,,,,,N,V*29\r\n"
        "$GPVTG,,,,,,,,,N*3\r\n0"
        "$GPGGA,,,,,,0,00,99.99,,,,,,*48\r\n"
        "$GPGSA,A,1,,,,,,,,,,,,,99.99,99.99,99.99,1*2D\r\n"
        "$GPGSV,1,1,00,1*64\r\n"
        "$GPGLL,,,,,,V,N*64\r\n"
		"$GPRMC,,V,,,,,,,,,,N,V*29\r\n"
		"$GPVTG,,,,,,,,,N*3\r\n0"
		"$GPGGA,,,,,,0,00,99.99,,,,,,*48\r\n"
		"$GPGSA,A,1,,,,,,,,,,,,,99.99,99.99,99.99,1*2D\r\n"
		"$GPGSV,1,1,00,1*64\r\n"
		"$GPGLL,,,,,,V,N*64\r\n"
         ;

/* GPS data example in San Jose */
const char gps_rx_data_example_4[] =

	    ""
		"$GPRMC,232430,A,3724.529,N,12153.559,W,000.0,360.0,041224,000.0,W*77\r\n"
		"$GPGGA,232430,3724.529,N,12153.559,W,1,12,1.0,0.0,M,0.0,M,,*67\r\n"
		"$GPGSA,A,3,02,,,07,,09,24,26,,,,,1.6,1.6,1.0*3D\r\n"
		"$GPGSV,2,1,08,02,43,088,38,04,42,145,00,05,11,291,00,07,60,043,35*71\r\n"
		"$GPGSV,2,2,08,08,02,145,00,09,46,303,47,24,16,178,32,26,18,231,43*77\r\n"
		"$GPGLL,3724.529,N,12153.559,W,232430,A*3D\r\n"
          ;

/* GPS data example in San Jose brief */
const char gps_rx_data_example_5[] =

        ""
		"$GPRMC,232430,A,3724.529,N,12153.559,W,000.0,360.0,041224,000.0,W*77\r\n"
		"$GPGGA,232430,3724.529,N,12153.559,W,1,12,1.0,0.0,M,0.0,M,,*67\r\n"
          ;



#ifndef GPS_h
#define GPS_h

#define  pi 3.14159265
extern char gps_formated [12][20];
extern char gps[82];
extern float lat_A;
extern float long_A;
extern float speed;
void gps_read(void);
float dist_to_degree(float angle);
float degree_to_rad(float angle);
float gps_get_distance(float lat_A,float long_A ,float lat_B2,float long_B2);
void gps_format(void);


#endif


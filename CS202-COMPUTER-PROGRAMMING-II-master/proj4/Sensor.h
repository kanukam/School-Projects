#ifndef SENSOR_H
#define SENSOR_H
class Sensor
{
	public:
			Sensor();
			Sensor(char *type);
			Sensor(Sensor &s);
			void setType(char *type);
			char *getType();
			float getExtraCost();
			static int getGpsCnt();
			static int getCamCnt();
			static int getLidarCnt();
			static int getRadarCnt();
			static void resetGpsCnt();
			static void resetCamCnt();
			static void resetLidarCnt();
			static void resetRadarCnt();
			
	private:
			char m_type[256];
			float m_extracost;
			static int gps_cnt;
			static int camera_cnt;
			static int lidar_cnt;
			static int radar_cnt;
};
#endif
bool operator==(Sensor &s1,Sensor &s2);
int myStringCompare(const char *str1, const char *str2);
char *myStringCopy(char *destination, const char *source);
char *myStringCat(char *destination, const char *source);
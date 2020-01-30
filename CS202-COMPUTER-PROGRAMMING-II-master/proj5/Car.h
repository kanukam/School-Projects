#ifndef CAR_H
#define CAR_H
#define MAXSTRING 256
class Car : public Vehicle{
	public:
			Car();
			Car(char *plates,int vin,float *lla);
			Car(Car &c);
			Car & operator =(const Car & Car);
			~Car();
			void drive(int throttle);
			void move(float *lla);
			char *getPlates();
			int getThrottle();
			friend ostream & operator <<(ostream &os,Car &c1);
	private:
			char m_plates[MAXSTRING];
			int m_throttle;
};
#endif
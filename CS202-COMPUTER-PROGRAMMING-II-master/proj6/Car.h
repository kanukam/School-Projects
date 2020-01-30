#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
class Car : public Vehicle{
	public:
			Car();
			Car(float *lla);
			Car(const Car & c1);
			virtual ~Car();
			Car &operator=(Car &c1);
			void drive(int throttle);
			virtual void Move(float *lla);
			
	private:
			int m_throttle;
			virtual void serialize(ostream &os);
};
#endif
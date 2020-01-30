#ifndef VEHICLE_H
#define VEHICLE_H
#define LLASIZE 3
using namespace std;
class Vehicle
{
	public:
			Vehicle();
			Vehicle(const float *lla);
			Vehicle(const Vehicle &v1);
			virtual ~Vehicle();
			Vehicle & operator=(const Vehicle &v1);
			virtual void Move(float *lla) = 0;
			void SetLLA(float *lla);
			friend ostream & operator <<(ostream & os,Vehicle &V);
	
	protected:
			float m_lla[LLASIZE];

	private:
			virtual void serialize(ostream & os); 

};
#endif
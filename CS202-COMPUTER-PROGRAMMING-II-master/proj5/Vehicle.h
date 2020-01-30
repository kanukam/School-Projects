#ifndef VEHICLE_H
#define VEHICHLE_H
#define SIZE 3
using namespace std;
class Vehicle
{
	public:
			Vehicle();
			Vehicle(const int vinNumber, const float *lla);
			Vehicle(const Vehicle & vehicle_1);
			~Vehicle();
			Vehicle & operator=(const Vehicle & vehicle_1);
			const int getVin() const;
			void move(const float *lla);
			static int getIdgen();
			void incrementStatic();
			friend ostream & operator <<(ostream & os,const Vehicle &V);
	protected:
			float m_lla[SIZE];
			const int m_vin;
	private:
			static int s_idgen;
};
#endif			 
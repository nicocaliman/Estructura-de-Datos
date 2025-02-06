#ifndef COMPLEJO
#define COMPLEJO

#include <iostream>
#include <stdexcept>
#include <math.h>

using namespace std;

class Complejo
{
	//parte privada
	static const int MAXIMO_I_R = 2;
	static const int MINIMO_I_R = -2;

	double parte_real;
	double parte_imaginaria;

	//parte publica
public:
	
	Complejo() { }	//constructor por defecto

	Complejo(double parte_real, double parte_imaginaria): parte_real(parte_real), parte_imaginaria(parte_imaginaria)
	{
	}

	double getReal() const { return this->parte_real; }
	double getImaginario() const { return this->parte_imaginaria; }

	Complejo operator+(const Complejo& C) const
	{
		double a = this->getReal();
		double b = this->getImaginario();
		
		double c = C.getReal();
		double d = C.getImaginario();

		return Complejo(a + c, b + d);
	}

	Complejo operator*(const Complejo& C) const
	{
		double a = this->getReal();
		double b = this->getImaginario();

		double c = C.getReal();
		double d = C.getImaginario();

		return Complejo( (a*c) - (b*d), (a*d) + (c*b) );
	}

	double operator%(const Complejo& C) const
	{
		return sqrt( (this->getReal() * this->getReal() ) + ( this->getImaginario() * this->getImaginario() ) );
	}
};

inline istream& operator>>(istream& in, Complejo& c)
{
	double primero, segundo;

	in >> primero >> segundo;

	c = Complejo(primero, segundo);

	return in;
}

#endif // !COMPLEJO
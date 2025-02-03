#ifndef HORAS
#define HORAS

#include <iostream>
#include <stdexcept>

using namespace std;

class Horas 
{
	static const int HORAS_DIA = 24;
	static const int MINUTOS_HORA = 60;
	static const int SEGUNDOS_MINUTO = 60;

	int horas;
	int minutos;
	int segundos;

public:

	Horas() {}

	Horas(int h, int m, int s): horas(h), minutos(m), segundos(s)
	{
		if (this->horas < 0 || this->horas >= HORAS_DIA)
		{
			throw invalid_argument("hora invalida");
		}

		else if (this->minutos < 0 || this->minutos >= MINUTOS_HORA)
		{
			throw invalid_argument("minutos invalidos");
		}

		else if (this->segundos < 0 || this->segundos >= SEGUNDOS_MINUTO)
		{
			throw invalid_argument("segundos invalidos");
		}
	}

	//consultoras
	int get_horas() const { return this->horas; }
	int get_minutos() const { return this->minutos; }
	int get_segundos() const { return this->segundos; }

	Horas operator+(const Horas& h) const
	{
		int nueva_hora = horas + h.horas;
		int nuevo_minuto = minutos + h.minutos;
		int nuevo_segundo = segundos + h.segundos;

		// Ajustar segundos
		if (nuevo_segundo >= SEGUNDOS_MINUTO) 
		{
			nuevo_minuto += nuevo_segundo / SEGUNDOS_MINUTO;
			nuevo_segundo %= SEGUNDOS_MINUTO;
		}

		// Ajustar minutos
		if (nuevo_minuto >= MINUTOS_HORA) 
		{
			nueva_hora += nuevo_minuto / MINUTOS_HORA;
			nuevo_minuto %= MINUTOS_HORA;
		}

		// Validar si la hora se sale del rango permitido (0-23)
		if (nueva_hora >= HORAS_DIA)
			throw overflow_error("hoy no");

		return Horas(nueva_hora, nuevo_minuto, nuevo_segundo);
	}
};

inline istream& operator>>(istream& in, Horas& h) 
{
	int horas;
	int minutos;
	int segundos;

	char x2puntos;

	in >> horas >> x2puntos >> minutos >> x2puntos >> segundos;

	h = Horas(horas, minutos, segundos);

	return in;
}

inline ostream& operator<<(ostream& out, const Horas& h)
{
	if (h.get_horas() < 10)
		out << "0" << h.get_horas() << ":";
	else
		out << h.get_horas() << ":";

	if (h.get_minutos() < 10)
		out << "0" << h.get_minutos() << ":";
	else
		out << h.get_minutos() << ":";

	if (h.get_segundos() < 10)
		out << "0" << h.get_segundos();
	else
		out << h.get_segundos();

	return out;
}

#endif // !HORAS


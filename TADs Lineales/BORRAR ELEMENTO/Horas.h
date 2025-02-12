
# ifndef HORAS
# define HORAS

# include <iostream>
# include <stdexcept>

using namespace std;	//IMPORTANTE: si no lo pongo tengo que poner antes de las excepciones std::

class Horas	//declaracion de clase horas
{
	//parte privada
	static const int HORAS_DIA = 24;
	static const int MINUTOS_HORA = 60;
	static const int SEGUNDOS_MINUTO = 60;

	int h, m, s;

	//parte publica
public:

	Horas() { }	//constructor por defecto

	Horas(int h, int m, int s) : h(h), m(m), s(s)	//constructor con 3 parametros
	{
		if (h < 0 || h >= HORAS_DIA)
		{
			throw invalid_argument("hora incorrecta");
		}

		else if (m < 0 || m >= MINUTOS_HORA)
		{
			throw invalid_argument("Minutos incorrectos");
		}

		else if (s < 0 || s >= SEGUNDOS_MINUTO)
		{
			throw invalid_argument("segundos incorrectos");
		}
	}

	//consultoras
	int get_hora() const { return this->h; }
	int get_minutos() const { return this->m; }
	int get_segundos() const { return this->s; }

	bool operator==(const Horas& h) const
	{
		return this->get_hora() == h.get_hora() && this->get_minutos() == h.get_minutos() && this->get_segundos() == h.get_segundos();
	}

	bool operator<(const Horas& h) const
	{
		int menor = false;

		if (this->get_hora() == h.get_hora())
		{
			if (this->get_minutos() == h.get_minutos())
			{
				if (this->get_segundos() < h.get_segundos())
				{
					menor = true;
				}
			}
			else if (this->get_minutos() < h.get_minutos())
			{
				menor = true;
			}
		}

		else if (this->get_hora() < h.get_hora())
		{
			menor = true;
		}

		return menor;
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
	if (h.get_hora() < 10)
		out << "0" << h.get_hora() << ":";
	else
		out << h.get_hora() << ":";

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

# endif

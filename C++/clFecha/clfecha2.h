#ifndef _FECHA_H
#define _FECHA_H
#include <iostream>
using namespace std;
#define dias_t long
#define ANIO_BASE 1601
#define ANIO_TOPE 9999
#define DIA_BASE_DOMINGO 149415  // Dia rel. corresp. al 31/1/2010 (domingo)
#define DIA_REL_MAX 3067671   // Dia relativo correspondiente al 31/12/9999

class Fecha    //Maneja fechas entre el 1/1/1601 y el 31/12/9999.
{private:
	 dias_t diaRel;    // dia relativo al 1/1/1601 1-->1/1/1601
	 static dias_t diaRelFchMaq; //dia relativo de la fecha de máquina

	 static int esBisiesto(int);
	 static int diasPorMes(int,int);
	 static int diasPorAnio(int);
	 static dias_t dmaANum(int d,int m,int a);
	 static int diaJuliano(int d,int m,int a);
	 static int esFechaValida(int d, int m, int a);
	 static void julAGreg(int,int&,int&);
     static dias_t current_date(void);
 public:
     Fecha ();//{diaRel=1;};
	 Fecha (int,int,int);
	 Fecha (const Fecha& f) {diaRel=f.diaRel;};
	 static Fecha get_fecha_sistema();
	 dias_t getNum() const {return diaRel;}; // ¨Sirve para algo?....
	 Fecha& operator++();
	 Fecha& operator--();
	 Fecha  operator++(int); // posfijo
	 Fecha  operator--(int); // posfijo
	 Fecha  operator+(long) const;
	 Fecha  operator-(long) const;
	 long operator-(const Fecha&) const;
     Fecha& operator+=(long);
     Fecha& operator-=(long);
	 bool operator>(const Fecha&) const;
	 bool operator<(const Fecha&) const;
	 bool operator==(const Fecha&)const;
	 bool operator>=(const Fecha&) const;
	 bool operator<=(const Fecha&) const;
	 bool operator!=(const Fecha&) const;
     Fecha& operator=(const Fecha& f);
	 friend istream& operator>>(istream& c,Fecha& f);
	 friend ostream& operator<<(ostream& c,const Fecha& f);
	 void getAnioMesDia(int& a,int& m,int& d) const;
	 void getJuliano(int& a,int& d) const;
     unsigned siglo() const;
  	 char* diaSemana(char *) const;
	 char* fechaString(char* texto) const;
};
#endif


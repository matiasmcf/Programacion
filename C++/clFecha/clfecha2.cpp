#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <dos.h>
#include "clfecha.h"

/*#ifndef _DEPURA_H
#define _DEPURA_H
#endif      */


Fecha::Fecha  ()
{
 #ifdef _DEPURA_H
   cout << "Const. Fecha por defecto" << endl;
 #endif
diaRel = 1;
}

Fecha Fecha::get_fecha_sistema()
{
    Fecha aux;
    aux.diaRel=diaRelFchMaq;
    return aux;
}

//Inicializador del atributo static
dias_t Fecha::diaRelFchMaq=current_date();


Fecha::Fecha (int d,int m,int a)
{
    if(!esFechaValida(d,m,a))  //if(!this->esFechaValida(d,m,a))
        diaRel=1;
    else
        diaRel=dmaANum(d,m,a);
}

dias_t Fecha::current_date(void)
{
    int d, m, a;
    time_t segundos = time((time_t*)NULL);       //Se le puede pasar NULL o la dir. de la variable donde se guarda el resultado.

	struct tm* fecha_lt = localtime(&segundos); //Transforma los segundos al formato d, m, a, pero el mes y el año están desplazados.

	d = fecha_lt->tm_mday;
	m = fecha_lt->tm_mon + 1;
	a = fecha_lt->tm_year + 1900;
	return dmaANum(d, m, a);
}
dias_t Fecha::dmaANum(int d,int m,int a)
{
    dias_t num;
    unsigned ca;
    ca = a - ANIO_BASE;
    num=ca *365 + (ca/4) - (ca/100) + (ca/400) + diaJuliano(d,m,a);
    return num;
}

int Fecha::esBisiesto(int a)
{
    return (a % 400 && ( a%4 || !(a % 100)) ? 0 : 1);
}

int Fecha::diasPorMes(int m,int a)
{
    static int diasXMes[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                               {31,29,31,30,31,30,31,31,30,31,30,31}};
    return diasXMes[esBisiesto(a)][m-1];
}

int Fecha::diasPorAnio(int a)
{
    return(esBisiesto(a) ? 366 : 365);
}

int Fecha::diaJuliano(int d,int m,int a)
{
    int i=1,dias=d;
    while(i<m)
        dias+=diasPorMes(i++,a);
    return dias;
}

int Fecha::esFechaValida(int d, int m, int a)
{
    bool val=false;
    if(a >= ANIO_BASE && a <= ANIO_TOPE)
        if(m>0&&m<13)
            if(d>0&&d<=diasPorMes(m,a))
                val=true;
    return val;
}

Fecha& Fecha::operator++()
{
    diaRel= diaRel == DIA_REL_MAX? 1: ++diaRel;
    return *this;
}

Fecha& Fecha::operator--()
{
    diaRel=diaRel==1? DIA_REL_MAX:--diaRel;
    return *this;
}

Fecha Fecha::operator++(int) // posfijo
{
    Fecha f=*this;
    diaRel= diaRel == DIA_REL_MAX? 1: ++diaRel;
    return f;
}

Fecha Fecha::operator--(int) // posfijo
{
    Fecha f=*this;
    diaRel=diaRel==1? DIA_REL_MAX:--diaRel;
    return f;
}

Fecha Fecha::operator+(long c) const
{
    Fecha f = *this;
    c = c % DIA_REL_MAX;
    f.diaRel += c;
    f.diaRel = f.diaRel > DIA_REL_MAX ? f.diaRel - DIA_REL_MAX: f.diaRel;
    f.diaRel = f.diaRel <= 0 ? f.diaRel + DIA_REL_MAX : f.diaRel;
    return f;
}

Fecha Fecha::operator-(long c) const
{
    Fecha f=*this;
    c = c % DIA_REL_MAX;
    f.diaRel -= c;
    f.diaRel = f.diaRel > DIA_REL_MAX ? f.diaRel - DIA_REL_MAX: f.diaRel;
    f.diaRel = f.diaRel <= 0 ? f.diaRel + DIA_REL_MAX : f.diaRel;
    return f;
}

long Fecha::operator-(const Fecha& f) const
{
    return(diaRel - f.diaRel);
}

Fecha& Fecha::operator+=(long c)
{
    c = c % DIA_REL_MAX;
    this->diaRel += cant;
    this->diaRel = this->diaRel > DIA_REL_MAX ? this->diaRel - DIA_REL_MAX
                                              : this->diaRel;
    this->diaRel = this->diaRel <= 0 ? this->diaRel + DIA_REL_MAX : this->diaRel;
    return *this;
}

Fecha& Fecha::operator-=(long c)
{
    c = c % DIA_REL_MAX;
    this->diaRel -= cant;
    this->diaRel = this->diaRel > DIA_REL_MAX ? this->diaRel - DIA_REL_MAX
 											  : this->diaRel;
    this->diaRel = this->diaRel <= 0 ? this->diaRel + DIA_REL_MAX
 									 : this->diaRel;
    return *this;
}


bool Fecha::operator>(const Fecha& f) const
{
    return(diaRel>f.diaRel);
}

bool Fecha::operator<(const Fecha& f) const
{
    return(diaRel<f.diaRel);
}

bool Fecha::operator==(const Fecha& f) const
{
    return(diaRel==f.diaRel);
}

bool Fecha::operator>=(const Fecha& f) const
{
    return(diaRel>=f.diaRel);
}

bool Fecha::operator<=(const Fecha& f) const
{
    return(diaRel<=f.diaRel);
}

bool Fecha::operator!=(const Fecha& f) const
{
    return(diaRel!=f.diaRel);
}

Fecha& Fecha::operator=(const Fecha& f)
{
	this->diaRel=f.diaRel;
    return *this;
}
istream& operator>>(istream& c,Fecha& f)
{
    int d,m,a;
    char car;
    c>>d>>car>>m>>car>>a;
    while(!f.esFechaValida(d,m,a))
    {
        cout<<"\nFecha Incorrecta. Ingrese otra (d/m/a): ";
        c>>d>>car>>m>>car>>a;
        cout<<d<<'/'<<m<<'/'<<a;
    }
    f.diaRel=f.dmaANum(d,m,a);
    return c;
}

ostream& operator<<(ostream& c,const Fecha& f)
{
    int a,m,d;
    f.getAnioMesDia(a,m,d);
    c <<d<<'/'<<m<<'/'<<a;
    return c;
}

void Fecha::getJuliano(int& a,int& d) const
{
    long dd;
    a=(diaRel/365);
    dd = (a * 365L) + a/4 - a/100 + a/400;
    while(dd >= diaRel)
    {
        a--;
        dd = (a * 365L) + a/4 - a/100 + a/400;
    }
    dd = diaRel - dd;
    a += ANIO_BASE;
    d=dd;
}

void Fecha::getAnioMesDia(int& a,int& m,int& d) const
{
    getJuliano(a,d);
    julAGreg(a,m,d);
}

void Fecha::julAGreg(int a,int& m,int& d)
{
    m=1;
    while(d>diasPorMes(m,a))
        d-=diasPorMes(m++,a);
}

unsigned Fecha::siglo() const
{
    int a, d;
    getJuliano(a,d);
    return a%100 == 0 ? a/100 : a/100 + 1;
}

char* Fecha::diaSemana(char * cad) const
{
    static char diaSem[][10]={"Domingo","Lunes","Martes","Mi‚rcoles","Jueves",
                              "Viernes","S bado",};
    int desp;
    long dif = diaRel - DIA_BASE_DOMINGO;
    desp = labs(dif) % 7;
    if(dif < 0)
        desp= 7 - desp;
    strcpy(cad, diaSem[desp]);
    return cad;
}
char* Fecha::fechaString(char* texto) const
{
    int a,m,d;
    static char nombMes[][11]={"enero","febrero","marzo","abril","mayo",
		                       "junio","julio","agosto","septiembre","octubre",
		                       "noviembre","diciembre"};
    getAnioMesDia(a,m,d);
    itoa(d,texto,10);
    strcat(texto," de ");
    strcat(texto,nombMes[m-1]);
    strcat(texto," de ");
    itoa(a,(texto+strlen(texto)),10);
    return texto;
}

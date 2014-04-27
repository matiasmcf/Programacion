#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "ut_fecha.h"
#define esBisiesto(anio) ((anio%4==0 && anio%100!=0) || anio%400==0) ? 1:0;


////////////////////////////////////////////////////////////////

int fechaValida(int d, int m, int a)
{
    int valido[12]={31,28,31,30,31,30,31,31,30,31,30,31},v=1;
        valido[1] += esBisiesto(a);
    if( m<1 || m>12 ||d<1 || d>valido[m-1] || a<1600)
        v=0;
    return v;

}

////////////////////////////////////////////////////////////////

void fechaSig(t_fecha *f)
{
    int valido[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(f->mes==2)
        valido[1]+= esBisiesto(f->anio);
    if(valido[f->mes-1]!=f->dia)//Si no es el ultimo dia del mes
        f->dia++;
        else if(f->mes==12)
            { // Si es el ultimo dia del año
            f->dia=1;
            f->mes=1;
            f->anio++;
            }
    else
        { //Si es el ultimo dia de algun mes distinto de diciembre
        f->dia=1;
        f->mes++;
        }
}

////////////////////////////////////////////////////////////////


void sumarDias (t_fecha *f,int n)
{
    int diasmes[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(f->mes==2)
        diasmes[1]+= esBisiesto(f->anio);
    f->dia+=n;
    while (f->dia>diasmes[f->mes-1])
    {
        f->dia-=diasmes[f->mes-1];
        f->mes++;
        if (f->mes>12)
        {
            f->mes=1;
            f->anio++;
        }
    }
}

///////////////////////////////////////////////////////////////////////////

int dia_juliano(t_fecha*f)
{
    int diasmes[12]={31,28,31,30,31,30,31,31,30,31,30,31},j=0;
    if(f->mes==2)
        diasmes[1]+= esBisiesto(f->anio);
    j+=f->dia;
    f->mes-=1;
    f->dia=diasmes[f->mes-1];
    while(f->mes>1)
    {
        j+=diasmes[f->mes-1];
        f->mes-=1;
    }
    return (j);
}

///////////////////////////////////////////////////////////////////////////

int difDias(const t_fecha*f1,const t_fecha*f2)
{
    long int df1,df2, af1=f1->anio-1600, af2=f2->anio-1600;
    df1=af1*365+af1/4-af1/100+af1/400;
    df1+=dia_juliano(f1);
    df2=af2*365+af2/4-af2/100+af2/400;
    df2+=dia_juliano(f2);
    return (abs(df1-df2));
}

///////////////////////////////////////////////////////////////////////////

int diaSemana (const t_fecha*f)
{
    t_fecha dom={25,8,2013};
    return (difDias(f,&dom)%7);
}

///////////////////////////////////////////////////////////////////////////

t_fecha ingreso(int marca)
{
            t_fecha fecha;
            marca==0 ? printf("\n\nIngrese fecha(dd/mm/aaaa): "): printf("\n\nFecha erronea, ingese fecha nueva: ");
            scanf("%d %d %d",&fecha.dia,&fecha.mes,&fecha.anio);
            return fecha;
}

///////////////////////////////////////////////////////////////////////////

int compFech(const t_fecha* f1, const t_fecha*f2)
{
    if(f1->anio>f2->anio)
        return 1;
    else if(f1->anio<f2->anio)
        return -1;
    else
        if(f1->mes>f2->mes)
            return 1;
        else if(f1->mes<f2->mes)
            return -1;
        else
            if(f1->dia>f2->dia)
                return 1;
            else if(f1->dia<f2->dia)
                return -1;
    return 0;
}

///////////////////////////////////////////////////////////////////////////

void mostrarFecha(const t_fecha*fecha)
{
    printf("%02d/%02d/%d",fecha->dia,fecha->mes,fecha->anio);
}

///////////////////////////////////////////////////////////////////////////


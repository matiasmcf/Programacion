#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double factorial (int i)
{
    double f=1;
    while (i>1)
    {
        f*=i;
        i--;
    }
    return f;
}

///////////////////////////////////////////////////////////////

int combinatoria (int m,int n)
{
    int c=factorial(m)/(factorial(n)*factorial(m-n));
    return c;
}

////////////////////////////////////////////////////////////////

float ex (int x,double tol)
{
    float r=1,t=x;
    int i=1;
    while (t>=tol)
    {
        r+=t;
        t*=(double)x/++i;
    }
    return r;
}
///////////////////////////////////////////////////////////////////



float seno (float x,float t)
{   int n=1, i=0;
    double res=0, term , denominador , numerador;
    do{
        numerador= pow(x,n);
        denominador=factorial(n);
        term=numerador/((float)denominador);
        i++;
        if (i%2==0)
            res-= term;
        else
            res+= term;
        n+=2;
    }while (fabs(term)>t);
    return res;
}


///////////////////////////////////////////////////////////////////

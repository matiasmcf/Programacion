#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void insertar_con_pos(int num,int pos,int*v)
{
    *(v+pos-1)=num;
}

//////////////////////////////////////////////////////////////////////////////////
void borrar (int * v,int cant,int num )
{
 int i,cont=0;
 for (i=0;i<cant;i++)
        {
            if(v[i]!=num)
            v[i-cont]=v[i];
            else
            cont++;
        }

        cant-=cont;
}


///////////////////////////////////////////////////////////////////////////////////////
int palindromo(char *cad)
{
    int cont=0,tamcad;
    char *punt;
    punt=cad;
    tamcad=strlen(cad);
    punt+=(tamcad-1);
    while (*cad==*punt && (tamcad/2>cont))
    {
        cont++;
        cad++;
        punt--;
    }
    if ((tamcad/2)-cont<=0 )
    return (1);
    else
        return 0;

}

//////////////////////////////////////////////////////////////////////////////////

int CargarVector(float *v,int tam)
{
    int i=0;
    float dato;
    printf("\nIngrese un dato: ");
    scanf("%f",&dato);
    while (dato!=0&&i<tam)
    {
        *(v+i)=dato;
        printf("\nIngrese un dato: ");
        scanf("%f",&dato);
        ++i;
    }
    return (i);
}

//////////////////////////////////////////////////////////////////////////////////

float minvector(float*v,int c)
{
    float minimo=*v;
    int i;
    for(i=1;i<c;i++)
        if(*(v+i)<minimo)
            minimo=*(v+i);
    return minimo;
}


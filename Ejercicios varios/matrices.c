#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int traza(int *mat,int cc)
{
    int i,sum=0;
    for(i=0;i<cc;i++)
        sum+=*(mat+i*cc+i);
    return (sum);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void mostrar_martiz(int*m,int c)
{
    int i,j;
    for(i=0;i<c;i++)
        {
        for(j=0;j<c;j++)
        printf("\t%d",*(m+i*c+j));
        printf("\n");
        }
}
//////////////////////////////////////////////////////////////////////////////////////////////

void carga_matriz(int *m,int cc)
{
    int i,j;
    printf("\nIngrese elementos de la matriz: ");
    printf("\n");
    for(i=0;i<cc;i++)
        for(j=0;j<cc;j++)
            {
            printf("Ingrese elemento [%d][%d]: ",i+1,j+1);
            scanf("%d",(m+i*cc+j));
            }
    printf("\n");
    mostrar_martiz(m,cc);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int sumatoria_elementos_superiores(int *m ,int cc)
{
    int i,j, sum=0;
    for(i=0;i<cc-1;i++)
        for(j=i+1;j<cc;j++)
            sum+=*(m+i*cc+j);
    return(sum);
}

/////////////////////////////////////////

int sumatoria_elementos_2da(int *m ,int cc)
{
    int i,j, sum=0;
    for(i=0;i<cc-1;i++)
        for(j=0;j<cc-i-1;j++)
            sum+=*(m+i*cc+j);
    return(sum);
}

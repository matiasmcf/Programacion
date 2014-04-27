#include <stdio.h>
#include <stdlib.h>
int str_cmp (char*, char*);
int str_cmpi (char*, char*);
char* str_str (char*, char*);
char* str_cat (char*, char*);
char* str_cpy (char*, char*);
char* str_upr (char*);
char* str_lwr (char*);
char* str_chr (char*, char);
char* str_rchr (char*, char);

int main () //Genera un menú con opciones para probar las funciones
{
    char cad1 [30], cad2 [30],c;
    int res;
    char opcion;
    do
    {
        puts ("\n\n*******************************************************");
        puts("\nSeleccione una opcion:\n\n\t0 : cmp\n\t1 : cmpi\n\t2 : str\n\t3 : cat\n\t4 : cpy\n\t5 : upr\n\t6 : lwr\n\t7 : chr\n\t8 : rchr\n\nQ : Salir");
        scanf("%c",&opcion);
        switch (opcion)
        {
            case '0' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_CMP");
                     puts ("\nIngrese cad1: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese cad2: ");
                     fflush(stdin);
                     gets (cad2);
                     res=str_cmp(cad1, cad2);
                     if (res==0)
                        puts("\nSon iguales");
                     else if (res>0)
                            puts ("\nCad1 es mayor");
                         else
                            puts("\nCad2 es mayor");
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;

            case '1' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_CMPI");
                     puts ("\nIngrese cad1: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese cad2: ");
                     fflush(stdin);
                     gets (cad2);
                     res=str_cmpi(cad1, cad2);
                     if (res==0)
                        puts("\nSon iguales");
                     else if (res>0)
                            puts ("\nCad1 es mayor");
                         else
                            puts("\nCad2 es mayor");
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;

            case '2' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_STR");
                     puts ("\nIngrese cad1: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese cad2: ");
                     fflush(stdin);
                     gets (cad2);
                     printf("\n%s", str_str(cad1, cad2));
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;

            case '3' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_CAT");
                     puts ("\nIngrese cad1: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese cad2: ");
                     fflush(stdin);
                     gets (cad2);
                     printf("\n%s", str_cat(cad1, cad2));
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;

            case '4' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_CPY");
                     puts ("\nIngrese cad1: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese cad2: ");
                     fflush(stdin);
                     gets (cad2);
                     str_cpy(cad1,cad2);
                     printf("\nCad1= %s\tCad2= %s",cad1,cad2 );
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;

            case '5' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_UPR");
                     puts ("\nIngrese cad: ");
                     fflush(stdin);
                     gets (cad1);
                     printf("\n%s", str_upr(cad1));
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;

            case '6' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_LWR");
                     puts ("\nIngrese cad: ");
                     fflush(stdin);
                     gets (cad1);
                     printf("\n%s", str_lwr(cad1));
                     puts("\nPresione una tecla para continuar..");
                     scanf("%c");
                     break;
            case '7' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_CHR");
                     puts ("\nIngrese cad: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese caracter: ");
                     fflush(stdin);
                     scanf ("%c",&c);
                     printf("\n%s", str_chr(cad1,c));
                     puts("\nPresione una tecla para continuar..");
                     fflush(stdin);
                     scanf("%c");
                     break;
            case '8' :
                     puts ("\n\n*******************************************************");
                     puts("\nSTR_RCHR");
                     puts ("\nIngrese cad: ");
                     fflush(stdin);
                     gets (cad1);
                     puts ("\nIngrese caracter: ");
                     fflush(stdin);
                     scanf ("%c",&c);
                     printf("\n%s", str_rchr(cad1,c));
                     puts("\nPresione una tecla para continuar..");
                     fflush(stdin);
                     scanf("%c");
                     break;
        }
    }while (opcion!='q');
    return 0;
}

/**************************************************************************/

char* str_str(char *cad1,char *cad2)
{
  char *p2, *p1inicio, *p1 = cad1;
  while (*p1)
  {
    char *p1inicio=p1, *p2=cad2;
    while (*p1 && *p2 && *p1 == *p2)
    {
      p1++;
      p2++;
    }
    if (!*p2)
      return p1inicio;
    p1=p1inicio+1;
  }
  return NULL;
}

/**************************************************************************/

int str_cmp(char* cad1, char* cad2)
{
    while ((*cad1 == *cad2) && (*cad1 != '\0'))
    {
        cad1++;
        cad2++;
    }
    return *cad1 - *cad2;
    return 0;
}


/**************************************************************************/

int str_cmpi(char* cad1, char* cad2)
{
    cad1=str_lwr(cad1);
    cad2=str_lwr(cad2);
    while ((*cad1 == *cad2) && (*cad1 != '\0'))
    {
        cad1++;
        cad2++;
    }
    return *cad1 - *cad2;
    return 0;
}

/****************************************************************************/

char* str_cat(char* cad1, char* cad2)
{
    char *inicio=cad1;
    while (*cad1)
        cad1++;
    while (*cad2)
    {
        *cad1=*cad2;
        cad1++;
        cad2++;
    }
    *cad1='\0';
    return inicio;
}

/****************************************************************************/

char* str_cpy(char*cad1, char* cad2)
{
    char* inicio;
    while(*cad2)
    {
        *cad1=*cad2;
        cad1++;
        cad2++;
    }
    *cad1='\0';
    return inicio;
}

/*****************************************************************************/

char* str_upr(char*cad)
{
    char*inicio=cad;
    while(*cad)
    {
        if(*cad>='a'&&*cad<='z')
            *cad-=32;
        cad++;
    }
    return inicio;
}

/*****************************************************************************/

char* str_lwr(char*cad)
{
    char*inicio=cad;
    while(*cad)
    {
        if(*cad>='A'&&*cad<='Z')
            *cad+=32;
        cad++;
    }
    return inicio;
}

/*****************************************************************************/

char* str_chr(char* cad, char c)
{
    while (*cad&&*cad!=c)
        cad++;
    if(*cad)
        return cad;
    else
        return NULL;
}

/*****************************************************************************/

char* str_rchr(char* cad, char c)
{
    char* inicio=cad;
    while (*cad)
        cad++;
    while (cad!=inicio&&*cad!=c)
        cad--;
    if(cad!=inicio)
        return cad;
    else
        return NULL;
}

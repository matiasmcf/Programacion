#ifndef UT_FECHA_H_INCLUDED
#define UT_FECHA_H_INCLUDED
 typedef struct{
                int dia,
                    mes,
                    anio;
                }t_fecha;


int fechaValida(int,int,int);
void fechaSig(t_fecha*);
void sumarDias(t_fecha*,int);
int difDias(const t_fecha*,const t_fecha*);
int dia_juliano(t_fecha*);
int diaSemana (const t_fecha*);
t_fecha ingreso(int);
int compFech(const t_fecha*,const t_fecha*);
void mostrarFecha(const t_fecha*);
#endif // UT_FECHA_H_INCLUDED

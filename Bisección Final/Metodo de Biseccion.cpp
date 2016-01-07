/***********************************/
/*  Programa de Metodos Numericos  */
/*   Intervalo Medio o Biseccion   */
/***********************************/


#include <stdio.h>
#include <conio.h>
#include <math.h>

void Lee_Datos(void);
double Funcion(double X);

double a, b, Error;
int Max_Iter;

int main(void)
	{
	  double Error_Aprox, Prod;
	  double Xr, Xn;
	  int Ciclos = 0;

	  Lee_Datos();
	  if ( Funcion(a)*Funcion(b)  > 0 )
		 printf("\n No existe Raiz en el intervalo ????");
	  else
		 {
		  Xr = ( a+b )/2;
		  printf("\n-------------------------------------------");
		  Error_Aprox = 1;
		  printf("\n Ciclo    a         b       Xn       Error");
		  printf("\n-------------------------------------------");
		  printf("\n%3d%10.4f%10.4f%10.4f",Ciclos,a,b,Xr);

		  while ( Ciclos <= Max_Iter && Error < Error_Aprox)
				{
				  Prod = Funcion(a)*Funcion(Xr);
				  if (Prod == 0)
					 printf(" La raiz es %lf",Xr);
				  else
					 if (Prod < 0)
						b = Xr;
					 else
						a = Xr;
				  Xn = ( a+b )/2;
				  Ciclos += 1;
				  Error_Aprox = fabs((Xn-Xr)/Xn);
				  printf("\n%3d%10.4f%10.4f%10.4f%10.4f",Ciclos,a,b,Xn,Error_Aprox);
				  Xr = Xn;
				}
		   if ( Ciclos< Max_Iter)
			  {
				printf("\n-------------------------------------------");
				printf("\n\n La Raiz de la Ecuacion es => %lf",Xn);
				printf("\n Se encontro en %d Iteraciones",Ciclos);
			  }
		   else
			  printf("\n No se encontro raiz en %d Iteraciones",Ciclos);

		 }
	  getch();
	  return 0;
	}

void Lee_Datos(void)

	{
	  clrscr();
	  printf("\nDar el valor de Xi: ");
	  scanf("%lf",&a);
	  printf("Dar el valor de Xf :");
	  scanf("%lf",&b);
	  printf("Cual es el Error Permitido :");
	  scanf("%lf",&Error);
	  printf("Cual es el Maximo de Ciclos :");
	  scanf("%d",&Max_Iter);
	}

double Funcion(double X)
	{
      return pow(X,2)-3;
	  //return 500*exp(-0.02480*X)-5;
	}


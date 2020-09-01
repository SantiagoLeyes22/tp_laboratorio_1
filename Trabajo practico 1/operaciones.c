#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(int num1,int num2,int flagNum1,int flagNum2)
{
    int opcion;
    if(flagNum1 != 1 && flagNum2 !=1)
    {
        num1 = 0;
        num2 = 0;
    }
    system("cls");
    printf("******Calculadora******\n\n");
    printf("1-Ingresar 1er operando(A=%d)\n",num1);
    printf("2-Ingresar 2do operando(B=%d)\n",num2);
    printf("3-Calcular las siguientes operaciones\n");
    printf("a)Calcular la suma de %d + %d:\n",num1,num2);
    printf("b)Calcular la resta de %d - %d:\n",num1,num2);
    printf("c)Calcular la division de %d / %d:\n",num1,num2);
    printf("d)Calcular la multiplicacion de %d * %d:\n",num1,num2);
    printf("4-Informar resultados\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int suma(int num1,int num2)
{
    int sum;
    sum = num1 + num2;
    return sum;
}
int resta(int num1,int num2)
{
    int rest;
    rest = num1 - num2;
    return rest;
}
float division(int num1,int num2)
{
    float divi;
    if(num2!=0)
    {
        divi = (float)num1 / num2;
    }
    else{
        printf("No se puede dividir por cero.");
    }
    return divi;
}
int multiplicacion(int num1,int num2)
{
    int multiplicar;
    multiplicar = num1 * num2;
    return multiplicar;
}
void mostrarOperaciones(int num1,int num2)
{
    printf("El resultado de %d + %d es: %d\n",num1,num2,suma(num1,num2));
    printf("El resultado de %d - %d es: %d\n",num1,num2,resta(num1,num2));
    if(num2!=0)
    {
        printf("El resultado de %d / %d es: %.2f\n",num1,num2,division(num1,num2));
    }
    else{
        printf("No se puede dividir por 0\n");
    }
    printf("El resultado de %d * %d es: %d\n",num1,num2,multiplicacion(num1,num2));
    printf("El factorial de %d es: %f y El factorial de %d es: %f\n",num1,factorialUno(num1),num2,factorialDos(num2));
    system("pause");
}
double factorialUno(int num1)
{
    double Resultado = 1;
    while(num1 > 1) {
       Resultado *= num1;
       num1--;
    }
    return Resultado;
}
double factorialDos(int num2)
{
    double ResultadoDos = 1;
    while(num2 > 1) {
       ResultadoDos *= num2;
       num2--;
    }
    return ResultadoDos;
}

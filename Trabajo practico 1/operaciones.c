#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
int menu(float num1,float num2,int flagNum1,int flagNum2)
{
    int opcion;
    if(flagNum1 != 1 && flagNum2 !=1)
    {
        num1 = 0;
        num2 = 0;
    }
    system("cls");
    printf("******Calculadora******\n\n");
    printf("1-Ingresar 1er operando(A=%.2f)\n",num1);
    printf("2-Ingresar 2do operando(B=%.2f)\n",num2);
    printf("3-Calcular las siguientes operaciones\n");
    printf("a)Calcular la suma de %.2f + %.2f:\n",num1,num2);
    printf("b)Calcular la resta de %.2f - %.2f:\n",num1,num2);
    printf("c)Calcular la division de %.2f / %.2f:\n",num1,num2);
    printf("d)Calcular la multiplicacion de %.2f * %.2f:\n",num1,num2);
    printf("e)Calcular el factorial de %d y el de %d\n",(int)num1,(int)num2);
    printf("4-Informar resultados\n");
    printf("5-Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

float suma(float num1,float num2)
{
    float sum;
    sum = num1 + num2;
    return sum;
}
float resta(float num1,float num2)
{
    float rest;
    rest = num1 - num2;
    return rest;
}
float division(float num1,float num2)
{
    float divi;
    if(num2!=0)
    {
        divi = num1 / num2;
    }
    else{
        printf("No se puede dividir por cero.");
    }
    return divi;
}
float multiplicacion(float num1,float num2)
{
    float multiplicar;
    multiplicar = num1 * num2;
    return multiplicar;
}
void mostrarOperaciones(float num1,float num2)
{
    printf("El resultado de %.2f + %.2f es: %.2f\n",num1,num2,suma(num1,num2));
    printf("El resultado de %.2f - %.2f es: %.2f\n",num1,num2,resta(num1,num2));
    if(num2!=0)
    {
        printf("El resultado de %.2f / %.2f es: %.2f\n",num1,num2,division(num1,num2));
    }
    else{
        printf("No se puede dividir por 0\n");
    }
    printf("El resultado de %.2f * %.2f es: %.2f\n",num1,num2,multiplicacion(num1,num2));
    if(num1 >=1)
    {
        printf("El factorial de %d es:%ld\n",(int)num1,factorialUno(num1));
    }
    else{
        printf("Para obtener el primer factoria el primer numero debe ser mayor o igual a uno\n");
    }
    if(num2>=1)
    {
        printf("El factorial de %d es:%ld\n",(int)num2,factorialDos(num2));
    }
    else{
        printf("Para obtener el segundo factorial el segundo numero debe ser mayor o igual a uno\n");
    }
    system("pause");
}

long int factorialUno(float num1)
{
    long int Resultado = 1;
    int numeroUno = (int)num1;
    if(numeroUno>=1)
    {
        while(numeroUno > 1) {
           Resultado *= numeroUno;
           numeroUno--;
        }
    }
    return Resultado;
}
long int factorialDos(float num2)
{
    long int ResultadoDos = 1;
    int numeroDos = (int)num2;
    if(numeroDos>=1)
    {
         while(numeroDos > 1) {
           ResultadoDos *= numeroDos;
           numeroDos--;
        }
    }
    return ResultadoDos;
}
int validarNumeros(char numero[])
{
    int i;
    for(i=0; i<strlen(numero);i++)
    {
        if(!(isdigit(numero[i]))&&!(numero[i]=='.'))
        {
            printf("Eso no es un numero, reingrese numero:");
            getch();
            return 0;
        }
    }
    return 1;
}
float pedirNumero()
{
    char numero[10];
    float num;
    int N;
    do{
        scanf("%s",numero);
        N = validarNumeros(numero);
    }while(N==0);
    num = atof(numero);

    return num;
}

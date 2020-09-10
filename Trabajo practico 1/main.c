#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
int main()
{
    char seguir = 's';
    char confirmar;
    float num1;
    float num2;
    int flagNum1;
    int flagNum2;
    int operacionesTerminadas;
    do{
    switch(menu(num1,num2,flagNum1,flagNum2))
    {
    case 1:
        printf("Ingrese primer operando:");
        num1 = pedirNumero();
        flagNum1 = 1;
        break;
    case 2:
        if(flagNum1 == 1)
        {
            printf("Ingrese segundo operando:");
            num2 = pedirNumero();
            flagNum2 = 1;
        }
        else{
            printf("Primero ingrese el primer operando.\n");
            system("pause");
        }
        break;
    case 3:
        if(flagNum2 == 1)
        {
            printf("La operaciones fueron exitosamente realizadas,utilize la opcion cuatro para saber resultados\n");
            operacionesTerminadas = 1;
            system("pause");
        }
        else{
            printf("Antes de realizar los calculos primero ingrese los operandos.\n");
            system("pause");
        }
        break;
    case 4:
        if(operacionesTerminadas == 1)
        {
            mostrarOperaciones(num1,num2);
        }
        else{
            printf("Antes de ver los resultados ingrese los operandos.\n");
            system("pause");
        }
        break;
    case 5:
        printf("¿Esta seguro que quiere salir?");
        fflush(stdin);
        scanf("%c",&confirmar);
        if(confirmar == 's')
        {
            seguir='n';
        }
        break;
    }
    }while(seguir == 's');
    return 0;
}

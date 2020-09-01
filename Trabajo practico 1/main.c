#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char seguir = 's';
    char confirmar;
    int num1 = 0;
    int num2 = 0;
    int flagNum1;
    int flagNum2;
    int operacionesTerminadas;
    do{
    switch(menu(num1,num2))
    {
    case 1:
        printf("Ingrese primer operando:");
        scanf("%d",&num1);
        flagNum1 = 1;
        break;
    case 2:
        if(flagNum1 == 1)
        {
            printf("Ingrese segundo operando:");
            scanf("%d",&num2);
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
            //subMenu(num1,num2);
            printf("La operaciones fueron exitosamente realizadas,precione la opcion cuatro para saber resultados\n");
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
        printf("Esta seguro que quiere salir?");
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

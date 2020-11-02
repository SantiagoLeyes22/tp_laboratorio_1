#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "get.h"
#include "LinkedList.h"
#include "Controller.h"

int menuPrincipal()
{
    int opcion;
    printf("****TP 3****\n\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados\n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10-Salir\n");
    printf("Ingrese una opcion:");
    scanf("%d",&opcion);
    return opcion;
}

int menuModificar()
{
    int opcion;
    system("cls");
    printf("MODIFICAR EMPLEADO:\n\n");
    printf("1-Nombre\n");
    printf("2-Horas trabajadas\n");
    printf("3-Salario\n");
    printf("4-Salir\n");
    opcion = getInt("Seleccione una opcion:");

    return opcion;
}
int menuOrdenar()
{
    system("cls");
    int option;
    printf("ORDENAR EMPLEADOS:\n\n");
    printf("Metodos:\n");
    printf("1-Empleados ordenados por ID\n");
    printf("2-Empleados ordenados por nombre\n");
    printf("3-Empleados ordenados por horas trabajadas\n");
    printf("4-Empleados ordenados por salario\n");
    option = getInt("Seleccione un metodo:");

    return option;
}

int getDireccion()
{
    system("cls");
    int optionDireccion;
    printf("ELIJA EL SENTIDO DE ORDENAMIENTO:\n\n");
    printf("1-Ascendente\n");
    printf("2-Descendente\n");
    printf("3-Salir\n");
    do
    {
        optionDireccion = getInt("Selecciones una opcion:");
        switch(optionDireccion)
        {
        case 1:
            optionDireccion = 1;
            break;
        case 2:
            optionDireccion = 0;
            break;
        }
        return optionDireccion;
    }
    while(optionDireccion != 3);
}
void opciones_principales_linkedList(LinkedList* listaEmpleados)
{
     int flag = 0;
     int option;
     do{
        option = menuPrincipal();
        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    flag = 1;
                    system("pause");
                }
                else{
                    printf("Ya se cargaron datos\n");
                    system("pause");
                }
                break;
            case 2:
                if(flag == 0)
                {
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    flag = 1;
                    system("pause");
                }
                else{
                    printf("Ya se cargaron datos\n");
                    system("pause");
                }
                break;
            case 3:
                if(flag == 1)
                {
                    controller_addEmployee(listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 4:
                if(flag == 1)
                {
                    controller_editEmployee(listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 5:
                if(flag == 1)
                {
                    controller_removeEmployee(listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 6:
                if(flag == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 7:
                if(flag == 1)
                {
                   controller_sortEmployee(listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 8:
                if(flag == 1)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 9:
                if(flag == 1)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    system("pause");
                }
                else{
                    printf("Primero cargue los datos\n");
                    system("pause");
                }
                break;
            case 10:

                break;
        }
        system("cls");
    }while(option != 10);
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "get.h"
#include "menus.h"
#include "Controller.h"

int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee)
{
    int estado = 0;
    FILE *pArchivo;
    if((pArchivo = fopen(path,"r"))==NULL)
    {
        printf("Error de lectura...\n");
    }
    else{
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        estado = 1;
    }
    return estado;
}

int controller_loadFromBinary(char* path ,LinkedList* pArrayListEmployee)
{
    int estado = 0;
    FILE *pArchivo;
    if((pArchivo = fopen(path,"rb"))==NULL)
    {
        printf("Error de lectura...\n");
    }
    else{
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        estado = 1;
    }
    return estado;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf("ALTA DE EMPLEADOS:\n\n");
    int estado = 0;
    Employee* nuevoEmpleado = employee_new();
    char idAux[50],nombreAux[50],horasTrabajadasAux[50],sueldoAux[50];
    int horasTrabajadas;
    int sueldo;
    int auxId;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee !=NULL)
    {
        auxId = len + 1;
        itoa(auxId,idAux,10);
        getString("Ingrese nombre:",nombreAux);
        horasTrabajadas = getInt("Ingrese el numero de horas trabajadas:");
        sueldo = getInt("Ingrese sueldo:");

        itoa(horasTrabajadas,horasTrabajadasAux,10);
        itoa(sueldo,sueldoAux,10);

        nuevoEmpleado = employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        ll_add(pArrayListEmployee,nuevoEmpleado);
        estado = 1;
    }
    return estado;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    system("cls");
    printf("MODIFICAR EMPLEADOS:\n\n");
    int estado = 0;
    Employee* auxEmpleado;
    char nombreAux[50];
    int id;
    int sueldo;
    int horasTrabajadas;
    int option;
    int len = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        id = getInt("Ingrese el ID del empleado que desea modificar:");
        system("cls");
        for(i=0;i<len;i++)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            if(id == auxEmpleado->id)
            {
                estado = 1;
                do
                {
                    option = menuModificar();

                    switch(option)
                    {
                    case 1:
                        getString("Ingrese nuevo nombre \n", nombreAux);
                        employee_setNombre(auxEmpleado, nombreAux);
                        break;
                    case 2:
                        horasTrabajadas = getInt("ingrese cantidad de horas trabajadas\n");
                        employee_setHorasTrabajadas(auxEmpleado,horasTrabajadas);
                        break;
                    case 3:
                        sueldo = getInt("ingrese nuevo sueldo \n");
                        employee_setSueldo(auxEmpleado,sueldo);
                        break;
                    case 4:
                        option = 4;
                        break;
                    default:
                        printf("Opcion invalida");
                        break;
                    }
                }
                while(option != 4);
            }
        }
        if(estado == 0)
        {
            printf("No hay ningun empleado registrado con ese ID\n");
        }
    }
    return estado;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int estado = 0;
    char respuesta;
    Employee* auxEmpleado;
    int i;
    int idAux;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee !=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idAux = getInt("Ingrese el id del empleado que desea eliminar:");
        system("cls");
        for(i=0;i<len;i++)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
            if(idAux==auxEmpleado->id)
            {
                respuesta = getChar("Esta seguro que desea eliminar el empleado? presione 's' para confirmar o 'n' para cancelar:");
                if(respuesta == 's')
                {
                    ll_remove(pArrayListEmployee,i);
                    printf("El empleado fue borrado con exito\n");
                    employee_delete(auxEmpleado);
                    estado = 1;
                    break;
                }
                else{
                    printf("Baja de empleado cancelada\n");
                    estado = 1;
                }
            }
        }
        if(estado == 0)
        {
            printf("El id ingresado no existe\n");
        }
    }
    return 0;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf("Listado de empleados:\n\n");
    Employee* pEmpleadoAux;
    int estado = 0;
    int idAux,horasTrabajadasAux,sueldoAux,i;
    char nombreAux[50];
    int len = ll_len(pArrayListEmployee);
    if(pArrayListEmployee !=NULL && len >0)
    {
        printf(" Id------Nombre-----Horas trabajadas---Sueldo \n");
        for(i = 0;i<len;i++)
        {
            pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleadoAux, &idAux);
            employee_getNombre(pEmpleadoAux,nombreAux);
            employee_getHorasTrabajadas(pEmpleadoAux,&horasTrabajadasAux);
            employee_getSueldo(pEmpleadoAux,&sueldoAux);
            printf("%5d  %10s %10d  %15d\n",idAux, nombreAux, horasTrabajadasAux,sueldoAux);
        }
        estado = 1;
    }
    else{
        printf("No se puede mostrar la lista, primero cargue algun empleado\n");
    }
    return estado;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;
    int sentido;
    if(pArrayListEmployee != NULL)
    {
        option = menuOrdenar();
    }

    switch(option)
    {
    case 1:
        sentido = getDireccion();
        ll_sort(pArrayListEmployee,employee_sortById,sentido);
        break;
    case 2:
        sentido = getDireccion();
        ll_sort(pArrayListEmployee,employee_sortByNombre,sentido);
        break;
    case 3:
        sentido = getDireccion();
        ll_sort(pArrayListEmployee,employee_sortByHorasTrabajadas,sentido);
        break;
    case 4:
        sentido = getDireccion();
        ll_sort(pArrayListEmployee,employee_sortBySueldo, sentido);
        break;
    }
    return 1;
}
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int estado = 0;
    int len = ll_len(pArrayListEmployee);
    Employee* pEmpleado;
    FILE* pArchivo = fopen(path,"w");
    int i;
    if(pArchivo !=NULL)
    {
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
        if(pArrayListEmployee != NULL)
        {
            for(i=0;i<len;i++)
            {
                pEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                fprintf(pArchivo,"%d,%s,%d,%d\n",pEmpleado->id,pEmpleado->nombre,pEmpleado->horasTrabajadas,pEmpleado->sueldo);
            }
            printf("Archivo guardado con exito\n");
        }
        fclose(pArchivo);
        estado = 1;
    }
    else{
        printf("Error al abrir el archivo\n");
    }
    return estado;
}
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int estado;
    Employee* pEmpleadoAux;
    FILE* pArchivo = fopen(path,"wb");

    int len = ll_len(pArrayListEmployee);
    int i;

    if(pArchivo == NULL)
    {
        printf("Error al guardar en binario\n");
        estado = 0;
    }

    if(pArrayListEmployee!=NULL)
    {
        for(i =0;i<len;i++)
        {
            pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmpleadoAux,sizeof(Employee), 1, pArchivo);
        }
        printf("Archivo.bin guardado correctamente\n");
        estado = 1;
    }
    fclose(pArchivo);
    return estado;
}

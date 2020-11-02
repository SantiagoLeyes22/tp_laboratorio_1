#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado = employee_new();
    int r;
    int i = 0;
    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        if(r==4)
        {
            auxEmpleado = employee_newParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
            ll_add(pArrayListEmployee,auxEmpleado);
            i++;
        }
    }
    printf("Se cargaron %d empleados a la lista en modo texto\n",i);
    return i;

}
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee empleadoAux;
    int i = 0;

    fread(&empleadoAux, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee *empleadoNuevo = employee_new();
        employee_setId(empleadoNuevo,empleadoAux.id);
        employee_setHorasTrabajadas(empleadoNuevo,empleadoAux.horasTrabajadas);
        employee_setNombre(empleadoNuevo,empleadoAux.nombre);
        employee_setSueldo(empleadoNuevo,empleadoAux.sueldo);
        i ++;
        ll_add(pArrayListEmployee,empleadoNuevo);
        fread(&empleadoAux,sizeof(Employee),1,pFile);
    }
    printf("Se cargaron %d empleados a la lista (modo binario) \n", i);
    return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
Employee* employee_new()
{
    Employee* pEmpleado;
    pEmpleado = (Employee*) calloc(sizeof(Employee),1);
    return pEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* auxiliarEmpleado = employee_new();

    if( auxiliarEmpleado != NULL )
    {
        int id = atoi(idStr);
        employee_setId(auxiliarEmpleado, id);

        int horasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(auxiliarEmpleado, horasTrabajadas);

        int sueldo = atoi(sueldoStr);
        employee_setSueldo(auxiliarEmpleado, sueldo);


        employee_setNombre(auxiliarEmpleado, nombreStr);
    }
    return auxiliarEmpleado;


    return 0;
}
int employee_setId(Employee* this,int id)
{
    int set = 0;
    if(this  !=NULL && id>0)
    {
        this->id = id;
        set = 1;
    }
    return set;
}
int employee_getId(Employee* this,int* id)
{
    int estado = 0;
    if(this !=NULL && id != NULL)
    {
        *id = this ->id;
        estado = 1;
    }

    return estado;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int estado = 0;
    if(this != NULL && nombre != NULL)
    {
        if(strlen(nombre)!=0)
        {
            strcpy(this->nombre,nombre);
            estado = 1;
        }
    }
    return estado = 0;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int estado = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        estado = 1;
    }
    return estado;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this ->horasTrabajadas = horasTrabajadas;
        estado = 1;
    }
    return estado;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int estado = 0;
    if(this != NULL)
    {
        *horasTrabajadas = this ->horasTrabajadas;
        estado = 1;
    }
    return estado;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int estado = 0;
    if(this != NULL && sueldo > 0)
    {
        this ->sueldo = sueldo;
        estado = 1;
    }
    return estado;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int estado = 0;
    if(this != NULL)
    {
        *sueldo = this ->sueldo;
        estado = 1;
    }
    return estado;
}
void employee_delete(Employee* this)
{
    if(this !=NULL)
    {
        free(this);
    }
}
int employee_sortById(void* empleadoA,void* empleadoB)
{
    int sort;
    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        int idA;
        int idB;
        employee_getId(empleadoA,&idA);
        employee_getId(empleadoB,&idB);
        if(idA>idB)
        {
            sort = 1;
        }
        else if(idA == idB)
        {
            sort = 0;
        }
        else{
            sort = -1;
        }
    }
    return sort;
}
int employee_sortByNombre(void* empleadoA,void* empleadoB)
{
    int sort;
    char nombreA[51];
    char nombreB[51];
    if(empleadoA != NULL && empleadoB !=NULL)
    {
        employee_getNombre(empleadoA, nombreA);
        employee_getNombre(empleadoB, nombreB);

        sort = strcmp(nombreA,nombreB);
    }
    return sort;
}
int employee_sortByHorasTrabajadas(void* empleadoA,void* empleadoB)
{
    int sort;
    if(empleadoA != NULL && empleadoB !=NULL)
    {
        int HorasA;
        int HorasB;
        employee_getHorasTrabajadas(empleadoA, &HorasA);
        employee_getHorasTrabajadas(empleadoB, &HorasB);
        if(HorasA >HorasB)
        {
            sort = 1;
        }
        else if(HorasA == HorasB)
        {
            sort = 0;
        }
        else
        {
            sort = -1;
        }
    }
    return sort;
}
int employee_sortBySueldo(void* empleadoA,void* empleadoB)
{
    int sort;
    if(empleadoA !=NULL && empleadoB !=NULL)
    {
        int sueldoA;
        int sueldoB;

        employee_getSueldo(empleadoA, &sueldoA);
        employee_getSueldo(empleadoB, &sueldoB);

        if(sueldoA >sueldoB)
        {
            sort = 1;
        }
        else if(sueldoA == sueldoB)
        {
            sort = 0;
        }
        else
        {
            sort = -1;
        }
    }
    return sort;
}

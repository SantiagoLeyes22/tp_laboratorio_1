#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "validaciones.h"
#define TAM 1000
int main()
{
    int id = 1000;
    eEmpleado listaEmpleados[TAM];
    inicializarEmpleados(listaEmpleados,TAM);
    opcionesPrincipales(listaEmpleados,TAM,id);
    return 0;
}

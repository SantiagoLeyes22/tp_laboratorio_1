#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmpleado;
#endif // ARRAYEMPLOYEES_H_INCLUDED
int menu();
void inicializarEmpleados(eEmpleado [],int);
void cargarTodosLosEmpleados(eEmpleado[],int,int);
eEmpleado cargarEmpleado(int);
int buscarLibre(eEmpleado[],int);
void mostrarUnEmpleado(eEmpleado);
void mostrarNominaEmpleados(eEmpleado[],int);
int verificarSiEsta(eEmpleado[],int,int);
void opcionesDeModificar(eEmpleado lista[],int legajo);
void confirmarModificacion(eEmpleado[],int,int,int);
int preguntarModificacion();
void modificarEmpleado(eEmpleado[],int);
int menuModificar();
void eliminarEmpleados(eEmpleado[],int);
void confirmarEliminacion(eEmpleado[],int,int,int);
int preguntar();
void eliminar(eEmpleado[],int,int);
int menuInformar();
void opcionesInformes(eEmpleado[],int);
void opcionesPrincipales(eEmpleado [],int,int);
float totalYpromedioSalarios(eEmpleado [],int);
int contarEmpleados(eEmpleado [],int);
int cantidadEmpleadosQueSuperanSalarioPromedio(eEmpleado [],int,int);
float acumular(eEmpleado [],int);
void mostrarPromediosYsalarios(int,float,int,float);
void ordenarEmpleados(eEmpleado [],int);

/** \brief Muestra menu seleccionable
 *
 * \param Muestra todas las opciones
 * \return int Se obtiene la opcion solicitada
 *
 */
int menu(int num1,int num2,int flagNum1,int flagNum2);
void mostrarOperaciones(int num1,int num2);
/** \brief Multiplica dos numeros
 *
 * \param int numero1 Primer factor
 * \param int numero2 Segundo factor
 * \return int Se obtiene la multiplicacion de ambos factores
 *
 */
int multiplicacion(int num1,int num2);
/** \brief Divide dos numeros
 *
 * \param int numero1  Es el dividendo
 * \param  int numero2  Es el divisor
 * \param  se castea num1 a float
 * \return float Se obtiene el resultado de la division
 * La funcion no valida si el divisor es 0
 */
float division(int num1,int num2);
/** \brief Resta dos numeros
 *
 * \param int numero1 El minuendo
 * \param int numero2 El sustraendo
 * \return int Se obtiene la diferencia
 *
 */
int resta(int num1,int num2);
/** \brief Suma dos numeros
 *
 * \param int numero1 El primer sumando
 * \param int numero2 El segundo sumando
 * \return int La suma de los numeros ingresados
 *
 */
int suma(int num1,int num2);
long int factorialUno(int num1);
long int factorialDos(int num2);


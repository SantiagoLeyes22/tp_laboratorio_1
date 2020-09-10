/** \brief Muestra menu seleccionable
 *
 * \param Muestra todas las opciones
 * \return int Se obtiene la opcion solicitada
 *
 */
int menu(float num1,float num2,int flagNum1,int flagNum2);
void mostrarOperaciones(float num1,float num2);
/** \brief Multiplica dos numeros
 *
 * \param int numero1 Primer factor
 * \param int numero2 Segundo factor
 * \return int Se obtiene la multiplicacion de ambos factores
 *
 */
float multiplicacion(float num1,float num2);
/** \brief Divide dos numeros
 *
 * \param int numero1  Es el dividendo
 * \param  int numero2  Es el divisor
 * \param  se castea num1 a float
 * \return float Se obtiene el resultado de la division
 * La funcion no valida si el divisor es 0
 */
float division(float num1,float num2);
/** \brief Resta dos numeros
 *
 * \param int numero1 El minuendo
 * \param int numero2 El sustraendo
 * \return int Se obtiene la diferencia
 *
 */
float resta(float num1,float num2);
/** \brief Suma dos numeros
 *
 * \param int numero1 El primer sumando
 * \param int numero2 El segundo sumando
 * \return int La suma de los numeros ingresados
 *
 */
float suma(float num1,float num2);
/** \brief Calcula el factorial de un numero
 *
 * \param num1 float
 * \return long int
 *
 */
long int factorialUno(float num1);
/** \brief Calcula el factorial de un numero
 *
 * \param num2 float
 * \return long int
 *
 */
long int factorialDos(float num2);
float pedirNumero();
int validarNumeros(char numero[]);

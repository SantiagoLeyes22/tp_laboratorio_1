#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/** \brief Asks for a number and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated number
 * \return The number validated
 *
 */
int getInt(char message[],char errorMessage[]);

/** \brief Asks for a float and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a non validated float number
 * \return The float number validated
 *
 */
float getFloat(char message[],char errorMessage[]);

/** \brief Asks for a string and returns it validated
 *
 * \param str The string to write on
  * \param message Message for the user
 * \param errorMessage A message in case the user enters a string that isn't only letters
 *
 */
void getString(char str[],int len,char message[],char errorMessage[]);

/** \brief Asks for a character,validates it and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't a letter
  * \return The character validated
 *
 */
char getChar(char message[],char errorMessage[]);

/** \brief Asks the user to choose an option between two characters, validates it's one of the options and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a character that isn't one of the options
 * \return  The character validated
 *
 */
char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2);

/** \brief Asks the user to choose an option between two numbers, validates it's one of the options and returns it validated
 *
 * \param message Message for the user
 * \param errorMessage A message in case the user enters a number that isn't one of the options
 * \return  The number validated
 *
 */
int getIntTwoOptions(char message[],char errorMessage[],int option1,int option2);

/** \brief Validates that a string has only numbers
 *
 * \param number The string to validate
 * \return 1 in case the string is only numbers and 0 if it's not
 *
 */
int validatePositiveInteger(char number[]);

/** \brief Validates that a string has only numbers and one '.'
 *
 * \param numberFloat The string to validate
 * \return 1 in case the string is only numbers or number and one '.' and 0 if it's not
 *
 */
int validatePositiveFloat(char numberFloat[]);

/** \brief Validates that a string has only letters
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and 0 if it's not
 *
 */
int isOnlyLetters(char str[]);

#endif // VALIDACIONES_H_INCLUDED



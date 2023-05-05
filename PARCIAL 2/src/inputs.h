#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * @fn int getInt(char*, char*, int, int)
 * @brief this ask the user to enter an int number and validates it
 *
 * @param _msg the message that will show up
 * @param _errMsg the message that will show up if there was an error with the input (< min or > max)
 * @param _min the minimum possible number
 * @param _max the maximum possible number
 * @return returns the int number entered
 */
int getInt(char *_msg, char *_errMsg, int _min, int _max);

/**
 * @fn int getCharacter(char*, char*)
 * @brief this asks the user to enter a char and validates it
 *
 * @param _character where the char will be stored
 * @param _msg the message that will show up
 * @return (-1) if error (character variable is null or message not found) - (0) if ok
 */
int getCharacter(char *_char, char *_msg);

/**
 * @fn int verify(char*)
 * @brief this asks the user to enter a char and validates if its an 's' or an 'S'
 *
 * @param _msg the message that will show up
 * @return (-1) if error (character is not an 's' or an 'S') - (0) if ok
 */
int verify(char *_msg);

/**
 * @fn void printLine(char*)
 * @brief This shows a separator with a message (or not)
 *
 * @param _msg the message that will be in the middle of the separator
 */
void printLine(char *_msg);

int menuOpcionFiltrarPorOrigen();

#endif /* INPUTS_H_ */

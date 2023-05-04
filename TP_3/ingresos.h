#ifndef INGRESOS_H_
#define INGRESOS_H_

int ingresarIntConRango(int* resultado, char* mensaje, char* mensajeError, int minimo, int maximo);
int ingresarCadenaCaracteres(int tam,char* textoIngresado,char* mensaje,char* mensajeError);
int verificarCaracterSN(char letra);
int ingresarIntConMinimo(int* resultado, char* mensaje, char* mensajeError, int minimo);
int getCharacter(char *_char, char *_msg);
int verify(char *_msg);

#endif /* INGRESOS_H_ */

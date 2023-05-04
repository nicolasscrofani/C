#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;

}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);
int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);
int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);
int selec_buscarPorId(LinkedList* pArrayListSeleccion, int idBuscado, int *indice);
int selec_AsignarDescripcionPais(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, int indice, char *descripcionPais);
int selec_Solicitar_Id(LinkedList* pArrayListSeleccion, int* indice);
int selec_IngresarConfederacion(char* opcion);
int selec_verificarConvocadosPorconfederacion(char* opcion, LinkedList* pArrayListSeleccion);
int selec_restarConvocado(LinkedList* pArrayListSeleccion, int idSeleccion);
int selec_ordenarPorConfederacion(void *a, void *b) ;

#endif // selec_H_INCLUDED

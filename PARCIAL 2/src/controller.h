#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "eCompras.h"

int controller_loadFromText(char *path, LinkedList *pArrayListCompra);
int controller_saveAsText(char *path, LinkedList *pArrayListCompra);
int controller_listarCompras(LinkedList *pArrayListCompra);
int controller_totalCompras(LinkedList *pArrayListCompra);
int controller_filtroAdministracion(LinkedList *pArrayListCompra);
int controller_filtroTaller(LinkedList *pArrayListCompra);
int controller_filtroVentas(LinkedList *pArrayListCompra);
int controller_sortCompras(LinkedList *pArrayServicios);


#endif /* CONTROLLER_H_ */

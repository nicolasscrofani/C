#include "servicio.h"

void hojaServicio_inicializarArray(eHojaServicio *servicios, int tam) {

	int i;

	if (servicios != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			(*(servicios + i)).estado = VACIO;
		}
	}
}

void hojaServicio_mostrarUno(eHojaServicio servicio) {

	printf("%-10d %-20d %-20s %-20.2f %d/%d/%d\n", servicio.idHoja,
			servicio.vehiculoId, servicio.descripcion, servicio.precioServicio,
			servicio.fecha.dia, servicio.fecha.mes, servicio.fecha.anio);

}

void hojaServicio_mostrarTodos(eHojaServicio *servicios, int tam) {

	int i;

	printf("\nMostrando servicios...\n\n"
			"\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "ID DEL VEHICULO",
			"DESCRIPCION", "PRECIO DEL SERVICIO", "FECHA");

	for (i = 0; i < tam; i++) {

		if ((*(servicios + i)).estado == OCUPADO) {

			hojaServicio_mostrarUno(*(servicios + i));
		}
	}
	printf("\n");

}

int hojaServicio_buscarEspacioLibre(eHojaServicio *servicios, int tam) {

	int i;
	int index = -1;

	if (servicios != NULL && tam > 0) {

		for (i = 0; i < tam; i++) {

			if ((*(servicios + i)).estado == VACIO) {

				index = i;
				break;
			}
		}
	}
	return index;
}

int hojaServicio_agregarUno(eHojaServicio *servicios, int tamServicios, eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos, int *id) {

	int rtn = -1;
	int nuevoId;
	int index;
	int aux;
	int idVehiculo;


	if (servicios != NULL && vehiculos != NULL && tipos != NULL && id != NULL && tamServicios > 0 && tamVehiculos > 0 && tamTipos > 0) {

		index = hojaServicio_buscarEspacioLibre(servicios, tamServicios);

		idVehiculo = vehiculo_obtenerId(vehiculos, tamVehiculos, tipos,
				tamTipos);



		aux = vehiculo_buscarPorId(vehiculos, tamVehiculos, idVehiculo);

		nuevoId = *id;

		if (aux != -1) {

			if (index != -1) {

				printf("ALTA DE HOJA DE SERVICIO\n");

				(*(servicios + index)).idHoja = nuevoId;
				(*(servicios + index)).vehiculoId = idVehiculo;


				pedirCadena((*(servicios + index)).descripcion,
						"Ingrese descripcion: ",
						"descripcion invalida, reingrese: ", 51);

				pedirFlotante(&(*(servicios + index)).precioServicio,
						"Ingrese precio del servicio: ",
						"Precio invalido, reingrese: ", 0, 1000000);

				(*(servicios + index)).fecha = pedirFecha("Ingese fecha");

				printf("\nMostrando Hoja de servicio...\n\n"
						"\n%-10s %-20s %-20s %-20s %-20s\n", "ID",
						"ID DEL VEHICULO", "DESCRIPCION", "PRECIO DEL SERVICIO",
						"FECHA");

				hojaServicio_mostrarUno(*(servicios + index));

				if (!verificarConfirmacion("\nConfirmar? Ingrese 's': ")) {

					(*(servicios + index)).estado = OCUPADO;

					nuevoId++;

					*id = nuevoId;

					printf("\nSe dio de alta una Hoja de servicio!\n");

					rtn = 1;

				} else {

					printf("\nSe canceló el alta de la Hoja de servicio...\n");

				}

			} else {

				printf("\nNo pueden cargarse mas Hojas de servicio...\n");

			}
		} else {

			printf("\nNo hay vehiculos bajo esa ID\n");

		}
	}

	return rtn;
}

int hojaServicio_mostrarLasDeUnaFecha(eHojaServicio *servicios, int tamServicios) {

	int rtn = -1;
	eFecha auxFecha;
	int i;

	if (servicios != NULL && tamServicios > 0) {

		auxFecha = pedirFecha("INGRESE FECHA\n");

		printf("\nMostrando Hoja de servicio...\n\n"
				"\n%-10s %-20s %-20s %-20s %-20s\n", "ID", "ID DEL VEHICULO",
				"DESCRIPCION", "PRECIO DEL SERVICIO", "FECHA");

		for (i = 0; i < tamServicios; i++) {

			if ((*(servicios + i)).estado == OCUPADO
					&& auxFecha.dia == (*(servicios + i)).fecha.dia
					&& auxFecha.mes == (*(servicios + i)).fecha.mes
					&& auxFecha.anio == (*(servicios + i)).fecha.anio) {

				hojaServicio_mostrarUno(*(servicios + i));

			}

		}
		rtn = 1;
	}

	return rtn;
}

int hojaServicio_importeTotalDeUnVehiculo(eHojaServicio *servicios, int tamServicios, eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos) {

	int rtn = -1;
	int index = -1;
	int idIngresado;
	int i;
	float acumPrecio = 0;

	if (servicios != NULL && vehiculos != NULL && tipos != NULL && tamServicios > 0 && tamVehiculos > 0 && tamTipos > 0) {

		vehiculo_mostrarTodos(vehiculos, tamVehiculos, tipos, tamTipos);

		pedirEntero(&idIngresado, "Ingrese ID del vehiculo (10000-20000): ",
				"Error. Reingrese ID valido (10000-20000): ", 10000, 20000);

		index = vehiculo_buscarPorId(vehiculos, tamVehiculos, idIngresado);

		if (index != -1) {

			printf("IMPORTE TOTAL\n");

			for (i = 0; i < tamServicios; i++) {

				if ((*(servicios + i)).estado == OCUPADO
						&& (*(servicios + i)).vehiculoId == idIngresado) {

					acumPrecio += (*(servicios + i)).precioServicio;

				}
			}

			printf("$%.2f\n", acumPrecio);

		} else {

			printf("\nError. Vehiculo no encontrada bajo ese id...\n\n");
		}

		rtn = 1;
	}
	return rtn;
}

int hojaServicio_importeTotalDeUnTipoEnUnaFecha(eHojaServicio *servicios, int tamServicios, eVehiculo *vehiculos, int tamVehiculos, eTipo *tipos, int tamTipos) {

	int rtn = -1;
	eFecha auxFecha;
	int i;
	float acumPrecio = 0;
	int idIngresado;
	int index;

	if (servicios != NULL && vehiculos != NULL && tipos != NULL && tamServicios && tamVehiculos && tamTipos > 0) {

		tipo_mostrarTodos(tipos, tamTipos);

		pedirEntero(&idIngresado, "Ingrese ID del tipo a mostrar (1000-1002): ",
				"Error. Reingrese ID del tipo a mostrar (1000-1002): ", 1000,
				1002);

		index = tipo_buscarPorId(tipos, tamTipos, idIngresado);

		if (index != -1) {

			auxFecha = pedirFecha("INGRESE FECHA\n");

			for (i = 0; i < tamServicios; i++) {



				if ((*(servicios + i)).estado == OCUPADO
						&&(*(vehiculos + i)).estado == OCUPADO
					    && idIngresado == (*(vehiculos + i)).tipoId
						&& auxFecha.dia == (*(servicios + i)).fecha.dia
						&& auxFecha.mes == (*(servicios + i)).fecha.mes
						&& auxFecha.anio == (*(servicios + i)).fecha.anio) {

					acumPrecio += (*(servicios + i)).precioServicio;

				}

			}

			printf("$%.2f\n", acumPrecio);

		}

		rtn = 1;
	}

	return rtn;

}

eFecha pedirFecha(char *mensaje) {

	eFecha fecha;

	if (mensaje != NULL) {

		printf(mensaje);

		pedirEntero(&fecha.dia, "Ingrese dia (1-31): ",
				"Error. Reingrese dia (1-31): ", 1, 31);

		pedirEntero(&fecha.mes, "Ingrese mes (1-12): ",
				"Error. Reingrese mes (1-12): ", 1, 12);

		pedirEntero(&fecha.anio, "Ingrese año (2000-2022): ",
				"Error. Reingrese año (2000-2022): ", 2000, 2022);

	}

	return fecha;
}

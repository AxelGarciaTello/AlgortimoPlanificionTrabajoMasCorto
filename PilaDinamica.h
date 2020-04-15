#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Definimos el tipo de dato de nuestra lista
typedef int TipoDato;

//Estructura de nuestra lista
typedef struct nodo{
	TipoDato dato;
	pthread_t hilo; //Identificador del hilo de este nodo
	struct nodo *siguiente;
} NODO;

//Cabeceras de las funciones
NODO *CrearNodo(NODO *, TipoDato);
void insertarCabLSE(NODO **, TipoDato);

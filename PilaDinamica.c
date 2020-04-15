#include "PilaDinamica.h"

//Creación de un nodo
NODO *CrearNodo(NODO *enlace, TipoDato x){
	//Pedimos el espacio de memoria necesario para nuestra estructura nodo
	NODO *nuevo=(NODO *) malloc(sizeof(NODO));
	//Asignamos valores a la estructura
	nuevo->dato=x;
	nuevo->siguiente=enlace;
	return nuevo;
}

//Función para la insertar un valor en un nodo
void insertarCabLSE(NODO **cab, TipoDato x){
	//Creamos el nodo
	NODO *nuevo=CrearNodo(nuevo, x);
	//Asignamos valores y agregamos a la lista
	nuevo->siguiente=*cab;
	*cab=nuevo;
}

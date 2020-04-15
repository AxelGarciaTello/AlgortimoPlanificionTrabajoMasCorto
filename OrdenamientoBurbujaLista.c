#include "OrdenamientoBurbujaLista.h"

//Código para ordenar por el método burbuja
void ordenar(NODO **cab){
  NODO *ordenado=NULL, //Almacenará la lista ordenada
       /*
        Esta y la siguiente variable nos permitirán usar la lista sin
        modificar la original.
       */
       *copia=NULL,
       *cabeceraCopia=*cab,
       /*
        Las siguientes dos variables nos permitirán ir eliminando nodos
        ya identificados.
       */
       *anterior=NULL,
       *actual=NULL;
  int numero=0,
      bandera=0; //Identificador de un nodo para su eliminación
  while(cabeceraCopia != NULL){
    //Buscamos el nodo con el valor más alto de la lista
    copia=cabeceraCopia;
    numero=cabeceraCopia->dato;
    copia=copia->siguiente;
    while(copia != NULL){
      if(numero < (copia->dato)){
        numero=copia->dato;
      }
      copia=copia->siguiente;
    }
    //Lo agregamos a la lista ordenada
    insertarCabLSE(&ordenado, numero);
    //Eliminados el nodo seleccionado
    actual=cabeceraCopia;
    bandera=0;
    while(bandera==0){
      if(actual->dato!=numero){
        anterior=actual;
        actual=actual->siguiente;
      }
      else{
        if(actual==cabeceraCopia){
          cabeceraCopia=actual->siguiente;
        }
        else{
          anterior->siguiente=actual->siguiente;
        }
        bandera=1;
      }
    }
  }
  //Igualamos los valores de la lista ordenada con la lista dada
  (*cab)=ordenado;
}

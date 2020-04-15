#include "OrdenamientoBurbujaLista.h"
#include <unistd.h>
#include <time.h>

//Número de hilos a crear
#define NoHilos 5

/*
  Función a seguir los hilos. Como todos los hilos hacen lo mismo,
  implementamos la misma función con la modificación de mostrar de qué
  hilo se trata por medio de los argumentos.
*/
void *CodigoHilo(void *arg){
  int *numeros=(int *)arg,
      x;
  printf("Ejecutando el proceso %d ",*numeros);
  printf("Con duración de %d segundos\n",*(numeros+1));
  for(x=1; x<=(*(numeros+1)); x++){
    printf("%d\n",x);
    sleep(1);
  }
  pthread_exit(NULL);
}

//Función principal
int main(void){
  int x=0,
      numero=0,
      argumentos[2];
  NODO *lista=NULL;
  srand(time(NULL)); //Nos permite crear números al azar
  for(x=0; x<NoHilos; x++){
    numero=(rand()%10)+1; //Número ubicado entre 1 a 10
    insertarCabLSE(&lista, numero); //Lo agregamos a la lista
  }
  ordenar(&lista); //Ordenamos la lista
  x=0;
  while(lista!=NULL){
    //Argumentos a enviar en la función
    argumentos[0]=x+1;
    argumentos[1]=lista->dato;
    /*
      Creamos los hilos con el identificador existente en cada nodo, la
      función programada anteriormente y los argumentos contenidos en el
      nodo.
    */
    pthread_create(&(lista->hilo), NULL, CodigoHilo, (void *)argumentos);
    pthread_join(lista->hilo, NULL); //Esperamos a finalizar el hilo
    printf("Hilo numero %d finalizado\n",x+1);
    //Actualizamos la lista
    lista=lista->siguiente;
    x++;
  }
}

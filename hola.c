#include <stdio.h>
#include <pthread.h>

#define MAXTHREAD 50

long countarray[MAXTHREAD];

// Funcion con el prototipo REQUERIDO por 'pthread' para asignar esta funcion
// a un hilo de ejecucion
void* worktodo(void* arg) {
	printf("hola %u\n",(unsigned int)pthread_self());
	return NULL;
	
}

int main(int argc, char** argv) {
	int i, 
	numworkers=10; // numero de hilos para esta ejecucion
	pthread_t ptarray[MAXTHREAD]; // almacena 'id' de hilos


	// Se crea y se le asigna a cada hilo un identificador e.g. 0, 1,...
	for (i = 0; i < numworkers; i++) {
		pthread_create(&ptarray[i],NULL, worktodo, NULL);
	}

	// Se espera por la terminacion de ejecucion de cada hilo
	for (i = 0; i < numworkers; i++) {
		pthread_join(ptarray[i],NULL);
	}

}

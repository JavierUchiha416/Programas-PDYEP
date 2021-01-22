#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* Variable Global */
static int cont = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/* Prototipos */
void errorExit(char *);
void* hilo1_correr(void *);
void* hilo2_correr(void *);

int main () {

    pthread_t hilo1, hilo2;

    if ( 0 != pthread_create ( &hilo1, NULL, hilo1_correr, NULL)) 
        errorExit("hilo 1 no se puede crear");

    if ( 0 != pthread_create ( &hilo2, NULL, hilo2_correr, NULL))
        errorExit("hilo 2 no se puede crear");

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    printf("Valor del contador: %d \n", cont);

    return 0;
}

void errorExit(char *mensaje) {
    
    perror(mensaje);
    exit(1);
    
}

void* hilo1_correr(void* unused) {
    /* Seccion Critica */
    for (int i = 0; i < 1000; i++) {
        /* Exclusion Mutua */
        pthread_mutex_lock(&mutex);
        cont++;
        pthread_mutex_unlock(&mutex);
    }
}

void* hilo2_correr(void* unused) {
    /* Seccion Critica */
    for (int i = 0; i < 1000; i++) {
        /* Exclusion Mutua */
        pthread_mutex_lock(&mutex);
        cont++;
        pthread_mutex_unlock(&mutex);
    }
}

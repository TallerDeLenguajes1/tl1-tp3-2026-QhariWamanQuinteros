#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

void MostrarPersonas(char *V[]);

int main(){
    printf("Hola.");
    char *lista[N];
    char buff[50];

    int cantLetrasNombre;

    for (int i = 0; i < N; i++)
    {
        printf("\nIngrese el nombre de la persona %d: ", i+1);
        gets(buff);
        cantLetrasNombre = strlen(buff);
        lista[i] = (char *)malloc(cantLetrasNombre * sizeof(char));
        strcpy(lista[i],buff);
    }
    MostrarPersonas(lista);
    for (int i = 0; i < N; i++)
    {
        free(lista[i]);
    }
    
    return 0;
}
void MostrarPersonas(char *V[]){
    for (int i = 0; i < N; i++)
    {
        printf("\nPersona %d: %s", i+1, V[i]);
    }
    
}
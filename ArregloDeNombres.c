#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

void MostrarPersonas(char *V[]);
void BuscarNombre(int id, char *V[]);

int main()
{
    printf("Hola.");
    char *lista[N];
    char buff[50];
    int cantLetrasNombre;

    int numero;

    for (int i = 0; i < N; i++)
    {
        printf("\nIngrese el nombre de la persona %d: ", i + 1);
        gets(buff);
        cantLetrasNombre = strlen(buff);
        lista[i] = (char *)malloc(cantLetrasNombre * sizeof(char));
        strcpy(lista[i], buff);
    }
    MostrarPersonas(lista);

    printf("\nIngrese el numero de la persona a buscar: ");
    scanf("%d", &numero);
    BuscarNombre(numero, lista);

    for (int i = 0; i < N; i++)
    {
        free(lista[i]);
    }

    return 0;
}
void MostrarPersonas(char *V[])
{
    for (int i = 0; i < N; i++)
    {
        printf("\nPersona %d: %s", i + 1, V[i]);
    }
}
void BuscarNombre(int id, char *V[])
{
    if (id > 0 && id <= N)
    {
        printf("\nPersona %d: %s", id, V[id - 1]);
    }
    else
    {
        printf("\nNo se encontro el valor buscado.");
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

void MostrarPersonas(char *V[]);
void BuscarNombrePorID(int id, char *V[]);
void BuscarNombrePorPalabra(char *buscado, char *V[]);

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
    BuscarNombrePorID(numero, lista);

    printf("\nIngrese un nombre o parte de un nombre a buscar: ");
    gets(buff);
    BuscarNombrePorPalabra(buff, lista);
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
void BuscarNombrePorID(int id, char *V[])
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

void BuscarNombrePorPalabra(char *buscado, char *V[])
{
    int bandera = 0;
    char *resultado;
    for (int i = 0; i < N; i++)
    {
        resultado = strstr(V[i], buscado);
        if (resultado != NULL)
        {
            printf("\nNombre encontrado: %s", V[i]);
            bandera = 1;
        }
    }
    if (resultado == NULL && bandera == 0)
    {
        printf("\nNo se encontro el valor buscado");
    }
}
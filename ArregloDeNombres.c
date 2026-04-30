#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #define N 5

void MostrarPersonas(char *V[], int *cantPersonas);
void BuscarNombrePorID(int id, char *V[], int *cantPersonas);
void BuscarNombrePorPalabra(char *buscado, char *V[], int *cantPersonas);

int main()
{
    char buff[50];
    int cantLetrasNombre;

    int seleccion;
    int numero;

    int cantPersonas;

    printf("Ingrese la cantidad de personas a cargar: ");
    scanf("%d", &cantPersonas);
    char **lista = (char **)malloc(cantPersonas * sizeof(char *)); //defino puntero a puntero a char...

    for (int i = 0; i < cantPersonas; i++)
    {
        printf("\nIngrese el nombre de la persona %d: ", i + 1);
        fflush(stdin);
        gets(buff);
        cantLetrasNombre = strlen(buff);
        lista[i] = (char *)malloc(cantLetrasNombre * sizeof(char) + 1);
        strcpy(lista[i], buff);
    }
    MostrarPersonas(lista, &cantPersonas); // MostrarPersonas(&lista[0]);

    printf("\nIngrese una opcion de busqueda\n1. Buscar por numero de persona\n2. Buscar por nombre o parte de un nombre\nOpcion: ");
    scanf("%d", &seleccion);
    if (seleccion == 1)
    {
        printf("\nIngrese el numero de la persona a buscar: ");
        scanf("%d", &numero);
        BuscarNombrePorID(numero, lista, &cantPersonas);
    }
    else
    {
        if (seleccion == 2)
        {
            printf("\nIngrese un nombre o parte de un nombre a buscar: ");
            fflush(stdin);
            gets(buff);
            BuscarNombrePorPalabra(buff, lista, &cantPersonas);
        }
    }
    for (int i = 0; i < cantPersonas; i++)
    {
        free(lista[i]);
    }
    free(lista);

    return 0;
}
void MostrarPersonas(char *V[], int *cantPersonas)
{
    for (int i = 0; i < *cantPersonas; i++)
    {
        printf("\nPersona %d: %s", i + 1, V[i]);
    }
}
void BuscarNombrePorID(int id, char *V[], int *cantPersonas)
{
    if (id > 0 && id <= *cantPersonas)
    {
        printf("\nPersona %d: %s", id, V[id - 1]);
    }
    else
    {
        printf("\nNo se encontro el valor buscado.");
    }
}

void BuscarNombrePorPalabra(char *buscado, char *V[], int *cantPersonas)
{
    int bandera = 0;
    char *resultado;
    for (int i = 0; i < *cantPersonas; i++)
    {
        resultado = strstr(V[i], buscado);
        if (resultado != NULL)
        {
            printf("\nNombre encontrado: %s", V[i]);
            bandera = 1;
        }
    }
    if (bandera == 0)
    {
        printf("\nNo se encontro el valor buscado");
    }
}
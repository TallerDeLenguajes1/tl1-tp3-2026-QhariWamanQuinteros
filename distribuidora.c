#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CANT_PRODUCTOS 10
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algun valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;
struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // Aleatorio entre 1 y 5
    Producto *Productos;         // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} typedef Cliente;

float costoProducto(Producto producto);
void cargarClientes(Cliente *Clientes, int cantClientes, float *costoTotalCliente);
void mostrarClientes(Cliente *Clientes, int cantClientes, float *costoTotalCliente);
void liberarMemoria(Cliente *Clientes, int cantClientes, float *costoTotalCliente);

int main()
{
    srand(time(NULL));
    int cantClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    float *costoTotalCliente = (float *)malloc(cantClientes * sizeof(float));
    Cliente *Clientes = (Cliente *)malloc(cantClientes * (sizeof(Cliente)));

    cargarClientes(Clientes, cantClientes, costoTotalCliente);
    mostrarClientes(Clientes, cantClientes, costoTotalCliente);
    liberarMemoria(Clientes, cantClientes, costoTotalCliente);

    return 0;
}

void cargarClientes(Cliente *Clientes, int cantClientes, float *costoTotalCliente)
{
    char nombre_cliente[30];
    float costoUnitario;

    for (int i = 0; i < cantClientes; i++)
    {
        costoTotalCliente[i] = 0;
        Clientes[i].ClienteID = i + 1;
        printf("\nIngrese el nombre del cliente: ");
        fflush(stdin);
        gets(nombre_cliente);
        Clientes[i].NombreCliente = (char *)malloc(strlen(nombre_cliente) * sizeof(char) + 1);
        strcpy(Clientes[i].NombreCliente, nombre_cliente);
        Clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        Clientes[i].Productos = (Producto *)malloc(Clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            Clientes[i].Productos[j].ProductoID = j + 1;
            Clientes[i].Productos[j].Cantidad = 1 + rand() % 10;
            Clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            Clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 91;
            costoUnitario = costoProducto(Clientes[i].Productos[j]);
            costoTotalCliente[i] += costoUnitario;
        }
    }
}

void mostrarClientes(Cliente *Clientes, int cantClientes, float *costoTotalCliente)
{
    for (int i = 0; i < cantClientes; i++)
    {
        printf("Cliente ID: %d\n", Clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n", Clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n", Clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < Clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\tProducto ID: %d\n", Clientes[i].Productos[j].ProductoID);
            printf("\tCantidad: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("\tTipo de producto: %s\n", Clientes[i].Productos[j].TipoProducto);
            printf("\tPrecio unitario: %.2f\n", Clientes[i].Productos[j].PrecioUnitario);
            printf("Costo total del producto por su cantidad: %.2f\n", Clientes[i].Productos[j].Cantidad * Clientes[i].Productos[j].PrecioUnitario);
        }
        printf("Costo total del cliente: %.2f\n", costoTotalCliente[i]);
    }
}

void liberarMemoria(Cliente *Clientes, int cantClientes, float *costoTotalCliente)
{
    for (int i = 0; i < cantClientes; i++)
    {
        free(Clientes[i].Productos);
        free(Clientes[i].NombreCliente);
    }
    free(Clientes);
    free(costoTotalCliente);
}

float costoProducto(Producto producto)
{
    float costo = producto.Cantidad * producto.PrecioUnitario;
    return costo;
}
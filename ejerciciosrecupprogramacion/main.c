#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1. Crear una función llamada calcularIVA que reciba como parámetro
el precio bruto de un producto y devuelva el valor del impuesto (el IVA es 21%).
 Realizar la llamada desde main. *

2. Crear una función que se llame reemplazarCaracter que reciba una cadena
 de caracteres como primer parámetro, como segundo parámetro el carácter a
 reemplazar y como tercero el nuevo carácter y devuelva la cantidad de veces
 se reemplazo el carácter. int reemplazarCaracter(char [], char, char); *

3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función
 que permita ordenar un array de dicha estructura por marca. Ante igualdad de marca
  deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main. *
*/

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

float aplicarIVA(float precio);
int ordenarXMarcaYPrecio(Notebook lista[], int tam);
int reemplazarcaracter(char caracter[], char caractererremplazo, char caracterreemplazado);


int main()
{
    float precio=100;
    float valorimpuesto= aplicarIVA(precio);
    printf("Precio: %.2f\nPrecio impuesto: %.2f\n", precio, valorimpuesto);
    char nombre[]= {"bel"};
    char caracterremplazo= 'b';
    char caracterreemplazado='s';
    reemplazarcaracter(nombre, caracterremplazo, caracterreemplazado);
    printf ("%s\n", nombre);

    eNotebook listado[5]= {{10, "Intel", "Lenovo", 100000}, {11, "AMD", "HP", 150000}, {12, "Intel", "Lenovo", 100850.5}, {13, "AMD", "HP", 100000.8}, {14, "Intel", "Asus", 180000}};
    printf("ID\tPROCESADOR\tMARCA\tPRECIO\n\n");
    printf("LISTA DESORDENADA \n\n");
    for(int i=0; i<5; i++)
    {
        printf("%d\t%s\t       %s\t%.2f\n", listado[i].id, listado[i].procesador, listado[i].marca, listado[i].precio);
    }
    printf("\n\nLISTA ORDENADA POR MARCA (DE LA A A LA Z) Y PRECIO (MENOR A MAYOR)\n\n");
    if(!ordenarXMarcaYPrecio(listado, 5))
    {
        printf("ID\tPROCESADOR\tMARCA\tPRECIO\n\n");
        for(int i=0; i<5; i++)
        {
            printf("%d\t%s\t       %s\t%.2f\n", listado[i].id, listado[i].procesador, listado[i].marca, listado[i].precio);
        }
    }
    return 0;
}

float aplicarIVA(float precio)
{
    float valorimpuesto;
    valorimpuesto= precio*1.21;
    return valorimpuesto;
}

int ordenarXMarcaYPrecio(Notebook lista[], int tam)
{
    int error=1;
    Notebook auxNotebook;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].marca, lista[j].marca)>0 || (strcmp(lista[i].marca, lista[j].marca)==0 && lista[i].precio>lista[j].precio))
                {
                    auxNotebook=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxNotebook;
                }
            }
        }
        error=0;
    }
    return error;
}
int reemplazarcaracter(char caracter[], char caractererremplazo, char caracterreemplazado)

{
    int contador = 0;
    for(int i=0; i<strlen(caracter); i++)
    {
        if(caracter[i] == caracterremplazo)
        {
            contador++;
            caracter[i] = caracterreemplazado;
        }
    }
    return contador;
}

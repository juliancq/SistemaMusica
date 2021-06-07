#ifndef ARBOLCANCIONES_H_INCLUDED
#define ARBOLCANCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
 int idCancion;
 char titulo[30];
 char artista[20];
 char duracion[30];
 char album[20];
 char anio[30];
 char genero[20];
 int eliminado;
} stCancion;

typedef struct
{
    stCancion dato;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
} nodoArbolCancion;

nodoArbolCancion *inicArbolCancion();
nodoArbolCancion *CrearNodoArbol(stCancion info);
nodoArbolCancion *Insertar(nodoArbolCancion *arbol, nodoArbolCancion *nuevo);
void preorder(nodoArbolCancion *arbol);
void inorder(nodoArbolCancion *arbol);
void postorder(nodoArbolCancion *arbol);
stCancion BusquedaCancionPorID(nodoArbolCancion *arbol, int id);
nodoArbolCancion *BusquedaNodoPorID(nodoArbolCancion *arbol, int id);
nodoArbolCancion *BusquedaPorNombre(nodoArbolCancion *arbol, char nombre[]);
nodoArbolCancion* AltaArbolCancion(nodoArbolCancion *arbol);
void mostrarCancion(stCancion c);
stCancion CargarCancion();
nodoArbolCancion *ArchivoToArbol(nodoArbolCancion * arbol);
void ArbolToArchivo(nodoArbolCancion *arbol);
void ArbolToArchivo2(nodoArbolCancion *arbol,FILE *bin);
int ContarCantidadCanciones();
int CargarArregloCanciones(stCancion *A);
nodoArbolCancion *ArregloCancionesToArbol(stCancion *A, int validos);

#endif // ARBOLCANCIONES_H_INCLUDED

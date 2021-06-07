#ifndef LISTASSIMPLES_H_INCLUDED
#define LISTASSIMPLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArbolCanciones.h"

typedef struct
{
    stCancion dato;
    struct nodoListaCancion *siguiente;
}nodoListaCancion;

nodoListaCancion *iniclista();
nodoListaCancion *CrearNodoLista(stCancion dato);
nodoListaCancion *AgregarAlPrincipio(nodoListaCancion *listita, nodoListaCancion *nuevo);
void MostrarLista(nodoListaCancion *listita);

#endif // LISTASSIMPLES_H_INCLUDED

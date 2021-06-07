#ifndef FUNCUSUARIO_H_INCLUDED
#define FUNCUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "FuncUsuario.h"
#include "CeldasUsuario.h"
#include "ArbolCanciones.h"

void verPerfil(int idUsuario, stCelda * A, int valCelda);
void mostrarPlaylist(int idUsuario, stCelda * A);
void borrarCancion(int idUsuario, stCelda * A);
nodoListaCancion * borrarCancionBuscada(char nombre[], nodoListaCancion * lista);
nodoListaCancion * buscarCancionEnLista(char nombre[], nodoListaCancion * lista);
void EscucharCancion(stCelda *A, int idUsuario, nodoArbolCancion *arbol);
void actualizarCancionesEscuchadas(stCelda *A, int valCelda);
void CancionesRecomendadas(nodoArbolCancion *arbol, stCelda *A, int idUsuario);
void MostrarPorGenero(nodoArbolCancion *arbol, char genero[], int *contador);

#endif // FUNCUSUARIO_H_INCLUDED

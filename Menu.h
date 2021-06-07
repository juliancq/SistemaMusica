#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "CeldasUsuario.h"

void menuPrincipal(stCelda *A, int validos,nodoArbolCancion *arbol);
int Registro(stCelda **A, int validos);
nodoArbolCancion *menuAdmin(stCelda *A, int validos, nodoArbolCancion *arbol);
void subMenuAdmin1(stCelda *A, int validos);
nodoArbolCancion *subMenuAdmin2(nodoArbolCancion *arbol);
void menuUser(int idUsuario, stCelda *A, int validos, nodoArbolCancion *arbol);
void inicioSesionUser(stCelda *A, int validos, nodoArbolCancion *arbol);
nodoArbolCancion *inicioSesionAdmin(stCelda *A, int validos,nodoArbolCancion *arbol);
void imprimirCabecera(char cabecera[]);
void codificarPassword(char password[]);


#endif // MENU_H_INCLUDED

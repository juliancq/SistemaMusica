#ifndef FUNCADMIN_H_INCLUDED
#define FUNCADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "CeldasUsuario.h"

void DarAltaUsuarios(stCelda *A, int validos);
void DarDeBajaUsuarios(stCelda *A, int validos);
void ModificarUsuario(stCelda *A, int validos);
void ConsultaUsuarios(stCelda *A, int validos);
void ListarUsuarios(stCelda *A, int validos);
nodoArbolCancion* DarDeBajaCancion(nodoArbolCancion *arbol);
void ConsultaDeCanciones(nodoArbolCancion *arbol);
nodoArbolCancion * modificarCanciones(nodoArbolCancion * arbol);

#endif // FUNCADMIN_H_INCLUDED

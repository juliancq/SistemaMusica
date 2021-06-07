#include <stdio.h>
#include <stdlib.h>
#include "FuncAdmin.h"
#include "Menu.h"
#include "ComprobacionDatos.h"

int main()
{
    stCelda *A = (stCelda*)malloc(sizeof(stCelda)* ContarCantidadUsuarios());
    nodoArbolCancion * arbol = inicArbolCancion();
    stCancion *can = (stCancion*)malloc(sizeof(stCancion)*ContarCantidadCanciones());

    int validos2 = CargarArregloCanciones(can);
    arbol = ArregloCancionesToArbol(can,validos2);

    int validos = CargarUsuariosADL(A,arbol);

    menuPrincipal(A,validos,arbol);
}




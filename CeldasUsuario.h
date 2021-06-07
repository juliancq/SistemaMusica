#ifndef CELDASUSUARIO_H_INCLUDED
#define CELDASUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListasCancion.h"

typedef struct
{
 int idPlaylist;
 int idUsuario;
 int idCancion;
}stPlaylist;

typedef struct
{
 int idUsuario;
 char nombreUsuario[30];
 char pass[20];
 char anioNacimiento[20];
 char genero;
 char pais[20];
 char correoElectronico[50];
 int eliminado;
 int aprobado;
 int tipoUsuario;
}stUsuario;

typedef struct
{
    stUsuario dato;
    nodoListaCancion *listaCanciones;
}stCelda;

int ContarCantidadUsuarios();
int CargarUsuariosADL(stCelda *A, nodoArbolCancion *arbol);
stUsuario BuscarUsuarioPorNombre(stCelda *A, int validos, char nombre[]);
stUsuario BuscarUsuarioPorID(stCelda *A, int validos, int id);
int ExisteUsuarioPorNombre(stCelda *A, int validos, char nombre[]);
int ExisteUsuarioPorID(stCelda *A, int validos, int id);
void MostrarUsuariosYCanciones(stCelda *A, int validos);
void agregarCancionToUsuario(stCelda *A, int validos, int idUs, nodoArbolCancion *arbol);
void MostrarUs(stUsuario aux);
stUsuario cargarUsuario(stCelda *A, int validos);
void CargarArchivoUsuarios();
void MostrarArchivoUsuarios();
void CargarPlaylistRustico();
void MostrarArchivoPlaylist();
void AgregarRegistroPlaylist(int idUs,int idCan);
int registroUsuario(stCelda **A, int validos);
int registroAdmin(stCelda **A, int validos);
int altaUsuarioADL(stUsuario nuevo, stCelda **A, int valCeldas);
int PreguntarContraseniaAdmin();
void ActualizarUsuarios(stCelda *A,int validos);


#endif // CELDASUSUARIO_H_INCLUDED

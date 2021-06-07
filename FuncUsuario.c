#include "FuncUsuario.h"

/**< Esta funcion muestra por pantalla el perfil del usuario en sesion */
void verPerfil(int idUsuario, stCelda * A, int valCelda)
{
    imprimirCabecera("PERFIL");
    stUsuario user = BuscarUsuarioPorID(A, valCelda, idUsuario);
    MostrarUs(user);
}

/**< Esta funcion muestra la lista de canciones del usuario en sesion */
void mostrarPlaylist(int idUsuario, stCelda * A)
{
    imprimirCabecera("PLAYLIST");
    if(A[idUsuario].listaCanciones==NULL)
    {
        printf("\nPlaylist vacia.");
    }
    else
    {
        MostrarLista(A[idUsuario].listaCanciones);
    }
}

/**< Esta funcion pide el ingreso por teclado de un nombre de cancion, lo busca y lo elimina de la playlist del usuario */
void borrarCancion(int idUsuario, stCelda * A)
{
    char nombre[30];
    printf("Ingrese el nombre de la cancion a borrar\n");
    fflush(stdin);
    gets(nombre);

    nodoListaCancion * aBorrar = buscarCancionEnLista(nombre, A[idUsuario].listaCanciones);

    if(aBorrar)
    {
        mostrarCancion(aBorrar->dato);

        char control;
        printf("\nDesea borrar esta cancion? S/N\n");
        fflush(stdin);
        control = getch();

        if(control == 's')
        {
            A[idUsuario].listaCanciones = borrarCancionBuscada(nombre, A[idUsuario].listaCanciones);
        }
    }
    else
    {
        printf("No se hallo la cancion en su playlist\n");
    }

}

/**< Esta funcion recibe un nombre y una lista de canciones, busca la cancion y la elimina */
nodoListaCancion * borrarCancionBuscada(char nombre[], nodoListaCancion * lista)
{
    nodoListaCancion * seg;
    nodoListaCancion * ante;

    if((lista != NULL) && (strcmp(nombre, lista->dato.titulo)== 0))
    {
        nodoListaCancion * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->dato.titulo)!= 0))
        {
            ante = seg;
            seg = seg->siguiente;
        }

        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;

            free(seg);
        }
    }
    return lista;
}


/**< Esta funcion recorre el arreglo de usuarios y actualiza el archivo "PLAYLIST.DAT" */
void actualizarCancionesEscuchadas(stCelda *A, int valCelda)
{
    FILE *pArchivo = fopen("playlist.dat", "wb");
    stPlaylist aux;
    int i = 0;
    if(pArchivo)
    {
        while(i < valCelda)
        {
            nodoListaCancion *seg = A[i].listaCanciones;
            aux.idUsuario = A[i].dato.idUsuario;
            aux.idPlaylist = aux.idUsuario;

            while(seg)
            {
                aux.idCancion = seg->dato.idCancion;
                fwrite(&aux, sizeof(stPlaylist), 1, pArchivo);
                seg = seg->siguiente;
            }
            i++;
        }
    }
    else
    {
        printf("error");
    }

}

/**< Esta funcion busca en una lista de tipo cancion si existe una cancion por nombre, si existe
retorna el nodo, si no existe retorna NULL */
nodoListaCancion * buscarCancionEnLista(char nombre[], nodoListaCancion *lista)
{
    nodoListaCancion * seg = lista;
    nodoListaCancion * can = NULL;


    while(seg != NULL && can == NULL)
    {
        if(strcmpi(nombre, seg->dato.titulo)== 0)
        {
            can = seg;
        }
        seg = seg->siguiente;
    }

    return can;
}



/**< Esta funcion pide al usuario que ingrese el nombre de una cancion, busca por nombre en el arbol y la
ingresa en la playlist del usuario */
void EscucharCancion(stCelda *A, int idUsuario, nodoArbolCancion *arbol)
{
    char nombre[30];
    printf("Ingrese la cancion que quiere escuchar: ");
    fflush(stdin);
    gets(nombre);
    nodoArbolCancion *nuevo = BusquedaPorNombre(arbol,nombre);
    if(nuevo==NULL)
    {
        printf("\nLa cancion no existe.");
    }
    else
    {
        printf("\nLa cancion se agrego correctamente\n");
        A[idUsuario].listaCanciones = AgregarAlPrincipio(A[idUsuario].listaCanciones,CrearNodoLista(nuevo->dato));
    }
}

/**< Busca el genero de la ultima cancion escuchada por el usuario e invoca a MostrarPorGenero, dando al usuario
canciones del mismo genero como recomendacion */
void CancionesRecomendadas(nodoArbolCancion *arbol, stCelda *A, int idUsuario)
{
    char genero[30];
    int a=0;
    strcpy(genero,A[idUsuario].listaCanciones->dato.genero);
    MostrarPorGenero(arbol,genero,&a);
}

/**< Busca en el arbol 3 canciones del genero indicado y las muestra por pantalla */
void MostrarPorGenero(nodoArbolCancion *arbol, char genero[], int *contador)
{
    if(arbol&&(*contador)<3)
    {
        if(strcmpi(genero,arbol->dato.genero)==0)
        {
            puts("\n-------------------");
            mostrarCancion(arbol->dato);
            (*contador)++;
        }
        MostrarPorGenero(arbol->izq,genero,contador);
        MostrarPorGenero(arbol->der,genero,contador);
    }
}

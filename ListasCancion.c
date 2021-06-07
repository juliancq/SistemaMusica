#include "ListasCancion.h"

/**< Inicializa una lista de tipo nodoListaCancion */
nodoListaCancion *iniclista()
{
    return NULL;
}

/**< Crea un nodo de tipo nodoListaCancion y le ingresa un dato */
nodoListaCancion *CrearNodoLista(stCancion dato)
{
    nodoListaCancion *aux = (nodoListaCancion*)malloc(sizeof(nodoListaCancion));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

/**< Recibe una lista y un nodoListaCancion nuevo, lo inserta al inicio de esta lista */
nodoListaCancion *AgregarAlPrincipio(nodoListaCancion *listita, nodoListaCancion *nuevo)
{
    if(!listita)
    {
        listita = nuevo;
    }
    else
    {
        nuevo->siguiente = listita;
        listita = nuevo;
    }
    return listita;
}

/**< Muestra una lista completamente */
void MostrarLista(nodoListaCancion *listita)
{
    nodoListaCancion *seg = listita;
    while(seg!=NULL)
    {
        puts("\n---------------------------");
        mostrarCancion(seg->dato);
        seg = seg->siguiente;
    }
    puts("\n---------------------------");
}

/**< Inserta por orden alfabetico de titulos un nodo nuevo en una lista dada */
nodoListaCancion *AgregarEnOrdenPorTitulo(nodoListaCancion *listita, nodoListaCancion *nuevo)
{
    if(listita==NULL)
    {
        listita = nuevo;
    }
    else
    {
        if(strcmpi(nuevo->dato.titulo,listita->dato.titulo)==-1)
        {
            listita = AgregarAlPrincipio(listita,nuevo);
        }
        else
        {
            nodoListaCancion *ante = listita;
            nodoListaCancion *seg = listita->siguiente;
            while(seg&&strcmpi(seg->dato.titulo,nuevo->dato.titulo)==-1)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return listita;
}

/**< Inserta por orden alfabetico de generos un nodo nuevo en una lista dada */
nodoListaCancion *AgregarEnOrdenPorGenero(nodoListaCancion *listita, nodoListaCancion *nuevo)
{
    if(listita==NULL)
    {
        listita = nuevo;
    }
    else
    {
        if(strcmpi(nuevo->dato.genero,listita->dato.genero)==-1)
        {
            listita = AgregarAlPrincipio(listita,nuevo);
        }
        else
        {
            nodoListaCancion *ante = listita;
            nodoListaCancion *seg = listita->siguiente;
            while(seg&&strcmpi(seg->dato.genero,nuevo->dato.genero)==-1)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }
    return listita;
}

/**< Pasa las canciones de un arbol a una lista, en orden alfabetico por titulo */
nodoListaCancion *ArbolToListaEnOrdenTitulo(nodoArbolCancion *arbol, nodoListaCancion *lista)
{
    if(arbol)
    {
        nodoListaCancion *nuevo = CrearNodoLista(arbol->dato);
        lista = AgregarEnOrdenPorTitulo(lista,nuevo);
        lista = ArbolToListaEnOrdenTitulo(arbol->izq,lista);
        lista = ArbolToListaEnOrdenTitulo(arbol->der,lista);
    }
    return lista;
}

/**< Pasa las canciones de un arbol a una lista, en orden alfabetico por genero */
nodoListaCancion *ArbolToListaEnOrdenGenero(nodoArbolCancion *arbol, nodoListaCancion *lista)
{
    if(arbol)
    {
        nodoListaCancion *nuevo = CrearNodoLista(arbol->dato);
        lista = AgregarEnOrdenPorGenero(lista,nuevo);
        lista = ArbolToListaEnOrdenGenero(arbol->izq,lista);
        lista = ArbolToListaEnOrdenGenero(arbol->der,lista);
    }
    return lista;
}



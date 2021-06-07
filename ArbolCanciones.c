#include "ArbolCanciones.h"

/**< Inicializa un arbol de tipo nodoArbolCancion */
nodoArbolCancion *inicArbolCancion()
{
    return NULL;
}

/**< Crea un nodo de tipo nodoArbolCancion y le asigna un dato */
nodoArbolCancion *CrearNodoArbol(stCancion info)
{
    nodoArbolCancion *aux = (nodoArbolCancion*)malloc(sizeof(nodoArbolCancion));
    aux->dato = info;
    aux->izq = NULL;
    aux->der = NULL;
    return aux;
}

/**< Inserta en un arbol un nuevo nodoArbolCancion */
nodoArbolCancion *Insertar(nodoArbolCancion *arbol, nodoArbolCancion *nuevo)
{
    if(arbol==NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if(nuevo->dato.idCancion>arbol->dato.idCancion)
        {
            arbol->der = Insertar(arbol->der,nuevo);
        }
        else
        {
            arbol->izq = Insertar(arbol->izq,nuevo);
        }
    }
    return arbol;
}


void preorder(nodoArbolCancion *arbol)
{
    if(arbol!=NULL)
    {
        puts("\n--------------------------");
        mostrarCancion(arbol->dato);
        puts("\n--------------------------");
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbolCancion *arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        puts("\n--------------------------");
        mostrarCancion(arbol->dato);
        puts("\n--------------------------");
        inorder(arbol->der);
    }
}

void postorder(nodoArbolCancion *arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        puts("\n--------------------------");
        mostrarCancion(arbol->dato);
        puts("\n--------------------------");

    }
}


/**<  Busca por ID y retorna los datos de la cancion.*////
stCancion BusquedaCancionPorID(nodoArbolCancion *arbol, int id)
{
    stCancion nuevo;
    if(arbol!=NULL)
    {
        if(arbol->dato.idCancion==id)
        {
            nuevo = arbol->dato;
        }
        else
        {
            if(id>arbol->dato.idCancion)
            {
                nuevo = BusquedaCancionPorID(arbol->der,id);
            }
            else
            {
                nuevo = BusquedaCancionPorID(arbol->izq,id);
            }
        }
    }
    return nuevo;
}

/**< Busca en un arbol una cancion por id, si la encuentra retorna dicha cancion, sino retorna NULL */
nodoArbolCancion *BusquedaNodoPorID(nodoArbolCancion *arbol, int id)
{
    nodoArbolCancion *aux = NULL;
    if(arbol!=NULL)
    {
        if(arbol->dato.idCancion==id)
        {
            aux = arbol;
        }
        else
        {
            aux = BusquedaNodoPorID(arbol->der,id);
            if(aux==NULL)
            {
                aux = BusquedaNodoPorID(arbol->izq,id);
            }
        }
    }
    return aux;
}


/**< Busca en un arbol una cancion por nombre, si la encuentra retorna dicha cancion, sino retorna NULL */
nodoArbolCancion *BusquedaPorNombre(nodoArbolCancion *arbol, char nombre[])
{
    nodoArbolCancion *nuevo = NULL;
    if(arbol)
    {
        if(strcmpi(nombre,arbol->dato.titulo)==0)
        {
            nuevo = arbol;
        }
        else
        {
            nuevo = BusquedaPorNombre(arbol->der,nombre);
            if(nuevo==NULL)
            {
                nuevo = BusquedaPorNombre(arbol->izq,nombre);
            }
        }
    }
    return nuevo;
}

/**< Alta de canciones en el arbol binario */
nodoArbolCancion* AltaArbolCancion(nodoArbolCancion *arbol)
{
    FILE *bin = fopen("canciones.dat","rb");
    char continuar = 's';
    stCancion aux;
    int cant = 0;
    if(bin)
    {
        fseek(bin,0,SEEK_END);
        cant = ftell(bin)/sizeof(stCancion);
    }
    while(continuar=='s')
    {
        aux = CargarCancion(cant);
        arbol = Insertar(arbol,CrearNodoArbol(aux));
        printf("\nDesea continuar ?(s/n)");
        fflush(stdin);
        continuar = getch();
        cant++;
    }
    return arbol;
}

/**< Muestra una cancion con todos sus elementos */
void mostrarCancion(stCancion c)
{
    printf("\nId de cancion: %d",c.idCancion);
    printf("\nTitulo: %s",c.titulo);
    printf("\nArtista: %s",c.artista);
    printf("\nDuracion: %s Minutos",c.duracion);
    printf("\nAlbum: %s",c.album);
    printf("\nAnio: %s",c.anio);
    printf("\nGenero: %s",c.genero);
    if(c.eliminado==1)
    {
        printf("\nEstado: ACEPTADA");
    }
    else
    {
        printf("\nEstado: ELIMINADA");
    }
}

/**< Carga una cancion comprobando tipos de datos */
stCancion CargarCancion(int cant)
{
    stCancion C;
    C.idCancion = cant;
    printf("\nIngrese titulo de la cancion: ");
    fflush(stdin);
    gets(C.titulo);
    while(comprobarTitulo(C.titulo)==0)
    {
        printf("\nPorfavor solo ingrese letras y numeros...");
        printf("\nIngrese titulo de la cancion: ");
        fflush(stdin);
        gets(C.titulo);
    }
    printf("\nIngrese Artista: ");
    fflush(stdin);
    gets(C.artista);
    while(comprobarArtista(C.artista)==0)
    {
        printf("\nPorfavor solo ingrese letras y numeros...");
        printf("\nIngrese Artista: ");
        fflush(stdin);
        gets(C.artista);
    }
    printf("\nIngrese duracion: ");
    fflush(stdin);
    gets(C.duracion);
    while(comprobarDuracion(C.duracion)==0)
    {
        printf("\nPorfavor solo ingrese numeros...");
        printf("\nIngrese duracion: ");
        fflush(stdin);
        gets(C.duracion);
    }
    printf("\nIngrese Album: ");
    fflush(stdin);
    gets(C.album);
    while(comprobarAlbum(C.album)==0)
    {
        printf("\nPorfavor solo ingrese letras y numeros...");
        printf("\nIngrese Album: ");
        fflush(stdin);
        gets(C.album);
    }
    printf("\nIngrese anio: ");
    fflush(stdin);
    gets(C.anio);
    while(comprobarAnio(C.anio)==0)
    {
        printf("\nPorfavor solo ingrese numeros...");
        printf("\nIngrese anio: ");
        fflush(stdin);
        gets(C.anio);
    }
    printf("\nIngrese genero: ");
    fflush(stdin);
    gets(C.genero);
    while(comprobarGenero(C.genero)==0)
    {
        printf("\nPorfavor solo ingrese letras...");
        printf("\nIngrese genero: ");
        fflush(stdin);
        gets(C.genero);
    }
    C.eliminado = 1;

    return C;
}

/**< Carga el arbol de canciones a partir del archivo "CANCIONES.DAT */
nodoArbolCancion *ArchivoToArbol(nodoArbolCancion * arbol)
{
    FILE * pArchivo = fopen("canciones.dat", "rb");
    stCancion  aux;

    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            fread(&aux, sizeof(stCancion), 1, pArchivo);
            if(!feof(pArchivo))
            {
                arbol = Insertar(arbol, CrearNodoArbol(aux));
            }
        }
        fclose(pArchivo);
    }
    else
    {
        puts("Error al abrir el archivo");
    }
    return arbol;
}

/**< Ingresa las canciones del arbol binario en el archivo "CANCIONES.DAT" */
void ArbolToArchivo(nodoArbolCancion *arbol)
{
    FILE *bin = fopen("canciones.dat","wb");
    if(bin)
    {
        ArbolToArchivo2(arbol,bin);
        fclose(bin);
    }
}

void ArbolToArchivo2(nodoArbolCancion *arbol,FILE *bin)
{
    if(arbol)
    {
        fwrite(&arbol->dato,sizeof(stCancion),1,bin);
        ArbolToArchivo2(arbol->izq,bin);
        ArbolToArchivo2(arbol->der,bin);
    }
}

/**< Cuenta la cantidad de canciones en el archivo "CANCIONES.DAT" y lo retorna */
int ContarCantidadCanciones()
{
    FILE *bin = fopen("canciones.dat","rb");
    fseek(bin,0,2);
    int cant = ftell(bin)/sizeof(stCancion);
    return cant;
}

/**< Carga un arreglo con las canciones del archivo "CANCIONES.DAT" */
int CargarArregloCanciones(stCancion *A)
{
    FILE *bin = fopen("canciones.dat","rb");
    stCancion aux;
    int i=0;
    if(bin)
    {
        while(fread(&aux,sizeof(stCancion),1,bin)>0)
        {
            A[i] = aux;
            i++;
        }
    }
    return i;
}

/**< Carga balanceadamente un arbol de canciones a partir de un arreglo de canciones */
nodoArbolCancion *ArregloCancionesToArbol(stCancion *A, int validos)
{
    nodoArbolCancion * arbol = NULL;

    int i;
    int mitad = (validos-1)/2;

    for(i=mitad; i>=0; i--)
    {
        if( (i%2)!=0 )
        {
            nodoArbolCancion *nuevo = CrearNodoArbol(A[i]);
            arbol = Insertar(arbol,nuevo);
        }
    }
    for(i=mitad; i>=0; i--)
    {
        if( (i%2)==0 )
        {
            nodoArbolCancion *nuevo = CrearNodoArbol(A[i]);
            arbol = Insertar(arbol,nuevo);
        }
    }

    for(i=mitad+1; i<validos; i++)
    {
        if( (i%2)!=0 )
        {
            nodoArbolCancion *nuevo = CrearNodoArbol(A[i]);
            arbol = Insertar(arbol,nuevo);
        }
    }

    for(i=mitad+1; i<validos; i++)
    {
        if( (i%2)==0 )
        {
            nodoArbolCancion *nuevo = CrearNodoArbol(A[i]);
            arbol = Insertar(arbol,nuevo);
        }
    }
    return arbol;
}

#include "FuncAdmin.h"

///FUNCIONES SOBRE USUARIOS

/**<  Muestra los usuarios que todavía no han sido aprobados y se le da la posibilidad al admin de aceptarlos.*/
void DarAltaUsuarios(stCelda *A, int validos)
{
    int i=0;
    char aux;
    while(i<validos)
    {
        if(A[i].dato.aprobado==0)
        {
            MostrarUs(A[i].dato);
            printf("\nDesea aprobar la solicitud de ingreso ?(s/n) ");
            fflush(stdin);
            aux = getch();
            if(aux=='s'||aux=='S')
            {
                A[i].dato.aprobado = 1;
                printf("\nUsuario aprobado con exito.");
            }
            else
            {
                printf("\nUsuario denegado.");
            }
        }
        i++;
    }
}

///El admin ingresa un numero de ID para buscar al usuario que quiera dar de baja y si existe, lo da de baja.
void DarDeBajaUsuarios(stCelda *A, int validos)
{
    int id;
    printf("\nIngrese el ID del usuario: ");
    fflush(stdin);
    scanf("%i",&id);
    int i = ExisteUsuarioPorID(A,validos,id);
    if(i==-1)
    {
        printf("\nUsuario no encontrado.");
    }
    else
    {
        A[i].dato.eliminado = 0;
        printf("\nOperacion exitosa.");
    }
}

/**< Esta funcion pide el ingreso de un idUsuario, lo muestra y genera un menu que permite al admin
modificar cualquier campo del perfil de dicho usuario */

void ModificarUsuario(stCelda *A, int validos)
{
    int id;
    int option;
    printf("\nIngrese el ID del usuario: ");
    fflush(stdin);
    scanf("%i",&id);
    int i = ExisteUsuarioPorID(A,validos,id);
    if(i==-1)
    {
        printf("\nUsuario no encontrado.");
    }
    else
    {
        MostrarUs(A[i].dato);
        while(option!=0)
        {

            printf("\nIngrese el campo que quiere modificar.");
            printf("\n\n1)NOMBRE DE USUARIO");
            printf("\n2)CONTRASENA");
            printf("\n3)ANO DE NACIMIENTO");
            printf("\n4)GENERO");
            printf("\n5)PAIS");
            printf("\n6)CORREO ELECTRONICO");
            printf("\n0)SALIR\n");
            fflush(stdin);
            scanf("%i",&option);
            switch(option)
            {

            case 1:
            {
                char aux[30];
                printf("Ingrese nombre de usuario\n");
                fflush(stdin);
                gets(aux);
                while(comprobarUser(aux) == 0&&ExisteUsuarioPorNombre(A,validos,aux)!=-1)
                {
                    if(comprobarUser(aux)==0)
                    {
                        printf("Porfavor ingrese solo letras y numeros\n");
                        printf("Ingrese su nombre de usuario\n");
                        fflush(stdin);
                        gets(aux);
                    }
                    else
                    {
                        printf("\nEl usuario ya existe, por favor ingrese otro.");
                        printf("\nIngrese su nombre de usuario: ");
                        fflush(stdin);
                        gets(aux);
                    }
                }
                strcpy(A[i].dato.nombreUsuario,aux);
                break;
            }
            case 2:
            {
                char aux[30];
                printf("Ingrese su contrasenia\n");
                fflush(stdin);
                gets(aux);
                strcpy(A[i].dato.pass,aux);
                break;
            }
            case 3:
            {
                char aux[30];
                printf("Ingrese anio de nacimiento\n");
                fflush(stdin);
                gets(aux);
                while(comprobarAnio(aux) == 0)
                {
                    printf("Porfavor ingrese solo numero\n");
                    printf("Ingrese su anio de nacimiento\n");
                    gets(aux);
                }
                strcpy(A[i].dato.anioNacimiento,aux);
                break;
            }
            case 4:
            {
                char aux;
                printf("Ingrese genero (M-F-O)\n");
                fflush(stdin);
                scanf("%c",&aux);
                while(aux != 'm' && aux != 'f' && aux != 'o')
                {
                    printf("Porfavor ingrese un genero valido\n");
                    printf("Ingrese su genero (M-F-O)\n");
                    fflush(stdin);
                    scanf("%c", &aux);
                }
                A[i].dato.genero = aux;
                break;
            }
            case 5:
            {
                char aux[30];
                printf("Ingrese pais\n");
                fflush(stdin);
                gets(aux);
                while(comprobarPais(aux) == 0)
                {
                    printf("Porfavor ingrese solo letras y espacios\n");
                    printf("Ingrese su pais\n");
                    fflush(stdin);
                    gets(aux);
                }
                strcpy(A[i].dato.pais,aux);
                break;
            }
            case 6:
            {
                char aux[30];
                printf("Ingrese correo electronico\n");
                fflush(stdin);
                gets(aux);
                while(comprobarMail(aux) == 0)
                {
                    printf("Porfavor ingrese un mail valido\n");
                    printf("Ingrese su correo electronico\n");
                    fflush(stdin);
                    gets(aux);
                }
                strcpy(A[i].dato.correoElectronico,aux);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                puts("Opcion invalida");
                system("pause");
                break;
            }
            }
        }
        system("cls");
    }
}

void ConsultaUsuarios(stCelda *A, int validos)
{
    int id;
    printf("\nIngrese el ID del usuario: ");
    fflush(stdin);
    scanf("%i",&id);
    int i = ExisteUsuarioPorID(A,validos,id);
    if(i==-1)
    {
        printf("\nEl usuario no existe.");
    }
    else
    {
        if(A[i].dato.aprobado==1)
        {
            MostrarUs(A[i].dato);
        }
        else
        {
            printf("\nEl usuario no ha sido aprobado.");
        }
    }
}

/**< Esta funcion muestra todos los usuarios del ADL */
void ListarUsuarios(stCelda *A, int validos)
{
    int i=0;
    while(i<validos)
    {
        MostrarUs(A[i].dato);
        i++;
    }
}



///FUNCIONES SOBRE CANCIONES

///La funcion de alta de cancion está en la libreria ArbolCanciones y se llama CargarArbolCanción.

nodoArbolCancion* DarDeBajaCancion(nodoArbolCancion *arbol)
{
    int id;
    printf("\nIngrese el ID de la cancion: ");
    fflush(stdin);
    scanf("%i",&id);
    nodoArbolCancion *encontrado = BusquedaNodoPorID(arbol,id);
    if(encontrado==NULL)
    {
        printf("\nCancion no encontrada.");
    }
    else
    {
        encontrado->dato.eliminado = 0;
        printf("\nCancion eliminada.");
    }
    return arbol;
}


/**< Busca una cancion por id y si la encuentra la imprime */
void ConsultaDeCanciones(nodoArbolCancion *arbol)
{
    int id;
    printf("\nIngrese el ID de la cancion: ");
    fflush(stdin);
    scanf("%i",&id);
    nodoArbolCancion *encontrado = BusquedaNodoPorID(arbol,id);
    if(encontrado==NULL)
    {
        printf("\nCancion no encontrada.");
    }
    else
    {
        mostrarCancion(encontrado->dato);
    }
}


/**< Busca una cancion por id, si la encuentra abre un menu que permitira modificar sus campos */
nodoArbolCancion * modificarCanciones(nodoArbolCancion * arbol)
{
    int aBuscar;
    int option;
    nodoArbolCancion * aModificar = NULL;
    printf("\nIngresar el ID de la cancion que desea modificar: ");
    fflush(stdin);
    scanf("%d",&aBuscar);

    aModificar = BusquedaNodoPorID(arbol,aBuscar);
    if(aModificar!=NULL)
    {
        system("cls");
        mostrarCancion(aModificar->dato);
        while(option!=0)
        {

            printf("\nIngrese el campo que quiere modificar.");
            printf("\n\n1) TITULO DE LA CANCION");
            printf("\n2) ARTISTA");
            printf("\n3) DURACION");
            printf("\n4) ALBUM");
            printf("\n5) ANIO");
            printf("\n6) GENERO");
            printf("\n0) SALIR\n");
            fflush(stdin);
            scanf("%d",&option);
            switch(option)
            {
            case 1:
            {

                printf("\nIngrese titulo de la cancion: ");
                fflush(stdin);
                gets(aModificar->dato.titulo);
                while(comprobarTitulo(aModificar->dato.titulo)==0)
                {
                    printf("\nPorfavor solo ingrese letras y numeros...");
                    printf("\nIngrese titulo de la cancion: ");
                    fflush(stdin);
                    gets(aModificar->dato.titulo);
                }
                break;
            }
            case 2:
            {
                printf("\nIngrese Artista: ");
                fflush(stdin);
                gets(aModificar->dato.artista);
                while(comprobarArtista(aModificar->dato.artista)==0)
                {
                    printf("\nPorfavor solo ingrese letras y numeros...");
                    printf("\nIngrese Artista: ");
                    fflush(stdin);
                    gets(aModificar->dato.artista);
                }
                break;
            }
            case 3:
            {
                printf("\nIngrese duracion: ");
                fflush(stdin);
                gets(aModificar->dato.duracion);
                while(comprobarDuracion(aModificar->dato.duracion)==0)
                {
                    printf("\nPorfavor solo ingrese numeros...");
                    printf("\nIngrese duracion: ");
                    fflush(stdin);
                    gets(aModificar->dato.duracion);
                }
                break;
            }
            case 4:
            {
                printf("\nIngrese Album: ");
                fflush(stdin);
                gets(aModificar->dato.album);
                while(comprobarAlbum(aModificar->dato.album)==0)
                {
                    printf("\nPorfavor solo ingrese letras y numeros...");
                    printf("\nIngrese Album: ");
                    fflush(stdin);
                    gets(aModificar->dato.album);
                }
                break;
            }
            case 5:
            {
                printf("\nIngrese anio: ");
                fflush(stdin);
                gets(aModificar->dato.anio);
                while(comprobarAnio(aModificar->dato.anio)==0)
                {
                    printf("\nPorfavor solo ingrese numeros...");
                    printf("\nIngrese anio: ");
                    fflush(stdin);
                    gets(aModificar->dato.anio);
                }
                break;
            }
            case 6:
            {
                printf("\nIngrese genero: ");
                fflush(stdin);
                gets(aModificar->dato.genero);
                while(comprobarGenero(aModificar->dato.genero)==0)
                {
                    printf("\nPorfavor solo ingrese letras...");
                    printf("\nIngrese genero: ");
                    fflush(stdin);
                    gets(aModificar->dato.genero);
                }
                break;
            }
            case 7:
            {
                printf("\nID: ");
                fflush(stdin);
                scanf("%i",&aModificar->dato.idCancion);
            }
            case 0:
            {
                break;
            }
            default:
            {
                puts("Opcion invalida");
                system("pause");
                break;
            }
            }
            system("cls");
        }
        printf("\n\nCancion Modificada: ");
    }
    else
    {
        printf("\nLa cancion no existe...");
    }

    return arbol;
}

/**< Muestra ordenado por titulo todas las canciones del arbol */
void ListarPorTitulo(nodoArbolCancion *arbol)
{
    nodoListaCancion *lista = iniclista();
    lista = ArbolToListaEnOrdenTitulo(arbol,lista);
    MostrarLista(lista);
}

/**< Muestra ordenado por genero todas las canciones del arbol */
void ListarPorGenero(nodoArbolCancion *arbol)
{
    nodoListaCancion *lista = iniclista();
    lista = ArbolToListaEnOrdenGenero(arbol,lista);
    MostrarLista(lista);
}


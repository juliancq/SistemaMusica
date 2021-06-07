#include "CeldasUsuario.h"

///Cuenta la cantidad de registros del archivo de Usuarios.
int ContarCantidadUsuarios()
{
    FILE *bin = fopen("usuarios.dat","rb");
    int cant;
    fseek(bin,0,SEEK_END);
    cant = ftell(bin)/sizeof(stUsuario);
    return cant;
}

///Carga los datos de los usuarios en el arreglo de listas y sus respectivas canciones a partir de los registros del archivo Playlist.
int CargarUsuariosADL(stCelda *A, nodoArbolCancion *arbol)
{
    FILE *bin = fopen("usuarios.dat","rb");
    FILE *bon = fopen("playlist.dat","rb");
    stPlaylist play;
    stUsuario aux;
    int i=0;
    if(bin)
    {
        if(bon)
        {
            while(fread(&aux,sizeof(stUsuario),1,bin)>0)
            {
                A[i].dato = aux;
                while(fread(&play,sizeof(stPlaylist),1,bon)>0)
                {
                    if(play.idUsuario == aux.idUsuario)
                    {
                        stCancion can = BusquedaCancionPorID(arbol,play.idCancion);
                        nodoListaCancion *nuevo = CrearNodoLista(can);
                        A[i].listaCanciones = AgregarAlPrincipio(A[i].listaCanciones, nuevo);
                    }
                }
                fseek(bon,0,0);
                i++;
            }

        }
        fclose(bin);
        fclose(bon);
    }
    else
    {
        printf("\nERROR.");
    }
    return i;
}

///Busca un usuario en el arreglo de listas que contiene los datos de los usuarios y retorna todos sus datos.
stUsuario BuscarUsuarioPorNombre(stCelda *A, int validos, char nombre[])
{
    int i=0;
    stUsuario aux;
    aux.idUsuario = -1;
    while(i<validos)
    {
        if(strcmpi(A[i].dato.nombreUsuario,nombre)==0)
        {
            aux = A[i].dato;
        }
        i++;
    }
    return aux;
}

stUsuario BuscarUsuarioPorID(stCelda *A, int validos, int id)
{
    int i=0;
    int flag=0;
    stUsuario aux;
    aux.idUsuario = -1;
    while(i<validos&&flag==0)
    {
        if(A[i].dato.idUsuario==id)
        {
            aux = A[i].dato;
            flag = 1;
        }
        i++;
    }
    return aux;
}

///Comprueba si existe un usuario buscando por nombre. Si el usuario no existe retorna -1. Si existe retorna la posicion del usuario en el arreglo.
int ExisteUsuarioPorNombre(stCelda *A, int validos, char nombre[])
{
    int i=0;
    int flag=-1;
    while(i<validos&&flag==-1)
    {
        if(strcmpi(A[i].dato.nombreUsuario,nombre)==0)
        {
            flag = i;
        }
        i++;
    }
    return flag;
}

///Comprueba si existe un usuario buscando por numero de ID. Si el usuario no existe retorna -1. Si existe retorna la posicion del usuario en el arreglo.
int ExisteUsuarioPorID(stCelda *A, int validos, int id)
{
    int i=0;
    int flag=-1;
    while(i<validos&&flag==-1)
    {
        if(A[i].dato.idUsuario==id)
        {
            flag = i;
        }
        i++;
    }
    return flag;
}

///Muestra el Arreglo de listas que contiene a los usuarios y sus listas de canciones.
void MostrarUsuariosYCanciones(stCelda *A, int validos)
{
    int i=0;
    while(i<validos)
    {
        puts("\n------------USUARIO------------");
        MostrarUs(A[i].dato);
        puts("\n------------CANCIONES----------");
        if(A[i].listaCanciones != NULL)
        {
            MostrarLista(A[i].listaCanciones);
        }
        else
        {
            puts("LISTA VACIA");
        }
        i++;
    }
}


///Muestra un solo usuario.
void MostrarUs(stUsuario aux)
{
    puts("\n------------------------");
    printf("\nID: %i",aux.idUsuario);
    printf("\nNOMBRE: %s",aux.nombreUsuario);
    printf("\nCONTRASENA: %s",aux.pass);
    printf("\nANO DE NACIMIENTO: %s",aux.anioNacimiento);
    printf("\nGENERO: ");
    if(aux.genero=='f'||aux.genero=='F')
    {
        printf("FEMENINO");
    }
    else if(aux.genero=='M'||aux.genero=='m')
    {
        printf("MASCULINO");
    }
    else
    {
        printf("OTRO");
    }
    printf("\nPAIS: %s",aux.pais);
    printf("\nCORREO: %s",aux.correoElectronico);
    if(aux.eliminado==0)
    {
        printf("\nUSUARIO ELIMINADO");
    }
    puts("\n------------------------");
}

///Carga un solo usuario. Esta funcion sirve para el registro de usuarios.
stUsuario cargarUsuario(stCelda *A, int validos)
{
    stUsuario aux;
    int i = 0;
    aux.idUsuario = validos;

    printf("Ingrese su nombre de usuario\n");
    fflush(stdin);
    gets(aux.nombreUsuario);
    while(comprobarUser(aux.nombreUsuario) == 0&&ExisteUsuarioPorNombre(A,validos,aux.nombreUsuario)!=-1)
    {
        if(comprobarUser(aux.nombreUsuario)==0)
        {
            printf("Porfavor ingrese solo letras y numeros\n");
            printf("Ingrese su nombre de usuario\n");
            fflush(stdin);
            gets(aux.nombreUsuario);
        }
        else
        {
            printf("\nEl usuario ya existe, por favor ingrese otro.");
            printf("\nIngrese su nombre de usuario: ");
            fflush(stdin);
            gets(aux.nombreUsuario);
        }
    }

    printf("Ingrese su contrasenia\n");
    codificarPassword(aux.pass);


    printf("Ingrese su anio de nacimiento\n");
    fflush(stdin);
    gets(aux.anioNacimiento);
    while(comprobarAnio(aux.anioNacimiento) == 0)
    {
        printf("Porfavor ingrese solo numero\n");
        printf("Ingrese su anio de nacimiento\n");
        gets(aux.anioNacimiento);
    }

    printf("Ingrese su genero (M-F-O)\n");
    fflush(stdin);
    scanf("%c", &aux.genero);
    while(aux.genero != 'm' && aux.genero != 'f' && aux.genero != 'o')
    {
        printf("Porfavor ingrese un genero valido\n");
        printf("Ingrese su genero (M-F-O)\n");
        fflush(stdin);
        scanf("%c", &aux.genero);
    }

    printf("Ingrese su pais\n");
    fflush(stdin);
    gets(aux.pais);
    while(comprobarPais(aux.pais) == 0)
    {
        printf("Porfavor ingrese solo letras y espacios\n");
        printf("Ingrese su pais\n");
        fflush(stdin);
        gets(aux.pais);
    }

    printf("Ingrese su correo electronico\n");
    fflush(stdin);
    gets(aux.correoElectronico);
    while(comprobarMail(aux.correoElectronico) == 0)
    {
        printf("Porfavor ingrese un mail valido\n");
        printf("Ingrese su correo electronico\n");
        fflush(stdin);
        gets(aux.correoElectronico);
    }

    aux.aprobado = 0;
    aux.eliminado = 1;
    aux.tipoUsuario = 0;

    return aux;
}


///Carga a mano usuarios directamente sobre el archivo. Usado para probar el sistema
void CargarArchivoUsuarios()
{
    FILE *bin = fopen("usuarios.dat","ab");
    stUsuario aux;
    char continuar='s';
    int cant;
    fseek(bin,0,SEEK_END);
    cant = ftell(bin)/sizeof(stUsuario);
    if(bin)
    {
        while(continuar=='s')
        {
            aux.idUsuario = cant;
            printf("Ingrese su nombre de usuario\n");
            fflush(stdin);
            gets(aux.nombreUsuario);
            while(comprobarUser(aux.nombreUsuario)==0)
            {
                printf("Porfavor ingrese solo letras y numeros\n");
                printf("Ingrese su nombre de usuario\n");
                fflush(stdin);
                gets(aux.nombreUsuario);

            }
            printf("Ingrese su contrasenia\n");
            fflush(stdin);
            gets(aux.pass);

            printf("Ingrese su anio de nacimiento\n");
            fflush(stdin);
            gets(aux.anioNacimiento);
            while(comprobarAnio(aux.anioNacimiento) == 0)
            {
                printf("Porfavor ingrese solo numero\n");
                printf("Ingrese su anio de nacimiento\n");
                gets(aux.anioNacimiento);
            }

            printf("Ingrese su genero (M-F-O)\n");
            fflush(stdin);
            scanf("%c", &aux.genero);
            while(aux.genero != 'm' && aux.genero != 'f' && aux.genero != 'o')
            {
                printf("Porfavor ingrese un genero valido\n");
                printf("Ingrese su genero (M-F-O)\n");
                fflush(stdin);
                scanf("%c", &aux.genero);
            }

            printf("Ingrese su pais\n");
            fflush(stdin);
            gets(aux.pais);
            while(comprobarPais(aux.pais) == 0)
            {
                printf("Porfavor ingrese solo letras y espacios\n");
                printf("Ingrese su pais\n");
                fflush(stdin);
                gets(aux.pais);
            }

            printf("Ingrese su correo electronico\n");
            fflush(stdin);
            gets(aux.correoElectronico);
            while(comprobarMail(aux.correoElectronico) == 0)
            {
                printf("Porfavor ingrese un mail valido\n");
                printf("Ingrese su correo electronico\n");
                fflush(stdin);
                gets(aux.correoElectronico);
            }

            aux.aprobado = 0;
            aux.eliminado = 1;
            aux.tipoUsuario = 0;
            fwrite(&aux,sizeof(stUsuario),1,bin);
            printf("\nDesea continuar ?(s/n)");
            fflush(stdin);
            continuar = getch();
            cant++;
        }
        fclose(bin);
    }
}

///Muestra el archivo que contiene los registros de usuario
void MostrarArchivoUsuarios()
{
    FILE *bin = fopen("usuarios.dat","rb");
    stUsuario aux;
    if(bin)
    {
        while(fread(&aux,sizeof(stUsuario),1,bin)>0)
        {
            MostrarUs(aux);
        }
        fclose(bin);
    }
}




///FUNCIONES PLAYLIST

///Carga a mano datos en el archivo de playlist. Usado para probar el sistema
void CargarPlaylistRustico()
{
    FILE *bin = fopen("playlist.dat","wb");
    stPlaylist aux;
    char continuar = 's';
    if(bin)
    {
        while(continuar=='s')
        {

            printf("\nCargue idCancion: ");
            fflush(stdin);
            scanf("%i",&aux.idCancion);
            printf("\nCargue idUsuario: ");
            fflush(stdin);
            scanf("%i",&aux.idUsuario);
            aux.idPlaylist = aux.idUsuario;
            fwrite(&aux,sizeof(stPlaylist),1,bin);

            printf("\nContinuar ?");
            fflush(stdin);
            continuar = getch();
        }
        fclose(bin);
    }
}

///Muestra el archivo que contiene los registros de Playlist
void MostrarArchivoPlaylist()
{
    FILE *bin = fopen("playlist.dat","rb");
    stPlaylist aux;
    if(bin)
    {
        while(fread(&aux,sizeof(stPlaylist),1,bin)>0)
        {
            puts("----------------------------");
            printf("\nID Playlist: %i\n",aux.idPlaylist);
            printf("\nID Cancion: %i\n",aux.idCancion);
            printf("\nID Usuario: %i\n",aux.idUsuario);
        }
        fclose(bin);
    }
}

void AgregarRegistroPlaylist(int idUs,int idCan)
{
    FILE *bin = fopen("playlist.dat", "wb");
    stPlaylist aux;
    aux.idCancion = idCan;
    aux.idUsuario = idUs;
    aux.idPlaylist = idUs;

    if(bin)
    {
        fwrite(&aux, sizeof(stPlaylist), 1, bin);
        fclose(bin);
    }
    else
    {
        puts("error");
    }
}

int registroUsuario(stCelda **A, int validos)
{
    stUsuario nuevo = cargarUsuario(*A, validos);
    validos = altaUsuarioADL(nuevo, A, validos);
    return validos;
}

int altaUsuarioADL(stUsuario nuevo, stCelda **A, int valCeldas)
{
    *A = realloc(*A, (valCeldas+1) *sizeof(stCelda));

    (*A)[valCeldas].dato = nuevo;
    (*A)[valCeldas].listaCanciones = iniclista();
    valCeldas++;
    return valCeldas;
}

int PreguntarContraseniaAdmin()
{
    char pass[20];
    int flag=0;
    printf("\nIngrese contrasena de admin: \n");
    codificarPassword(pass);
    if(strcmp("1234", pass) == 0)
    {
        flag = 1;
    }
    return flag;
}

int registroAdmin(stCelda **A, int validos)
{
    stUsuario nuevo = cargarUsuario(*A, validos);
    nuevo.tipoUsuario = 1;
    altaUsuarioADL(nuevo, A, validos);
    validos++;
    return validos;
}


/**< Esta funcion recorre el arreglo de usuarios y actualiza el archivo "USUARIOS.DAT" */
void ActualizarUsuarios(stCelda *A, int validos)
{
    FILE *bin = fopen("usuarios.dat","wb");
    stUsuario aux;
    int i=0;
    if(bin)
    {
        while(i<validos)
        {
            fwrite(&A[i].dato,sizeof(stUsuario),1,bin);
            i++;
        }
        fclose(bin);
    }
    else
    {
        printf("\nERROR.");
    }
}







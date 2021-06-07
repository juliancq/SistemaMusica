#include "Menu.h"

void menuPrincipal(stCelda *A, int validos, nodoArbolCancion *arbol)
{
    int option = 1;

    while(option != 0)
    {
        system("cls");
        imprimirCabecera("S P O T I F Y");
        printf("\n");
        printf("1) Inicio sesion como administrador\n");
        printf("2) Inicio sesion como usuario\n");
        printf("3) Registrarse\n");
        printf("0) Abandonar el sistema\n");

        scanf("%i",&option);

        switch(option)
        {
        case 1:
        {
            system("cls");
            arbol = inicioSesionAdmin(A,validos,arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            inicioSesionUser(A,validos,arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 3:
        {
            validos = Registro(&A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 0:
        {
            puts("Gracias por utilizar Spotify");
            break;
        }
        default:
        {
            puts("Opcion invalida");
            printf("\n");
            system("pause");
            break;
        }
        }
    }
    ArbolToArchivo(arbol);
    actualizarCancionesEscuchadas(A,validos);
    ActualizarUsuarios(A,validos);
}

int Registro(stCelda **A, int validos)
{
    int option = 1;
    while(option!=0)
    {
        system("cls");
        printf("\n");
        printf("\n1) Registrarse como usuario.");
        printf("\n2) Registrarse como administrador.");
        printf("\n0) Para salir.\n");
        fflush(stdin);
        scanf("%i",&option);
        switch(option)
        {
            case 1:
        {
            system("cls");
            validos = registroUsuario(A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            int flag = PreguntarContraseniaAdmin();
            if(flag==1)
            {
                system("cls");
                validos = registroAdmin(A,validos);
            }
            else
            {
                printf("\nContrasena incorrecta.");
            }
            printf("\n");
            system("pause");
            break;
        }
        }
    }
    return validos;
}

nodoArbolCancion *menuAdmin(stCelda *A, int validos, nodoArbolCancion *arbol)
{
    int option = 1;

    while(option != 0)
    {
        system("cls");
        printf("BIENVENIDO ADMIN\n");
        printf("1) Funciones sobre usuarios\n");
        printf("2) Funciones sobre canciones\n");
        printf("0) <- Volver\n");

        scanf("%i",&option);

        switch(option)
        {
        case 1:
        {

            subMenuAdmin1(A, validos);

            break;
        }
        case 2:
        {

            arbol = subMenuAdmin2(arbol);

            break;
        }

        case 0:
        {
            break;
        }
        default:
        {
            puts("Opcion invalida");
            printf("\n");
            system("pause");
            break;
        }
        }
    }
    return arbol;
}


void subMenuAdmin1(stCelda *A, int validos)
{
    int option = 1;

    while(option != 0)
    {
        system("cls");
        printf("FUNCIONES SOBRE USUARIOS\n");
        printf("1) Dar de alta usuarios\n");
        printf("2) Dar de baja usuarios\n");
        printf("3) Modificar usuarios\n");
        printf("4) Consulta usuarios\n");
        printf("5) Listar usuarios\n");
        printf("0) <- Volver\n");

        scanf("%i",&option);

        switch(option)
        {
        case 1:
        {
            puts("ALTA USUARIOS");
            DarAltaUsuarios(A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 2:
        {
            puts("BAJA USUARIOS");
            DarDeBajaUsuarios(A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 3:
        {
            puts("MODIFICACION USUARIOS");
            ModificarUsuario(A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 4:
        {
            puts("CONSULTA USUARIOS");
            ConsultaUsuarios(A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 5:
        {
            puts("LISTAR USUARIOS");
            ListarUsuarios(A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            puts("Opcion invalida");
            printf("\n");
            system("pause");
            break;
        }
        }
    }
}


nodoArbolCancion *subMenuAdmin2(nodoArbolCancion *arbol)
{
    int option = 1;
    while(option != 0)
    {
        system("cls");
        printf("FUNCIONES SOBRE CANCIONES\n");
        printf("1) Dar de alta canciones\n");
        printf("2) Dar de baja canciones\n");
        printf("3) Modificar canciones\n");
        printf("4) Consulta canciones\n");
        printf("5) Listar por titulo\n");
        printf("6) Listar por genero\n");
        printf("0) <- Volver\n");

        scanf("%i",&option);

        switch(option)
        {
        case 1:
        {
            system("cls");
            puts("ALTA CANCIONES");
            arbol = AltaArbolCancion(arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            puts("BAJA CANCIONES");
            arbol = DarDeBajaCancion(arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            puts("MODIFICACION CANCIONES");
            arbol = modificarCanciones(arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            puts("CONSULTA CANCIONES");
            ConsultaDeCanciones(arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            puts("LISTAR CANCIONES X TITULO");
            ListarPorTitulo(arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            puts("LISTAR CANCIONES X GENERO");
            ListarPorGenero(arbol);
            system("pause");
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            puts("Opcion invalida");
            printf("\n");
            system("pause");
            break;
        }
        }
    }
    return arbol;
}

void menuUser(int idUsuario, stCelda *A, int validos, nodoArbolCancion *arbol)
{
    int option = 1;

    while(option != 0)
    {
        system("cls");
        printf("BIENVENIDO\n");
        printf("1) Ver perfil\n");
        printf("2) Mostrar playlist\n");
        printf("3) Escuchar cancion\n");
        printf("4) Modificar playlist\n");
        printf("5) Canciones recomendadas\n");
        printf("0) <- Volver\n");

        scanf("%i",&option);

        switch(option)
        {
        case 1:
        {
            puts("VER PERFIL");
            verPerfil(idUsuario,A,validos);
            printf("\n");
            system("pause");
            break;
        }
        case 2:
        {
            puts("MOSTRAR PLAYLIST");
            mostrarPlaylist(idUsuario,A);
            printf("\n");
            system("pause");
            break;
        }
        case 3:
        {
            puts("ESCUCHAR CANCION");
            EscucharCancion(A,idUsuario,arbol);
            printf("\n");
            system("pause");
            break;
        }
        case 4:
        {
            puts("BORRAR CANCION");
            borrarCancion(idUsuario,A);
            printf("\n");
            system("pause");
            break;
        }
        case 5:
        {
            puts("CANCIONES RECOMENDADAS");
            CancionesRecomendadas(arbol,A,idUsuario);
            printf("\n");
            system("pause");
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            puts("Opcion invalida");
            printf("\n");
            system("pause");
            break;
        }
        }
    }
}

void inicioSesionUser(stCelda *A, int validos, nodoArbolCancion *arbol)
{
    char nombre[30];
    char pass[20];

    printf("Ingrese su nombre de usuario\n");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese su contrasena\n");
    codificarPassword(pass);


    stUsuario aux;
    aux = BuscarUsuarioPorNombre(A,validos,nombre);
    if(aux.idUsuario!=-1)
    {
        if(strcmp(pass, aux.pass) == 0)
        {
            if(aux.aprobado == 1 && aux.eliminado == 1)
            {
                printf("Ingreso correcto");
                menuUser(aux.idUsuario,A,validos,arbol);
            }
            else
            {
                printf("Su cuenta esta inhabilitada o aun no fue aprobada\n");
            }
        }
        else
        {
            printf("Contrasena incorrecta");
        }
    }
    else
    {
        printf("Nombre de usuario inexistente");
    }
}

nodoArbolCancion *inicioSesionAdmin(stCelda *A, int validos,nodoArbolCancion *arbol)
{
    char nombre[30];
    char pass[20];

    printf("Ingrese su nombre de usuario\n");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese su contrasena\n");
    codificarPassword(pass);

    stUsuario aux = BuscarUsuarioPorNombre(A,validos,nombre);
    if(aux.idUsuario!=-1)
    {
        if(aux.tipoUsuario == 1)
        {
            if(strcmp(pass, aux.pass) == 0)
            {
                if(aux.eliminado == 1)
                {
                    printf("Ingreso correcto");
                    arbol = menuAdmin(A,validos,arbol);
                }
                else
                {
                    printf("Este usuario fue eliminado \n");
                }

            }
            else
            {
                printf("Contrasena incorrecta");
            }
        }
        else
        {
            printf("Este usuario no cuenta con privilegios de adminisrador, por favor inicie sesion como usuario\n");
        }
    }
    else
    {
        printf("Nombre de usuario inexistente");
    }
}

/**< Esta funcion permite oculta la contraseña en las instancias de registro o inicio de sesion */
void codificarPassword(char password[])
{
    int i = 0;
    char caracter;

    while(i<20 && caracter != 13)
    {
        fflush(stdin);
        caracter = getch();
        if(caracter == 13)
        {
            password[i] = '\0';
        }
        else
        {
            password[i] = caracter;
            printf("*");
        }

         i++;
    }
    printf("\n");
}

/**< Imprime una cabecera */
void imprimirCabecera(char cabecera[])
{
    int i;
    printf("%c", 201);
    for(i=0;i<50;i++){
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0;i<50;i++){
        printf("%c",205);
    }
    printf("%c", 188);
}


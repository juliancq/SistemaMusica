#include "ComprobacionDatos.h"

/**********************/
/** INGRESO USUARIOS **/
/**********************/

///Recibe un string y comprueba que este compuesto por Letras o Numeros
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarUser(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalnum(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Letras o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarNombre(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalpha(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Letras, Numeros o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarDomicilio(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalnum(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}


///Recibe un string y comprueba que este compuesto por Letras, Numeros o Simbolos("@",".")
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarMail(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalnum(string[i]) && string[i] != '@' && string[i] != '.')
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}


///Recibe un string y comprueba que este compuesto por Letras o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarPais(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalpha(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

/***********************/
/** INGRESO CANCIONES **/
/***********************/


 ///Recibe un string y comprueba que este compuesto por Letras, Numeros o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarTitulo(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalnum(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Letras, Numeros o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarArtista(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalnum(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Letras, Numeros o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarAlbum(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalnum(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Numeros o Simbolos(":")
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarDuracion(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isdigit(string[i]) && string[i] != ':')
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Numeros
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarAnio(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isdigit(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

///Recibe un string y comprueba que este compuesto por Letras o Espacios
///Retorna 1 si el string cumple las condiciones, 0 si no las cumple
int comprobarGenero(char string[])
{
    int i = 0;
    int flag = 1;

    while(i < strlen(string) && flag == 1)
    {
        if(!isalpha(string[i]) && !isspace(string[i]))
        {
            flag = 0;
        }

        i++;
    }

    return flag;
}

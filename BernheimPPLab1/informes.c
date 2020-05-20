#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "motos.h"
#include "trabajos.h"
#include "informes.h"


char menuInformes()
{
    char opcion;
    system("cls");
    printf("**** Menu de Informes ****\n\n");
    printf("a- Informar motos de un color\n");
    printf("b- Informar motos de un tipo\n");
    printf("c- Informar la o las motos de mayor cilindrada\n");
    printf("d- Informar motos separadas por tipo\n");
    printf("e- Informar total motos de un tipo y color\n");
    printf("f- Informar el o los colores mas elegidos\n");
    printf("g- Salir\n\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);

    opcion=tolower(opcion);

    return opcion;
}
void informar(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos,eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios, eColorMasElegido listaCME[])
{
    char seguir ='s';
    char confirma;

    do
    {
        switch(menuInformes())
        {
        case 'a':
            //INFORMAR MOTOS POR COLOR
            informarMotosColor(vec,tamMotos,colores,tamColores,tipos,tamTipos);
            system("pause");
            break;
        case 'b':
            //INFORMAR MOTOS POR TIPO
            informarMotosTipo(vec,tamMotos,colores,tamColores,tipos,tamTipos);
            system("pause");
            break;
        case 'c':
            //INFORMAR MOTOS MAYOR CILINDRADA
            informarMotoMayorCilindrada(vec,tamMotos,colores,tamColores,tipos,tamTipos);
            system("pause");
            break;
        case 'd':
            //LISTADO MOTOS POR TIPO
            informarMotosPorTipo(vec,tamMotos,colores,tamColores,tipos,tamTipos);
            system("pause");
            break;
        case 'e':
            //INFORMAR CANTIDAD POR COLOR Y TIPO
            informarMotosColorYTipo(vec,tamMotos,colores,tamColores,tipos,tamTipos);
            system("pause");
            break;
        case 'f':
            //INFORMAR EL O LOS COLORES MAS ELEGIDOS
            informarColorMasElegido(vec,tamMotos,colores,tamColores,tipos,tamTipos,listaCME);
            system("pause");
            break;
        case 'g':
            //SALIR
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        }
    }
    while(seguir =='s');

}
void informarMotosColor(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos)
{
    int flag=0;
    int color;
    mostrarDescripcionColores(colores,tamColores);
    if((utn_getEntero(&color,2,"Ingrese el color: ","Error. Reingrese el color\n",10000,10004))==0)
    {
    system("cls");
    printf("*****INFORMAR MOTOS POR COLOR *****\n");
    printf("ID           MARCA          TIPO           COLOR     CILINDRADA \n\n");

    for(int i=0; i<tamMotos; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idColor == color)
        {
            mostrarMoto(vec[i],tipos,tamTipos,colores,tamColores);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay motos que listar\n\n");
    }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el color\n\n");
    }



}
void informarMotosTipo(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos)
{
    int flag=0;
    int tipo;
    mostrarDescripcionTipos(tipos,tamTipos);
    if((utn_getEntero(&tipo,2,"Ingrese el tipo: ","Error. Reingrese el tipo\n",1000,1003))==0)
    {
    system("cls");
    printf("*****INFORMAR MOTOS POR TIPO *****\n");
    printf("ID           MARCA          TIPO           COLOR     CILINDRADA \n\n");

    for(int i=0; i<tamMotos; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].idTipo == tipo)
        {
            mostrarMoto(vec[i],tipos,tamTipos,colores,tamColores);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay motos que listar\n\n");
    }
    }
    else
    {
        printf("Se quedo sin intentos para ingresar el tipo\n\n");
    }



}
void informarMotoMayorCilindrada(eMoto motos[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos)
{

    int flag=0;
    int mayorCilindrada = 0;

    system("cls");

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            if(motos[i].cilindrada>mayorCilindrada || flag==0)
            {
                mayorCilindrada=motos[i].cilindrada;
                flag=1;
            }
        }

    }

    printf("*****INFORMAR MOTOS MAYOR CILINDRADA *****\n\n");
    printf("ID           MARCA          TIPO           COLOR     CILINDRADA \n\n");

    for(int i=0; i<tamMotos; i++)
    {
        if(motos[i].cilindrada == mayorCilindrada)
        {
            mostrarMoto(motos[i],tipos,tamTipos,colores,tamColores);
        }
    }


}
void informarMotosPorTipo(eMoto motos[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos)
{
    int flag = 0;

    system("cls");
    printf("***** INFORMAR MOTOS POR TIPO *****\n\n");
    printf("ID           MARCA          TIPO           COLOR     CILINDRADA \n\n");

    for(int s=0; s<tamTipos; s++)
    {
        printf("Tipo: %s\n",tipos[s].nombreTipo);
        printf("----------\n");

        for(int e=0; e<tamMotos; e++)
        {
            if(motos[e].isEmpty == 0 && motos[e].idTipo == tipos[s].id)
            {
                mostrarMoto(motos[e],tipos,tamTipos,colores,tamColores);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay motos de este tipo\n\n");
        }
        printf("\n---------------------------------------\n\n");
    }



}
void informarMotosColorYTipo(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos)
{
    int flag=0;
    int tipo;
    int color;
    int contadorMotos = 0;
    mostrarDescripcionTipos(tipos,tamTipos);
    if((utn_getEntero(&tipo,2,"Ingrese el tipo: ","Error. Reingrese el tipo\n",1000,1003))==0)
    {
        mostrarDescripcionColores(colores,tamColores);
        if((utn_getEntero(&color,2,"Ingrese el color: ","Error. Reingrese el color\n",10000,10004))==0)
        {
            system("cls");
            printf("*****INFORMAR MOTOS POR TIPO Y COLOR *****\n");
            printf("ID           MARCA          TIPO           COLOR     CILINDRADA \n\n");

            for(int i=0; i<tamMotos; i++)
            {
                if(vec[i].isEmpty == 0 && vec[i].idTipo == tipo && vec[i].idColor ==color)
                {
                    mostrarMoto(vec[i],tipos,tamTipos,colores,tamColores);
                    flag=1;
                    contadorMotos++;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay motos que listar\n\n");
            }
        }
        else
        {
            printf("Se quedo sin intentos para ingresar el color\n\n");
        }

    }
    else
    {
        printf("Se quedo sin intentos para ingresar el tipo\n\n");
    }

    if(flag)
    {
        printf("\n\nLa cantidad de motos del color y tipo son: %d\n\n",contadorMotos);
    }

}
void inicializarCME(eColorMasElegido listaCME[],int tamCME)
{
    for(int i=0; i<tamCME; i++)
    {
        listaCME[i].isEmpty = 1;
    }
}
void informarColorMasElegido(eMoto motos[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos,eColorMasElegido listaCME[])
{
	int contadorC;
	int CME = 0;
	int flag = 0;
	int indice;
	eColorMasElegido auxCME;

	for(int c = 0; c < tamColores; c++)
	{
		contadorC = 0;

		for(int m = 0; m < tamMotos; m++)
		{
			if(motos[m].isEmpty == 0 && motos[m].idColor == colores[c].id)
			{
				contadorC++;
			}
		}


        listaCME[CME].isEmpty = 0;
		listaCME[CME].idColor = colores[c].id;
		listaCME[CME].cantidadElegida = contadorC;

		CME++;

	}

	for(int j = 0; j < tamColores; j++)
	{
		if(flag == 0)
		{
			auxCME = listaCME[j];
			flag = 1;
		}
		else if(listaCME[j].cantidadElegida > auxCME.cantidadElegida && listaCME[j].isEmpty == 0)
		{
			auxCME = listaCME[j];
		}
	}

    system("cls");
	printf("***** INFORMAR COLOR/ES MAS ELEGIDO/S *****\n");
	printf("Listado de colores mas elegidos: \n");
	printf("  ID       Descripcion\n\n");

	for(int i = 0; i < tamColores; i++)
	{
		if(auxCME.cantidadElegida == listaCME[i].cantidadElegida && listaCME[i].isEmpty == 0)
		{
			indice = buscarColor(listaCME[i].idColor, colores, tamColores);
			mostrarColor(colores[indice]);
		}
	}

}
int buscarColor(int idColor, eColor colores[], int tamColores)
{
	int indice = -1;

	for(int i = 0; i < tamColores; i++)
	{
		if(colores[i].id == idColor)
		{
			indice = i;
			break;
		}
	}

	return indice;
}
void mostrarColor(eColor color)
{

    printf(" %d     %10s     \n",color.id,color.nombreColor);

}

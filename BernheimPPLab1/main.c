#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "motos.h"
#include "trabajos.h"
#include "hardcodeMotos.h"
#include "informes.h"

#define TAMTIPO 4
#define TAMMOTOS 1000
#define TAMCOLORES 5
#define TAMSERVICIOS 4
#define TAMTRABAJOS 1000
#define TAMHARDCODEOMOTOS 10
#define TAMHARDCODEOTRABAJOS 10




int mostrarMenu();
void hardcodearMotos(eMoto vec[], int tam);
void hardcodearTrabajos(eTrabajo vec[], int tam);




int main()
{
    char seguir='s';
    char confirma;


    eMoto listaMotos[TAMMOTOS];
    eTrabajo listaTrabajos[TAMTRABAJOS];

    int proximoIdMoto = 1;
    int proximoIdTrabajo = 21000;
    int flagAltaMoto = 0;
    int flagAltaTrabajo = 0;

    eTipo tiposMotos [TAMTIPO]= {{1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"},{1003, "CicloMotor"}};

    eColor colores[TAMCOLORES] = {{10000, "Gris"}, {10001, "Negro"}, {10002, "Blanco"},{10003, "Azul"},{10004,"Rojo"}};

    eServicio servicios[TAMSERVICIOS] = {{20000, "Limpieza",250}, {20001, "Ajuste",300}, {20002, "Balanceo",17},{20003, "Cadena",190}};

    eColorMasElegido listaCME[TAMCOLORES];

    inicializarMotos(listaMotos,TAMMOTOS);
    inicializarTrabajos(listaTrabajos,TAMTRABAJOS);
    inicializarCME(listaCME,TAMCOLORES);

    //HARDCODEO
    proximoIdMoto += TAMHARDCODEOMOTOS;
    proximoIdTrabajo += TAMHARDCODEOTRABAJOS;
    hardcodearMotos(listaMotos,TAMHARDCODEOMOTOS);
    hardcodearTrabajos(listaTrabajos,TAMHARDCODEOTRABAJOS);

    do
    {
        fflush(stdin);
        switch(mostrarMenu())
        {
        case 1:
            //ALTA MOTO
            if(altaMoto(proximoIdMoto,listaMotos,TAMMOTOS,tiposMotos,TAMTIPO,colores,TAMCOLORES))
            {
                proximoIdMoto++;
                flagAltaMoto = 1;
            }
            break;
        case 2:
            //MODIFICAR MOTO
            if(flagAltaMoto)
            {
                modificarMoto(listaMotos,TAMMOTOS,tiposMotos,TAMTIPO,colores,TAMCOLORES);
            }
            else
            {
                printf("Primero debe ingresar una moto para poder modificarla\n\n");
            }
            break;
        case 3:
            //BAJA MOTO
            if(flagAltaMoto)
            {
                bajaMoto(listaMotos,TAMMOTOS,tiposMotos,TAMTIPO,colores,TAMCOLORES);
            }
            else
            {
                printf("Primero debe ingresar una moto para poder dar de baja\n\n");
            }
            break;
        case 4:
            //LISTAR MOTOS
            if(flagAltaMoto)
            {
                listarMotos(listaMotos,TAMMOTOS,tiposMotos,TAMTIPO,colores,TAMCOLORES);
            }
            else
            {
                printf("Primero debe ingresar una moto para poder listar\n\n");
            }
            break;
        case 5:
            //LISTAR TIPOS
            system("cls");
            mostrarDescripcionTipos(tiposMotos,TAMTIPO);
            break;
        case 6:
            //LISTAR COLORES
            system("cls");
            mostrarDescripcionColores(colores,TAMCOLORES);
            break;
        case 7:
            //LISTAR SERVICIOS
            system("cls");
            mostrarDescripcionServicios(servicios,TAMSERVICIOS);
            break;
        case 8:
            // ALTA TRABAJO
            if(flagAltaMoto)
            {
                if(altaTrabajo(proximoIdTrabajo,listaTrabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,listaMotos,TAMMOTOS,tiposMotos,TAMTIPO,colores,TAMCOLORES))
                {
                    proximoIdTrabajo++;
                    flagAltaTrabajo = 1;
                }
            }
            else
            {
                printf("\nPrimero debe ingresar una moto para poder dar de alta trabajos\n\n");
            }
            break;
        case 9:
            //LISTAR TRABAJOS
            if(flagAltaTrabajo)
            {
                mostrarTrabajos(listaTrabajos,TAMTRABAJOS,servicios,TAMSERVICIOS);
            }
            else
            {
                printf("Primero debe ingresar trabajos para poder listarlos\n\n");
            }
            break;
        case 10:
            //INFORMES
            if(flagAltaMoto && flagAltaTrabajo)
            {
                informar(listaMotos,TAMMOTOS,colores,TAMCOLORES,tiposMotos,TAMTIPO,listaTrabajos,TAMTRABAJOS,servicios,TAMSERVICIOS,listaCME);
            }
            else
            {
                printf("Primero debe ingresar motos y trabajos para ingresar a los informes\n\n");
            }
            break;
        case 11:
            //SALIR
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("\n\nIngrese una opcion valida\n\n");
        }
        system("pause");
    }
    while(seguir=='s');



    return 0;
}

int mostrarMenu()
{
    int opcion;
    system("cls");
    printf("**** Menu de opciones ****\n\n");
    printf("1- Alta moto\n");
    printf("2- Modificar moto\n");
    printf("3- Baja moto\n");
    printf("4- Listar motos \n");
    printf("5- Listar tipos\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar trabajos\n");
    printf("10- Informes\n");
    printf("11- Salir\n\n");
    printf("Indique la opcion: ");
    scanf("%d",&opcion);


    return opcion;
}

void hardcodearMotos(eMoto vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
		vec[i].id = idsMotos[i];
        vec[i].idTipo = idsTipos[i];
        vec[i].idColor = idsColores[i];
        vec[i].cilindrada = cilindradas[i];
        strcpy(vec[i].marca, marcas[i]);
		vec[i].isEmpty = 0;
	}
}

void hardcodearTrabajos(eTrabajo vec[], int tam)
{
	for(int i=0; i<tam; i++)
	{
        vec[i].id = idsTrabajos[i];
        vec[i].idMoto = idsMotosTrabajos[i];
        vec[i].idServicio = idsServicios[i];
        vec[i].fecha.dia = dias[i];
        vec[i].fecha.mes = meses[i];
        vec[i].fecha.anio = anios[i];
		vec[i].isEmpty = 0;
	}
}


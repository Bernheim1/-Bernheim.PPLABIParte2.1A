#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


typedef struct{

	int idColor;
	int cantidadElegida;
	int isEmpty;

}eColorMasElegido;


#endif // INFORMES_H_INCLUDED


char menuInformes();
void informar(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos,eTrabajo trabajos[],int tamTrabajos,eServicio servicios[],int tamServicios, eColorMasElegido listaCME[]);
void informarMotosColor(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos);
void informarMotosTipo(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos);
void informarMotoMayorCilindrada(eMoto motos[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos);
void informarMotosPorTipo(eMoto motos[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos);
void informarMotosColorYTipo(eMoto vec[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos);
void inicializarCME(eColorMasElegido listaCME[],int tamCME);
void mostrarColor(eColor color);
int buscarColor(int idColor, eColor colores[], int tamColores);
void informarColorMasElegido(eMoto motos[], int tamMotos,eColor colores[],int tamColores,eTipo tipos[],int tamTipos,eColorMasElegido listaCME[]);

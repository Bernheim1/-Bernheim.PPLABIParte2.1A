#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[26];
    float precio;

} eServicio;

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;

#endif // TRABAJOS_H_INCLUDED

/** \brief muestra la descripcion de cada servicio, su id y su precio
 *
 * \param vector de servicios donde se buscan el id, la descripcion y el precio
 * \param tamanio del vector de eServicio a recorrer
 *
 */
void mostrarDescripcionServicios(eServicio servicios[],int tamServicio);

/** \brief busca en un vector de eTrabajo si hay un espacio con isEmpty=1
 *
 * \param vector de eTrabajo a recorrer
 * \param tamanio del vector a recorrer
 *
 * \return 1 si no encuentra espacio vacio,sino el indice del espacio vacio
 *
 */
int buscarLibreTrabajo(eTrabajo vec[],int tam);

/** \brief le da valor 1 a todos los trabajos del vector que se le pasa por parametro
 *
 * \param vector de eTrabajo a recorrer
 * \param tamanio del vector de trabajos
 *
 */
void inicializarTrabajos(eTrabajo vec[],int tam);

/** \brief busca un espacio vacio en un vector de eTrabajo y le carga los datos si el usuario ingresa
 *  bien todos los campos
 *
 * \param id a asignarle al nuevo trabajo
 * \param vector de eTrabajo a utilizar para cargar el nuevo trabajo
 * \param tamanio del vector de eTrabajo para recorrer
 * \param vector de servicios para listar en el ingreso
 * \param tamanio del vector de eServicio
 * \param vector de eMoto para buscar el id de la moto en la que se hara el trabajo
 * \param tamanio del vector de eMoto
 * \param vector de tipos de motos para listar en el ingreso
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para listar en el ingreso
 * \param tamanio del vector de eColor
 *
 * \return 1 si pudo cargar los datos, -1 si no lo pudo hacer
 *
 */
int altaTrabajo(int idX,eTrabajo vec[], int tamTrabajo,eServicio servicios[],int tamServicios,eMoto listaMotos[], int tamMotos,eTipo tipos[],int tamTipos,eColor colores[],int tamColores);

/** \brief muestra todos los datos de un trabajo
 *
 * \param escalar de eTrabajo a mostrar
 * \param vector de servicios para cargar la descripcion
 * \param tamanio del vector de eServicio
 *
 */
void mostrarTrabajo(eTrabajo x,eServicio servicios[], int tamServicios);

/** \brief carga la descripcion de un servicio y el precio en dos variables pasadas por parametro
 *
 * \param vector donde se cargara la descripcion
 * \param variable donde se cargara el precio
 * \param id del servicio a buscar
 * \param vector de servicios donde buscar la descripcion y el precio
 * \param tamanio del vector de eServicio a recorrer
 *
 * \return 1 si logra cargar la descripcion, sino 0
 *
 */
int cargarDescripcionServicio(char servicio[],float* precio,int id, eServicio servicios[], int tamServicios);

/** \brief muestra por pantalla todos los trabajos del vector que se le pase
 *
 * \param vector de eTrabajo a recorrer
 * \param vector de servicios para cargar la descripcion
 * \param tamanio del vector de eServicio
 *
 */
void mostrarTrabajos(eTrabajo x[],int tamTrabajos,eServicio servicios[],int tamServicios);

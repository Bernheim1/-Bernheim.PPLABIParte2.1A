#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED

typedef struct
{
    int id;
    char nombreTipo[21];

} eTipo;

typedef struct
{
    int id;
    char nombreColor[21];
} eColor;

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;
} eMoto;


#endif // MOTOS_H_INCLUDED


/** \brief le da valor 1 a todas las motos del vector que se le pasa por parametro
 *
 * \param vector de eMoto a recorrer
 * \param tamanio del vector de motos
 *
 */
void inicializarMotos(eMoto vec[],int tam);

/** \brief busca en un vector de eMoto si hay un espacio con isEmpty=1
 *
 * \param vector de eMoto a recorrer
 * \param tamanio del vector a recorrer
 *
 * \return 1 si no encuentra espacio vacio,sino el indice del espacio vacio
 *
 */
int buscarLibreMoto(eMoto vec[],int tam);

/** \brief muestra la descripcion de cada tipo y su id
 *
 * \param vector de tipos donde se buscan el id y la descripcion
 * \param tamanio del vector de eTipo a recorrer
 *
 */
void mostrarDescripcionTipos(eTipo tipos[],int tamTipo);

/** \brief muestra la descripcion de cada color y su id
 *
 * \param vector de colores donde se buscan el id y la descripcion
 * \param tamanio del vector de eColor a recorrer
 *
 */
void mostrarDescripcionColores(eColor colores[],int tamColores);

/** \brief busca un espacio vacio en un vector de eMoto y le carga los datos si el usuario ingresa
 *  bien todos los campos
 *
 * \param id a asignarle a la nueva moto
 * \param vector de eMoto a utilizar para cargar la nueva moto
 * \param tamanio del vector de eMoto para recorrer
 * \param vector de tipos de motos para listar en el ingreso
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para listar en el ingreso
 * \param tamanio del vector de eColor
 *
 * \return 1 si pudo cargar los datos, -1 si no lo pudo hacer
 *
 */
int altaMoto(int idX,eMoto vec[], int tam,eTipo tipos[], int tamTipos,eColor colores[],int tamColores);

/** \brief carga la descripcion de un tipo de moto en una variable pasada por parametro
 *
 * \param vector donde se cargara la descripcion
 * \param id del tipo a buscar
 * \param vector de tipos donde buscar la descripcion
 * \param tamanio del vector de eTipo a recorrer
 *
 * \return 1 si logra cargar la descripcion, sino 0
 *
 */
int cargarDescripcionTipo(char tipo[],int id, eTipo tipos[], int tam);

/** \brief muestra todos los datos de una moto
 *
 * \param escalar de eMoto a mostrar
 * \param vector de tipos de motos para cargar la descripcion
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para cargar la descripcion
 * \param tamanio del vector de eColor
 *
 */
void mostrarMoto(eMoto x,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);

/** \brief carga la descripcion de un color de moto en una variable pasada por parametro
 *
 * \param vector donde se cargara la descripcion
 * \param id del color a buscar
 * \param vector de colores donde buscar la descripcion
 * \param tamanio del vector de eColor a recorrer
 *
 * \return 1 si logra cargar la descripcion, sino 0
 *
 */
int cargarDescripcionColor(char color[],int id, eColor colores[], int tamColores);

/** \brief muestra por pantalla todas las motos del vector que se le pase
 *
 * \param vector de eMoto a recorrer
 * \param vector de tipos de motos para cargar la descripcion
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para cargar la descripcion
 * \param tamanio del vector de eColor
 *
 */
void mostrarMotos(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);

/** \brief busca el id de una moto en un vector de eMoto
 *
 * \param	id pasado por parametro a buscar
 * \param	vector de eMoto a recorrer
 * \param	tamanio del vector a recorrer
 *
 * \return -1 si no encuentra el id en el vector, sino la posicion del id en el vector
 *
 */
int buscarMoto(int id, eMoto vec[], int tam);

/** \brief pide id de una moto para modificar uno de sus campos
 *
 * \param vector de eMoto a recorrer
 * \param tamanio del vector a recorrer
 * \param vector de tipos de motos para cargar la descripcion
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para cargar la descripcion
 * \param tamanio del vector de eColor
 *
 */
void modificarMoto(eMoto vec[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);

/** \brief	muestra el menu de opciones a modificar
 *
 * \return opcion elegida por el usuario
 *
 */
int menuModificar();

/** \brief pide el id de una moto para realizar la baja logica de la moto en el vector
 *
 * \param vector de eMoto en el que se busca el id
 * \param tamanio del vector eMoto a recorrer
 * \param vector de tipos de motos para cargar la descripcion
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para cargar la descripcion
 * \param tamanio del vector de eColor
 *
 * \return
 *
 */
void bajaMoto(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);

/** \brief  ordena las motos cargadas en el vector pasado por parametro por tipo y id y las muestra en pantalla
 *
 * \param vector de eMoto a recorrer
 * \param tamanio del vector de motos a recorrer
 * \param vector de tipos de motos para cargar la descripcion
 * \param tamanio del vector de eTipo
 * \param vector de colores de motos para cargar la descripcion
 * \param tamanio del vector de eColor
 *
 */
void listarMotos(eMoto x[],int tamMotos,eTipo tipos[],int tamTipos,eColor colores[], int tamColores);

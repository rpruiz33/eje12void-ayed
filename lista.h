#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

enum Booleanos {FALSE, TRUE};
struct NodoE;
struct listaE;

typedef struct NodoE * Nodo;

typedef struct listaE *  Lista;


Nodo crearNodo(Lista lista, void *data);
Lista crearLista( int tamDelDatoEnBytes);
int estaVacia( Lista lista);
int obtenerTamanio( Lista lista);

void* obtenerDato( Lista lista, int pos);
void* obtenerPrimerDato( Lista lista);
void* obtenerUltimoDato( Lista lista);

int obtenerDatoEnParametro( Lista lista, int pos, void *backup);
int insertar(Lista lista, void *data, int pos);
int insertarInicio(Lista lista, void *data);
int insertarFinal(Lista lista, void *data);
int removerInicio(Lista lista, void *backup);
int removerFinal(Lista lista, void *backup);
int remover(Lista lista, int pos, void *backup);
void liberarlista(Lista lista);

void ordenarXnombre( Lista lista);
int busqueda(Lista lista, char busco[20]);

Lista getListaTamanio(Lista l);
Nodo getListaPrimero(Lista l);
int getListaTamByte(Lista l);
Nodo getListaUltimo(Lista l);
void setData(Nodo n,void* data);
void *getData(Nodo n);
Nodo getSiguiente(Nodo n);
Nodo getAnterior(Nodo n);
Nodo getNodo(Lista lista, int indice);
void setSiguiente(Nodo nodo, Nodo siguiente);

#endif // LISTA_H_INCLUDED

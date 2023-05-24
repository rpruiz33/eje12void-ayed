#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "factura.h"
#include "cliente.h"
#include "detalle.h"
#include "producto.h"
enum {MEMORIA_LLENA= (-1), OK=1};

struct NodoE {
    void  * data;
    Nodo siguiente;
    Nodo anterior;
};

struct listaE{
    Nodo primero;//Igual
    Nodo ultimo;  //Opci�n
    int tamanio;  //igual
    int tamDelDatoEnBytes; ///NUEVO!!!!!
};



Nodo crearNodo(Lista lista, void * data) {

    Nodo temp =  malloc(sizeof (struct NodoE));

    //if (!temp) return FALSE;

    ///temp->data = data

    temp->data = malloc(lista->tamDelDatoEnBytes);

    if (!temp->data) {
        free(temp);
        return temp;
    }


   ///Analizar
    memcpy(temp->data, data, lista->tamDelDatoEnBytes);

    temp->data = data ;

    return temp;
}

/*Nodo crearNodo (Lista lista, void * data) {

}
/*
Lista crearLista( int tamDelDatoEnBytes){

Lista l = malloc (sizeof(struct listaE));
l->primero=l->ultimo=NULL;

  l->tamDelDatoEnBytes = tamDelDatoEnBytes;




return l;

};
*/
Lista crearLista( int tamDelDatoEnBytes) {

    Lista lista = malloc(sizeof(struct listaE));



    lista->primero = lista->ultimo = NULL;
    lista->tamanio = 0;
    lista->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return lista;
}
int insertar (Lista lista, void *data, int pos) {

    if (!lista || pos < 0 || pos > lista->tamanio) // lista nula ou posi��o inv�lida
        return FALSE;

   /* if (pos == 0) // Insere na primeira posi��o
        return insertarInicio(lista, data);

    if (pos == lista->tamanio) // Insere na �ltima posi��o
        return removerFinal(lista, data);

    // Insere no meio
*/
    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->siguiente;
    }
    // Nesse momento 'f' aponta para a posi��o anterior � que ser� inserido o elemento

    Nodo temp;
    if (!(temp = crearNodo(lista, data)))
        return FALSE;

    temp->siguiente = f->siguiente;
    f->siguiente = temp;
    lista->tamanio++;
    return TRUE;
}
void* obtenerDato (Lista lista, int pos) {
    if (!lista || pos < 0 || lista->tamanio <= 0 || pos >= lista->tamanio)
        return NULL;

    if (pos == 0)
        return lista->primero->data;

    if (pos == lista->tamanio - 1)
        return lista->ultimo->data;

    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->siguiente;
    }

    return f->siguiente->data;
}

void setSiguiente(Nodo nodo, Nodo siguiente) {
    nodo->siguiente = siguiente;
}
void setListaPrimero(Lista lista, Nodo nodo) {
    lista->primero = nodo;
}


Lista getListaTamanio(Lista l){

return l->tamanio;
}
Nodo getListaPrimero(Lista l){

return l->primero;
}
int getListaTamByte(Lista l){

return l->tamDelDatoEnBytes;
}

Nodo getListaUltimo(Lista l){

return l->ultimo;
}

void setData(Nodo n,void* data){
n->data=data;

};
void* getData(Nodo n){
return n->data;

};
Nodo getSiguiente(Nodo n){
return n->siguiente;
};
Nodo getAnterior(Nodo n){
return n->anterior;
};

Nodo getNodoAnterior(Nodo n){

return n->anterior;
}
int insertarFinal (Lista lista, void *data) {
    Nodo temp;
    if (!(temp = crearNodo(lista, data)))
        return FALSE;

    if (lista->tamanio == 0) {
        lista->primero = lista->ultimo = temp;
        temp->siguiente = NULL;
        lista->tamanio++;
        return TRUE;
    } else {
        lista->ultimo->siguiente = temp;
        lista->ultimo = temp;
        lista->ultimo->siguiente = NULL;
    }
}
int insertarInicio (Lista lista, void *data) {
    Nodo temp;
    if (!(temp = crearNodo(lista, data)))
        return FALSE;

    if (lista->tamanio == 0) {
        lista->primero = lista->ultimo = temp;
        temp->siguiente= NULL;
        lista->tamanio++;
        return TRUE;
    }

    temp->siguiente = lista->primero;
    lista->primero = temp;
    lista->tamanio++;

    return OK;
}



int removerInicio (Lista lista, void *backup) {
	if (lista->tamanio == 0)
		return FALSE;
    else if (lista->tamanio == 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        //liberarlista(lista); // Portanto, apenas limpe a lista!
    } else {
        Nodo proximoCpy = lista->primero->siguiente;
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);

        free(lista->primero->data);
        free(lista->primero);
        lista->primero = proximoCpy;
        lista->tamanio--;
    }
    return OK;
}


int removerFinal (Lista lista, void *backup) {
    if (!lista)
        return FALSE;

    // Se a lista tiver apenas 1 elemento
    if (lista->tamanio == 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        liberarlista(lista);
    }
    // A lista possui mais de um elemento
    else {
        Nodo f = NULL, ultimo = NULL;
        memcpy(backup, lista->ultimo->data, lista->tamDelDatoEnBytes);

        // Percorre a lista at� encontrar o pen�ltimo elemento da lista
        for (f = lista->primero; f != lista->ultimo; f = f->siguiente)
            ultimo = f;

        // Nesse momento 'ultimo' aponta para o pen�ltimo elemeto da lista

        free(lista->ultimo->data); // Remove o dado do �ltimo elemento
        free(lista->ultimo); // Remove o �ltimo elemento
        lista->ultimo = ultimo; // Agora o �ltimo elemento se torna 'ultimo'
        lista->ultimo->siguiente = NULL; // Portanto ultimo->proximo deve ser NULL
        lista->tamanio--;
    }
    return OK;
}



int remover (Lista lista, int pos, void *backup) {

    if (!lista || lista->tamanio<= 0 || pos < 0 || pos >= lista->tamanio) // lista vazia ou nula ou posi��o inv�lida
        return FALSE;

    // Remove da �ltima posi��o
    if (pos == lista->tamanio - 1)
        return removerFinal(lista, backup);

    // O usi�rio deseja remover um elemento do in�cio
    if (pos == 0)
        return removerInicio(lista, backup);

    // Remover algum elemento no MEIO da lista
    Nodo f = NULL, proximoCpy;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->siguiente;
    }
    // Nesse momento 'f' aponta para o elemento anterior ao que ser� removido

    proximoCpy = f->siguiente->siguiente; // 'proximoCpy' aponta para o elemento posterior ao que ser� removido
    memcpy(backup, f->siguiente->data, lista->tamDelDatoEnBytes);

    free(f->siguiente->data); // Remove o VALOR do elemento (C�lula) entre 'f' e 'proximoCpy', que pertence justamente o elemento que o usu�rio deseja remover
    free(f->siguiente); // Remove o ELEMENTO entre 'f' e 'proximoCpy', que � justamente o elemento que o usu�rio deseja remover
    f->siguiente = proximoCpy; // Portanto lique 'f' em 'proximoCpy'
    lista->tamanio--;
    return OK;
}

void liberarlista (Lista lista) {
    if (!lista || lista->tamanio <= 0 || lista->primero == NULL)
        return;

    // 'curr' iniciar� apontando para o primeiro elemento da lista e proximo para o segundo
    // (que pode ser nulo caso a lista possua apenas um elemento)

    Nodo proximo;
    for ( Nodo p = lista->primero; p != NULL;) {
        proximo = p->siguiente;
        free(p->data);
        free(p);
        p = proximo;
    }

    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->tamanio= 0;
}

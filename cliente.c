#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
struct ClienteE{
int dni;
char nombre[30];
};

ClienteP crearCleinte(int dni, char nombre[30]){
ClienteP c= malloc(sizeof(struct ClienteE));
c->dni=dni;
strcpy(c->nombre,nombre);

return c;
};
void destruirCliente(ClienteP c){
free(c);

};
void mostrarCliente(ClienteP c){
printf("\n-------------cliente-----------------\n");
printf("\nel dni es %d\nel nombre es %s\n",c->dni,c->nombre);
};

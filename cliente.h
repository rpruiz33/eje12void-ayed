#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct ClienteE;
typedef struct ClienteE* ClienteP;
ClienteP crearCleinte(int dni, char nombre[30]);
void destruirCliente(ClienteP c);
void mostrarCliente(ClienteP c);

#endif // CLIENTE_H_INCLUDED

#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED
#include "lista.h"
struct FacturaE;

typedef struct FacturaE * FacturaP;

FacturaP crearFactura(int numero, char fecha[30]);

void destruirFactura(FacturaP f);

void mostrarFactura(FacturaP f);

void mostrarLista(Lista lista);
#endif // FACTURA_H_INCLUDED

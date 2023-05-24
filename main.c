#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "factura.h"
#include "cliente.h"
#include"detalle.h"
#include "producto.h"
#include "lista.h"
int main()
{

      void *backup;
    Lista listaE = crearLista(sizeof(FacturaP));
    printf("LISTA DE EDIFICIOS-SIMPLE ENLACE-VOID");
    int tam=obtenerTamanio(listaE);
    FacturaP x[tam];
     x[0] = crearFactura(12,"12-12-14");

    insertarFinal(listaE, &x[0]);
    x[1] = crearFactura(12,"12-12-15");

    insertarInicio(listaE, &x[1]);
    mostrarLista(listaE);
    printf("-------------------");
    return 0;
}

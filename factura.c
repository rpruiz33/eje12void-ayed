#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "factura.h"
#include "cliente.h"
#include "detalle.h"
#include "producto.h"
#include "lista.h"
struct FacturaE{
int numero;
char fecha[30];

ClienteP c;
DetalleP d[10];
};


FacturaP crearFactura(int numero, char fecha[30]){
FacturaP f=malloc(sizeof(struct FacturaE));
strcpy(f->fecha,fecha);
f->numero=numero;
f->c = crearCleinte(123456,"roberto");

 for(int i=0;i<10;i++){
    f->d[i]=crearDetalle(123,"qasqs",12,12.3);
 }
return f;
};

void destruirFactura(FacturaP f){
free(f);
};

void mostrarFactura(FacturaP f){
mostrarCliente(f->c);
printf("\n-------------factura-----------------\n");
printf("\nnumero es %d y la fecha es %s\n",f->numero,f->fecha);

for (int i=0;i<10;i++){
mostrarDetalle(f->d[i]);
}
}

void mostrarLista(Lista lista){

    for ( int i = 0; i< obtenerTamanio(lista); i++){

        FacturaP info = * ((FacturaP*) obtenerDato(lista, i));

        mostrarCliente(info->c);
printf("\n-------------factura-----------------\n");
printf("\nnumero es %d y la fecha es %s\n",info->numero,info->fecha);

for (int i=0;i<10;i++){
mostrarDetalle(info->d[i]);
}


    }

}
int obtenerTamanio ( Lista lista) {
    if (!lista)
        return -1;
    return getListaTamanio(lista);
}

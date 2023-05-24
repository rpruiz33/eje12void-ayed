#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "detalle.h"
#include "factura.h"
#include "cliente.h"
#include "detalle.h"
#include "producto.h"
struct DetalleE{
int nroDetalle;
ProductoP p;
int cantidad;
float precio;
float precioTotal;

};

DetalleP crearDetalle(int nroDetalle,char producto[30], int cantidad,float precio){
DetalleP d=malloc(sizeof(struct DetalleE));
d->cantidad=cantidad;

d->precio=precio;
d->precioTotal=precio*cantidad;
d->p=crearPro("asdasd",123,"asdas",22);
d->nroDetalle=nroDetalle;


return d;

};
void destruirDetalle(DetalleP d){
free(d);
};
void mostrarDetalle(DetalleP d){
printf("\n-------------detalle-----------------\n");
mostrar(d->p);
printf("\nel nro de detalle es %d\nla cantidad es %d\nel precio es %f\nel precioTotal es %f, producto:%s\n ",d->nroDetalle,d->cantidad,d->precio,d->precioTotal,d->p);

};

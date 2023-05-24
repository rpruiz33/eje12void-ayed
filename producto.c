#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "factura.h"
#include "cliente.h"
#include "detalle.h"
#include "producto.h"
struct ProductoE{
char nombre[30];
float precio;
char codigo[30];
int cantidadDisponible;
};

ProductoP crearPro(char nombre[30], float precio, char codigo[30],int cantidadDisponible){
ProductoP p= malloc(sizeof(struct ProductoE));
p->cantidadDisponible=cantidadDisponible;
p->precio=precio;
strcpy(p->nombre,nombre);
strcpy(p->codigo,codigo);
return p;


};
void destruirProducto(ProductoP p){

free(p);

};
void mostrar (ProductoP p){
printf("\nproducto----------------->\n");
printf("\nel nombre del producto  es %s\n",p->nombre);
printf("e codigo es %s\n",p->codigo);
printf("el precio del producto  es %f\n",p->precio);
printf("la cantidad disponible es %d",p->cantidadDisponible);
};
void setNombre(ProductoP p, char nombre[30]){

     strcpy(p->nombre,nombre);

}

#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED


struct ProductoE;
typedef struct ProductoE * ProductoP;
ProductoP crearPro(char nombre[30], float precio, char codigo[30],int cantidadDisponible);
void destruirProducto(ProductoP p);
void mostrar (ProductoP p);
void setNombre(ProductoP p,char nombre[20]);
#endif // PRODUCTO_H_INCLUDED

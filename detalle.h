#ifndef DETALLE_H_INCLUDED
#define DETALLE_H_INCLUDED


struct DetalleE;
typedef struct DetalleE * DetalleP;
DetalleP crearDetalle(int nroDetalle,char producto[30],int cantidad,float precio);

void destruirDetalle(DetalleP d);
void mostrarDetalle(DetalleP d);

#endif // DETALLE_H_INCLUDED

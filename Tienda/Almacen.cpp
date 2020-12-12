#include "Almacen.h"

bool Almacen::ModificarInventarioArticulo(Articulo* artPtr, int cantidad)
{
	for (int i = 0; i < articulos.size(); ++i) {
		if ((*artPtr).nombre == articulos[i].articulo->nombre) {
			int total = cantidad + articulos[i].cantidad;
			if (total < 0) {
				return false;
			}
			else {
				articulos[i].cantidad = articulos[i].cantidad + cantidad;
				return true;
			}
		}
	}
	if (cantidad <= 0) {
		return false;
	}
	else {
		ArticuloAlmacenado art;
		art.articulo = artPtr;
		art.cantidad = cantidad;
		articulos.push_back(art);
		return true;
	}
    /*ArticuloAlmacenado artic;
    artic.articulo = artPtr;
    artic.cantidad = cantidad;
	int total = 0;
	int aux = 0;
	string nombre = "";
	string x = artPtr->nombre;
	for (int i = 0; i < articulos.size(); i++) {
		nombre = articulos[i].articulo->nombre;
		if (nombre == artic.articulo) {
			
        }
        else {
            articulos.push_back(artic);
        }
	}
	total = cantidad + artic.cantidad;
	if (total < 0) {
		return false;
	}
	else {
		artic.cantidad = total;
		return true;
	}*/
}

string Almacen::ObtenerNombre() const
{
	return nombre;
}

string Almacen::ObtenerInventario() const
{
	string invStr = "";
	invStr.append("\nArticulo\tCantidad\n");
	for (int i = 0, n = articulos.size(); i < n; i++)
	{
		invStr.append(articulos[i].articulo->nombre);
		invStr.append("\t");
		invStr.append(to_string(articulos[i].cantidad));
		invStr.append("\n");
	}
	return invStr;
}

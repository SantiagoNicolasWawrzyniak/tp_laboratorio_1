/*
 * funciones.h
 *
 *  Created on: 16 abr. 2022
 *      Author: Santi
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int pedirDatos();
int ingresarKilometros();
int ingresarPrecioVueloAerolineas();
int ingresarPrecioVueloLatam();
float calcularCosto(char tipo, int precio);
float calcularBitcoin(int precio);
void cargaForzadaDeDatos();

#endif /* FUNCIONES_H_ */

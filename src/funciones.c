/*
 * funciones.c
 *
 *  Created on: 16 abr. 2022
 *      Author: Santi
 */
#include <stdio.h>
#include "funciones.h"

//FUNCIONES

//Funcion para pedir datos (Menu principal)

int pedirDatos(int opcion)
{
	printf("1. Ingresar kilometros:\n");
	printf("2. Ingresar Precio de Vuelos:\n");
	printf("3. Calcular todos los costos:\n");
	printf("4. Informar resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	printf("Opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

//Funcion para ingresar la cantidad de kilometros (Opcion 1)

int ingresarKilometros()
{
	int kilometros;
	printf("Ingrese kilometros: ");
	scanf("%d", &kilometros);
	fflush(stdin);

	return kilometros;
}

//Funcion para ingresar el precio del vuelo de Aerolineas (Opcion 2.1)

int ingresarPrecioVueloAerolineas()
{
	int precioAerolineas;
	printf("Ingrese precio de Aerolineas: ");
	scanf("%d", &precioAerolineas);
	fflush(stdin);

	return precioAerolineas;
}

//Funcion para ingresar el precio del vuelo de Latam (Opcion 2.2)

int ingresarPrecioVueloLatam()
{
	int precioLatam;
	printf("Ingrese precio de Latam: ");
	scanf("%d", &precioLatam);
	fflush(stdin);

	return precioLatam;
}

//Función  que calcula el costo dependiendo del tipo (Débito, Crédito), precio (de cada aerolinea), y la aerolinea
float calcularCosto(char tipo, int precio)
{
	int valor; float resultado;

	if (tipo == 'D')
	{
		valor = (precio * 0.10);
		resultado = precio - valor;
	}
	if (tipo == 'C')
	{
		valor = (precio * 0.25);
		resultado = precio + valor;
	}
	if (tipo == 'B')
	{
		resultado = calcularBitcoin(precio);
	}

	return resultado;
}

float calcularBitcoin(int precio){
	float valorBitcoin = 4606954.55;

	return precio / valorBitcoin;
}

//Funcion para cargar datos de manera forzada (Opcion 5)

void cargaForzadaDeDatos()
{
	int km = 7090;
	float precioY = 1335000.66;
	float precioZ = 1350000.76;
	float precioTarjetaDebito;
	float precioTarjetaCredito;
	float precioBitcoin;
	float precioUnitario;
	float diferencia;


	printf("KMs ingresados: %d km \n\n", km);

	printf("Precio Aerolineas: $%.2f \n", precioY);

	precioTarjetaDebito = calcularCosto('D',precioY);
	printf("a) Precio con tarjeta de debito: $%.2f \n",precioTarjetaDebito);

	precioTarjetaCredito = calcularCosto('C', precioY);
	printf("b) Precio con tarjeta de credito: $%.2f \n", precioTarjetaCredito);

	precioBitcoin = calcularCosto('B', precioY);
	printf("c) Precio pagando con bitcoin: %.2f BTC \n", precioBitcoin);

	precioUnitario = precioY / km;
	printf("d) Precio unitario: $%.2f \n\n", precioUnitario);

	printf("Precio Latam: $%.2f \n", precioZ);

	precioTarjetaDebito = calcularCosto('D',precioZ);
	printf("a) Precio con tarjeta de debito: $%.2f \n",precioTarjetaDebito);

	precioTarjetaCredito = calcularCosto('C', precioZ);
	printf("b) Precio con tarjeta de credito: $%.2f \n", precioTarjetaCredito);

	precioBitcoin = calcularCosto('B', precioZ);
	printf("c) Precio pagando con bitcoin: %.2f BTC \n", precioBitcoin);

	precioUnitario = precioZ / km;
	printf("d) Precio unitario: $%.2f \n\n", precioUnitario);

	diferencia = precioZ - precioY;
	printf("La diferencia de precio es: $%.2f \n", diferencia);
}

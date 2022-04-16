/*
 ============================================================================
 Name        : TP_1.c
 Author      : Santiago Nicolas, Wawrzyniak
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int pedirDatos();
int ingresarKilometros();
int ingresarPrecioVueloAerolineas();
int ingresarPrecioVueloLatam();
float calcularCosto(char tipo, int precio);
float calcularBitcoin(int precio);
void cargaForzadaDeDatos();

int main(void)
{
	//Declaracion de variables

	setbuf(stdout, NULL);
	int opcion = 0, kilometros, precioAerolineas, precioLatam;
	int descuentoDebitoAerolineas, descuentoDebitoLatam, interesCreditoAerolineas, interesCreditoLatam;
	float precioUnitarioAerolineas, precioUnitarioLatam, bitcoinAerolineas, bitcoinLatam;
	int diferencia;

	// Menu de opciones

	while(opcion != 6)
	{
		printf("1. Ingresar kilometros:\n");
		printf("2. Ingresar Precio de Vuelos:\n");
		printf("3. Calcular todos los costos:\n");
		printf("4. Informar resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		printf("Opcion: \n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				kilometros = ingresarKilometros();
				printf("Usted ingresó %d km. \n\n", kilometros);
				break;

			case 2:
				precioAerolineas = ingresarPrecioVueloAerolineas();
				precioLatam = ingresarPrecioVueloLatam();
				break;

			case 3:
				descuentoDebitoAerolineas = calcularCosto('D',precioAerolineas);
				descuentoDebitoLatam = calcularCosto('D',precioLatam);
				interesCreditoAerolineas = calcularCosto('C',precioAerolineas);
				interesCreditoLatam = calcularCosto('C',precioLatam);
				bitcoinAerolineas = calcularCosto('B',precioAerolineas);
				bitcoinLatam = calcularCosto('B',precioLatam);
				precioUnitarioAerolineas = precioAerolineas / kilometros;
				precioUnitarioLatam = precioLatam / kilometros;
				diferencia = precioLatam - precioAerolineas;
				printf("Los costos han sido calculados exitosamente. \n");
				break;

			case 4:
				printf("Aerolineas: $%d \n\n", precioAerolineas);
				printf("a) Precio con tarjeta de debito: $ %d \n", descuentoDebitoAerolineas);
				printf("b) Precio con tarjeta de credito: $ %d \n", interesCreditoAerolineas);
				printf("c) Precio pagando con bitcoin: %.2f BTC \n", bitcoinAerolineas);
				printf("d) Precio unitario: $ %.2f \n\n", precioUnitarioAerolineas);
				printf("Latam: $%d \n\n", precioLatam);
				printf("a) Precio con tarjeta de debito: $ %d \n", descuentoDebitoLatam);
				printf("b) Precio con tarjeta de credito: $ %d \n", interesCreditoLatam);
				printf("c) Precio pagando con bitcoin: %.2f BTC \n", bitcoinLatam);
				printf("d) Precio unitario: $ %.2f \n\n", precioUnitarioLatam);
				printf("La diferencia de precio es: $%d \n", diferencia);
				opcion = 6;
				break;

			case 5:
				cargaForzadaDeDatos();
				opcion = 6;
				break;

			case 6:
				break;

			default:
				printf("Error, ingrese una opcion valida. \n");
		}
	}
	return EXIT_SUCCESS;
}

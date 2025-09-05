#include "Robot.h"
#include "RobotMecanico.h"
#include "RobotExplorador.h"

void menu() {
	Robot* robot;
    int opcion = 0, tipoMec = 0, bat = 0, proce = 0, potHerramientas = 0, cantHerramientas = 0, alcance = 0, cantSen = 0;
	string nom = " ", herramienta = " ";
	do{
		cout << "---FABRICA DE ROBOTS---\n";
		cout << "1. Crear Robot\n";
		cout << "2. Listar Robots\n";
		cout << "3. Optimizar Robot\n";
		cout << "4. Mostrar Especificamente\n";
		cout << "5. Diagnostico General\n";
		cout << "6. Salir\n";
		cout << "Seleccione una opicion: "; cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Elegir tipo: (1. Mecanico, 2. Explorador)"; cin >> tipoMec;
			if (tipoMec >= 1 && tipoMec <= 2){
				cout << "Nombre :"; cin >> nom;
				cout << "Bateria(1-10): "; cin >> bat;

				if (bat >= 1 && bat <= 10){
					cout << "Procesador(1-10): "; cin >> proce;

					if (proce >= 1 && proce <= 10){
						if (tipoMec == 1){
							cout << "Potencia herramientas: "; cin >> potHerramientas;
							cout << "Cantidad herramientas: "; cin >> cantHerramientas;
							robot = new RobotMecanico(nom, bat, proce, potHerramientas, cantHerramientas);
							cout << "Robot Mecanico creado con exito!!\n\n";														

						}else{
							cout << "Alcance: "; cin >> alcance;
							cout << "Cantidad de Sensores: "; cin >> cantSen;
							robot = new RobotExplorador(nom, bat, proce, alcance, cantSen);
							cout << "Robot Explorador creado con exito!!\n\n";
						}

					}else {
						cout << "Opcion invalida\n";
					}
				}else {
					cout << "Opcion invalida\n";
				}
			}else {
				cout << "Opcion invalida\n";
			}
			

			menu();
			break;

		case 2:
			menu();
			break;

		case 3:
			menu();
			break;

		case 4:
			menu();
			break;

		case 5:
			menu();
			break;

		case 6:
			cout << "Saliendo del programa...\n";
			exit(0);
			break;

		default: cout << "Opcion invalida...\n\n";
			menu();
			break;
		}
	} while (opcion != 6);
}
int main(){
    menu();
}
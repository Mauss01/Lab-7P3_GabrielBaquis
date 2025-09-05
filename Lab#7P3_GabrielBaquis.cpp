#include "Robot.h"
#include "RobotMecanico.h"
#include "RobotExplorador.h"

void menu() {
	Robot* robot;
    int opcion = 0, tipoMec = 0, bat = 0, proce = 0, potHerramientas = 0, cantHerramientas = 0, alcance = 0, cantSen = 0, seleccion = 0;
	string nom = " ", herramienta = " ";
	vector<Robot*> robots;

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
							cout << "Robot Mecanico \"" << nom << "\" creado con exito!!\n\n";														
							robots.push_back(robot);

						}else{
							cout << "Alcance: "; cin >> alcance;
							cout << "Cantidad de Sensores: "; cin >> cantSen;
							robot = new RobotExplorador(nom, bat, proce, alcance, cantSen);
							cout << "Robot Explorador \"" << nom << "\" creado con exito!!\n\n";
							robots.push_back(robot);

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
			if (robots.empty()){
				cout << "\nCrea robots primero para verlos\n";
			}else {
				cout << "----ROBOTS----\n";
				for (int i = 0; i < robots.size(); i++) {
					cout << i << ". "; robots[i]->mostrarEspecificaciones();
				}
				cout << endl;
			}			
			menu();
			break;

		case 3:
			if (robots.empty()) {
				cout << "\nCrea robots primero para optimizarlos\n";
			}else {
				cout << "----ROBOTS----\n";
				for (int i = 0; i < robots.size(); i++) {
					cout << i << ". "; robots[i]->getNombre(); cout << endl;
				}
				cout << "Seleccione un robot: "; cin >> seleccion;
				if (seleccion < 0 && seleccion > robots.size()){
					cout << "Opcion invalida\n";
				}else {
					robots[seleccion]->optimizar();
					cout << "Robot "; robots[seleccion]->getNombre(); cout << " optimizado correctamente\n";
				}
				cout << endl;
			}
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
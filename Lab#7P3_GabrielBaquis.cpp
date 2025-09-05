#include "Robot.h"
#include "RobotMecanico.h"
#include "RobotExplorador.h"

// utils.h es el metodo template 

void menu(vector<Robot*> &robots) {
	Robot* robot;
    int opcion = 0, tipoMec = 0, bat = 0, proce = 0, potHerramientas = 0, cantHerramientas = 0, alcance = 0, cantSen = 0, seleccion = 0;
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
			cout << "Elegir tipo (1. Mecanico, 2. Explorador): "; cin >> tipoMec;
			if (tipoMec >= 1 && tipoMec <= 2){
				cout << "Nombre: "; cin.ignore(); getline(cin, nom);
				cout << "Bateria(1-10): "; cin >> bat;

				if (bat >= 1 && bat <= 10){
					cout << "Procesador(1-10): "; cin >> proce;

					if (proce >= 1 && proce <= 10){
						if (tipoMec == 1){
							cout << "Potencia herramientas (max 100): "; cin >> potHerramientas;
							if (potHerramientas > 0 && potHerramientas <= 100){
								cout << "Cantidad herramientas: "; cin >> cantHerramientas;								
								robot = new RobotMecanico(nom, bat, proce, potHerramientas, cantHerramientas);								
								robots.push_back(robot);
								cout << "Robot Mecanico \"" << nom << "\" creado con exito!!\n\n";

							}else {
								cout << "\nOpcion invalida\n\n";
							}							
						}else{
							cout << "Alcance (max 100): "; cin >> alcance;
							if (alcance > 0 && alcance <= 100) {
								cout << "Cantidad de Sensores: "; cin >> cantSen;
								robot = new RobotExplorador(nom, bat, proce, alcance, cantSen);								
								robots.push_back(robot);
								cout << "Robot Explorador \"" << nom << "\" creado con exito!!\n\n";

							}else {
								cout << "\nOpcion invalida\n\n";
							}							
						}
					}else {
						cout << "\nOpcion invalida\n\n";
					}
				}else {
					cout << "\nOpcion invalida\n\n";
				}
			}else {
				cout << "\nOpcion invalida\n\n";
			}			
			menu(robots);
			break;

		case 2:
			if (robots.empty()){
				cout << "\nCrea robots primero para verlos\n\n";
			}else {

				cout << "\n----ROBOTS----\n";
				for (int i = 0; i < robots.size(); i++) {
					robots[i]->mostrarEspecificaciones();
				}
				cout << endl;
			}			
			menu(robots);
			break;

		case 3:
			if (robots.empty()) {
				cout << "\nCrea robots primero para optimizarlos\n\n";
			}else {

				cout << "\n----ROBOTS----\n";
				for (int i = 0; i < robots.size(); i++) {
					cout << i << ". "<< robots[i]->getNombre() << endl;
				}

				cout << "Seleccione un robot: "; cin >> seleccion;

				if (seleccion < 0 && seleccion > robots.size()){
					cout << "Opcion invalida\n\n";
				}else {
					robots[seleccion]->optimizar();
					cout << "Robot \"" << robots[seleccion]->getNombre() << "\" optimizado correctamente\n\n";
				}
				cout << endl;
			}
			menu(robots);
			break;

		case 4:
			if (robots.empty()) {
				cout << "\nCrea robots primero para mostrarlos\n\n";
			}else {

				cout << "\n----ROBOTS----\n";
				for (int i = 0; i < robots.size(); i++) {
					cout << i << ". " << robots[i]->getNombre() << endl;
				}
				cout << "Seleccione un robot: "; cin >> seleccion;
				if (seleccion < 0 && seleccion > robots.size()) {
					cout << "Opcion invalida\n\n";
				}else {
					robots[seleccion]->mostrarEspecificaciones();
				}
				cout << endl;
			}
			menu(robots);
			break;

		case 5:
			if (robots.empty()) {
				cout << "\nCrea robots primero para hacer un diagnostico general\n\n";
			}else {
				
				for (int i = 0; i < robots.size(); i++) {
					RobotExplorador* re = dynamic_cast<RobotExplorador*>(robots[i]); //valida si es de la clase derivada adecuada
					if (re && re->necesitaMantenimiento()) {
						cout << "[MAL ESTADO] " << re->getNombre() << " muchos sensores con baja sensibilidad\n";
					}else {
						cout << "[OK] " << re->getNombre() << " no necesita mantenimiento\n";
					}

					RobotMecanico* rm = dynamic_cast<RobotMecanico*>(robots[i]);
					if (rm && rm->sobrecargado()) {
						cout << "[DESCARGADO] " << re->getNombre() << " tiene bateria baja\n";
					}else {
						cout << "[OK] " << re->getNombre() << " no esta sobrecargado\n";
					}					
				}
				cout << endl;
			}
			menu(robots);
			break;

		case 6:
			cout << "Saliendo del programa...\n\n";
			exit(0);
			break;

		default: cout << "Opcion invalida...\n\n";
			menu(robots);
			break;
		}
	} while (opcion != 6);
}
int main(){
	vector<Robot*> robots;
    menu(robots);
}
#include<iostream>
#include<string>
using namespace std;

struct contactoEmai{
	string nombre;
	char sexo;
	int edad;
	int telefono;
	string email;
	string nacionalidad;
};

void menu(){
	char opcion;
	
	cout << "            ---------------MENU PRINCIPAL---------------\n" << endl;
	
	do{
		cout << "\n ---------------------------------------------------------------------\n";
		cout << "  a) Agregar contacto" << endl;
		cout << "  b) Eliminar un contacto" << endl;
		cout << "  c) Mostrar listado general de contactos registrados hasta el momento" << endl;
		cout << "  d) Mostrar listado de contactos existentes\n";
		cout << "     ordenado por servidor de correo de las cuentas\n";
		cout << "     (gmail.com, outlook.com, yahoo.com, etc.)" << endl;
		cout << "  e) Salir del programa" << endl;
		cout << " ---------------------------------------------------------------------\n";

		cout << "\n  Eliga una opcion: ";
		cin >> opcion;
	
		switch (opcion){
			case 'a':
				//agregarcontacto();
				break;
			case 'b':
				//eliminarContacto();
				break;
			case 'c':
				//MostrarlistaGeneral();
				break;
			case 'd':
				//MostrarListaOrdenadaPorServidor();
				break;
			case 'e':
				cout << "\n -----------------------------------------";
				cout << "\n  GRACIAS POR USAR MI PROMGRAMA <3!" << endl;
				cout << "\n  Saliendo del programa ..." << endl;
				cout << "  PROGRAMA FINALIZADO!" << endl;
				break;
			default:
				cout << "\n  INVALIDO, porfavor ingrese una opcion valida\n" << endl;
				break;
		}		
	}while (opcion != 'e');

}

int main(){
	menu();
	
	return 0;
}
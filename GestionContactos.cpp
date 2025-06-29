#include<iostream>
#include<string>
using namespace std;

struct contactoEmail{
	string nombre;
	char sexo;
	int edad;
	int telefono;
	string email;
	string nacionalidad;
};

void agregarContacto(contactoEmail Contacto[], int &cantidad){
	
	cout << "\nIngrese datos del nuevo contacto:\n" << endl;
	cout << "NOMBRE COMPLETO: ";
	cin.ignore();
	getline(cin, Contacto[cantidad].nombre);
	
	cout << "Sexo (M/F): ";
	cin >> Contacto[cantidad].sexo;
	
	cout << "Edad: ";
	cin >> Contacto[cantidad].edad;
	
	cout << "Telefono: ";
    cin >> Contacto[cantidad].telefono;

    cout << "Email: ";
    cin >> Contacto[cantidad].email;

    cout << "Nacionalidad: ";
    cin.ignore(); // limpiar buffer otra vez
    getline(cin, Contacto[cantidad].nacionalidad);
    
    cantidad++;
	
}

void menu(){
	char opcion;
	const int TAM = 100;
	contactoEmail guardarContacto[TAM];
	int cantidadContactos = 0;
	
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
				agregarContacto(guardarContacto, cantidadContactos);
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
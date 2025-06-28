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
	
	cout << " --------MENU PRINCIPAL--------\n" << endl;
	cout << "  a) Agregar contacto" << endl;
	cout << "  b) Eliminar un contacto" << endl;
	cout << "  c) Mostrar listado general de contactos registrados hasta ese momento" << endl;
	cout << "  d) Mostrar listado de contactos existentes\n";
	cout << "     ordenado por servidor de correo de las cuentas\n";
	cout << "     (gmail.com, outlook.com, yahoo.com, etc.)" << endl;
	cout << "  e) Salir del programa" << endl;
	cout << "\n  Eliga una opcion: ";
	cin >> opcion;

}

int main(){
	menu();
}
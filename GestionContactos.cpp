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
	
	cout << "\nIngrese datos del nuevo contacto " << cantidad + 1 << ": \n" << endl;
	cout << "Nombre completo: ";
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

void eliminarContacto(contactoEmail guardarContacto[], int &cantidad){
    int indice;

    cout << "\nIngrese el numero del contacto que desea eliminar (1 a " << cantidad << "): ";
    cin >> indice;

    if (indice > 0 && indice <= cantidad) {
        // Mover los contactos siguientes una posición hacia arriba
        for (int i = indice - 1; i < cantidad - 1; i++) {
            guardarContacto[i] = guardarContacto[i + 1];
        }

        cantidad--;

        cout << "\nContacto eliminado\n";
    } else {
        cout << "\nNumero invalido, no se encontro el contacto\n";
    }

}

void MostrarlistaGeneral(contactoEmail contactos[], int cantidad){
	
	cout << "\nLISTA DE CONTACTOS REGISTRADOS:\n";
	if (cantidad != 0){

	    for (int i = 0; i < cantidad; i++) {
	    	
	        cout << "\nContacto #" << (i + 1) << ":\n";
	        cout << "  Nombre: " << contactos[i].nombre << endl;
	        cout << "  Sexo: " << contactos[i].sexo << endl;
	        cout << "  Edad: " << contactos[i].edad << endl;
	        cout << "  Telefono: " << contactos[i].telefono << endl;
	        cout << "  Email: " << contactos[i].email << endl;
	        cout << "  Nacionalidad: " << contactos[i].nacionalidad << endl;
	    }
	}else {
        cout << "\nNo se agrego ningun contacto todavia..." << endl;
    }
}

string obtenerDominio(string email) {
    string dominio = "";
    bool arroba = false;
    int i = 0;

    while (email[i] != '\0') {
        if (arroba) {
            dominio += email[i];
        }
        if (email[i] == '@') {
            arroba = true;
        }
        i++;
    }

    return dominio;
}

void ordenarPorDominio(contactoEmail contactos[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - 1 - i; j++) {
            string dominio1 = obtenerDominio(contactos[j].email);
            string dominio2 = obtenerDominio(contactos[j + 1].email);

            if (dominio1 > dominio2) {
                contactoEmail temp = contactos[j];
                contactos[j] = contactos[j + 1];
                contactos[j + 1] = temp;
            }
        }
    }
}

void MostrarListaOrdenadaPorServidor(contactoEmail contactos[], int cantidad){
    string dominioActual;
    if (cantidad == 0) {
        cout << "\nNo hay contactos registrados\n";
        return;
    }

    ordenarPorDominio(contactos, cantidad);

    cout << "\nContactos ordenados por servidor de correo:\n";

    dominioActual = "";

    for (int i = 0; i < cantidad; i++) {
        string dominio = obtenerDominio(contactos[i].email);

        if (dominio != dominioActual) {
            dominioActual = dominio;
            cout << "\n--- " << dominioActual << " ---\n";
        }

        cout << "- " << contactos[i].nombre << " (" << contactos[i].email << ")\n";
    }
}


void menu(){
	char opcion;
	const int TAM = 100;
	contactoEmail guardarContacto[TAM];
	int cantidadContactos = 0;
	
	
	do{
		cout << "            ---------------MENU PRINCIPAL---------------\n" << endl;
		
		cout << "\n ---------------------------------------------------------------------\n";
		cout << "  a) Agregar contacto" << endl;
		cout << "  b) Eliminar un contacto" << endl;
		cout << "  c) Mostrar listado general de contactos registrados hasta el momento" << endl;
		cout << "  d) Mostrar listado de contactos existentes\n";
		cout << "     ordenado por servidor de correo de las cuentas\n";
		cout << "     (gmail.com, outlook.com, yahoo.com, etc.)" << endl;
		cout << "  e) Salir del programa" << endl;
		cout << " ---------------------------------------------------------------------\n";

		cout << "\n  Elija una opcion: ";
		cin >> opcion;
	
		switch (opcion){
			case 'a':
				agregarContacto(guardarContacto, cantidadContactos);
				system("pause");
				break;
				
			case 'b':
				eliminarContacto(guardarContacto, cantidadContactos);
				system("pause");
				break;
			case 'c':
				MostrarlistaGeneral(guardarContacto, cantidadContactos);
				system("pause");
				break;
			case 'd':
				MostrarListaOrdenadaPorServidor(guardarContacto, cantidadContactos);
				system("pause");
				break;
			case 'e':
				cout << "\n -----------------------------------------";
				cout << "\n  GRACIAS POR USAR MI PROGRAMA <3!" << endl;
				cout << "\n  Saliendo del programa ..." << endl;
				cout << "  PROGRAMA FINALIZADO!" << endl;
				system("pause");
				break;
			default:
				cout << "\n  INVALIDO, porfavor ingrese una opcion valida\n" << endl;
				system("pause");
				break;
		}	
		system("cls");	
	}while (opcion != 'e');

}

int main(){
	
	menu();
	
	return 0;
}
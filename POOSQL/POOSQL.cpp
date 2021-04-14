#include <mysql.h>
#include <iostream>
#include "cliente.h"

using namespace std;
int q_estado;

void repetir();

void menu_general()
{
	string nit, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono;
	Cliente c = Cliente();
	int opcion,opcion2, id_cliente;
	cout << "__________ TABLA DE CLIENTES __________" << endl;
	cout << "	1. Leer datos" << endl;
	cout << "	2. Ingresar datos" << endl;
	cout << "	3. Actualizar datos" << endl;
	cout << "	4. Eliminar datos" << endl;
	cout << " Ingrese su opcion: ";
	cin >> opcion;
	cin.ignore();
	switch (opcion)
	{
	case 1:
		system("cls");
		c.leer();
		repetir();
		break;
		//_____________________________________________________________________________
	case 2:
		system("cls");
		cout << "Ingrese Nit:";
		getline(cin, nit);
		cout << "Ingrese Nombres:";
		getline(cin, nombres);
		cout << "Ingrese Apellidos:";
		getline(cin, apellidos);
		cout << "Ingrese Direccion:";
		getline(cin, direccion);
		cout << "Ingrese Telefono:";
		cin >> telefono;
		cin.ignore();
		cout << "Fecha Nacimiento:";
		cin >> fecha_nacimiento;
		c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		c.crear();
		repetir();
		break;
		//_____________________________________________________________________________
	case 3:
		system("cls");
		c.leer();
		cout << endl << endl;
		cout << "ingrese id cliente del registro: "; cin >> id_cliente;
		opcion2=c.menu();
		if (opcion2 == 1)
		{
			cout << "\ningrese el nuevo nit: "; cin >> nit;
			c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
			
		}
		else if (opcion2 == 2)
		{
			cout << "\ningrese el nuevo nombre: "; getline(cin,nombres);
			c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		}
		else if (opcion2 == 3)
		{
			cout << "\ningrese el nuevo apellido: "; getline(cin, apellidos);
			c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		}
		else if (opcion2 == 4)
		{
			cout << "\ningrese la nueva direccion: "; getline(cin, direccion);
			c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		}
		else if (opcion2 == 5)
		{
			cout << "\ningrese el nuevo telefono: "; cin>> telefono;
			c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		}
		else if (opcion2 == 6)
		{
			cout << "\ningrese la nueva fecha de nacimiento: "; getline(cin, fecha_nacimiento);
			c = Cliente(nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);
		}
		c.update(opcion2, id_cliente);
		repetir();
		break;
		//_____________________________________________________________________________
	case 4:
		system("cls");
		c.leer();
		cout << endl << endl;
		cout << "ingrese el id del registro que desea eliminar: "; cin >> id_cliente;
		c.eliminar(id_cliente);
		repetir();
		break;
		//_____________________________________________________________________________
	default:
		cout << "---XXX ESA OPCION NO EXISTE XXX---" << endl;
		break;
	}
}


void repetir()
{
	string opc;
	cout << endl << endl << "Desea probar otra opcion (s/n): ";
	cin >> opc;
	cin.ignore();
	if (opc == "S" || opc == "s")
	{
		system("cls");
		menu_general();
	}
}

int main()
{
	menu_general();
}

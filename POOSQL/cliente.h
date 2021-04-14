#pragma once

#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"
#include "Persona.h"


using namespace std;

class Cliente : Persona {
private: string nit;
	   // constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : Persona(nom, ape, dir, tel, fn) {
		nit = n;
	}
	


	// METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + nit + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() 
	{
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------- Datos de Clientes ----------------------------" << endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << endl<<endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	int menu()
	{
		int opcion2;
		
		system("cls");
		cout << "----------LISTADO DE DATOS DE LA TABLA PRODUCTOS ----------" << endl;
		cout << "   1. Nit" << endl;
		cout << "   2. Nombres" << endl;
		cout << "   3. Apellidos" << endl;
		cout << "   4. Direccion" << endl;
		cout << "   5. Telefono" << endl;
		cout << "   6. Fecha de nacimiento" << endl;
		cout << "Que elemento desea modificar: ";
		cin >> opcion2;
		cin.ignore();
		return opcion2;
	}

	void update(int opcion2, int id)
	{
		int q_estado;
		string id_c = to_string(id);
		string tel = to_string(telefono);
		string consulta;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar())
		{
			
			switch (opcion2)
			{
			case 1:
				consulta = "update clientes set nit='" + nit + "' where id_clientes=" + id_c; 
				break;
			case 2:
				consulta = "update clientes set nombres='" + nombres + "' where id_clientes=" + id_c;
				break;
			case 3:
				consulta = "update clientes set apellidos='" + apellidos + "' where id_clientes=" + id_c;
				break;
			case 4:
				consulta = "update clientes set direccion='" + direccion + "' where id_clientes=" + id_c;
				break;
			case 5:
				consulta = "update clientes set telefono= " + tel + " where id_clientes=" + id_c;
				break;
			case 6:
				consulta = "update clientes set fecha_nacimiento='" + fecha_nacimiento + "' where id_clientes=" + id_c;
				break;
			
			}
			
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado)
			{
				cout << "update exitoso" << endl;
			}
			else
			{
				cout << "error en el update" << endl;
			}
		}
		cn.cerrar_conexion();
	}

	void eliminar(int id)
	{
		string id_c = to_string(id);
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		
		if (cn.getConectar()) {
			string  insertar = "delete from clientes where id_clientes= " + id_c;
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "delete Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error en el delete  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};


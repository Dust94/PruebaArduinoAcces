// LibreriaPrincipal.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections;

namespace LibreriaPrincipal {

	public ref class Persona
	{
	public:
		int id; // Identificador de Customer o Staff en la DB. No se reinicia cada dia.
		String^ dni;
		String^ name; // Nombre de la Persona
		String^ apellido_Paterno;
		String^ apellido_Materno;
		char sexo; // Masculino(M) Femenino(F)
		String^ username;  // para el logeo con su cuenta
		String^ password;  // para el logeo con su cuenta
	}; // Fin Clase Persona

	public ref class Customer :Persona
	{
	public:
		String^ codigoPUCP; //Si no es de la PUCP de queda en blanco
		String^ facultad; //Para saber de que facultad vienen mas estudiantes a determinado modulo

	}; // Fin Clase Customer

	public ref class Staff :Persona
	{
	public:
		DateTime^ hora_entrada; //Hora de Entrada al Trabajo
		DateTime^ hora_salida; //Hora de Salida del Trabajo
		String^ puesto;
	}; // Fin Clase Staff

	public ref class Product
	{
	public:
		int id;
		String^ name;
		String^ description; //Descripcion del Producto
		double price; //Precio de 1 Producto
		int stock;
	};// Fin Clase Product

	public ref class ModuloStansa{
	public:
		int id;
		String^ name;
		String^ place;
		int MaquinasOperativas;
		List<Staff^>^ listStaff; //Cada ModuloStansa tiene un grupo de Staff trabajando en el.
		List<Product^>^ listProduct; //Cada ModuloStansa tiene una lista de Productos que puede vender
	};

	public ref class Attention {
	public:
		int id; //Identifica una fila. Una atencion
		DateTime^ fecha; //Dia de la Atencion
		int n_orden; //El Numero de Orden de la Persona que esta siendo atendida
		DateTime^ hora_ini; //Inicia la atencion con el Ticket de Numero de Orden
		DateTime^ hora_fin; //Finaliza la atencion de un Usuario
		String^ estado; //El estado del Usuario: Atendido o Esperando
		Customer^ customer; //Que Usuario fue atendido
		ModuloStansa^ moduloStansa; //En cual ModuloStansa fue atendido
		Staff^ staff; //Quien fue la persona(staff) que lo atendio.
	};
}

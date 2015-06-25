// Libreria Controller.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace LibreriaPrincipal;

namespace LibreriaController {

	public ref class CustomerDB //Base de Datos para Todos los Customers
	{
	public:
		List<Customer^> ^ listCustomer;
	public:
		Customer^ QueryById(int id);
		Customer^ QueryByDni(String^ dni);
		Customer^ QueryByCodigoPUCP(String^ codigoPUCP);
		List<Customer^>^ QueryAll();
	}; //Fin Clase CustomerDB

	public ref class AttentionDB
	{
	public:
		List<Attention^> ^ listAttention;
	public:
		void Add(Attention^ a);
		void Update(Attention^ a);
		Attention^ QueryById(int id);
		List<Attention^>^ QueryAll();
		List<Attention^>^ QueryAllByModuloStansa(ModuloStansa^ modulo);
		List<Attention^>^ QueryAllByModuloStansaAndCustomer(ModuloStansa^ modulo, Customer^ customer);
	}; //Fin Clase AttentionDB

	public ref class StansaArduinoManager
	{
	public:
		static CustomerDB^ customerDB = gcnew CustomerDB();
		static AttentionDB^ attentionDB = gcnew AttentionDB();
	public:
		//metodos de clase globlales para Customer
		static Customer^ QueryCustomerById(int id);
		static Customer^ QueryCustomerByDni(String^ dni);
		static Customer^ QueryCustomerByCodigoPUCP(String^ codigoPUCP);
		static List<Customer^>^ QueryAllCustomer();

		//metodos de clase globlales para Attention
		static void AddAttention(Attention^ a);
		static void UpdateAttention(Attention^ a);
		static Attention^ QueryAttentionById(int id);
		static List<Attention^>^ QueryAllAttention();
		static List<Attention^>^ QueryAllAttentionByModuloStansa(ModuloStansa^ modulo);
		static List<Attention^>^ QueryAllAttentionByModuloStansaAndCustomer(ModuloStansa^ modulo, Customer^ customer);
	}; //Fin Clase StansaArduinoManager

}

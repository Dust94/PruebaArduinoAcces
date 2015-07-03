// Archivo DLL principal.

#include "stdafx.h"
#include "ControllerLibrary.h"



using namespace ControllerLibrary;
using namespace System::IO;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Data::SqlClient;

//Metodos de la Clase CustomerDB
Customer^ CustomerDB::QueryById(int id){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM Costumer_DB " +
		"WHERE id=@p1";
	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::Int);
	p1->Value = id; // int

	comm->Parameters->Add(p1);
	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados	
	Customer ^c = nullptr;
	if (dr->Read()){
		c = gcnew Customer();
		c->id = (int)dr["id"];
		if (dr["dni"] != System::DBNull::Value)
			c->dni = safe_cast<String^>(dr["dni"]);
		if (dr["name"] != System::DBNull::Value)
			c->name = safe_cast<String ^>(dr["name"]);
		if (dr["lastName"] != System::DBNull::Value)
			c->apellido_Paterno = safe_cast<String ^>(dr["lastName"]);
		if (dr["secondLastName"] != System::DBNull::Value)
			c->apellido_Materno = safe_cast<String ^>(dr["secondLastName"]);
		if (dr["sex"] != System::DBNull::Value)
			c->sexo = Char::Parse(safe_cast<String ^>(dr["sex"]));
		if (dr["username"] != System::DBNull::Value)
			c->username = safe_cast<String ^>(dr["username"]);
		if (dr["password"] != System::DBNull::Value)
			c->password = safe_cast<String ^>(dr["password"]);
		if (dr["codePUCP"] != System::DBNull::Value)
			c->codigoPUCP = safe_cast<String ^>(dr["codePUCP"]);
		if (dr["academicUnit"] != System::DBNull::Value)
			c->facultad = safe_cast<String ^>(dr["acaademicUnit"]);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return c;
}
Customer^ CustomerDB::QueryByDni(String^ dni){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM Costumer_DB " +
		"WHERE dni=@p1";

	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::VarChar);
	p1->Value = dni; // String

	comm->Parameters->Add(p1);
	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados	
	Customer ^c = nullptr;
	if (dr->Read()){
		c = gcnew Customer();
		c->id = (int)dr["id"];
		if (dr["dni"] != System::DBNull::Value)
			c->dni = safe_cast<String^>(dr["dni"]);
		if (dr["name"] != System::DBNull::Value)
			c->name = safe_cast<String ^>(dr["name"]);
		if (dr["lastName"] != System::DBNull::Value)
			c->apellido_Paterno = safe_cast<String ^>(dr["lastName"]);
		if (dr["secondLastName"] != System::DBNull::Value)
			c->apellido_Materno = safe_cast<String ^>(dr["secondLastName"]);
		if (dr["sex"] != System::DBNull::Value)
			c->sexo = Char::Parse(safe_cast<String ^>(dr["sex"]));
		if (dr["username"] != System::DBNull::Value)
			c->username = safe_cast<String ^>(dr["username"]);
		if (dr["password"] != System::DBNull::Value)
			c->password = safe_cast<String ^>(dr["password"]);
		if (dr["codePUCP"] != System::DBNull::Value)
			c->codigoPUCP = safe_cast<String ^>(dr["codePUCP"]);
		if (dr["academicUnit"] != System::DBNull::Value)
			c->facultad = safe_cast<String ^>(dr["academicUnit"]);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return c;
}
Customer^ CustomerDB::QueryByCodigoPUCP(String^ codigoPUCP){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM Costumer_DB " +
		"WHERE codePucp LIKE @p1";
	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::VarChar);
	p1->Value = "%" + codigoPUCP + "%"; // String 

	comm->Parameters->Add(p1);
	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados	
	Customer ^c = nullptr;
	if (dr->Read()){
		c = gcnew Customer();
		c->id = (int)dr["id"];
		if (dr["dni"] != System::DBNull::Value)
			c->dni = safe_cast<String^>(dr["dni"]);
		if (dr["name"] != System::DBNull::Value)
			c->name = safe_cast<String ^>(dr["name"]);
		if (dr["lastName"] != System::DBNull::Value)
			c->apellido_Paterno = safe_cast<String ^>(dr["lastName"]);
		if (dr["secondLastName"] != System::DBNull::Value)
			c->apellido_Materno = safe_cast<String ^>(dr["secondLastName"]);
		if (dr["sex"] != System::DBNull::Value)
			c->sexo = Char::Parse(safe_cast<String ^>(dr["sex"]));
		if (dr["username"] != System::DBNull::Value)
			c->username = safe_cast<String ^>(dr["username"]);
		if (dr["password"] != System::DBNull::Value)
			c->password = safe_cast<String ^>(dr["password"]);
		if (dr["codePUCP"] != System::DBNull::Value)
			c->codigoPUCP = safe_cast<String ^>(dr["codePUCP"]);
		if (dr["academicUnit"] != System::DBNull::Value)
			c->facultad = safe_cast<String ^>(dr["academicUnit"]);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return c;
}
List<Customer^>^ CustomerDB::QueryAll(){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM Costumer_DB ";

	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados
	List<Customer^>^ customerList = gcnew List<Customer^>();
	while (dr->Read()){
		Customer^c = gcnew Customer();
		c->id = (int)dr["id"];
		if (dr["dni"] != System::DBNull::Value)
			c->dni = safe_cast<String^>(dr["dni"]);
		if (dr["name"] != System::DBNull::Value)
			c->name = safe_cast<String ^>(dr["name"]);
		if (dr["lastName"] != System::DBNull::Value)
			c->apellido_Paterno = safe_cast<String ^>(dr["lastName"]);
		if (dr["secondLastName"] != System::DBNull::Value)
			c->apellido_Materno = safe_cast<String ^>(dr["secondLastName"]);
		if (dr["sex"] != System::DBNull::Value)
			c->sexo = Char::Parse(safe_cast<String ^>(dr["sex"]));
		if (dr["username"] != System::DBNull::Value)
			c->username = safe_cast<String ^>(dr["username"]);
		if (dr["password"] != System::DBNull::Value)
			c->password = safe_cast<String ^>(dr["password"]);
		if (dr["codePUCP"] != System::DBNull::Value)
			c->codigoPUCP = safe_cast<String ^>(dr["codePUCP"]);
		if (dr["academicUnit"] != System::DBNull::Value)
			c->facultad = safe_cast<String ^>(dr["academicUnit"]);
		customerList->Add(c);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return customerList;
}

//Metodos de la Clase AttentionDB
void AttentionDB::Add(Attention^ a){
	
	//Paso 1: Obtener la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "INSERT INTO Attention_DB " +
		" (date, orderNumber, inTime, outTime, status, idCustomer,idModStansa )" +
		" VALUES (@p1,@p2,@p3,@p4,@p5,@p6,@p7)";
	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::DateTime);
	SqlParameter^ p2 = gcnew SqlParameter("@p2",
		System::Data::SqlDbType::Int);
	SqlParameter^ p3 = gcnew SqlParameter("@p3",
		System::Data::SqlDbType::DateTime);
	SqlParameter^ p4 = gcnew SqlParameter("@p4",
		System::Data::SqlDbType::DateTime);
	SqlParameter^ p5 = gcnew SqlParameter("@p5",
		System::Data::SqlDbType::VarChar);
	SqlParameter^ p6 = gcnew SqlParameter("@p6",
		System::Data::SqlDbType::Int);
	SqlParameter^ p7 = gcnew SqlParameter("@p7",
		System::Data::SqlDbType::Int);
	//SqlParameter^ p8 = gcnew SqlParameter("@p8",
//		System::Data::SqlDbType::Int);

	p1->Value = a->fecha; //DateTime
	p2->Value = a->n_orden; //int
	p3->Value = a->hora_ini; //DateTime
	p4->Value = a->hora_fin; //DateTime
	p5->Value = a->estado; // String
	p6->Value = a->customer->id; //int
	p7->Value = a->moduloStansa->id;
	//p8->Value = a->staff->id;

	comm->Parameters->Add(p1);
	comm->Parameters->Add(p2);
	comm->Parameters->Add(p3);
	comm->Parameters->Add(p4);
	comm->Parameters->Add(p5);
	comm->Parameters->Add(p6);
	comm->Parameters->Add(p7);

	//Paso 3: Ejecuci�n de la sentencia
	comm->ExecuteNonQuery();
	//Paso 4: Cerramos la conexi�n con la BD
	conn->Close();
}
void AttentionDB::Update(Attention^ a){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "UPDATE Attention_DB " +

		"SET date=@p1, orderNumber=@p2, inTime=@p3, outTime=@p4, status=@p5, idCustomer=@p6 , idModStansa=@p7 , idStaff=@p8  " +
		" WHERE id=@p9";
	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::DateTime);
	SqlParameter^ p2 = gcnew SqlParameter("@p2",
		System::Data::SqlDbType::Int);
	SqlParameter^ p3 = gcnew SqlParameter("@p3",
		System::Data::SqlDbType::DateTime);
	SqlParameter^ p4 = gcnew SqlParameter("@p4",
		System::Data::SqlDbType::DateTime);
	SqlParameter^ p5 = gcnew SqlParameter("@p5",
		System::Data::SqlDbType::VarChar);
	SqlParameter^ p6 = gcnew SqlParameter("@p6",
		System::Data::SqlDbType::Int);
	SqlParameter^ p7 = gcnew SqlParameter("@p7",
		System::Data::SqlDbType::Int);
	SqlParameter^ p8 = gcnew SqlParameter("@p8",
		System::Data::SqlDbType::Int);
	SqlParameter^ p9 = gcnew SqlParameter("@p9",
		System::Data::SqlDbType::Int);

	p1->Value = a->fecha; //String
	p2->Value = a->n_orden; //int
	p3->Value = a->hora_ini; //String
	p4->Value = a->hora_fin; //String
	p5->Value = a->estado; // String
	p6->Value = a->customer->id; //int
	p7->Value = a->moduloStansa->id; //int
	p8->Value = a->staff->id; //int
	p9->Value = a->id; //int

	comm->Parameters->Add(p1);
	comm->Parameters->Add(p2);
	comm->Parameters->Add(p3);
	comm->Parameters->Add(p4);
	comm->Parameters->Add(p5);
	comm->Parameters->Add(p6);
	comm->Parameters->Add(p7);
	comm->Parameters->Add(p8);
	comm->Parameters->Add(p9);
	//Paso 3: Ejecuci�n de la sentencia
	comm->ExecuteNonQuery();
	//Paso 4: Cerramos la conexi�n con la BD
	conn->Close();
}
Attention^ AttentionDB::QueryById(int id){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM Attention_DB " +
		"WHERE id=@p1";
	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::Int);
	p1->Value = id; // int

	comm->Parameters->Add(p1);
	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados	
	Attention ^ a = nullptr;
	if (dr->Read()){
		a = gcnew Attention();
		a->id = (int)dr["id"];
		if (dr["date"] != System::DBNull::Value)
			a->fecha = safe_cast<DateTime^>(dr["date"]);
		if (dr["orderNumber"] != System::DBNull::Value)
			a->n_orden = safe_cast<int>(dr["orderNumber"]);
		if (dr["inTime"] != System::DBNull::Value)
			a->hora_ini = safe_cast<DateTime^>(dr["inTime"]);
		if (dr["outTime"] != System::DBNull::Value)
			a->hora_fin = safe_cast<DateTime^>(dr["outTime"]);
		if (dr["status"] != System::DBNull::Value)
			a->estado = safe_cast<String^>(dr["status"]);
		if (dr["idCustomer"] != System::DBNull::Value)
			a->customer->id = safe_cast<int>(dr["idCustomer"]);
		if (dr["idModStansa"] != System::DBNull::Value)
			a->moduloStansa->id = safe_cast<int>(dr["idModStansa"]);
		if (dr["idStaff"] != System::DBNull::Value)
			a->staff->id = safe_cast<int>(dr["idStaff"]);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return a;
}
List<Attention^>^ AttentionDB::QueryAll(){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM Attention_DB ";

	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados
	List<Attention^>^ AttentionList = gcnew List<Attention^>();
	while (dr->Read()){
		Attention^a = gcnew Attention();
		a->id = (int)dr["id"];
		if (dr["date"] != System::DBNull::Value)
			a->fecha = safe_cast<DateTime^>(dr["date"]);
		if (dr["orderNumber"] != System::DBNull::Value)
			a->n_orden = safe_cast<int>(dr["orderNumber"]);
		if (dr["inTime"] != System::DBNull::Value)
			a->hora_ini = safe_cast<DateTime^>(dr["inTime"]);
		if (dr["hora_fin"] != System::DBNull::Value)
			a->hora_fin = safe_cast<DateTime^>(dr["hora_fin"]);
		if (dr["status"] != System::DBNull::Value)
			a->estado = safe_cast<String^>(dr["status"]);
		if (dr["idCustomer"] != System::DBNull::Value)
			a->customer->id = safe_cast<int>(dr["idCustomer"]);
		if (dr["idModStansa"] != System::DBNull::Value)
			a->moduloStansa->id = safe_cast<int>(dr["idModStansa"]);
		if (dr["idStaff"] != System::DBNull::Value)
			a->staff->id = safe_cast<int>(dr["idStaff"]);

		AttentionList->Add(a);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return AttentionList;
}
List<Attention^>^ AttentionDB::QueryAllByModuloStansa(ModuloStansa^ modulo){ return nullptr; }
List<Attention^>^ AttentionDB::QueryAllByModuloStansaAndCustomer(ModuloStansa^ modulo, Customer^ customer){ return nullptr; }

//metodos de clase globlales para Customer
Customer^ StansaArduinoManager::QueryCustomerById(int id){
	return customerDB->QueryById(id);
}
Customer^ StansaArduinoManager::QueryCustomerByDni(String^ dni){
	return customerDB->QueryByDni(dni);
}
Customer^ StansaArduinoManager::QueryCustomerByCodigoPUCP(String^ codigoPUCP){
	return customerDB->QueryByCodigoPUCP(codigoPUCP);
}
List<Customer^>^ StansaArduinoManager::QueryAllCustomer(){
	return customerDB->QueryAll();
}


//metodos modulo Stansa

List<ModuloStansa^>^ ModuloStansaDB::QueryAll(){

	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM ModStansa_DB ";

	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados
	List<ModuloStansa^>^ ModStansaList = gcnew List<ModuloStansa^>();
	while (dr->Read()){
		ModuloStansa^m = gcnew ModuloStansa();
		m->id = (int)dr["id"];
		m->name = safe_cast<String^>(dr["name"]);
		if (dr["name"] != System::DBNull::Value)
			m->name = safe_cast<String ^>(dr["name"]);
		if (dr["place"] != System::DBNull::Value)
			m->place = safe_cast<String ^>(dr["place"]);
		if (dr["operativeMachines"] != System::DBNull::Value)
			m->MaquinasOperativas = safe_cast<int>(dr["operativeMachines"]);

		ModStansaList->Add(m);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return ModStansaList;

}
ModuloStansa^ ModuloStansaDB::QuerryByName(String^ name){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237g4;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT * FROM ModStansa_DB " +
		"WHERE name=@p1";

	SqlParameter^ p1 = gcnew SqlParameter("@p1",
		System::Data::SqlDbType::VarChar);
	p1->Value = name; // String
	comm->Parameters->Add(p1);

	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados	
	ModuloStansa ^ m = nullptr;
	if (dr->Read()){
		m = gcnew ModuloStansa();
		m->id = (int)dr["id"];
		if (dr["name"] != System::DBNull::Value)
			m->name = safe_cast<String ^>(dr["name"]);
		if (dr["place"] != System::DBNull::Value)
			m->place = safe_cast<String ^>(dr["place"]);
		if (dr["operativeMachines"] != System::DBNull::Value)
			m->MaquinasOperativas = safe_cast<int>(dr["operativeMachines"]);
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return m;

};

List<int>^ AttentionDB::TakeTime(){
	//Paso 1: Se abre la conexi�n
	SqlConnection^ conn;
	conn = gcnew SqlConnection();
	conn->ConnectionString = "Server=inti.lab.inf.pucp.edu.pe;" +
		"Database=inf237;User ID=inf237g4;Password=wXJ7FpUHDnYKjf89;";
	conn->Open();
	//Paso 2: Preparamos la sentencia
	SqlCommand^ comm = gcnew SqlCommand();
	comm->Connection = conn;
	comm->CommandText = "SELECT DATEPART(dd,date) AS OrderDay, " +
		"DATEPART(hh, date) AS OrderHour, "+
		"DATEPART(mi, date) AS Orderminute, "+
		"DATEPART(ss, date) AS OrderSecond "+
		"FROM Attention_DB "+
		"WHERE id = 1 ";

	//Paso 3: Ejecuci�n de la sentencia
	SqlDataReader^ dr = comm->ExecuteReader();
	//Paso 3.1: Procesamos los resultados	
	List<int>^ time = gcnew List<int>();
	if (dr->Read()){
		if (dr["OrderDay"] != System::DBNull::Value)
			time->Add(safe_cast<int>(dr["OrderDay"]));
		if (dr["OrderHour"] != System::DBNull::Value)
			time->Add(safe_cast<int>(dr["OrderHour"]));
		if (dr["Orderminute"] != System::DBNull::Value)
			time->Add(safe_cast<int>(dr["Orderminute"]));
		if (dr["OrderSecond"] != System::DBNull::Value)
			time->Add(safe_cast<int>(dr["OrderSecond"]));
	}
	//Paso 4: Cerramos el dataReader y la conexi�n con la BD
	dr->Close();
	conn->Close();
	return time;
}











//metodos de clase globlales para Stansa Arduino MAnager
void StansaArduinoManager::AddAttention(Attention^ a){
	attentionDB->Add(a);
}
void StansaArduinoManager::UpdateAttention(Attention^ a){
	attentionDB->Update(a);
}
Attention^ StansaArduinoManager::QueryAttentionById(int id){
	return attentionDB->QueryById(id);
}
List<Attention^>^ StansaArduinoManager::QueryAllAttention(){
	return attentionDB->QueryAll();
}
List<Attention^>^ StansaArduinoManager::QueryAllAttentionByModuloStansa(ModuloStansa^ modulo){
	return attentionDB->QueryAllByModuloStansa(modulo);
}
List<Attention^>^ StansaArduinoManager::QueryAllAttentionByModuloStansaAndCustomer(ModuloStansa^ modulo, Customer^ customer){
	return attentionDB->QueryAllByModuloStansaAndCustomer(modulo, customer);
}
List<ModuloStansa^>^ StansaArduinoManager::QuerryAllModuloStansa(){
	return moduloStansaDB->QueryAll();
};
ModuloStansa^ StansaArduinoManager::QuerryModuloStansaByName(String^ name){
	return moduloStansaDB->QuerryByName(name);
};
List<int>^ StansaArduinoManager::AttentionTakeTime(){
	return attentionDB->TakeTime();
}
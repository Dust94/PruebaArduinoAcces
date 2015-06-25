#pragma once

namespace PruebaIngresaAttention {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace LibreriaPrincipal;
	using namespace LibreriaController;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for AccesForm
	/// </summary>
	public ref class AccesForm : public System::Windows::Forms::Form
	{
	public:
		AccesForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtDni;
	protected:

	private: System::Windows::Forms::TextBox^  txtCodigoPUCP;
	protected:

	private: System::Windows::Forms::Button^  btnAddAttention;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtDni = (gcnew System::Windows::Forms::TextBox());
			this->txtCodigoPUCP = (gcnew System::Windows::Forms::TextBox());
			this->btnAddAttention = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtDni
			// 
			this->txtDni->Location = System::Drawing::Point(262, 74);
			this->txtDni->Name = L"txtDni";
			this->txtDni->Size = System::Drawing::Size(200, 20);
			this->txtDni->TabIndex = 10;
			// 
			// txtCodigoPUCP
			// 
			this->txtCodigoPUCP->Location = System::Drawing::Point(262, 45);
			this->txtCodigoPUCP->Name = L"txtCodigoPUCP";
			this->txtCodigoPUCP->Size = System::Drawing::Size(200, 20);
			this->txtCodigoPUCP->TabIndex = 9;
			// 
			// btnAddAttention
			// 
			this->btnAddAttention->Location = System::Drawing::Point(167, 116);
			this->btnAddAttention->Name = L"btnAddAttention";
			this->btnAddAttention->Size = System::Drawing::Size(137, 23);
			this->btnAddAttention->TabIndex = 8;
			this->btnAddAttention->Text = L"Sacar Ticket";
			this->btnAddAttention->UseVisualStyleBackColor = true;
			this->btnAddAttention->Click += gcnew System::EventHandler(this, &AccesForm::btnAddAttention_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(87, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Busqueda por DNI";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(87, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Busqueda por codigo PUCP";
			// 
			// AccesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 235);
			this->Controls->Add(this->txtDni);
			this->Controls->Add(this->txtCodigoPUCP);
			this->Controls->Add(this->btnAddAttention);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AccesForm";
			this->Text = L"AccesForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: Customer^ c = gcnew Customer();
	public: bool Validacion(){
		bool codigo = String::Equals(txtCodigoPUCP->Text, ""); //Vacio = true. //Llenado = false
		bool dni = String::Equals(txtDni->Text, "");
		if (!codigo && !dni){
			MessageBox::Show("Sólo debe ingresar un criterio de búsqueda");
			return false;
		}
		if (!codigo && dni){ //Si solo se ha llenado el campo de codigo
			String^ CodigoPUCP = txtCodigoPUCP->Text; //Codigo PUCP Ingresado por Usuario
			c = StansaArduinoManager::QueryCustomerByCodigoPUCP(CodigoPUCP);
			if (c != nullptr) return true; //Se ha encontrado el usuario
			else {
				MessageBox::Show("Codigo PUCP Incorrecto");
				return false;
			}
		}
		if (codigo && !dni){ //Si solo se ha llenado el campo de dni
			String^ dni = txtDni->Text; //Codigo PUCP Ingresado por Usuario
			c = StansaArduinoManager::QueryCustomerByDni(dni);
			if (c != nullptr) return true; //Se ha encontrado el usuario
			else {
				MessageBox::Show("DNI Incorrecto");
				return false;
			}
		}
		if (codigo && dni){ //Si ambos campos estan vacios
			MessageBox::Show("Ingrese algun Campo de Busqueda");
			return false;
		}
	}// Fin de Metodo Validacion

	private: System::Void btnAddAttention_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (Validacion()){
			DateTime^ fechaActual = DateTime::Now; //Creo un objeto DateTime con la hora actual
			Attention^ atencion = gcnew Attention();

			atencion->fecha = fechaActual;
			atencion->hora_ini = fechaActual;
			atencion->hora_fin = fechaActual;
			atencion->estado = "Esperando";
			atencion->customer->id = c->id;
			StansaArduinoManager::AddAttention(atencion);
			MessageBox::Show("Atencion Ingresada Correctamente"); //compila
		}
	}
};
}

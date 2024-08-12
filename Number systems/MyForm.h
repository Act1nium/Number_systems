#pragma once
#include "MyForm1.h"

namespace Numbersystems {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Dictionary<System::String^, int>^ numbers10 = gcnew Dictionary<System::String^, int>(); //Dictionary для перевода в десятичную СС
		String^ decimal = ""; //переменная для хранения числа в 10 СС
		String^ tempString = ""; //временная переменная типа String^
	public:
		MyForm(void)
		{
			InitializeComponent();

			numbers10->Add("0", 0);
			numbers10->Add("1", 1);
			numbers10->Add("2", 2);
			numbers10->Add("3", 3);
			numbers10->Add("4", 4);
			numbers10->Add("5", 5);
			numbers10->Add("6", 6);
			numbers10->Add("7", 7);
			numbers10->Add("8", 8);
			numbers10->Add("9", 9);
			numbers10->Add("A", 10);
			numbers10->Add("B", 11);
			numbers10->Add("C", 12);
			numbers10->Add("D", 13);
			numbers10->Add("E", 14);
			numbers10->Add("F", 15);
			numbers10->Add("G", 16);
			numbers10->Add("H", 17);
			numbers10->Add("I", 18);
			numbers10->Add("J", 19);
			numbers10->Add("K", 20);
			numbers10->Add("L", 21);
			numbers10->Add("M", 22);
			numbers10->Add("N", 23);
			numbers10->Add("O", 24);
			numbers10->Add("P", 25);
			numbers10->Add("Q", 26);
			numbers10->Add("R", 27);
			numbers10->Add("S", 28);
			numbers10->Add("T", 29);
			numbers10->Add("U", 30);
			numbers10->Add("V", 31);
			numbers10->Add("W", 32);
			numbers10->Add("X", 33);
			numbers10->Add("Y", 34);
			numbers10->Add("Z", 35);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxDecimal;
	private: System::Windows::Forms::TextBox^ textBoxBinary;
	private: System::Windows::Forms::TextBox^ textBoxOctal;
	private: System::Windows::Forms::TextBox^ textBoxHexadecimal;
	private: System::Windows::Forms::ComboBox^ comboBoxChoice;
	protected:





	private: System::Windows::Forms::TextBox^ textBoxChosen;
	private: System::Windows::Forms::Button^ ButtonCalculator;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	protected:




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBoxDecimal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxBinary = (gcnew System::Windows::Forms::TextBox());
			this->textBoxOctal = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHexadecimal = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxChoice = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxChosen = (gcnew System::Windows::Forms::TextBox());
			this->ButtonCalculator = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBoxDecimal
			// 
			this->textBoxDecimal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxDecimal->Location = System::Drawing::Point(18, 39);
			this->textBoxDecimal->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxDecimal->Name = L"textBoxDecimal";
			this->textBoxDecimal->Size = System::Drawing::Size(473, 30);
			this->textBoxDecimal->TabIndex = 0;
			this->textBoxDecimal->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			// 
			// textBoxBinary
			// 
			this->textBoxBinary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxBinary->Location = System::Drawing::Point(18, 104);
			this->textBoxBinary->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxBinary->Name = L"textBoxBinary";
			this->textBoxBinary->Size = System::Drawing::Size(473, 30);
			this->textBoxBinary->TabIndex = 1;
			// 
			// textBoxOctal
			// 
			this->textBoxOctal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxOctal->Location = System::Drawing::Point(18, 169);
			this->textBoxOctal->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxOctal->Name = L"textBoxOctal";
			this->textBoxOctal->Size = System::Drawing::Size(473, 30);
			this->textBoxOctal->TabIndex = 2;
			// 
			// textBoxHexadecimal
			// 
			this->textBoxHexadecimal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxHexadecimal->Location = System::Drawing::Point(18, 234);
			this->textBoxHexadecimal->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxHexadecimal->Name = L"textBoxHexadecimal";
			this->textBoxHexadecimal->Size = System::Drawing::Size(473, 30);
			this->textBoxHexadecimal->TabIndex = 3;
			// 
			// comboBoxChoice
			// 
			this->comboBoxChoice->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxChoice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxChoice->FormattingEnabled = true;
			this->comboBoxChoice->IntegralHeight = false;
			this->comboBoxChoice->ItemHeight = 25;
			this->comboBoxChoice->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"3", L"4", L"5", L"6", L"7", L"9", L"11",
					L"12", L"13", L"14", L"15", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", L"27", L"28", L"29", L"30",
					L"31", L"32", L"33", L"34", L"35", L"36"
			});
			this->comboBoxChoice->Location = System::Drawing::Point(428, 299);
			this->comboBoxChoice->Name = L"comboBoxChoice";
			this->comboBoxChoice->Size = System::Drawing::Size(63, 33);
			this->comboBoxChoice->TabIndex = 4;
			// 
			// textBoxChosen
			// 
			this->textBoxChosen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxChosen->Location = System::Drawing::Point(18, 302);
			this->textBoxChosen->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxChosen->Name = L"textBoxChosen";
			this->textBoxChosen->Size = System::Drawing::Size(403, 30);
			this->textBoxChosen->TabIndex = 5;
			// 
			// ButtonCalculator
			// 
			this->ButtonCalculator->Location = System::Drawing::Point(18, 340);
			this->ButtonCalculator->Name = L"ButtonCalculator";
			this->ButtonCalculator->Size = System::Drawing::Size(153, 58);
			this->ButtonCalculator->TabIndex = 6;
			this->ButtonCalculator->Text = L"Calculator";
			this->ButtonCalculator->UseVisualStyleBackColor = true;
			this->ButtonCalculator->Click += gcnew System::EventHandler(this, &MyForm::ButtonCalculator_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Decimal (10)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Binary (2)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 25);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Octal (8)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 204);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(166, 25);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Hexadecimal (16)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(423, 271);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 25);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Basis";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 415);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ButtonCalculator);
			this->Controls->Add(this->textBoxChosen);
			this->Controls->Add(this->comboBoxChoice);
			this->Controls->Add(this->textBoxHexadecimal);
			this->Controls->Add(this->textBoxOctal);
			this->Controls->Add(this->textBoxBinary);
			this->Controls->Add(this->textBoxDecimal);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Number systems";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ButtonCalculator_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Application::OpenForms->Count < 2)
	{
		MyForm1^ form1 = gcnew MyForm1(); //создаем новый экземпляр формы
		form1->Show();
	}
}
private: System::Void textBoxDecimal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	decimal = textBoxDecimal->Text;
	decimal = decimal->ToUpper();
	textBoxDecimal->Text = decimal;
	if (textBoxDecimal->Text != "")
	{
		for (int i = 0; i < decimal->Length; i++)
		{
			if (numbers10[decimal->Substring(i, 1)] >= 10)
			{
				if (i != decimal->Length - 1)
				{
					decimal = decimal->Substring(0, i) + decimal->Substring(i + 1);
					textBoxDecimal->Text = decimal;
					textBoxDecimal->SelectionStart = i;
				}
				else
				{
					decimal = decimal->Substring(0, decimal->Length - 1);
					textBoxDecimal->Text = decimal;
					textBoxDecimal->SelectionStart = textBoxDecimal->Text->Length;
				}
			}
		}
		/*if (numbers10[decimal->Substring(decimal->Length - 1, 1)] >= 10)
		{
			decimal = decimal->Substring(0, decimal->Length - 1);
			textBoxDecimal->Text = decimal;
		}*/
	}
}
};
}

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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Dictionary<String^, int>^ numbers10 = gcnew Dictionary<String^, int>(); //Dictionary ��� �������� � 10 ��
		Dictionary<int, String^>^ numbers = gcnew Dictionary<int, String^>(); //Dictionary ��� �������� �� 10 ��
		Dictionary<int, int>^ decimals = gcnew Dictionary<int, int>(); //Dictionary ��� ���-�� ������ ����� ������� (�� - ���-�� ������)
	private: System::Windows::Forms::Label^ labelError;
		   String^ lastDecimal = ""; //������� ����� � 10 ��
	public:
		void ReverseString(String^& str)
		{
			String^ temp = "";

			for (int i = str->Length - 1; i >= 0; i--)
			{
				temp += str[i];
			}

			str = temp;
		}
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

			numbers->Add(0, "0");
			numbers->Add(1, "1");
			numbers->Add(2, "2");
			numbers->Add(3, "3");
			numbers->Add(4, "4");
			numbers->Add(5, "5");
			numbers->Add(6, "6");
			numbers->Add(7, "7");
			numbers->Add(8, "8");
			numbers->Add(9, "9");
			numbers->Add(10, "A");
			numbers->Add(11, "B");
			numbers->Add(12, "C");
			numbers->Add(13, "D");
			numbers->Add(14, "E");
			numbers->Add(15, "F");
			numbers->Add(16, "G");
			numbers->Add(17, "H");
			numbers->Add(18, "I");
			numbers->Add(19, "J");
			numbers->Add(20, "K");
			numbers->Add(21, "L");
			numbers->Add(22, "M");
			numbers->Add(23, "N");
			numbers->Add(24, "O");
			numbers->Add(25, "P");
			numbers->Add(26, "Q");
			numbers->Add(27, "R");
			numbers->Add(28, "S");
			numbers->Add(29, "T");
			numbers->Add(30, "U");
			numbers->Add(31, "V");
			numbers->Add(32, "W");
			numbers->Add(33, "X");
			numbers->Add(34, "Y");
			numbers->Add(35, "Z");

			decimals->Add(2, 12);
			decimals->Add(3, 11);
			decimals->Add(4, 10);
			decimals->Add(5, 9);
			decimals->Add(6, 8);
			decimals->Add(7, 7);
			decimals->Add(8, 6);
			decimals->Add(9, 6);
			decimals->Add(10, 6);
			decimals->Add(11, 6);
			decimals->Add(12, 6);
			decimals->Add(13, 6);
			decimals->Add(14, 6);
			decimals->Add(15, 6);
			decimals->Add(16, 6);
			decimals->Add(17, 6);
			decimals->Add(18, 6);
			decimals->Add(19, 6);
			decimals->Add(20, 6);
			decimals->Add(21, 5);
			decimals->Add(22, 5);
			decimals->Add(23, 5);
			decimals->Add(24, 5);
			decimals->Add(25, 5);
			decimals->Add(26, 5);
			decimals->Add(27, 5);
			decimals->Add(28, 5);
			decimals->Add(29, 5);
			decimals->Add(30, 5);
			decimals->Add(31, 4);
			decimals->Add(32, 4);
			decimals->Add(33, 4);
			decimals->Add(34, 4);
			decimals->Add(35, 4);
			decimals->Add(36, 4);
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->labelError = (gcnew System::Windows::Forms::Label());
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
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->Location = System::Drawing::Point(209, 9);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(0, 25);
			this->labelError->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 415);
			this->Controls->Add(this->labelError);
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
		MyForm1^ form1 = gcnew MyForm1(); //������� ����� ��������� �����
		form1->Show();
	}
}
private: System::Void textBoxDecimal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//����������
	String^ decimal = ""; //���������� ��� �������� ����� � 10 ��
	String^ decimalBeforePoint = ""; //����� � 10 �� �� �����
	String^ decimalAfterPoint = ""; //����� � 10 �� ����� �����
	String^ strNumber10BeforePoint = ""; //����� � 10 �� �� ����� (�������)
	String^ strNumber10Fractional = ""; // ����� � 10 �� ����� �����(�������)
	String^ binaryBeforePoint = ""; //����� � 2 �� �� �����
	String^ binaryAfterPoint = ""; //����� � 2 �� ����� �����
	String^ binary = ""; //����� � 2 ��
	int pointsDecimal = 0; //���-�� ����� � ����� � 10 ��
	int number10BeforePoint = 0; //����� ����� ����� � 10 ��
	int temp; //��������� ���������� - ����� ��� �������� �� 10 ���
	double number10Fractional = 0; //������� ����� ����� � 10 ��
	double number10; //����� � 10 ��
	bool zero = false; //�������� �� ����� �����

	decimal = textBoxDecimal->Text;
	decimal = decimal->ToUpper();
	textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
	textBoxDecimal->Text = decimal;
	textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
	labelError->Text = "";
	//��������� ������� ������ ������ �������
	if (textBoxDecimal->Text != "")
	{
		for (int i = 0; i < decimal->Length; i++)
		{
			if (numbers10->ContainsKey(decimal->Substring(i, 1)))
			{
				if (numbers10[decimal->Substring(i, 1)] >= 10 ||
					i == 1 && decimal[0] == '0' && decimal[1] == '0' ||
					i == 2 && decimal[0] == '-' && decimal[1] == '0' && decimal[2] == '0')
				{
					decimal = decimal->Substring(0, i) + decimal->Substring(i + 1);
					textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
					textBoxDecimal->Text = decimal;
					textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
					textBoxDecimal->SelectionStart = i;
				}
			}
			else
			{
				switch (decimal[i])
				{
				case '-':
					if (i != 0)
					{
						decimal = decimal->Substring(0, i) + decimal->Substring(i + 1);
						textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
						textBoxDecimal->Text = decimal;
						textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
						textBoxDecimal->SelectionStart = i;
					}
					break;
				case '.':
					if (pointsDecimal > 0)
					{
						decimal = decimal->Substring(0, i) + decimal->Substring(i + 1);
						textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
						textBoxDecimal->Text = decimal;
						textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
						textBoxDecimal->SelectionStart = i;
					}
					else
					{
						if (decimal == "." || decimal == "-.")
						{
							decimal = decimal->Replace(".", "");
							decimal += "0.";
							textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
							textBoxDecimal->Text = decimal;
							textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
							textBoxDecimal->SelectionStart = i + 2;
						}
						else
						pointsDecimal++;
					}
					break;
				case ',':
					if (pointsDecimal > 0)
					{
						decimal = decimal->Substring(0, i) + decimal->Substring(i + 1);
						textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
						textBoxDecimal->Text = decimal;
						textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
						textBoxDecimal->SelectionStart = i;
					}
					else
					{
						if (decimal == "," || decimal == "-,")
						{
							decimal = decimal->Replace(",", "");
							decimal += "0.";
							textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
							textBoxDecimal->Text = decimal;
							textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
							textBoxDecimal->SelectionStart = i + 2;
						}
						else
						{
							pointsDecimal++;
							decimal = decimal->Replace(",", ".");
							textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
							textBoxDecimal->Text = decimal;
							textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
							textBoxDecimal->SelectionStart = i + 1;
						}
					}
					break;
				default:
					decimal = decimal->Substring(0, i) + decimal->Substring(i + 1);
					textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
					textBoxDecimal->Text = decimal;
					textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
					textBoxDecimal->SelectionStart = i;
					break;
				}
			}
		}
		pointsDecimal = 0;
		//����� ��������� ����� �� ����� � ������� �����
		for (int i = 0; i < decimal->Length; i++)
		{
			if (decimal[i] != '.')
			{
				if (decimal[i] != '-')
				{
					if (pointsDecimal == 0)
						decimalBeforePoint += decimal[i];
					else if (pointsDecimal == 1)
						decimalAfterPoint += decimal[i];
				}
			}
			else
				pointsDecimal++;
		}
		if (decimalBeforePoint->Length < 10)
		{
			pointsDecimal = 0;
			//��������� � 10 �� ����� ����� �����
			for (int i = 0; i < decimalBeforePoint->Length; i++)
				number10BeforePoint += numbers10[decimalBeforePoint->Substring(i, 1)] * pow(10, decimalBeforePoint->Length - i - 1);
			//��������� � 10 �� ������� ����� ����� 
			if (decimalAfterPoint != "")
			{
				for (int i = 0; i < decimalAfterPoint->Length && i < 30; i++)
					number10Fractional += numbers10[decimalAfterPoint->Substring(i, 1)] * pow(10, -(i + 1));
			}

			number10 = number10BeforePoint + number10Fractional;

			strNumber10Fractional = "0.";
			//��������� ����� ����� ����� �� 10 �� � 2 ��
			if (number10BeforePoint != 0)
			{
				while (number10BeforePoint != 0)
				{
					binaryBeforePoint += numbers[number10BeforePoint % 2];
					number10BeforePoint /= 2;
				}
				ReverseString(binaryBeforePoint);
			}
			else
				binaryBeforePoint = "0";
		}
		else
		{
			textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			textBoxDecimal->Text = "";
			textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			labelError->Text = "ERROR";
		}
	}
	//��������� ������� ����� ����� �� 10 �� 2 ��
	while (number10Fractional >= 1)
		number10Fractional /= 10;
	for (int i = 0; number10Fractional != 0 && i < decimals[2]; i++)
	{
		number10Fractional *= 2;
		temp = number10Fractional;
		if (number10Fractional != 0)
		{
			binaryAfterPoint += numbers[temp];
			if (temp != 0)
			{
				for (int i = 0; i < number10Fractional.ToString()->Length; i++)
				{
					if (number10Fractional.ToString()[i] != ',')
					{
						if (pointsDecimal == 1)
							strNumber10Fractional += number10Fractional.ToString()[i];
					}
					else
					{
						pointsDecimal += 1;
					}
				}
				pointsDecimal = 0;
				System::Globalization::CultureInfo^ culture = System::Globalization::CultureInfo::InvariantCulture;
				number10Fractional = System::Double::Parse(strNumber10Fractional, culture);
				strNumber10Fractional = "0.";
			}
		}
	}
	if (binaryAfterPoint != "")
	{
		binary += binaryBeforePoint + "." + binaryAfterPoint;
	}
	else
		binary = binaryBeforePoint;

	for (int i = 0; i < binary->Length; i++)
	{
		if (binary[i] != '-' && binary[i] != '.')
		{
			if (binary[i] == '0')
			{
				if (i == binary->Length - 1)
					zero = true;
			}
			else
			{
				zero = false;
			}
		}
	}
	if (!zero)
	{
		if (decimal != "")
		{
			if (decimal[0] == '-')
				binary = "-" + binary;
		}
	}

	textBoxBinary->Text = binary;
}
};
}

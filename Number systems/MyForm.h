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
		Dictionary<String^, int>^ numbers10 = gcnew Dictionary<String^, int>(); //Dictionary для перевода в 10 СС
		Dictionary<int, String^>^ numbers = gcnew Dictionary<int, String^>(); //Dictionary для перевода из 10 СС
		Dictionary<int, int>^ decimals = gcnew Dictionary<int, int>(); //Dictionary для кол-ва знаков после запятой (СС - кол-во знаков)
		Dictionary<int, int>^ maxLength = gcnew Dictionary<int, int>(); //Dictionary для кол-ва символо INT_MAX

		String^ lastDecimal = ""; //прошлое число в 10 СС
		String^ lastBinary = ""; //прошлое число в 2 СС
		String^ lastOctal = ""; //прошлое число в 8 СС
		String^ lastHexadecimal = ""; //прошлое число в 16 СС
		String^ lastChosen = ""; //прошлое число в выбранной СС

		int points = 0; //кол-во точек в числe
		int temporary; //временная переменная
		bool zero = false; //является ли число нулем


		public:
		void ReverseString(String^& str)
		{
			String^ temporaryorary = "";

			for (int i = str->Length - 1; i >= 0; i--)
			{
				temporaryorary += str[i];
			}

			str = temporaryorary;
		}
		//вторая часть отсеивания неверных символов
		void Symbols(TextBox^ textBoxInput, String^& inputNumber, String^& lastInputNumber, int& enterSystem)
		{
			temporary = textBoxInput->SelectionStart;
			inputNumber = textBoxInput->Text;
			inputNumber = inputNumber->ToUpper();
			textBoxInput->Text = inputNumber;
			labelErrors->Text = "";
			textBoxInput->SelectionStart = temporary;
			for (int i = 0; i < inputNumber->Length; i++)
			{
				if (inputNumber != lastInputNumber)
				{
					if (numbers10->ContainsKey(inputNumber->Substring(i, 1)))
					{
						if (numbers10[inputNumber->Substring(i, 1)] >= enterSystem)
						{
							inputNumber = lastInputNumber;
							textBoxInput->Text = inputNumber;
							textBoxInput->SelectionStart = i;
						}
						else if (i == 1 && inputNumber[0] == '0' || i == 2 && inputNumber[0] == '-' && inputNumber[1] == '0')
						{
							if (inputNumber[0] == '-')
							{
								if (textBoxInput->SelectionStart == 3)
								{
									inputNumber = inputNumber->Substring(0, i) + inputNumber->Substring(i + 1);
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i;
								}
								else if (textBoxInput->SelectionStart == 2)
								{
									inputNumber = inputNumber->Substring(0, 1) + inputNumber->Substring(2);
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = 1;
									for (int k = 1; k < inputNumber->Length; k++)
									{
										if (inputNumber[k] == '0')
										{
											inputNumber = inputNumber->Substring(0, 1) + inputNumber->Substring(2);;
											textBoxInput->Text = inputNumber;
											textBoxInput->SelectionStart = 1;
											k--;
										}
										else
											break;
									}
								}
							}
							else
							{
								if (textBoxInput->SelectionStart == 2)
								{
									inputNumber = inputNumber->Substring(0, i) + inputNumber->Substring(i + 1);
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i;
								}
								else if (textBoxInput->SelectionStart == 1)
								{
									inputNumber = inputNumber->Substring(1);
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = 0;
									for (int k = 0; k < inputNumber->Length; k++)
									{
										if (inputNumber[k] == '0')
										{
											inputNumber = inputNumber->Substring(1);
											textBoxInput->Text = inputNumber;
											k--;
										}
										else
											break;
									}
								}
							}
						}
						else if (i == 1 && inputNumber[0] == '0' && inputNumber[1] == '0' || i == 2 && inputNumber[0] == '-' && inputNumber[1] == '0' && inputNumber[2] == '0')
						{
							inputNumber = inputNumber->Substring(0, i) + inputNumber->Substring(i + 1);
							textBoxInput->Text = inputNumber;
							textBoxInput->SelectionStart = i;
						}
					}
					else
					{
						switch (inputNumber[i])
						{
						case '-':
							if (i != 0)
							{
								inputNumber = inputNumber->Substring(0, i) + inputNumber->Substring(i + 1);
								textBoxInput->Text = inputNumber;
								textBoxInput->SelectionStart = i;
							}
							break;
						case '.':
							if (points > 0)
							{
								inputNumber = inputNumber->Substring(0, i) + inputNumber->Substring(i + 1);
								textBoxInput->Text = inputNumber;
								textBoxInput->SelectionStart = i;
							}
							else
							{
								if (inputNumber == "." || inputNumber == "-.")
								{
									inputNumber = inputNumber->Replace(".", "");
									inputNumber += "0.";
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 2;
								}
								else if (inputNumber[0] == '.')
								{
									inputNumber = "0" + inputNumber;
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 2;
								}
								else if (inputNumber[0] == '-' && inputNumber[1] == '.')
								{
									inputNumber = inputNumber->Replace("-", "");
									inputNumber = "-" + "0" + inputNumber;
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 2;
								}
								else
								{
									points++;
								}
							}
							break;
						case ',':
							if (points > 0)
							{
								inputNumber = inputNumber->Substring(0, i) + inputNumber->Substring(i + 1);
								textBoxInput->Text = inputNumber;
								textBoxInput->SelectionStart = i;
							}
							else
							{
								if (inputNumber == "," || inputNumber == "-,")
								{
									inputNumber = inputNumber->Replace(",", "");
									inputNumber += "0.";
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 2;
								}
								else if (inputNumber[0] == ',')
								{
									inputNumber = inputNumber->Replace(",", "");
									inputNumber = "0." + inputNumber;
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 2;
								}
								else if (inputNumber[0] == '-' && inputNumber[1] == ',')
								{
									inputNumber = inputNumber->Replace("-", "");
									inputNumber = inputNumber->Replace(",", "");
									inputNumber = "-" + "0." + inputNumber;
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 2;
								}
								else
								{
									points++;
									inputNumber = inputNumber->Replace(",", ".");
									textBoxInput->Text = inputNumber;
									textBoxInput->SelectionStart = i + 1;
								}
							}
							break;
						default:
							inputNumber = lastInputNumber;
							textBoxInput->Text = inputNumber;
							textBoxInput->SelectionStart = i;
							break;
						}
					}
				}
				else
				{
					points = 0;
					break;
				}
			}
			points = 0;
		}
		//делим введенное число на целую и дробную части
		void Devide(String^& inputNumber,
			String^& inputNumberBeforePoint, String^& inputNumberAfterPoint)
		{
			for (int i = 0; i < inputNumber->Length; i++)
			{
				if (inputNumber[i] != '.')
				{
					if (inputNumber[i] != '-')
					{
						if (points == 0)
							inputNumberBeforePoint += inputNumber[i];
						else if (points == 1)
							inputNumberAfterPoint += inputNumber[i];
					}
				}
				else
					points++;
			}
			points = 0;
		}
		//проверка кол-ва знаков после запятой (точки)
		void CheckLength(TextBox^ textBoxInput, String^& inputNumber, String^& inputNumberAfterPoint,
			int& enterSystem)
		{
			if (inputNumberAfterPoint->Length > decimals[enterSystem])
			{
				temporary = textBoxInput->SelectionStart;
				textBoxInput->Text = inputNumber->Substring(0, inputNumber->Length - inputNumberAfterPoint->Length + decimals[enterSystem]);
				textBoxInput->SelectionStart = temporary;
				inputNumber = textBoxInput->Text;
			}
		}
		//переводим число в 10 СС
		void InputSystemTo10(String^& inputNumber,
			String^& inputNumberBeforePoint, String^& inputNumberAfterPoint,
			int& enterSystem, double& num10, int& num10BeforePoint, double& num10Fractional)
		{		
			//переводим в 10 СС целую часть числа
			for (int i = 0; i < inputNumberBeforePoint->Length; i++)
				num10BeforePoint += numbers10[inputNumberBeforePoint->Substring(i, 1)] * pow(enterSystem, inputNumberBeforePoint->Length - i - 1);
			//переводим в 10 СС дробную часть числа 
			if (inputNumberAfterPoint != "")
			{
				for (int i = 0; i < inputNumberAfterPoint->Length && i < 30; i++)
					num10Fractional += numbers10[inputNumberAfterPoint->Substring(i, 1)] * pow(enterSystem, -(i + 1));
			}

			num10 = num10BeforePoint + num10Fractional;
		}
		//переводим число в нужную СС
		void ToOutput(TextBox^ textBoxInput, TextBox^ textBoxOutput, String^& inputNumber,
			int num10BeforePoint, double num10Fractional, String^ strNum10Fractional,
			String^& outputNumber, String^& outputNumberBeforePoint, String^& outputAfterPoint,
			int outputSystem)
		{
			if (textBoxInput->Text != "")
			{
				//переводим целую часть числа из 10 СС в нужную СС
				if (num10BeforePoint != 0)
				{
					while (num10BeforePoint != 0)
					{
						outputNumberBeforePoint += numbers[num10BeforePoint % outputSystem];
						num10BeforePoint /= outputSystem;
					}
					ReverseString(outputNumberBeforePoint);
				}
				else
					outputNumberBeforePoint = "0";
			}
			//переводим дробную часть числа из 10 СС нужную СС
			while (num10Fractional >= 1)
				num10Fractional /= 10;
			for (int i = 0; num10Fractional != 0 && i < decimals[outputSystem]; i++)
			{
				num10Fractional *= outputSystem;
				temporary = num10Fractional;
				if (num10Fractional != 0)
				{
					outputAfterPoint += numbers[temporary];
					if (temporary != 0)
					{
						for (int i = 0; i < num10Fractional.ToString()->Length; i++)
						{
							if (num10Fractional.ToString()[i] != ',')
							{
								if (points == 1)
									strNum10Fractional += num10Fractional.ToString()[i];
							}
							else
							{
								points++;
							}
						}
						points = 0;
						System::Globalization::CultureInfo^ culture = System::Globalization::CultureInfo::InvariantCulture;
						num10Fractional = System::Double::Parse(strNum10Fractional, culture);
						strNum10Fractional = "0.";
					}
				}
			}
			if (outputAfterPoint != "")
			{
				outputNumber += outputNumberBeforePoint + "." + outputAfterPoint;
			}
			else
				outputNumber = outputNumberBeforePoint;

			for (int i = 0; i < outputNumber->Length; i++)
			{
				if (outputNumber[i] != '-' && outputNumber[i] != '.')
				{
					if (outputNumber[i] == '0')
					{
						if (i == outputNumber->Length - 1)
							zero = true;
					}
					else
					{
						zero = false;
						break;
					}
				}
			}
			if (!zero)
			{
				if (inputNumber != "")
				{
					if (inputNumber[0] == '-')
						outputNumber = "-" + outputNumber;
				}
			}
			zero = false;

			textBoxOutput->Text = outputNumber;
		}
private: System::Windows::Forms::Label^ labelErrors;
public:

public:


		   
	
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

			decimals->Add(2, 20);
			decimals->Add(3, 18);
			decimals->Add(4, 16);
			decimals->Add(5, 14);
			decimals->Add(6, 12);
			decimals->Add(7, 10);
			decimals->Add(8, 8);
			decimals->Add(9, 7);
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
			decimals->Add(31, 5);
			decimals->Add(32, 5);
			decimals->Add(33, 5);
			decimals->Add(34, 5);
			decimals->Add(35, 5);
			decimals->Add(36, 5);

			maxLength->Add(2, 31);
			maxLength->Add(3, 20);
			maxLength->Add(4, 16);
			maxLength->Add(5, 14);
			maxLength->Add(6, 12);
			maxLength->Add(7, 12);
			maxLength->Add(8, 11);
			maxLength->Add(9, 10);
			maxLength->Add(10, 10);
			maxLength->Add(11, 9);
			maxLength->Add(12, 9);
			maxLength->Add(13, 9);
			maxLength->Add(14, 9);
			maxLength->Add(15, 8);
			maxLength->Add(16, 8);
			maxLength->Add(17, 8);
			maxLength->Add(18, 8);
			maxLength->Add(19, 8);
			maxLength->Add(20, 8);
			maxLength->Add(21, 8);
			maxLength->Add(22, 7);
			maxLength->Add(23, 7);
			maxLength->Add(24, 7);
			maxLength->Add(25, 7);
			maxLength->Add(26, 7);
			maxLength->Add(27, 7);
			maxLength->Add(28, 7);
			maxLength->Add(29, 7);
			maxLength->Add(30, 7);
			maxLength->Add(31, 7);
			maxLength->Add(32, 7);
			maxLength->Add(33, 7);
			maxLength->Add(34, 7);
			maxLength->Add(35, 7);
			maxLength->Add(36, 6);
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
			this->labelErrors = (gcnew System::Windows::Forms::Label());
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
			this->textBoxBinary->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxBinary_TextChanged);
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
			this->textBoxOctal->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxOctal_TextChanged);
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
			this->textBoxHexadecimal->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
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
			this->comboBoxChoice->TextChanged += gcnew EventHandler(this, &MyForm::comboBoxChoice_TextChanged);
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
			this->textBoxChosen->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxChosen_TextChanged);
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
			// labelErrors
			// 
			this->labelErrors->AutoSize = true;
			this->labelErrors->Location = System::Drawing::Point(214, 9);
			this->labelErrors->Name = L"labelErrors";
			this->labelErrors->Size = System::Drawing::Size(23, 25);
			this->labelErrors->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 415);
			this->Controls->Add(this->labelErrors);
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
	//переменные
	int inputSystem = 10; //входящая СС
	double number10; //число в 10 СС
	int number10BeforePoint = 0; //целая часть числа в 10 СС
	double number10Fractional = 0; //дробная часть числа в 10 СС
	String^ strNumber10BeforePoint = ""; //число в 10 СС до точки (строкой)
	String^ strNumber10Fractional = ""; // число в 10 СС после точки (строкой)

	String^ decimal = ""; //переменная для хранения числа в 10 СС
	String^ decimalBeforePoint = ""; //число в 10 СС до точки
	String^ decimalAfterPoint = ""; //число в 10 СС после точки
	String^ last10 = lastDecimal; //копия прошлого числа в 10 СС
	
	String^ binary = ""; //число в 2 СС
	String^ binaryBeforePoint = ""; //число в 2 СС до точки
	String^ binaryAfterPoint = ""; //число в 2 СС после точки

	String^ octal = ""; //число в 8 СС
	String^ octalBeforePoint = ""; //число в 8 СС до точки
	String^ octalAfterPoint = ""; //число в 8 СС после точки

	String^ hexadecimal = ""; //число в 16 СС
	String^ hexadecimalBeforePoint = ""; //число в 16 СС до точки
	String^ hexadecimalAfterPoint = ""; //число в 16 СС после точки

	String^ chosen = ""; //число в выбранной СС
	String^ chosenBeforePoint = ""; //число в выбранной СС до точки
	String^ chosenAfterPoint = ""; //число в выбранной СС после точки


	if (textBoxDecimal->Text != "")
	{
		//разрешаем вводить только нужные символы (2)
		textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
		Symbols(textBoxDecimal, decimal, last10, inputSystem);
		textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);

		if (decimal != lastDecimal)
		{
			Devide(decimal, decimalBeforePoint, decimalAfterPoint);
			textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			CheckLength(textBoxDecimal, decimal, decimalAfterPoint, inputSystem);
			textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			InputSystemTo10(decimal, decimalBeforePoint, decimalAfterPoint, inputSystem, number10, number10BeforePoint, number10Fractional);
		}
	}

	if (decimal != lastDecimal)
	{
		lastDecimal = decimal;
		strNumber10Fractional = "0.";
		if (decimalBeforePoint->Length < maxLength[10])
		{
			textBoxBinary->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			ToOutput(textBoxDecimal, textBoxBinary, decimal, number10BeforePoint, number10Fractional, strNumber10Fractional, binary, binaryBeforePoint, binaryAfterPoint, 2);
			textBoxBinary->TextChanged += gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			lastBinary = binary;

			textBoxOctal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			ToOutput(textBoxDecimal, textBoxOctal, decimal, number10BeforePoint, number10Fractional, strNumber10Fractional, octal, octalBeforePoint, octalAfterPoint, 8);
			textBoxOctal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			lastOctal = octal;

			textBoxHexadecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			ToOutput(textBoxDecimal, textBoxHexadecimal, decimal, number10BeforePoint, number10Fractional, strNumber10Fractional, hexadecimal, hexadecimalBeforePoint, hexadecimalAfterPoint, 16);
			textBoxHexadecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			lastHexadecimal = hexadecimal;

			if (comboBoxChoice->Text != "")
			{
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				ToOutput(textBoxDecimal, textBoxChosen, decimal, number10BeforePoint, number10Fractional, strNumber10Fractional, chosen, chosenBeforePoint, chosenAfterPoint, System::Int32::Parse(comboBoxChoice->Text));
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				lastChosen = chosen;
			}
		}
		else
		{
			textBoxDecimal->Text = "";
			labelErrors->Text = "ERROR";
		}
	}
}

private: System::Void textBoxBinary_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//переменные
	int inputSystem = 2; //входящая СС
	double number10; //число в 10 СС
	int number10BeforePoint = 0; //целая часть числа в 10 СС
	double number10Fractional = 0; //дробная часть числа в 10 СС
	String^ strNumber10BeforePoint = ""; //число в 10 СС до точки (строкой)
	String^ strNumber10Fractional = ""; // число в 10 СС после точки (строкой)

	String^ decimal = ""; //переменная для хранения числа в 10 СС
	String^ decimalBeforePoint = ""; //число в 10 СС до точки
	String^ decimalAfterPoint = ""; //число в 10 СС после точки
	
	String^ binary = ""; //число в 2 СС
	String^ binaryBeforePoint = ""; //число в 2 СС до точки
	String^ binaryAfterPoint = ""; //число в 2 СС после точки
	String^ last2 = lastBinary; //копия прошлого числа в 2 СС

	String^ octal = ""; //число в 8 СС
	String^ octalBeforePoint = ""; //число в 8 СС до точки
	String^ octalAfterPoint = ""; //число в 8 СС после точки

	String^ hexadecimal = ""; //число в 16 СС
	String^ hexadecimalBeforePoint = ""; //число в 16 СС до точки
	String^ hexadecimalAfterPoint = ""; //число в 16 СС после точки

	String^ chosen = ""; //число в выбранной СС
	String^ chosenBeforePoint = ""; //число в выбранной СС до точки
	String^ chosenAfterPoint = ""; //число в выбранной СС после точки


	if (textBoxBinary->Text != "")
	{
		//разрешаем вводить только нужные символы (2)
		textBoxBinary->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
		Symbols(textBoxBinary, binary, last2, inputSystem);
		textBoxBinary->TextChanged += gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);

		if (binary != lastBinary)
		{
			Devide(binary, binaryBeforePoint, binaryAfterPoint);
			textBoxBinary->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			CheckLength(textBoxBinary, binary, binaryAfterPoint, inputSystem);
			textBoxBinary->TextChanged += gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			InputSystemTo10(binary, binaryBeforePoint, binaryAfterPoint, inputSystem, number10, number10BeforePoint, number10Fractional);
		}
	}

	if (binary != lastBinary)
	{
		lastBinary = binary;
		strNumber10Fractional = "0.";
		if (binaryBeforePoint->Length < maxLength[inputSystem])
		{
			textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			ToOutput(textBoxBinary, textBoxDecimal, binary, number10BeforePoint, number10Fractional, strNumber10Fractional, decimal, decimalBeforePoint, decimalAfterPoint, 10);
			textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			lastDecimal = decimal;

			textBoxOctal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			ToOutput(textBoxBinary, textBoxOctal, binary, number10BeforePoint, number10Fractional, strNumber10Fractional, octal, octalBeforePoint, octalAfterPoint, 8);
			textBoxOctal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			lastOctal = octal;

			textBoxHexadecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			ToOutput(textBoxBinary, textBoxHexadecimal, binary, number10BeforePoint, number10Fractional, strNumber10Fractional, hexadecimal, hexadecimalBeforePoint, hexadecimalAfterPoint, 16);
			textBoxHexadecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			lastHexadecimal = hexadecimal;

			if (comboBoxChoice->Text != "")
			{
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				ToOutput(textBoxBinary, textBoxChosen, binary, number10BeforePoint, number10Fractional, strNumber10Fractional, chosen, chosenBeforePoint, chosenAfterPoint, System::Int32::Parse(comboBoxChoice->Text));
				textBoxChosen->TextChanged += gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				lastChosen = chosen;
			}
		}
		else
		{
			textBoxBinary->Text = "";
			labelErrors->Text = "ERROR";
		}
	}
}

private: System::Void textBoxOctal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//переменные
	int inputSystem = 8; //входящая СС
	double number10; //число в 10 СС
	int number10BeforePoint = 0; //целая часть числа в 10 СС
	double number10Fractional = 0; //дробная часть числа в 10 СС
	String^ strNumber10BeforePoint = ""; //число в 10 СС до точки (строкой)
	String^ strNumber10Fractional = ""; // число в 10 СС после точки (строкой)

	String^ decimal = ""; //переменная для хранения числа в 10 СС
	String^ decimalBeforePoint = ""; //число в 10 СС до точки
	String^ decimalAfterPoint = ""; //число в 10 СС после точки

	String^ binary = ""; //число в 2 СС
	String^ binaryBeforePoint = ""; //число в 2 СС до точки
	String^ binaryAfterPoint = ""; //число в 2 СС после точки

	String^ octal = ""; //число в 8 СС
	String^ octalBeforePoint = ""; //число в 8 СС до точки
	String^ octalAfterPoint = ""; //число в 8 СС после точки
	String^ last8 = lastOctal; //копия прошлого числа в 8 СС

	String^ hexadecimal = ""; //число в 16 СС
	String^ hexadecimalBeforePoint = ""; //число в 16 СС до точки
	String^ hexadecimalAfterPoint = ""; //число в 16 СС после точки

	String^ chosen = ""; //число в выбранной СС
	String^ chosenBeforePoint = ""; //число в выбранной СС до точки
	String^ chosenAfterPoint = ""; //число в выбранной СС после точки


	if (textBoxOctal->Text != "")
	{
		//разрешаем вводить только нужные символы (2)
		textBoxOctal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
		Symbols(textBoxOctal, octal, last8, inputSystem);
		textBoxOctal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);

		if (octal != lastOctal)
		{
			Devide(octal, octalBeforePoint, octalAfterPoint);
			textBoxOctal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			CheckLength(textBoxOctal, octal, octalAfterPoint, inputSystem);
			textBoxOctal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			InputSystemTo10(octal, octalBeforePoint, octalAfterPoint, inputSystem, number10, number10BeforePoint, number10Fractional);
		}
	}

	if (octal != lastOctal)
	{
		lastOctal = octal;
		strNumber10Fractional = "0.";
		if (octalBeforePoint->Length < maxLength[inputSystem])
		{
			textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			ToOutput(textBoxOctal, textBoxDecimal, octal, number10BeforePoint, number10Fractional, strNumber10Fractional, decimal, decimalBeforePoint, decimalAfterPoint, 10);
			textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);

			textBoxBinary->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			ToOutput(textBoxOctal, textBoxBinary, octal, number10BeforePoint, number10Fractional, strNumber10Fractional, binary, binaryBeforePoint, binaryAfterPoint, 2);
			textBoxBinary->TextChanged += gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);

			textBoxHexadecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			ToOutput(textBoxOctal, textBoxHexadecimal, octal, number10BeforePoint, number10Fractional, strNumber10Fractional, hexadecimal, hexadecimalBeforePoint, hexadecimalAfterPoint, 16);
			textBoxHexadecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			lastHexadecimal = hexadecimal;

			if (comboBoxChoice->Text != "")
			{
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				ToOutput(textBoxOctal, textBoxChosen, octal, number10BeforePoint, number10Fractional, strNumber10Fractional, chosen, chosenBeforePoint, chosenAfterPoint, System::Int32::Parse(comboBoxChoice->Text));
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				lastChosen = chosen;
			}
		}
		else
		{
			textBoxOctal->Text = "";
			labelErrors->Text = "ERROR";
		}
	}
}

private: System::Void textBoxHexadecimal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//переменные
	int inputSystem = 16; //входящая СС
	double number10; //число в 10 СС
	int number10BeforePoint = 0; //целая часть числа в 10 СС
	double number10Fractional = 0; //дробная часть числа в 10 СС
	String^ strNumber10BeforePoint = ""; //число в 10 СС до точки (строкой)
	String^ strNumber10Fractional = ""; // число в 10 СС после точки (строкой)

	String^ decimal = ""; //переменная для хранения числа в 10 СС
	String^ decimalBeforePoint = ""; //число в 10 СС до точки
	String^ decimalAfterPoint = ""; //число в 10 СС после точки

	String^ binary = ""; //число в 2 СС
	String^ binaryBeforePoint = ""; //число в 2 СС до точки
	String^ binaryAfterPoint = ""; //число в 2 СС после точки

	String^ octal = ""; //число в 8 СС
	String^ octalBeforePoint = ""; //число в 8 СС до точки
	String^ octalAfterPoint = ""; //число в 8 СС после точки

	String^ hexadecimal = ""; //число в 16 СС
	String^ hexadecimalBeforePoint = ""; //число в 16 СС до точки
	String^ hexadecimalAfterPoint = ""; //число в 16 СС после точки
	String^ last16 = lastHexadecimal; //копия прошлого числа в 16 СС

	String^ chosen = ""; //число в выбранной СС
	String^ chosenBeforePoint = ""; //число в выбранной СС до точки
	String^ chosenAfterPoint = ""; //число в выбранной СС после точки


	if (textBoxHexadecimal->Text != "")
	{
		//разрешаем вводить только нужные символы (2)
		textBoxHexadecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
		Symbols(textBoxHexadecimal, hexadecimal, last16, inputSystem);
		textBoxHexadecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);

		if (hexadecimal != lastHexadecimal)
		{
			Devide(hexadecimal, hexadecimalBeforePoint, hexadecimalAfterPoint);
			textBoxHexadecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			CheckLength(textBoxHexadecimal, hexadecimal, hexadecimalAfterPoint, inputSystem);
			textBoxHexadecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
			InputSystemTo10(hexadecimal, hexadecimalBeforePoint, hexadecimalAfterPoint, inputSystem, number10, number10BeforePoint, number10Fractional);
		}
	}

	if (hexadecimal != lastHexadecimal)
	{
		lastHexadecimal = hexadecimal;
		strNumber10Fractional = "0.";
		if (hexadecimalBeforePoint->Length < maxLength[inputSystem])
		{
			textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			ToOutput(textBoxHexadecimal, textBoxDecimal, hexadecimal, number10BeforePoint, number10Fractional, strNumber10Fractional, decimal, decimalBeforePoint, decimalAfterPoint, 10);
			textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
			lastDecimal = decimal;

			textBoxBinary->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			ToOutput(textBoxHexadecimal, textBoxBinary, hexadecimal, number10BeforePoint, number10Fractional, strNumber10Fractional, binary, binaryBeforePoint, binaryAfterPoint, 2);
			textBoxBinary->TextChanged += gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
			lastBinary = binary;

			textBoxOctal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			ToOutput(textBoxHexadecimal, textBoxOctal, hexadecimal, number10BeforePoint, number10Fractional, strNumber10Fractional, octal, octalBeforePoint, octalAfterPoint, 8);
			textBoxOctal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
			lastOctal = octal;

			if (comboBoxChoice->Text != "")
			{
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				ToOutput(textBoxHexadecimal, textBoxChosen, hexadecimal, number10BeforePoint, number10Fractional, strNumber10Fractional, chosen, chosenBeforePoint, chosenAfterPoint, System::Int32::Parse(comboBoxChoice->Text));
				textBoxChosen->TextChanged += gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				lastChosen = chosen;
			}
		}
		else
		{
			textBoxHexadecimal->Text = "";
			labelErrors->Text = "ERROR";
		}
	}
}

private: System::Void textBoxChosen_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxChoice->Text != "")
	{
		//переменные

		int inputSystem = System::Int32::Parse(comboBoxChoice->Text); //входящая СС
		double number10; //число в 10 СС
		int number10BeforePoint = 0; //целая часть числа в 10 СС
		double number10Fractional = 0; //дробная часть числа в 10 СС
		String^ strNumber10BeforePoint = ""; //число в 10 СС до точки (строкой)
		String^ strNumber10Fractional = ""; // число в 10 СС после точки (строкой)

		String^ decimal = ""; //переменная для хранения числа в 10 СС
		String^ decimalBeforePoint = ""; //число в 10 СС до точки
		String^ decimalAfterPoint = ""; //число в 10 СС после точки

		String^ binary = ""; //число в 2 СС
		String^ binaryBeforePoint = ""; //число в 2 СС до точки
		String^ binaryAfterPoint = ""; //число в 2 СС после точки

		String^ octal = ""; //число в 8 СС
		String^ octalBeforePoint = ""; //число в 8 СС до точки
		String^ octalAfterPoint = ""; //число в 8 СС после точки

		String^ hexadecimal = ""; //число в 16 СС
		String^ hexadecimalBeforePoint = ""; //число в 16 СС до точки
		String^ hexadecimalAfterPoint = ""; //число в 16 СС после точки

		String^ chosen = ""; //число в выбранной СС
		String^ chosenBeforePoint = ""; //число в выбранной СС до точки
		String^ chosenAfterPoint = ""; //число в выбранной СС после точки
		String^ lastC = lastChosen; //копия прошлого числа в выбранной СС


		if (textBoxChosen->Text != "")
		{
			//разрешаем вводить только нужные символы (2)
			textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
			Symbols(textBoxChosen, chosen, lastC, inputSystem);
			textBoxChosen->TextChanged += gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);

			if (chosen != lastChosen)
			{
				Devide(chosen, chosenBeforePoint, chosenAfterPoint);
				textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				CheckLength(textBoxChosen, chosen, chosenAfterPoint, inputSystem);
				textBoxChosen->TextChanged += gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
				InputSystemTo10(chosen, chosenBeforePoint, chosenAfterPoint, inputSystem, number10, number10BeforePoint, number10Fractional);
			}
		}

		if (chosen != lastChosen)
		{
			lastChosen = chosen;
			strNumber10Fractional = "0.";
			if (chosenBeforePoint->Length < maxLength[inputSystem])
			{
				textBoxDecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
				ToOutput(textBoxChosen, textBoxDecimal, chosen, number10BeforePoint, number10Fractional, strNumber10Fractional, decimal, decimalBeforePoint, decimalAfterPoint, 10);
				textBoxDecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxDecimal_TextChanged);
				lastDecimal = decimal;

				textBoxBinary->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
				ToOutput(textBoxChosen, textBoxBinary, chosen, number10BeforePoint, number10Fractional, strNumber10Fractional, binary, binaryBeforePoint, binaryAfterPoint, 2);
				textBoxBinary->TextChanged += gcnew EventHandler(this, &MyForm::textBoxBinary_TextChanged);
				lastBinary = binary;

				textBoxOctal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
				ToOutput(textBoxChosen, textBoxOctal, chosen, number10BeforePoint, number10Fractional, strNumber10Fractional, octal, octalBeforePoint, octalAfterPoint, 8);
				textBoxOctal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxOctal_TextChanged);
				lastOctal = octal;

				textBoxHexadecimal->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
				ToOutput(textBoxChosen, textBoxHexadecimal, chosen, number10BeforePoint, number10Fractional, strNumber10Fractional, hexadecimal, hexadecimalBeforePoint, hexadecimalAfterPoint, 16);
				textBoxHexadecimal->TextChanged += gcnew EventHandler(this, &MyForm::textBoxHexadecimal_TextChanged);
				lastHexadecimal = hexadecimal;
			}
			else
			{
				textBoxChosen->Text = "";
				labelErrors->Text = "ERROR";
			}
		}
	}
	else
	{
		textBoxChosen->Text = "";
		labelErrors->Text = "Choose a basis";
	}
}

private: System::Void comboBoxChoice_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	labelErrors->Text = "";
	if (textBoxDecimal->Text != "")
	{
		//переменные
		int inputSystem = 10;
		double number10; //число в 10 СС
		int number10BeforePoint = 0; //целая часть числа в 10 СС
		double number10Fractional = 0; //дробная часть числа в 10 СС
		String^ strNumber10Fractional = "0."; // число в 10 СС после точки (строкой)

		String^ decimal = textBoxDecimal->Text; //переменная для хранения числа в 10 СС
		String^ decimalBeforePoint = ""; //число в 10 СС до точки
		String^ decimalAfterPoint = ""; //число в 10 СС после точки

		String^ chosen = ""; //число в выбранной СС
		String^ chosenBeforePoint = ""; //число в выбранной СС до точки
		String^ chosenAfterPoint = ""; //число в выбранной СС после точки
		int chosenSystem = System::Int32::Parse(comboBoxChoice->Text);


		Devide(decimal, decimalBeforePoint, decimalAfterPoint);
		InputSystemTo10(decimal, decimalBeforePoint, decimalAfterPoint, inputSystem, number10, number10BeforePoint, number10Fractional);
		textBoxChosen->TextChanged -= gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
		ToOutput(textBoxDecimal, textBoxChosen, decimal, number10BeforePoint, number10Fractional, strNumber10Fractional, chosen, chosenBeforePoint, chosenAfterPoint, chosenSystem);
		textBoxChosen->TextChanged += gcnew EventHandler(this, &MyForm::textBoxChosen_TextChanged);
		lastChosen = chosen;
	}
}
};
}
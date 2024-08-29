#pragma once
#include <map>

using namespace System::Collections::Generic;

namespace Numbersystems {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private:
		Dictionary<String^, int>^ numbers10 = gcnew Dictionary<String^, int>(); //Dictionary для перевода в 10 СС
		Dictionary<int, String^>^ numbers = gcnew Dictionary<int, String^>(); //Dictionary для перевода из 10 СС
		Dictionary<int, int>^ decimals = gcnew Dictionary<int, int>(); //Dictionary для кол-ва знаков после запятой (СС - кол-во знаков)
		Dictionary<int, int>^ maxLength = gcnew Dictionary<int, int>(); //Dictionary для кол-ва символо INT_MAX

		String^ lastFirst = ""; //прошлое первое число
		String^ lastSecond = ""; //прошлое второе число

		int points = 0; //кол-во точек в числe
		int temporary; //временная переменная
		bool zero = false; //является ли число нулем
	private: System::Windows::Forms::ListBox^ listBoxOperation;

	public:
		//разворот строки
		void ReverseString(String^& str)
		{
			String^ temporaryorary = "";

			for (int i = str->Length - 1; i >= 0; i--)
			{
				temporaryorary += str[i];
			}

			str = temporaryorary;
		}
		//отсеиваниe неверных символов
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
								else
									points++;
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
				
				inputNumberAfterPoint = "";
				for (int i = inputNumber->Length - 1; i > 1; i--)
				{
					if (inputNumber[i] != '.')
						inputNumberAfterPoint += inputNumber[i];
					else
						break;
				}
				ReverseString(inputNumberAfterPoint);
			}
		}
		//является ли число нулем
		bool IsZero(TextBox^ textBox)
		{
			for (int i = 0; i < textBox->Text->Length; i++)
			{
				if (textBox->Text[i] != '0' && textBox->Text[i] != '-' && textBox->Text[i] != ',')
					return false;
			}
		}
		//является ли число не целым
		bool IsFractional (TextBox^ textBoxS)
		{
			for (int i = 0; i < textBoxS->Text->Length; i++)
			{
				if (textBoxS->Text[i] == '.')
					points++;
				else if (points == 1 && textBoxS->Text[i] != '0')
				{
					points = 0;
					return true;
				}
			}
			points = 0;
			return false;
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
			if (inputNumber[0] == '-')
				num10 *= -1;
		}
		//считаем
		void Count(double& total10, String^& strTotal10, int& total10BeforePoint, double& total10Fractional, double& first10, double& second10)
		{
			switch (listBoxOperation->Text[0])
			{
			case '+':
				total10 = first10 + second10;
				break;
			case '-':
				total10 = first10 - second10;
				break;
			case '*':
				total10 = first10 * second10;
				break;
			case '/':
				total10 = first10 / second10;
				break;
			case '^':
				total10 = pow(first10, second10);
				break;
			}

			strTotal10 = System::Convert::ToString(total10);
			total10BeforePoint = total10;
			total10Fractional = total10 - total10BeforePoint;
			if (System::Convert::ToString(total10)[0] == '-')
			{
				total10BeforePoint *= -1;
				total10Fractional *= -1;
			}
		}
		//переводим ответ в нужную СС
		void ToOutput(TextBox^ textBoxOutput, String^& inputNumber,
			int num10BeforePoint, double num10Fractional, String^ strNum10Fractional,
			String^& outputNumber, String^& outputNumberBeforePoint, String^& outputAfterPoint,
			int outputSystem)
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
				if (outputNumber != "0")
				{
					for (int i = outputNumber->Length - 1; i >= 0; i--)
					{
						if (outputNumber[i] == '0')
							outputNumber = outputNumber->Substring(0, outputNumber->Length - 1);
						else
							break;
					}
					if (outputNumber[outputNumber->Length - 1] == '.')
						outputNumber = outputNumber->Substring(0, outputNumber->Length - 1);
				}
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
					if (System::Convert::ToString(inputNumber)[0] == '-')
						outputNumber = "-" + outputNumber;
			}
			zero = false;

			textBoxOutput->Text = outputNumber;
		}
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxFirst;
	private: System::Windows::Forms::TextBox^ textBoxSecond;
	private: System::Windows::Forms::ComboBox^ comboBoxFirst;

	protected:





	private: System::Windows::Forms::ComboBox^ comboBoxSecond;
	private: System::Windows::Forms::ComboBox^ comboBoxAnswer;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxAnswer;
	private: System::Windows::Forms::Label^ labelErrors;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->textBoxFirst = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSecond = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxFirst = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxSecond = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAnswer = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxAnswer = (gcnew System::Windows::Forms::TextBox());
			this->labelErrors = (gcnew System::Windows::Forms::Label());
			this->listBoxOperation = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// textBoxFirst
			// 
			this->textBoxFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxFirst->Location = System::Drawing::Point(13, 65);
			this->textBoxFirst->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxFirst->Name = L"textBoxFirst";
			this->textBoxFirst->Size = System::Drawing::Size(403, 30);
			this->textBoxFirst->TabIndex = 6;
			this->textBoxFirst->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBoxFirst_TextChanged);
			// 
			// textBoxSecond
			// 
			this->textBoxSecond->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSecond->Location = System::Drawing::Point(13, 240);
			this->textBoxSecond->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxSecond->Name = L"textBoxSecond";
			this->textBoxSecond->Size = System::Drawing::Size(403, 30);
			this->textBoxSecond->TabIndex = 7;
			this->textBoxSecond->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBoxSecond_TextChanged);
			// 
			// comboBoxFirst
			// 
			this->comboBoxFirst->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxFirst->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxFirst->FormattingEnabled = true;
			this->comboBoxFirst->IntegralHeight = false;
			this->comboBoxFirst->ItemHeight = 25;
			this->comboBoxFirst->Items->AddRange(gcnew cli::array< System::Object^  >(35) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", L"27",
					L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36"
			});
			this->comboBoxFirst->Location = System::Drawing::Point(423, 62);
			this->comboBoxFirst->Name = L"comboBoxFirst";
			this->comboBoxFirst->Size = System::Drawing::Size(63, 33);
			this->comboBoxFirst->TabIndex = 9;
			this->comboBoxFirst->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::comboBoxFirst_SelectedIndexChanged);
			// 
			// comboBoxSecond
			// 
			this->comboBoxSecond->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxSecond->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxSecond->FormattingEnabled = true;
			this->comboBoxSecond->IntegralHeight = false;
			this->comboBoxSecond->ItemHeight = 25;
			this->comboBoxSecond->Items->AddRange(gcnew cli::array< System::Object^  >(35) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36"
			});
			this->comboBoxSecond->Location = System::Drawing::Point(423, 237);
			this->comboBoxSecond->Name = L"comboBoxSecond";
			this->comboBoxSecond->Size = System::Drawing::Size(63, 33);
			this->comboBoxSecond->TabIndex = 13;
			this->comboBoxSecond->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::comboBoxSecond_SelectedIndexChanged);
			// 
			// comboBoxAnswer
			// 
			this->comboBoxAnswer->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAnswer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxAnswer->FormattingEnabled = true;
			this->comboBoxAnswer->IntegralHeight = false;
			this->comboBoxAnswer->ItemHeight = 25;
			this->comboBoxAnswer->Items->AddRange(gcnew cli::array< System::Object^  >(35) {
				L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36"
			});
			this->comboBoxAnswer->Location = System::Drawing::Point(423, 331);
			this->comboBoxAnswer->Name = L"comboBoxAnswer";
			this->comboBoxAnswer->Size = System::Drawing::Size(63, 33);
			this->comboBoxAnswer->TabIndex = 14;
			this->comboBoxAnswer->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::comboBoxAnswer_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(418, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 25);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Basis";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(418, 209);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 25);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Basis";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(418, 303);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 25);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Basis";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(240, 275);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 29);
			this->label3->TabIndex = 18;
			this->label3->Text = L"=";
			// 
			// textBoxAnswer
			// 
			this->textBoxAnswer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxAnswer->Location = System::Drawing::Point(13, 334);
			this->textBoxAnswer->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBoxAnswer->Name = L"textBoxAnswer";
			this->textBoxAnswer->ReadOnly = true;
			this->textBoxAnswer->Size = System::Drawing::Size(403, 30);
			this->textBoxAnswer->TabIndex = 8;
			// 
			// labelErrors
			// 
			this->labelErrors->AutoSize = true;
			this->labelErrors->Location = System::Drawing::Point(210, 20);
			this->labelErrors->Name = L"labelErrors";
			this->labelErrors->Size = System::Drawing::Size(0, 25);
			this->labelErrors->TabIndex = 19;
			// 
			// listBoxOperation
			// 
			this->listBoxOperation->FormattingEnabled = true;
			this->listBoxOperation->ItemHeight = 25;
			this->listBoxOperation->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"+", L"-", L"*", L"/", L"^" });
			this->listBoxOperation->Location = System::Drawing::Point(168, 110);
			this->listBoxOperation->Name = L"listBoxOperation";
			this->listBoxOperation->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBoxOperation->Size = System::Drawing::Size(168, 104);
			this->listBoxOperation->TabIndex = 12;
			this->listBoxOperation->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::listBoxOperation_SelectedIndexChanged);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 415);
			this->Controls->Add(this->labelErrors);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxAnswer);
			this->Controls->Add(this->comboBoxSecond);
			this->Controls->Add(this->listBoxOperation);
			this->Controls->Add(this->comboBoxFirst);
			this->Controls->Add(this->textBoxAnswer);
			this->Controls->Add(this->textBoxSecond);
			this->Controls->Add(this->textBoxFirst);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Number systems";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void textBoxFirst_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	labelErrors->Text = "";
	if (comboBoxFirst->Text != "")
	{
		//переменные
		int firstSystem = System::Int32::Parse(comboBoxFirst->Text); //СС первого числа

		double firstNumber10; //первое число в 10 СС
		int firstNumber10BeforePoint = 0; //целая часть первого числа в 10 СС
		double firstNumber10Fractional = 0; //дробная часть первого числа в 10 СС

		String^ first = ""; //первое число
		String^ firstBeforePoint = ""; //первое число до точки
		String^ firstAfterPoint = ""; //первое число после точки
		String^ lastF = lastFirst; //копия прошлого первого числа

		if (textBoxFirst->Text != "")
		{
			//разрешаем вводить только нужные символы
			textBoxFirst->TextChanged -= gcnew EventHandler(this, &MyForm1::textBoxFirst_TextChanged);
			Symbols(textBoxFirst, first, lastF, firstSystem);
			textBoxFirst->TextChanged += gcnew EventHandler(this, &MyForm1::textBoxFirst_TextChanged);
			Devide(first, firstBeforePoint, firstAfterPoint);

			if (firstBeforePoint->Length < maxLength[firstSystem])
			{
				lastFirst = first;

				textBoxFirst->TextChanged -= gcnew EventHandler(this, &MyForm1::textBoxFirst_TextChanged);
				CheckLength(textBoxFirst, first, firstAfterPoint, firstSystem);
				textBoxFirst->TextChanged += gcnew EventHandler(this, &MyForm1::textBoxFirst_TextChanged);

				if (textBoxFirst->Text != "" && textBoxFirst->Text != "-" &&
					textBoxSecond->Text != "" && textBoxSecond->Text != "-" &&
					comboBoxAnswer->Text != "" &&
					listBoxOperation->Text != "")
				{
					if (!(textBoxFirst->Text[0] == '-' && listBoxOperation->Text[0] == '^' && IsFractional(textBoxSecond)))
					{
						//переменные
						int secondSystem = System::Int32::Parse(comboBoxSecond->Text); //СС второго числа
						int answerSystem = System::Int32::Parse(comboBoxAnswer->Text); //СС ответа

						double secondNumber10; //второе число в 10 СС
						int secondNumber10BeforePoint = 0; //целая часть второго числа в 10 СС
						double secondNumber10Fractional = 0; //дробная часть второго числа в 10 СС

						String^ second = textBoxSecond->Text; //второе число
						String^ secondBeforePoint = ""; //второе число до точки
						String^ secondAfterPoint = ""; //второе число после точки
						String^ lastS = lastSecond; //копия прошлого второго числа

						double answer10; //ответ в 10 СС
						String^ strAnswer10 = ""; //ответ в 10 СС (строкой)
						int answer10BeforePoint; //ответ в 10 СС до точки
						double answer10Fractional; //десятичная часть ответа в 10 СС
						String^ strAnswer10Fractional = "0."; //десятичная часть ответа в 10 СС (строкой)

						String^ answer = ""; //ответ
						String^ answerBeforePoint = ""; //ответ до точки
						String^ answerAfterPoint = ""; //ответ после точки
						//переводим введенные числа в 10 СС
						InputSystemTo10(first, firstBeforePoint, firstAfterPoint, firstSystem, firstNumber10, firstNumber10BeforePoint, firstNumber10Fractional);

						Devide(second, secondBeforePoint, secondAfterPoint);
						InputSystemTo10(second, secondBeforePoint, secondAfterPoint, secondSystem, secondNumber10, secondNumber10BeforePoint, secondNumber10Fractional);

						Count(answer10, strAnswer10, answer10BeforePoint, answer10Fractional, firstNumber10, secondNumber10);

						if (answer10 == INFINITY || answer10 == -INFINITY || answer10 < INT_MIN || answer10 > INT_MAX)
							textBoxAnswer->Text = "ERROR";
						else
							ToOutput(textBoxAnswer, strAnswer10, answer10BeforePoint, answer10Fractional, strAnswer10Fractional, answer, answerBeforePoint, answerAfterPoint, System::Int32::Parse(comboBoxAnswer->Text));
					}
					else
						textBoxAnswer->Text = "COMPLEX";
				}
				else
					textBoxAnswer->Text = "";
			}
			else
			{
				textBoxFirst->Text = "";
				labelErrors->Text = "ERROR";
			}
		}
		else
		{
			lastFirst = first;
			textBoxAnswer->Text = "";
		}
	}
	else
	{
		textBoxFirst->Text = "";
		labelErrors->Text = "Choose a basis";
	}
}

private: System::Void textBoxSecond_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	labelErrors->Text = "";
	if (comboBoxSecond->Text != "")
	{
		//переменные
		int secondSystem = System::Int32::Parse(comboBoxSecond->Text); //СС второго числа

		double secondNumber10; //второе число в 10 СС
		int secondNumber10BeforePoint = 0; //целая часть второго числа в 10 СС
		double secondNumber10Fractional = 0; //дробная часть второго числа в 10 СС

		String^ second = ""; //второе число
		String^ secondBeforePoint = ""; //второе число до точки
		String^ secondAfterPoint = ""; //второе число после точки
		String^ lastS = lastSecond; //копия прошлого второго числа

		if (textBoxSecond->Text != "")
		{
			//разрешаем вводить только нужные символы
			textBoxSecond->TextChanged -= gcnew EventHandler(this, &MyForm1::textBoxSecond_TextChanged);
			Symbols(textBoxSecond, second, lastS, secondSystem);
			textBoxSecond->TextChanged += gcnew EventHandler(this, &MyForm1::textBoxSecond_TextChanged);
			Devide(second, secondBeforePoint, secondAfterPoint);

			if (secondBeforePoint->Length < maxLength[secondSystem])
			{
				lastSecond = second;

				textBoxSecond->TextChanged -= gcnew EventHandler(this, &MyForm1::textBoxSecond_TextChanged);
				CheckLength(textBoxSecond, second, secondAfterPoint, secondSystem);
				textBoxSecond->TextChanged += gcnew EventHandler(this, &MyForm1::textBoxSecond_TextChanged);

				if (textBoxFirst->Text != "" && textBoxFirst->Text != "-" &&
					textBoxSecond->Text != "" && textBoxSecond->Text != "-" &&
					comboBoxAnswer->Text != "" &&
					listBoxOperation->Text != "")
				{
					if (!(textBoxFirst->Text[0] == '-' && listBoxOperation->Text[0] == '^' && IsFractional(textBoxSecond)))
					{
						//переменные
						int firstSystem = System::Int32::Parse(comboBoxFirst->Text); //СС первого числа
						int answerSystem = System::Int32::Parse(comboBoxAnswer->Text); //СС ответа

						double firstNumber10; //первое число в 10 СС
						int firstNumber10BeforePoint = 0; //целая часть первого числа в 10 СС
						double firstNumber10Fractional = 0; //дробная часть первого числа в 10 СС

						String^ first = textBoxFirst->Text; //первое число
						String^ firstBeforePoint = ""; //первое число до точки
						String^ firstAfterPoint = ""; //первое число после точки
						String^ lastF = lastFirst; //копия прошлого первого числа

						double answer10; //ответ в 10 СС
						String^ strAnswer10 = ""; //ответ в 10 СС (строкой)
						int answer10BeforePoint; //ответ в 10 СС до точки
						double answer10Fractional; //десятичная часть ответа в 10 СС
						String^ strAnswer10Fractional = "0."; //десятичная часть ответа в 10 СС (строкой)

						String^ answer = ""; //ответ
						String^ answerBeforePoint = ""; //ответ до точки
						String^ answerAfterPoint = ""; //ответ после точки
						//переводим введенные числа в 10 СС
						InputSystemTo10(second, secondBeforePoint, secondAfterPoint, secondSystem, secondNumber10, secondNumber10BeforePoint, secondNumber10Fractional);

						Devide(first, firstBeforePoint, firstAfterPoint);
						InputSystemTo10(first, firstBeforePoint, firstAfterPoint, firstSystem, firstNumber10, firstNumber10BeforePoint, firstNumber10Fractional);

						Count(answer10, strAnswer10, answer10BeforePoint, answer10Fractional, firstNumber10, secondNumber10);

						if (answer10 == INFINITY || answer10 == -INFINITY || answer10 < INT_MIN || answer10 > INT_MAX)
							textBoxAnswer->Text = "ERROR";
						else
							ToOutput(textBoxAnswer, strAnswer10, answer10BeforePoint, answer10Fractional, strAnswer10Fractional, answer, answerBeforePoint, answerAfterPoint, System::Int32::Parse(comboBoxAnswer->Text));
					}
					else
						textBoxAnswer->Text = "COMPLEX";
				}
				else
					textBoxAnswer->Text = "";
			}
			else
			{
				textBoxSecond->Text = "";
				labelErrors->Text = "ERROR";
			}
		}
		else
		{
			lastSecond = second;
			textBoxAnswer->Text = "";
		}
	}
	else
	{
		textBoxSecond->Text = "";
		labelErrors->Text = "Choose a basis";
	}
}
private: System::Void listBoxOperation_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBoxFirst->Text != "" && textBoxFirst->Text != "-" &&
		textBoxSecond->Text != "" && textBoxSecond->Text != "-" &&
		comboBoxAnswer->Text != "")
	{
		//переменные
		int firstSystem = System::Int32::Parse(comboBoxFirst->Text); //СС первого числа
		int secondSystem = System::Int32::Parse(comboBoxSecond->Text); //СС второго числа

		String^ first = textBoxFirst->Text; //первое число
		String^ firstBeforePoint = ""; //первое число до точки
		String^ firstAfterPoint = ""; //первое число после точки

		double firstNumber10; //первое число в 10 СС
		int firstNumber10BeforePoint = 0; //целая часть первого числа в 10 СС
		double firstNumber10Fractional = 0; //дробная часть первого числа в 10 СС

		String^ second = textBoxSecond->Text; //второе число
		String^ secondBeforePoint = ""; //второе число до точки
		String^ secondAfterPoint = ""; //второе число после точки

		double secondNumber10; //второе число в 10 СС
		int secondNumber10BeforePoint = 0; //целая часть второго числа в 10 СС
		double secondNumber10Fractional = 0; //дробная часть второго числа в 10 СС

		if (!(textBoxFirst->Text[0] == '-' && listBoxOperation->Text[0] == '^' && IsFractional(textBoxSecond)))
		{
			double answer10; //ответ в 10 СС
			String^ strAnswer10 = ""; //ответ в 10 СС (строкой)
			int answer10BeforePoint; //ответ в 10 СС до точки
			double answer10Fractional; //десятичная часть ответа в 10 СС
			String^ strAnswer10Fractional = "0."; //десятичная часть ответа в 10 СС (строкой)

			String^ answer = ""; //ответ
			String^ answerBeforePoint = ""; //ответ до точки
			String^ answerAfterPoint = ""; //ответ после точки
			//переводим введенные числа в 10 СС
			Devide(first, firstBeforePoint, firstAfterPoint);
			InputSystemTo10(first, firstBeforePoint, firstAfterPoint, firstSystem, firstNumber10, firstNumber10BeforePoint, firstNumber10Fractional);

			Devide(second, secondBeforePoint, secondAfterPoint);
			InputSystemTo10(second, secondBeforePoint, secondAfterPoint, secondSystem, secondNumber10, secondNumber10BeforePoint, secondNumber10Fractional);

			Count(answer10, strAnswer10, answer10BeforePoint, answer10Fractional, firstNumber10, secondNumber10);

			if (answer10 == INFINITY || answer10 == -INFINITY || answer10 < INT_MIN || answer10 > INT_MAX)
				textBoxAnswer->Text = "ERROR";
			else
				ToOutput(textBoxAnswer, strAnswer10, answer10BeforePoint, answer10Fractional, strAnswer10Fractional, answer, answerBeforePoint, answerAfterPoint, System::Int32::Parse(comboBoxAnswer->Text));
		}
		else
			textBoxAnswer->Text = "COMPLEX";
	}
}

private: System::Void comboBoxAnswer_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBoxFirst->Text != "" && textBoxFirst->Text != "-" &&
		textBoxSecond->Text != "" && textBoxSecond->Text != "-" &&
		listBoxOperation->Text != "")
	{
		//переменные
		int firstSystem = System::Int32::Parse(comboBoxFirst->Text); //СС первого числа
		int secondSystem = System::Int32::Parse(comboBoxSecond->Text); //СС второго числа

		String^ first = textBoxFirst->Text; //первое число
		String^ firstBeforePoint = ""; //первое число до точки
		String^ firstAfterPoint = ""; //первое число после точки

		double firstNumber10; //первое число в 10 СС
		int firstNumber10BeforePoint = 0; //целая часть первого числа в 10 СС
		double firstNumber10Fractional = 0; //дробная часть первого числа в 10 СС

		String^ second = textBoxSecond->Text; //второе число
		String^ secondBeforePoint = ""; //второе число до точки
		String^ secondAfterPoint = ""; //второе число после точки

		double secondNumber10; //второе число в 10 СС
		int secondNumber10BeforePoint = 0; //целая часть второго числа в 10 СС
		double secondNumber10Fractional = 0; //дробная часть второго числа в 10 СС

		if (!(textBoxFirst->Text[0] == '-' && listBoxOperation->Text[0] == '^' && IsFractional(textBoxSecond)))
		{
			double answer10; //ответ в 10 СС
			String^ strAnswer10 = ""; //ответ в 10 СС (строкой)
			int answer10BeforePoint; //ответ в 10 СС до точки
			double answer10Fractional; //десятичная часть ответа в 10 СС
			String^ strAnswer10Fractional = "0."; //десятичная часть ответа в 10 СС (строкой)

			String^ answer = ""; //ответ
			String^ answerBeforePoint = ""; //ответ до точки
			String^ answerAfterPoint = ""; //ответ после точки
			//переводим введенные числа в 10 СС
			Devide(first, firstBeforePoint, firstAfterPoint);
			InputSystemTo10(first, firstBeforePoint, firstAfterPoint, firstSystem, firstNumber10, firstNumber10BeforePoint, firstNumber10Fractional);

			Devide(second, secondBeforePoint, secondAfterPoint);
			InputSystemTo10(second, secondBeforePoint, secondAfterPoint, secondSystem, secondNumber10, secondNumber10BeforePoint, secondNumber10Fractional);

			Count(answer10, strAnswer10, answer10BeforePoint, answer10Fractional, firstNumber10, secondNumber10);

			if (answer10 == INFINITY || answer10 == -INFINITY || answer10 < INT_MIN || answer10 > INT_MAX)
				textBoxAnswer->Text = "ERROR";
			else
				ToOutput(textBoxAnswer, strAnswer10, answer10BeforePoint, answer10Fractional, strAnswer10Fractional, answer, answerBeforePoint, answerAfterPoint, System::Int32::Parse(comboBoxAnswer->Text));
		}
		else
			textBoxAnswer->Text = "COMPLEX";
	}
}
private: System::Void comboBoxFirst_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	labelErrors->Text = "";
	textBoxFirst->Text = "";
}
private: System::Void comboBoxSecond_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	labelErrors->Text = "";
	textBoxSecond->Text = "";
}
};
}
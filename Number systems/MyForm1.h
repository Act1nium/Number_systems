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
	/// —водка дл€ MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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
	private: System::Windows::Forms::ListBox^ listBoxOperation;
	protected:





	private: System::Windows::Forms::ComboBox^ comboBoxSecond;
	private: System::Windows::Forms::ComboBox^ comboBoxAnswer;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxAnswer;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->textBoxFirst = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSecond = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxFirst = (gcnew System::Windows::Forms::ComboBox());
			this->listBoxOperation = (gcnew System::Windows::Forms::ListBox());
			this->comboBoxSecond = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAnswer = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxAnswer = (gcnew System::Windows::Forms::TextBox());
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
			// 
			// listBoxOperation
			// 
			this->listBoxOperation->FormattingEnabled = true;
			this->listBoxOperation->ItemHeight = 25;
			this->listBoxOperation->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"+", L"-", L"*", L"/", L"^" });
			this->listBoxOperation->Location = System::Drawing::Point(168, 103);
			this->listBoxOperation->Name = L"listBoxOperation";
			this->listBoxOperation->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBoxOperation->Size = System::Drawing::Size(168, 104);
			this->listBoxOperation->TabIndex = 12;
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
			this->label3->Location = System::Drawing::Point(242, 275);
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
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 415);
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
};
}

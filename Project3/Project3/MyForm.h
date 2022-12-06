#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ runButton;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ searchTermInput;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ beginsWithInput;
	private: System::Windows::Forms::TextBox^ endsWithInput;
	private: System::Windows::Forms::TextBox^ minLengthInput;
	private: System::Windows::Forms::TextBox^ maxLengthInput;
	private: System::Windows::Forms::TextBox^ numOfSyllablesInput;











	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ partOfSpeechPick;


	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ComboBox^ dataStructurePick;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ term10;

	private: System::Windows::Forms::Label^ term9;

	private: System::Windows::Forms::Label^ term8;

	private: System::Windows::Forms::Label^ term7;

	private: System::Windows::Forms::Label^ term6;

	private: System::Windows::Forms::Label^ term5;
	private: System::Windows::Forms::Label^ term4;
	private: System::Windows::Forms::Label^ term3;
	private: System::Windows::Forms::Label^ term2;
	private: System::Windows::Forms::Label^ term1;
	protected:

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
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->searchTermInput = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->beginsWithInput = (gcnew System::Windows::Forms::TextBox());
			this->endsWithInput = (gcnew System::Windows::Forms::TextBox());
			this->minLengthInput = (gcnew System::Windows::Forms::TextBox());
			this->maxLengthInput = (gcnew System::Windows::Forms::TextBox());
			this->numOfSyllablesInput = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->term10 = (gcnew System::Windows::Forms::Label());
			this->term9 = (gcnew System::Windows::Forms::Label());
			this->term8 = (gcnew System::Windows::Forms::Label());
			this->term7 = (gcnew System::Windows::Forms::Label());
			this->term6 = (gcnew System::Windows::Forms::Label());
			this->term5 = (gcnew System::Windows::Forms::Label());
			this->term4 = (gcnew System::Windows::Forms::Label());
			this->term3 = (gcnew System::Windows::Forms::Label());
			this->term2 = (gcnew System::Windows::Forms::Label());
			this->term1 = (gcnew System::Windows::Forms::Label());
			this->partOfSpeechPick = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->dataStructurePick = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// runButton
			// 
			this->runButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->runButton->Location = System::Drawing::Point(328, 434);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(201, 41);
			this->runButton->TabIndex = 0;
			this->runButton->Text = L"Run!";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(10, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(125, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Search Term:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(51, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(181, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Highest Matching Terms";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// searchTermInput
			// 
			this->searchTermInput->Location = System::Drawing::Point(141, 79);
			this->searchTermInput->Multiline = true;
			this->searchTermInput->Name = L"searchTermInput";
			this->searchTermInput->Size = System::Drawing::Size(139, 24);
			this->searchTermInput->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(375, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 24);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Constraints";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(325, 64);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Begins With";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(324, 116);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Ends With";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(325, 167);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(104, 16);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Minimum Length";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(325, 219);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(108, 16);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Maximum Length";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(325, 273);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(129, 16);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Number of Syllables";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(324, 326);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(96, 16);
			this->label10->TabIndex = 11;
			this->label10->Text = L"Part of Speech";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// beginsWithInput
			// 
			this->beginsWithInput->Location = System::Drawing::Point(328, 84);
			this->beginsWithInput->Name = L"beginsWithInput";
			this->beginsWithInput->Size = System::Drawing::Size(200, 20);
			this->beginsWithInput->TabIndex = 12;
			this->beginsWithInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// endsWithInput
			// 
			this->endsWithInput->Location = System::Drawing::Point(328, 135);
			this->endsWithInput->Name = L"endsWithInput";
			this->endsWithInput->Size = System::Drawing::Size(200, 20);
			this->endsWithInput->TabIndex = 13;
			this->endsWithInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// minLengthInput
			// 
			this->minLengthInput->Location = System::Drawing::Point(327, 186);
			this->minLengthInput->Name = L"minLengthInput";
			this->minLengthInput->Size = System::Drawing::Size(201, 20);
			this->minLengthInput->TabIndex = 14;
			this->minLengthInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// maxLengthInput
			// 
			this->maxLengthInput->Location = System::Drawing::Point(328, 238);
			this->maxLengthInput->Name = L"maxLengthInput";
			this->maxLengthInput->Size = System::Drawing::Size(200, 20);
			this->maxLengthInput->TabIndex = 15;
			this->maxLengthInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// numOfSyllablesInput
			// 
			this->numOfSyllablesInput->Location = System::Drawing::Point(328, 292);
			this->numOfSyllablesInput->Name = L"numOfSyllablesInput";
			this->numOfSyllablesInput->Size = System::Drawing::Size(200, 20);
			this->numOfSyllablesInput->TabIndex = 16;
			this->numOfSyllablesInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->Controls->Add(this->term10);
			this->panel1->Controls->Add(this->term9);
			this->panel1->Controls->Add(this->term8);
			this->panel1->Controls->Add(this->term7);
			this->panel1->Controls->Add(this->term6);
			this->panel1->Controls->Add(this->term5);
			this->panel1->Controls->Add(this->term4);
			this->panel1->Controls->Add(this->term3);
			this->panel1->Controls->Add(this->term2);
			this->panel1->Controls->Add(this->term1);
			this->panel1->Location = System::Drawing::Point(14, 161);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(267, 314);
			this->panel1->TabIndex = 18;
			// 
			// term10
			// 
			this->term10->AutoSize = true;
			this->term10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term10->Location = System::Drawing::Point(13, 256);
			this->term10->Name = L"term10";
			this->term10->Size = System::Drawing::Size(57, 16);
			this->term10->TabIndex = 9;
			this->term10->Text = L"Term 10";
			this->term10->Click += gcnew System::EventHandler(this, &MyForm::term10_Click);
			// 
			// term9
			// 
			this->term9->AutoSize = true;
			this->term9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term9->Location = System::Drawing::Point(13, 230);
			this->term9->Name = L"term9";
			this->term9->Size = System::Drawing::Size(50, 16);
			this->term9->TabIndex = 8;
			this->term9->Text = L"Term 9";
			this->term9->Click += gcnew System::EventHandler(this, &MyForm::term9_Click);
			// 
			// term8
			// 
			this->term8->AutoSize = true;
			this->term8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term8->Location = System::Drawing::Point(13, 203);
			this->term8->Name = L"term8";
			this->term8->Size = System::Drawing::Size(50, 16);
			this->term8->TabIndex = 7;
			this->term8->Text = L"Term 8";
			this->term8->Click += gcnew System::EventHandler(this, &MyForm::term8_Click);
			// 
			// term7
			// 
			this->term7->AutoSize = true;
			this->term7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term7->Location = System::Drawing::Point(13, 175);
			this->term7->Name = L"term7";
			this->term7->Size = System::Drawing::Size(50, 16);
			this->term7->TabIndex = 6;
			this->term7->Text = L"Term 7";
			this->term7->Click += gcnew System::EventHandler(this, &MyForm::term7_Click);
			// 
			// term6
			// 
			this->term6->AutoSize = true;
			this->term6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term6->Location = System::Drawing::Point(13, 148);
			this->term6->Name = L"term6";
			this->term6->Size = System::Drawing::Size(50, 16);
			this->term6->TabIndex = 5;
			this->term6->Text = L"Term 6";
			this->term6->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// term5
			// 
			this->term5->AutoSize = true;
			this->term5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term5->Location = System::Drawing::Point(13, 121);
			this->term5->Name = L"term5";
			this->term5->Size = System::Drawing::Size(50, 16);
			this->term5->TabIndex = 4;
			this->term5->Text = L"Term 5";
			this->term5->Click += gcnew System::EventHandler(this, &MyForm::term5_Click);
			// 
			// term4
			// 
			this->term4->AutoSize = true;
			this->term4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term4->Location = System::Drawing::Point(13, 94);
			this->term4->Name = L"term4";
			this->term4->Size = System::Drawing::Size(50, 16);
			this->term4->TabIndex = 3;
			this->term4->Text = L"Term 4";
			this->term4->Click += gcnew System::EventHandler(this, &MyForm::term4_Click);
			// 
			// term3
			// 
			this->term3->AutoSize = true;
			this->term3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term3->Location = System::Drawing::Point(13, 67);
			this->term3->Name = L"term3";
			this->term3->Size = System::Drawing::Size(50, 16);
			this->term3->TabIndex = 2;
			this->term3->Text = L"Term 3";
			this->term3->Click += gcnew System::EventHandler(this, &MyForm::term3_Click);
			// 
			// term2
			// 
			this->term2->AutoSize = true;
			this->term2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term2->Location = System::Drawing::Point(13, 42);
			this->term2->Name = L"term2";
			this->term2->Size = System::Drawing::Size(50, 16);
			this->term2->TabIndex = 1;
			this->term2->Text = L"Term 2";
			this->term2->Click += gcnew System::EventHandler(this, &MyForm::term2_Click);
			// 
			// term1
			// 
			this->term1->AutoSize = true;
			this->term1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->term1->Location = System::Drawing::Point(13, 15);
			this->term1->Name = L"term1";
			this->term1->Size = System::Drawing::Size(50, 16);
			this->term1->TabIndex = 0;
			this->term1->Text = L"Term 1";
			this->term1->Click += gcnew System::EventHandler(this, &MyForm::term1_Click);
			// 
			// partOfSpeechPick
			// 
			this->partOfSpeechPick->FormattingEnabled = true;
			this->partOfSpeechPick->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Noun", L"Adjective", L"Verb" });
			this->partOfSpeechPick->Location = System::Drawing::Point(328, 346);
			this->partOfSpeechPick->Name = L"partOfSpeechPick";
			this->partOfSpeechPick->Size = System::Drawing::Size(200, 21);
			this->partOfSpeechPick->TabIndex = 20;
			this->partOfSpeechPick->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(325, 381);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(92, 16);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Data Structure";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// dataStructurePick
			// 
			this->dataStructurePick->FormattingEnabled = true;
			this->dataStructurePick->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Graph", L"Heap" });
			this->dataStructurePick->Location = System::Drawing::Point(328, 401);
			this->dataStructurePick->Name = L"dataStructurePick";
			this->dataStructurePick->Size = System::Drawing::Size(201, 21);
			this->dataStructurePick->TabIndex = 22;
			this->dataStructurePick->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 33);
			this->label1->TabIndex = 23;
			this->label1->Text = L"WordWiz";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(553, 499);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataStructurePick);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->partOfSpeechPick);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->numOfSyllablesInput);
			this->Controls->Add(this->maxLengthInput);
			this->Controls->Add(this->minLengthInput);
			this->Controls->Add(this->endsWithInput);
			this->Controls->Add(this->beginsWithInput);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->searchTermInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->runButton);
			this->Name = L"MyForm";
			this->Text = L"WordWiz";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void term10_Click(System::Object^ sender, System::EventArgs^ e) {
	}

};
}

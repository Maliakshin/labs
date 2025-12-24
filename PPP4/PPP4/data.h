#pragma once

namespace PPP4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для data
	/// </summary>
	public ref class data : public System::Windows::Forms::Form
	{
	public:
		data(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		data(bool t)
		{
			InitializeComponent();
			if (!t) {
				dataGridView1->Columns[2]->Visible = false;
			}
			update();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~data()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Имя;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Фамилия;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Паспорт;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Количество_дней;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Тип_комнаты;
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
		void update();
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Имя = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Фамилия = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Паспорт = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Количество_дней = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Тип_комнаты = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Имя, this->Фамилия,
					this->Паспорт, this->Количество_дней, this->Тип_комнаты
			});
			this->dataGridView1->Location = System::Drawing::Point(22, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(570, 202);
			this->dataGridView1->TabIndex = 0;
			// 
			// Имя
			// 
			this->Имя->Name = L"Имя";
			this->Имя->ReadOnly = true;
			// 
			// Фамилия
			// 
			this->Фамилия->Name = L"Фамилия";
			this->Фамилия->ReadOnly = true;
			// 
			// Паспорт
			// 
			this->Паспорт->Name = L"Паспорт";
			this->Паспорт->ReadOnly = true;
			// 
			// Количество_дней
			// 
			this->Количество_дней->Name = L"Количество_дней";
			this->Количество_дней->ReadOnly = true;
			this->Тип_комнаты->Name = L"Тип_комнаты";
			this->Тип_комнаты->ReadOnly = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 238);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обновить данные";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &data::button1_Click);
			// 
			// data
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 312);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"data";
			this->Text = L"data";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}

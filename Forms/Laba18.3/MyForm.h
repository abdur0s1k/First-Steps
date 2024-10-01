#pragma once

namespace Laba20 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm(void) {
            InitializeComponent();
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);

            // Инициализация таймера и начальной позиции
            this->timer1->Interval = 100;
            this->timer1->Enabled = false;
            currentPosition = Point(0, 0); // Начальное положение трапеции
        }

    protected:
        ~MyForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Timer^ timer1;
        System::ComponentModel::Container^ components;
        Point currentPosition;
        const int speed = 5; // Скорость движения трапеции
        int moveState = 0; // Направление движения

    protected:
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(41, 15);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(361, 193);
            this->dataGridView1->TabIndex = 2;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(449, 15);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(100, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Start";
            this->button1->UseVisualStyleBackColor = true;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(584, 361);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->button1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

        }

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            // Создаем массив
            array<array<int, 5>>^ B = gcnew array<array<int, 5>>(5);

            // Заполняем массив данными из dataGridView1
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    // Преобразуем значение из ячейки в int
                    B[i][j] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[j]->Value);
                }
            }

            // Вычисляем произведение элементов ниже левой диагонали
            int product = 1;
            for (int i = 1; i < 5; i++) {
                for (int j = 0; j < i; j++) {
                    product *= B[i][j];
                }
            }

            // Выводим результат
            MessageBox::Show("Произведение элементов ниже левой диагонали: " + product);
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ button1;
    };
}

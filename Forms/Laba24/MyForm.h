#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace Laba24 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// Структура для хранения информации о заказе
	struct Order {
		std::string customerName; // Имя заказчика
		std::string productName;  // Название продукта
		double price;             // Цена
		int quantity;             // Количество

		// Конструктор
		Order(std::string customerName, std::string productName, double price, int quantity)
			: customerName(customerName), productName(productName), price(price), quantity(quantity) {}
	};

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(449, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 15);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(418, 259);
			this->textBox1->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 361);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Открываем файл для чтения
		std::ifstream file("orders.txt");

		if (!file.is_open()) {
			textBox1->Text = "Ошибка открытия файла.";
			return;
		}

		// Читаем информацию о заказах из файла в вектор
		std::vector<Order> orders;
		std::string customerName, productName;
		double price;
		int quantity;

		while (file >> customerName >> productName >> price >> quantity) {
			Order order(customerName, productName, price, quantity);
			orders.push_back(order);
		}

		// Закрываем файл
		file.close();

		// Выводим информацию о заказах
		if (!orders.empty()) {
			textBox1->Text = "Информация о заказах:\r\n";

			for (const auto& order : orders) {
				textBox1->Text += gcnew System::String((order.customerName + " заказал " + std::to_string(order.quantity) +
					" единиц продукта '" + order.productName + "' по цене " + std::to_string(order.price) + " руб.\r\n").c_str());
			}
		}
		else {
			textBox1->Text = "Файл пуст или не содержит информации о заказах.";
		}
	}


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	};
}

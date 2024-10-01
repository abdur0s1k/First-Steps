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

	// ��������� ��� �������� ���������� � ������
	struct Order {
		std::string customerName; // ��� ���������
		std::string productName;  // �������� ��������
		double price;             // ����
		int quantity;             // ����������

		// �����������
		Order(std::string customerName, std::string productName, double price, int quantity)
			: customerName(customerName), productName(productName), price(price), quantity(quantity) {}
	};

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
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

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
		// ��������� ���� ��� ������
		std::ifstream file("orders.txt");

		if (!file.is_open()) {
			textBox1->Text = "������ �������� �����.";
			return;
		}

		// ������ ���������� � ������� �� ����� � ������
		std::vector<Order> orders;
		std::string customerName, productName;
		double price;
		int quantity;

		while (file >> customerName >> productName >> price >> quantity) {
			Order order(customerName, productName, price, quantity);
			orders.push_back(order);
		}

		// ��������� ����
		file.close();

		// ������� ���������� � �������
		if (!orders.empty()) {
			textBox1->Text = "���������� � �������:\r\n";

			for (const auto& order : orders) {
				textBox1->Text += gcnew System::String((order.customerName + " ������� " + std::to_string(order.quantity) +
					" ������ �������� '" + order.productName + "' �� ���� " + std::to_string(order.price) + " ���.\r\n").c_str());
			}
		}
		else {
			textBox1->Text = "���� ���� ��� �� �������� ���������� � �������.";
		}
	}


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	};
}

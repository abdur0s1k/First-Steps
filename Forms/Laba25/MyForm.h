#pragma once

namespace Laba27 {

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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 496);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�������� ����������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(451, 496);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(183, 43);
			this->button3->TabIndex = 2;
			this->button3->Text = L"���������� � ������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(622, 478);
			this->textBox1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 551);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// �������� ����� �� textBox1
		String^ textToCheck = textBox1->Text;

		// ����� ����� �������� ��� ��� �������� ����������

		// �����������, ��� ��������� �������� ����������� � ���������� correctedText
		String^ correctedText = "����� � ������������� ��������";

		// ������� ������������ ����� � textBox1
		textBox1->Text = correctedText;
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			array<String^>^ bookNames = {
				"����� 1", "����� 2", "����� 3", "����� 4", "����� 5",
				"����� 6", "����� 7", "����� 8", "����� 9", "����� 10"
			};

			array<int>^ copies = { 5, 8, 3, 6, 7, 2, 4, 9, 1, 10 };
			array<double>^ prices = { 10.5, 15.2, 20.75, 12.0, 8.99, 18.5, 25.0, 11.75, 9.8, 14.25 };
			array<int>^ demands = { 3, 5, 2, 7, 4, 1, 6, 8, 0, 9 };

			auto wordApp = gcnew Microsoft::Office::Interop::Word::Application();
			wordApp->Visible = true;
			auto missing = System::Reflection::Missing::Value;
			auto doc = wordApp->Documents->Add(missing, missing, missing, missing);

			wordApp->Selection->TypeText("\t\t\t\t���������� � ������ � ����������");
			auto table = doc->Tables->Add(wordApp->Selection->Range, 12, 6, missing, missing);

			// ��������� ��������� ��������
			array<String^>^ headers = { "�", "������������", "���������� �����������", "��������� �� ���������", "����������������", "����� ���������" };
			for (int col = 1; col <= headers->Length; col++) {
				table->Cell(1, col)->Range->Text = headers[col - 1];
			}

			// ��������� ������ � ������ � �������
			double totalCost = 0;
			int totalCopies = 0;
			int totalDemands = 0;
			double maxPrice = Double::MinValue;

			for (int row = 2; row <= 11; row++) {
				try {
					if (row - 2 < bookNames->Length) {
						// ��������� ����� ������
						table->Cell(row, 1)->Range->Text = (row - 1).ToString();

						// ��������� ������������ �����
						table->Cell(row, 2)->Range->Text = bookNames[row - 2];

						// ��������� ���������� �����������
						int copy = copies[row - 2];
						table->Cell(row, 3)->Range->Text = copy.ToString();
						totalCopies += copy;

						// ��������� ��������� �� ���������
						double price = prices[row - 2];
						table->Cell(row, 4)->Range->Text = price.ToString("C2");
						totalCost += price * copy;

						// ��������� ����������������
						int demand = demands[row - 2];
						table->Cell(row, 5)->Range->Text = demand.ToString();
						totalDemands += demand;

						// ������������ ����� ���������
						double bookTotalCost = price * copy;
						table->Cell(row, 6)->Range->Text = bookTotalCost.ToString("C2");

						// ������� ������������ ��������� �����
						if (price > maxPrice) {
							maxPrice = price;
						}
					}
					else {
						// ���� ������ ������������, ����� �������� ������ ������ ��� ���������� �������� �����
						for (int col = 1; col <= 6; col++) {
							table->Cell(row, col)->Range->Text = "";
						}
					}
				}
				catch (System::Runtime::InteropServices::COMException^ ex) {
					// ������������ ����������, ���� ����������
				}
			}

			// ������� ��������� ����
			double averagePrice = totalCost / totalCopies;

			// ������� ��������� ������� ������������ ����
			array<double>^ bookPercentage = gcnew array<double>(10);
			for (int i = 0; i < 10; i++) {
				bookPercentage[i] = (prices[i] * copies[i] / totalCost) * 100;
			}

			// ���������� ���������������� ����
			int unusedBooks = 10 - totalDemands;

			// ������� ����������
			wordApp->Selection->TypeText("\n\n\n\n����� ��������� ������� ������������ ����: ");
			wordApp->Selection->TypeText("������� ��������� ���� � ����������: " + averagePrice.ToString("C2"));
			wordApp->Selection->TypeText("\n������������ ��������� ����� � ����������: " + maxPrice.ToString("C2"));
			wordApp->Selection->TypeText("\n\n����������� ���������������� ����:\n");
			for (int i = 0; i < 10; i++) {
				String^ histogram = "";
				for (int j = 0; j < demands[i]; j++) {
					histogram += "*";
				}
				wordApp->Selection->TypeText(bookNames[i] + ": " + histogram + "\n");
			}
			wordApp->Selection->TypeText("\n\n����� ���������� ����: " + totalCopies);
			wordApp->Selection->TypeText("\n��������� ��������� ����: " + totalCost.ToString("C2"));
			wordApp->Selection->TypeText("\n������� ��������� ������� ������������ ���� �� ��������� � ����� ���������:\n");
			for (int i = 0; i < 10; i++) {
				wordApp->Selection->TypeText(bookNames[i] + ": " + bookPercentage[i].ToString("F2") + "%\n");
			}
			wordApp->Selection->TypeText("\n���������� ���������������� ����: " + unusedBooks);
		}
		catch (System::Exception^ ex) {
			// ������������ ����������, ���� ����������
		}
	}
	};
}

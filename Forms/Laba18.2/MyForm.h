#pragma once
#include <vector>
namespace Laba21 {
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnPrint_Click;

	private: System::Windows::Forms::TrackBar^ trB1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnPrint_Click = (gcnew System::Windows::Forms::Button());
			this->trB1 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trB1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(16, 15);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(377, 244);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// btnPrint_Click
			// 
			this->btnPrint_Click->Location = System::Drawing::Point(401, 50);
			this->btnPrint_Click->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnPrint_Click->Name = L"btnPrint_Click";
			this->btnPrint_Click->Size = System::Drawing::Size(147, 55);
			this->btnPrint_Click->TabIndex = 1;
			this->btnPrint_Click->Text = L"–исовать";
			this->btnPrint_Click->UseVisualStyleBackColor = true;
			this->btnPrint_Click->Click += gcnew System::EventHandler(this, &MyForm::btnPrint_Click_Click);
			// 
			// trB1
			// 
			this->trB1->Location = System::Drawing::Point(401, 139);
			this->trB1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->trB1->Maximum = 100;
			this->trB1->Minimum = 1;
			this->trB1->Name = L"trB1";
			this->trB1->Size = System::Drawing::Size(139, 56);
			this->trB1->TabIndex = 2;
			this->trB1->Value = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(588, 300);
			this->Controls->Add(this->trB1);
			this->Controls->Add(this->btnPrint_Click);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trB1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void DrawPattern(Graphics^ g, Pen^ pen, int stepSize) {
		// Starting point is 4 units down and 10 units to the right
		int startX = 10 * stepSize;
		int startY = 4 * stepSize;
		Point current(startX, startY);

		// Initialize the list to store the sequence of points
		List<Point>^ points = gcnew List<Point>();
		points->Add(current); // Add the starting point

		// Following the sequence of instructions
		current.X -= stepSize; current.Y += stepSize; points->Add(current); // Left and down diagonally
		current.X += stepSize; current.Y += stepSize; points->Add(current); // Right and down diagonally
		current.X += stepSize; current.Y -= stepSize; points->Add(current); // Right and up diagonally
		current.X -= 3 * stepSize; current.Y -= 3 * stepSize; points->Add(current); // Left and up diagonally 3 units
		current.X -= stepSize; points->Add(current); // Left 1 unit
		current.X -= stepSize; current.Y += stepSize; points->Add(current); // Left and down diagonally
		current.X += stepSize; points->Add(current); // Right 1 unit
		current.X -= 3 * stepSize; current.Y += 3 * stepSize; points->Add(current); // Left and down diagonally 3 units
		current.Y += 2 * stepSize; points->Add(current); // Down 2 units
		current.X -= 2 * stepSize; current.Y -= 2 * stepSize; points->Add(current); // Left and up diagonally 2 units
		current.Y -= stepSize; points->Add(current); // Up 1 unit
		current.X += stepSize; current.Y -= stepSize; points->Add(current); // Right and up diagonally
		current.X += stepSize; points->Add(current); // Right 1 unit
		current.X += 3 * stepSize; current.Y += 3 * stepSize; points->Add(current); // Right and down diagonally 3 units
		current.X -= stepSize; current.Y += stepSize; points->Add(current); // Left and down diagonally
		current.X += 2 * stepSize; points->Add(current); // Right 2 unit
		current.X += 2 * stepSize; current.Y -= 2 * stepSize; points->Add(current); // Right and up diagonally 2 units
		current.X -= 3 * stepSize; points->Add(current); // Left 3 units
		current.Y -= stepSize; points->Add(current); // Up 1 unit
		current.X += stepSize; points->Add(current); // Right 1 unit
		current.X += stepSize; current.Y += stepSize; points->Add(current); // Right and down diagonally

		// Draw lines between all the points in the list
		for (int i = 0; i < points->Count - 1; i++) {
			g->DrawLine(pen, points[i], points[i + 1]);
		}
	}


#pragma endregion
	private: System::Void btnPrint_Click_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ eva = pictureBox1->CreateGraphics();
		eva->Clear(Color::White);
		Pen^ p = gcnew Pen(Color::Red, 5);
		DrawPattern(eva, p, trB1->Value);
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}


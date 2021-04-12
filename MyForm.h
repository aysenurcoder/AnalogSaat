#pragma once

namespace Project2 {

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

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(43, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(339, 362);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 473);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
	public:
		Graphics^ g;
		int Genislik = 300, Yukseklik = 300, SaniyeIbre = 140, DakikaIbre = 110, SaatIbre = 80;
		int OrtaX, OrtaY;
		Bitmap^ bmp;

#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		bmp = gcnew Bitmap(Genislik + 1, Yukseklik + 1);
		OrtaX = Genislik / 2;
		OrtaY = Yukseklik / 2;

		timer1->Start();


	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: int* Koordinat(int val, int hlen) {
		int* koordinat = new int[2];

		val *= 6;
		if (val >= 0 && val <= 180) {
			koordinat[0] = OrtaX + (int)(hlen * Math::Sin(Math::PI * val / 180));
			koordinat[1] = OrtaY - (int)(hlen * Math::Cos(Math::PI * val / 180));
		}
		else
		{
			koordinat[0] = OrtaX - (int)(hlen * -Math::Sin(Math::PI * val / 180));
			koordinat[1] = OrtaY - (int)(hlen * Math::Cos(Math::PI * val / 180));
		}

		return koordinat;
	}

	private: int* sKoordinat(int sval, int dval, int hlen) {
		int* koordinat = new int[2];

		int val = (int)((sval * 30) + (dval * 0.5));

		if (val >= 0 && val <= 180) {
			koordinat[0] = OrtaX + (int)(hlen * Math::Sin(Math::PI * val / 180));
			koordinat[1] = OrtaY - (int)(hlen * Math::Cos(Math::PI * val / 180));
		}
		else {
			koordinat[0] = OrtaX - (int)(hlen * -Math::Sin(Math::PI * val / 180));
			koordinat[1] = OrtaY - (int)(hlen * Math::Cos(Math::PI * val / 180));
		}
		return koordinat;
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		g = Graphics::FromImage(bmp);

		DateTime zaman = DateTime::Now;
		int ss = zaman.Second;
		int mm = zaman.Minute;
		int hh = zaman.Hour;
		int* koordinat;

		g->Clear(Color::White);

		/*Image^ image = Image::FromFile("??C:\\Users\\win 7\\Desktop\\images.jpg");
		g->DrawImage(image, 0, 0, image->Size.Width, image->Size.Height);*/

		g->DrawEllipse(gcnew Pen(Color::Black,4), 2, 2, Genislik-3, Yukseklik-3);
		System::Drawing::Font^ font = gcnew System::Drawing::Font("arial", 13);
		SolidBrush^ renk = gcnew SolidBrush(Color::Aqua);

		float r, xOrta, yOrta;
		r = (pictureBox1->Width / 2) - 19;
		xOrta = r; yOrta = r;
		r -= 10;
		int x1, x2, y1, y2;
	
		for (int aci = 0; aci <= 360; aci += 6) {
			x1 = (int)(xOrta + (r + 10) * Math::Cos(aci * 3.1415 / 180));
			y1 = (int)(yOrta - (r + 10) * Math::Sin(aci * 3.1415 / 180));
			x2 = (int)(xOrta + (r)*Math::Cos(aci * 3.1415 / 180));
			y2 = (int)(yOrta - (r)*Math::Sin(aci * 3.1415 / 180));

			
			if (aci % 30 == 0)
				g->DrawLine(gcnew Pen(Color::Black, 3), x1, y1, x2, y2);
			else 
				g->DrawLine(gcnew Pen(Color::Black, 1), x1, y1, x2, y2);
		}


		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		
		g->DrawString("1", drawFont, drawBrush, PointF(207, 27));
		g->DrawString("2", drawFont, drawBrush, PointF(255, 75));
		g->DrawString("3", drawFont, drawBrush, PointF(272, 138));
		g->DrawString("4", drawFont, drawBrush, PointF(255, 205));
		g->DrawString("5", drawFont, drawBrush, PointF(206, 252));
		g->DrawString("6", drawFont, drawBrush, PointF(140, 267));
		g->DrawString("7", drawFont, drawBrush, PointF(74, 252));
		g->DrawString("8", drawFont, drawBrush, PointF(27, 205));
		g->DrawString("9", drawFont, drawBrush, PointF(9, 138));
		g->DrawString("10", drawFont, drawBrush, PointF(23, 75));
		g->DrawString("11", drawFont, drawBrush, PointF(71, 26));
		g->DrawString("12", drawFont, drawBrush, PointF(134, 9));


		koordinat = Koordinat(ss, SaniyeIbre);
		Pen^ greenPen = gcnew Pen(Color::Red, 1.0F);
		g->DrawLine(greenPen, OrtaX, OrtaY, koordinat[0], koordinat[1]);

		koordinat = Koordinat(mm, DakikaIbre);
		Pen^ grayPen = gcnew Pen(Color::Black, 3.0F);
		g->DrawLine(grayPen, OrtaX, OrtaY, koordinat[0], koordinat[1]);

		koordinat = sKoordinat(hh % 12, mm, SaatIbre);
		Pen^ grayPen2 = gcnew Pen(Color::Black, 5.0F);
		g->DrawLine(grayPen2, OrtaX, OrtaY, koordinat[0], koordinat[1]);

		pictureBox1->Image = bmp;

		
	}
    
};
}

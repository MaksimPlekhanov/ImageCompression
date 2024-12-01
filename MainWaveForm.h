#pragma once
#include "prelude.h"

using namespace IPr;

namespace WaveletForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainWaveForm
	/// </summary>
	public ref class MainWaveForm : public System::Windows::Forms::Form
	{
	public:
		std::string* FilePath;
		std::vector<std::vector<float>>* ImageDataR;
		std::vector<std::vector<float>>* ImageDataG;
		std::vector<std::vector<float>>* ImageDataB;
		int* channel;

	private: System::Windows::Forms::RadioButton^ RdButGray;
	private: System::Windows::Forms::RadioButton^ RdButColor;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ chBoxDecMode;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ DecompButton;
	private: System::Windows::Forms::Button^ SaveImageButton;
	public:
		   
		MainWaveForm(void)
		{
			InitializeComponent();
			FilePath = new std::string;
			ImageDataR = new std::vector<std::vector<float>>;
			ImageDataG = new std::vector<std::vector<float>>;
			ImageDataB = new std::vector<std::vector<float>>;
			channel = new int;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainWaveForm()
		{
			if (components)
			{
				if(FilePath) delete FilePath;
				if(ImageDataR) delete ImageDataR;
				if (ImageDataG) delete ImageDataG;
				if (ImageDataB) delete ImageDataB;
				if(channel) delete channel;
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ LoadImageButton;
	private: System::Windows::Forms::Button^ CompressImButton;
	private: System::Windows::Forms::Button^ ShowImButton;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWaveForm::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->LoadImageButton = (gcnew System::Windows::Forms::Button());
			this->CompressImButton = (gcnew System::Windows::Forms::Button());
			this->ShowImButton = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SaveImageButton = (gcnew System::Windows::Forms::Button());
			this->RdButGray = (gcnew System::Windows::Forms::RadioButton());
			this->RdButColor = (gcnew System::Windows::Forms::RadioButton());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->DecompButton = (gcnew System::Windows::Forms::Button());
			this->chBoxDecMode = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Image Files(*.png,*.jpg,*.jpeg,*.bmp)|*.png;*.jpg;*.jpeg;*.bmp";
			this->openFileDialog1->InitialDirectory = L"C:\\Program Files (x86)\\cv\\WaveletForms\\WaveletForms\\testimages";
			this->openFileDialog1->Title = L"Выбор изображения";
			// 
			// LoadImageButton
			// 
			this->LoadImageButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->LoadImageButton->Location = System::Drawing::Point(3, 9);
			this->LoadImageButton->Name = L"LoadImageButton";
			this->LoadImageButton->Size = System::Drawing::Size(220, 45);
			this->LoadImageButton->TabIndex = 0;
			this->LoadImageButton->Text = L"Загрузить изображение";
			this->LoadImageButton->UseVisualStyleBackColor = false;
			this->LoadImageButton->Click += gcnew System::EventHandler(this, &MainWaveForm::LoadImage_Click);
			// 
			// CompressImButton
			// 
			this->CompressImButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->CompressImButton->Enabled = false;
			this->CompressImButton->Location = System::Drawing::Point(7, 77);
			this->CompressImButton->Name = L"CompressImButton";
			this->CompressImButton->Size = System::Drawing::Size(267, 35);
			this->CompressImButton->TabIndex = 1;
			this->CompressImButton->Text = L"Сжать изображение";
			this->CompressImButton->UseVisualStyleBackColor = false;
			this->CompressImButton->Click += gcnew System::EventHandler(this, &MainWaveForm::CompressImButton_Click);
			// 
			// ShowImButton
			// 
			this->ShowImButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ShowImButton->Enabled = false;
			this->ShowImButton->Location = System::Drawing::Point(3, 153);
			this->ShowImButton->Name = L"ShowImButton";
			this->ShowImButton->Size = System::Drawing::Size(220, 41);
			this->ShowImButton->TabIndex = 2;
			this->ShowImButton->Text = L"Вывести изображение";
			this->ShowImButton->UseVisualStyleBackColor = false;
			this->ShowImButton->Click += gcnew System::EventHandler(this, &MainWaveForm::ShowImButton_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(78, 466);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(948, 25);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(270, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Выберите вейвлет-преобразование";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->Filter = L"Image Files(*.png,*.jpg,*.jpeg,*.bmp)|*.png;*.jpg;*.jpeg;*.bmp";
			this->saveFileDialog1->InitialDirectory = L"C:\\Program Files (x86)\\cv\\WaveletForms\\WaveletForms\\transformimages";
			this->saveFileDialog1->Title = L"Сохранить изображение";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Вейвлет Хаара", L"Вейвлет Добеши(4)", L"Вейвлет Добеши(6)",
					L"Вейвлет Добеши(8)", L"Вейвлет Добеши(10)", L"Вейвлет Добеши(12)", L"Вейвлет Добеши(14)", L"Вейвлет Добеши(16)", L"Вейвлет Добеши(18)",
					L"Вейвлет Добеши(20)"
			});
			this->comboBox1->Location = System::Drawing::Point(7, 31);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(267, 26);
			this->comboBox1->TabIndex = 6;
			// 
			// SaveImageButton
			// 
			this->SaveImageButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->SaveImageButton->Enabled = false;
			this->SaveImageButton->Location = System::Drawing::Point(3, 112);
			this->SaveImageButton->Name = L"SaveImageButton";
			this->SaveImageButton->Size = System::Drawing::Size(220, 41);
			this->SaveImageButton->TabIndex = 9;
			this->SaveImageButton->Text = L"Сохранить изображение";
			this->SaveImageButton->UseVisualStyleBackColor = false;
			this->SaveImageButton->Click += gcnew System::EventHandler(this, &MainWaveForm::SaveImage_Click);
			// 
			// RdButGray
			// 
			this->RdButGray->AutoSize = true;
			this->RdButGray->Checked = true;
			this->RdButGray->Location = System::Drawing::Point(3, 88);
			this->RdButGray->Name = L"RdButGray";
			this->RdButGray->Size = System::Drawing::Size(173, 22);
			this->RdButGray->TabIndex = 10;
			this->RdButGray->TabStop = true;
			this->RdButGray->Text = L"Серое изображение";
			this->RdButGray->UseVisualStyleBackColor = true;
			// 
			// RdButColor
			// 
			this->RdButColor->AutoSize = true;
			this->RdButColor->Location = System::Drawing::Point(3, 60);
			this->RdButColor->Name = L"RdButColor";
			this->RdButColor->Size = System::Drawing::Size(187, 22);
			this->RdButColor->TabIndex = 11;
			this->RdButColor->Text = L"Цветное изображение";
			this->RdButColor->UseVisualStyleBackColor = true;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(201, 168);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(63, 26);
			this->numericUpDown1->TabIndex = 12;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->DecompButton);
			this->panel1->Controls->Add(this->chBoxDecMode);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->numericUpDown1);
			this->panel1->Controls->Add(this->CompressImButton);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(749, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(277, 251);
			this->panel1->TabIndex = 13;
			// 
			// DecompButton
			// 
			this->DecompButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->DecompButton->Location = System::Drawing::Point(7, 200);
			this->DecompButton->Name = L"DecompButton";
			this->DecompButton->Size = System::Drawing::Size(266, 35);
			this->DecompButton->TabIndex = 15;
			this->DecompButton->Text = L"Декомпрессия изображения";
			this->DecompButton->UseVisualStyleBackColor = false;
			this->DecompButton->Click += gcnew System::EventHandler(this, &MainWaveForm::DecompButton_Click);
			// 
			// chBoxDecMode
			// 
			this->chBoxDecMode->AutoSize = true;
			this->chBoxDecMode->Checked = true;
			this->chBoxDecMode->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chBoxDecMode->Location = System::Drawing::Point(20, 131);
			this->chBoxDecMode->Name = L"chBoxDecMode";
			this->chBoxDecMode->Size = System::Drawing::Size(253, 22);
			this->chBoxDecMode->TabIndex = 14;
			this->chBoxDecMode->Text = L"С децимацией коэффициентов";
			this->chBoxDecMode->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(174, 18);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Процент отбрас. коэф.";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->ShowImButton);
			this->panel2->Controls->Add(this->LoadImageButton);
			this->panel2->Controls->Add(this->RdButColor);
			this->panel2->Controls->Add(this->SaveImageButton);
			this->panel2->Controls->Add(this->RdButGray);
			this->panel2->Location = System::Drawing::Point(78, 38);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(231, 208);
			this->panel2->TabIndex = 14;
			// 
			// MainWaveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::DarkKhaki;
			this->ClientSize = System::Drawing::Size(1093, 526);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->progressBar1);
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->ImeMode = System::Windows::Forms::ImeMode::On;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MainWaveForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TransformImages";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void LoadImage_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ ImName;
		cv::Mat Image;
		openFileDialog1->ShowDialog();
		ImName = openFileDialog1->FileName;
		std::string s = msclr::interop::marshal_as<std::string>(ImName);
		if (!s[0]) return;
		*FilePath = s;
		for (size_t i = 0; i < (*FilePath).size(); i++)
			if ((*FilePath)[i] == '\\') (*FilePath)[i] = '/';
		if (RdButGray->Checked) Image = cv::imread(*FilePath, 0);
		else if (RdButColor->Checked) Image = cv::imread(*FilePath, 1);
		(*ImageDataR).resize(Image.rows);
		*channel = 1;
		if (Image.channels() == 3) {
			(*ImageDataG).resize(Image.rows);
			(*ImageDataB).resize(Image.rows);
			*channel = 3;
		}
		for (int i = 0; i < Image.rows; i++) {
			if (Image.channels() == 3) {
				(*ImageDataB)[i].resize(Image.cols);
				(*ImageDataG)[i].resize(Image.cols);
				(*ImageDataR)[i].resize(Image.cols);
			}
			else (*ImageDataR)[i].resize(Image.cols);
		}
		for (int i = 0; i < Image.rows; i++) {
			for (int j = 0; j < Image.cols; j++) {
				if (Image.channels() == 3) {
					(*ImageDataB)[i][j] = (Image.at<cv::Vec3b>(i, j)[0]);
					(*ImageDataG)[i][j] = (Image.at<cv::Vec3b>(i, j)[1]);
					(*ImageDataR)[i][j] = (Image.at<cv::Vec3b>(i, j)[2]);
				}
				else if (Image.channels() == 1)
					(*ImageDataR)[i][j] = (Image.at<uchar>(i, j));
			}
		}
		CompressImButton->Enabled = true;
		SaveImageButton->Enabled = true;
		ShowImButton->Enabled = true;
	}

private: System::Void CompressImButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = comboBox1->SelectedIndex;
	if (n > -1 && n < 10 && ImageDataR) {
		n = (n + 1) * 2;
		DbCompressing(n, *ImageDataR);
		if (*channel == 3 && ImageDataG && ImageDataB) {
			DbCompressing(n, *ImageDataG);
			DbCompressing(n, *ImageDataB);
		}
		double importance = (float)numericUpDown1->Value / 100.0 * 255.0;
		if (chBoxDecMode->Checked) {
			Decimate(*ImageDataR, importance);
		}
		else if (chBoxDecMode->Checked && *channel && ImageDataG && ImageDataB) {
			Decimate(*ImageDataG, importance);
			Decimate(*ImageDataB, importance);
		}
	}
}

private: System::Void ShowImButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!ImageDataR)
		return;
	cv::Mat Image;
	if (*channel == 3 && ImageDataG && ImageDataB) Image = cv::imread(*FilePath, 1);
	else Image = cv::imread(*FilePath, 0);
		for (int i = 0; i < (*ImageDataR).size(); i++) {
			for (int j = 0; j < (*ImageDataR)[0].size(); j++) {
				if (*channel == 3) {
					(Image.at<cv::Vec3b>(i, j)[0]) = Clamp((*ImageDataB)[i][j]);
					(Image.at<cv::Vec3b>(i, j)[1]) = Clamp((*ImageDataG)[i][j]);
					(Image.at<cv::Vec3b>(i, j)[2]) = Clamp((*ImageDataR)[i][j]);
				}
				else if (*channel == 1)
					(Image.at<uchar>(i, j)) = Clamp((*ImageDataR)[i][j]);
			}
		}
	
	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);
	imshow("Image", Image);
}

private: System::Void SaveImage_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!ImageDataR)
		return;
	saveFileDialog1->ShowDialog();
	std::string filename = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
	if (!filename[0]) return;
	for (size_t i = 0; i < filename.size(); i++)
		if (filename[i] == '\\') filename[i] = '/';
	for (size_t i = 0; i < 4; i++)
		filename.pop_back();
	filename += ".jpeg";
	cv::Mat Image;
	if (*channel == 3 && ImageDataG && ImageDataB) Image = cv::imread(*FilePath, 1);
	else Image = cv::imread(*FilePath, 0);
		for (int i = 0; i < Image.rows; i++) {
			for (int j = 0; j < Image.cols; j++) {
				if (*channel == 3 && ImageDataG && ImageDataB) {
					(Image.at<cv::Vec3b>(i, j)[0]) = Clamp((*ImageDataB)[i][j]);
					(Image.at<cv::Vec3b>(i, j)[1]) = Clamp((*ImageDataG)[i][j]);
					(Image.at<cv::Vec3b>(i, j)[2]) = Clamp((*ImageDataR)[i][j]);
				}
				else if (*channel == 1)
					(Image.at<uchar>(i, j)) = Clamp((*ImageDataR)[i][j]);
			}
		}
	cv::imwrite(filename, Image);
}

private: System::Void DecompButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int n = comboBox1->SelectedIndex;
	if (n > -1 && n < 10 && ImageDataR) {
		n = (n + 1) * 2;
		DbDecompressing(n, *ImageDataR);
		if (*channel == 3 && ImageDataG && ImageDataB) {
			DbDecompressing(n, *ImageDataG);
			DbDecompressing(n, *ImageDataB);
		}
	}
}
};
}

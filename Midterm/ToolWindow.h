#pragma once

namespace OpenGL
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for ToolWindow
    /// </summary>
    public ref class ToolWindow : public System::Windows::Forms::Form
    {
    public:
        static int YPercent;
        static int UPercent;
        static int VPercent;
        static bool InvertColors;


        ToolWindow(void)
        {
            InitializeComponent();


            // Initialize YUV controls defaults
            trackBarY->Minimum = 0;
            trackBarY->Maximum = 200;
            trackBarY->Value = 100;
            trackBarU->Minimum = 0;
            trackBarU->Maximum = 200;
            trackBarU->Value = 100;
            trackBarV->Minimum = 0;
            trackBarV->Maximum = 200;
            trackBarV->Value = 100;
            labelYValue->Text = L"100%";
            labelUValue->Text = L"100%";
            labelVValue->Text = L"100%";
            checkBoxInvertColors->Checked = false;
            ToolWindow::YPercent = 100;
            ToolWindow::UPercent = 100;
            ToolWindow::VPercent = 100;
            ToolWindow::InvertColors = false;

            this->TopMost = true;
            this->Text = L"Tool Box";
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ToolWindow()
        {
            if (components)
            {
                delete components;
            }
        }

        // New controls for Y/U/V and invert
    private:
        System::Windows::Forms::TrackBar^ trackBarY;

    private:
        System::Windows::Forms::TrackBar^ trackBarU;

    private:
        System::Windows::Forms::TrackBar^ trackBarV;

    private:
        System::Windows::Forms::Label^ labelY;

    private:
        System::Windows::Forms::Label^ labelU;

    private:
        System::Windows::Forms::Label^ labelV;

    private:
        System::Windows::Forms::Label^ labelYValue;

    private:
        System::Windows::Forms::Label^ labelUValue;

    private:
        System::Windows::Forms::Label^ labelVValue;

    private:
        System::Windows::Forms::CheckBox^ checkBoxInvertColors;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
            this->trackBarU = (gcnew System::Windows::Forms::TrackBar());
            this->trackBarV = (gcnew System::Windows::Forms::TrackBar());
            this->labelY = (gcnew System::Windows::Forms::Label());
            this->labelU = (gcnew System::Windows::Forms::Label());
            this->labelV = (gcnew System::Windows::Forms::Label());
            this->labelYValue = (gcnew System::Windows::Forms::Label());
            this->labelUValue = (gcnew System::Windows::Forms::Label());
            this->labelVValue = (gcnew System::Windows::Forms::Label());
            this->checkBoxInvertColors = (gcnew System::Windows::Forms::CheckBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->BeginInit();
            this->SuspendLayout();
            // 
            // trackBarY
            // 
            this->trackBarY->Location = System::Drawing::Point(12, 24);
            this->trackBarY->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->trackBarY->Name = L"trackBarY";
            this->trackBarY->Size = System::Drawing::Size(150, 45);
            this->trackBarY->TabIndex = 3;
            this->trackBarY->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarY_Scroll);
            // 
            // trackBarU
            // 
            this->trackBarU->Location = System::Drawing::Point(14, 73);
            this->trackBarU->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->trackBarU->Name = L"trackBarU";
            this->trackBarU->Size = System::Drawing::Size(150, 45);
            this->trackBarU->TabIndex = 4;
            this->trackBarU->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarU_Scroll);
            // 
            // trackBarV
            // 
            this->trackBarV->Location = System::Drawing::Point(11, 121);
            this->trackBarV->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->trackBarV->Name = L"trackBarV";
            this->trackBarV->Size = System::Drawing::Size(150, 45);
            this->trackBarV->TabIndex = 5;
            this->trackBarV->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarV_Scroll);
            // 
            // labelY
            // 
            this->labelY->AutoSize = true;
            this->labelY->Location = System::Drawing::Point(11, 9);
            this->labelY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->labelY->Name = L"labelY";
            this->labelY->Size = System::Drawing::Size(14, 13);
            this->labelY->TabIndex = 6;
            this->labelY->Text = L"Y";
            // 
            // labelU
            // 
            this->labelU->AutoSize = true;
            this->labelU->Location = System::Drawing::Point(11, 56);
            this->labelU->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->labelU->Name = L"labelU";
            this->labelU->Size = System::Drawing::Size(15, 13);
            this->labelU->TabIndex = 7;
            this->labelU->Text = L"U";
            // 
            // labelV
            // 
            this->labelV->AutoSize = true;
            this->labelV->Location = System::Drawing::Point(12, 105);
            this->labelV->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->labelV->Name = L"labelV";
            this->labelV->Size = System::Drawing::Size(14, 13);
            this->labelV->TabIndex = 8;
            this->labelV->Text = L"V";
            // 
            // labelYValue
            // 
            this->labelYValue->AutoSize = true;
            this->labelYValue->Location = System::Drawing::Point(166, 24);
            this->labelYValue->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->labelYValue->Name = L"labelYValue";
            this->labelYValue->Size = System::Drawing::Size(33, 13);
            this->labelYValue->TabIndex = 9;
            this->labelYValue->Text = L"100%";
            // 
            // labelUValue
            // 
            this->labelUValue->AutoSize = true;
            this->labelUValue->Location = System::Drawing::Point(166, 73);
            this->labelUValue->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->labelUValue->Name = L"labelUValue";
            this->labelUValue->Size = System::Drawing::Size(33, 13);
            this->labelUValue->TabIndex = 10;
            this->labelUValue->Text = L"100%";
            // 
            // labelVValue
            // 
            this->labelVValue->AutoSize = true;
            this->labelVValue->Location = System::Drawing::Point(166, 121);
            this->labelVValue->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->labelVValue->Name = L"labelVValue";
            this->labelVValue->Size = System::Drawing::Size(33, 13);
            this->labelVValue->TabIndex = 11;
            this->labelVValue->Text = L"100%";
            // 
            // checkBoxInvertColors
            // 
            this->checkBoxInvertColors->AutoSize = true;
            this->checkBoxInvertColors->Location = System::Drawing::Point(11, 170);
            this->checkBoxInvertColors->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->checkBoxInvertColors->Name = L"checkBoxInvertColors";
            this->checkBoxInvertColors->Size = System::Drawing::Size(85, 17);
            this->checkBoxInvertColors->TabIndex = 12;
            this->checkBoxInvertColors->Text = L"Invert Colors";
            this->checkBoxInvertColors->UseVisualStyleBackColor = true;
            this->checkBoxInvertColors->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::checkBoxInvertColors_CheckedChanged);
            // 
            // ToolWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(225, 276);
            this->Controls->Add(this->checkBoxInvertColors);
            this->Controls->Add(this->labelVValue);
            this->Controls->Add(this->labelUValue);
            this->Controls->Add(this->labelYValue);
            this->Controls->Add(this->labelV);
            this->Controls->Add(this->labelU);
            this->Controls->Add(this->labelY);
            this->Controls->Add(this->trackBarV);
            this->Controls->Add(this->trackBarU);
            this->Controls->Add(this->trackBarY);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"ToolWindow";
            this->Text = L"ToolWindow";
            this->TopMost = true;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion


        // New event handlers to update static values
    private:
        System::Void trackBarY_Scroll(System::Object^ sender, System::EventArgs^ e)
        {
            ToolWindow::YPercent = trackBarY->Value;
            labelYValue->Text = trackBarY->Value.ToString() + L"%";
        }

    private:
        System::Void trackBarU_Scroll(System::Object^ sender, System::EventArgs^ e)
        {
            ToolWindow::UPercent = trackBarU->Value;
            labelUValue->Text = trackBarU->Value.ToString() + L"%";
        }

    private:
        System::Void trackBarV_Scroll(System::Object^ sender, System::EventArgs^ e)
        {
            ToolWindow::VPercent = trackBarV->Value;
            labelVValue->Text = trackBarV->Value.ToString() + L"%";
        }

    private:
        System::Void checkBoxInvertColors_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            ToolWindow::InvertColors = checkBoxInvertColors->Checked;
        }
    };
}

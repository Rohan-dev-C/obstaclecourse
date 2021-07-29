
namespace ObstacleCourse
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label2 = new System.Windows.Forms.Label();
            this.TopTimeTitle = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Number1Time = new System.Windows.Forms.Label();
            this.Number2Time = new System.Windows.Forms.Label();
            this.Number3Time = new System.Windows.Forms.Label();
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.enterYourNameTextBox = new System.Windows.Forms.TextBox();
            this.EnterNameButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.WorldRecord = new System.Windows.Forms.Label();
            this.CurrentTime = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Himalaya", 50F);
            this.label2.Location = new System.Drawing.Point(724, 490);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(345, 67);
            this.label2.TabIndex = 0;
            this.label2.Text = "Enter Your Name";
            // 
            // TopTimeTitle
            // 
            this.TopTimeTitle.AutoSize = true;
            this.TopTimeTitle.Font = new System.Drawing.Font("Microsoft Himalaya", 40F);
            this.TopTimeTitle.Location = new System.Drawing.Point(53, 148);
            this.TopTimeTitle.Name = "TopTimeTitle";
            this.TopTimeTitle.Size = new System.Drawing.Size(190, 54);
            this.TopTimeTitle.TabIndex = 1;
            this.TopTimeTitle.Text = "Top Times:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Himalaya", 90F);
            this.label1.Location = new System.Drawing.Point(213, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(579, 120);
            this.label1.TabIndex = 0;
            this.label1.Text = "Obstacle Course";
            // 
            // Number1Time
            // 
            this.Number1Time.AutoSize = true;
            this.Number1Time.Font = new System.Drawing.Font("Microsoft Himalaya", 25F);
            this.Number1Time.Location = new System.Drawing.Point(182, 214);
            this.Number1Time.Name = "Number1Time";
            this.Number1Time.Size = new System.Drawing.Size(34, 34);
            this.Number1Time.TabIndex = 2;
            this.Number1Time.Text = "1)";
            // 
            // Number2Time
            // 
            this.Number2Time.AutoSize = true;
            this.Number2Time.Font = new System.Drawing.Font("Microsoft Himalaya", 25F);
            this.Number2Time.Location = new System.Drawing.Point(182, 294);
            this.Number2Time.Name = "Number2Time";
            this.Number2Time.Size = new System.Drawing.Size(34, 34);
            this.Number2Time.TabIndex = 3;
            this.Number2Time.Text = "2)";
            // 
            // Number3Time
            // 
            this.Number3Time.AutoSize = true;
            this.Number3Time.Font = new System.Drawing.Font("Microsoft Himalaya", 25F);
            this.Number3Time.Location = new System.Drawing.Point(182, 358);
            this.Number3Time.Name = "Number3Time";
            this.Number3Time.Size = new System.Drawing.Size(40, 34);
            this.Number3Time.TabIndex = 4;
            this.Number3Time.Text = "3) ";
            // 
            // timer2
            // 
            this.timer2.Interval = 10;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // enterYourNameTextBox
            // 
            this.enterYourNameTextBox.Enabled = false;
            this.enterYourNameTextBox.Location = new System.Drawing.Point(736, 560);
            this.enterYourNameTextBox.Name = "enterYourNameTextBox";
            this.enterYourNameTextBox.Size = new System.Drawing.Size(333, 20);
            this.enterYourNameTextBox.TabIndex = 5;
            // 
            // EnterNameButton
            // 
            this.EnterNameButton.Location = new System.Drawing.Point(810, 605);
            this.EnterNameButton.Name = "EnterNameButton";
            this.EnterNameButton.Size = new System.Drawing.Size(204, 23);
            this.EnterNameButton.TabIndex = 6;
            this.EnterNameButton.Text = "Enter Name";
            this.EnterNameButton.UseVisualStyleBackColor = true;
            this.EnterNameButton.Click += new System.EventHandler(this.EnterNameButton_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Himalaya", 25F);
            this.label3.Location = new System.Drawing.Point(56, 214);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 34);
            this.label3.TabIndex = 7;
            this.label3.Text = "1)";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Himalaya", 25F);
            this.label4.Location = new System.Drawing.Point(56, 294);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(34, 34);
            this.label4.TabIndex = 8;
            this.label4.Text = "2)";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Himalaya", 25F);
            this.label5.Location = new System.Drawing.Point(56, 358);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(40, 34);
            this.label5.TabIndex = 9;
            this.label5.Text = "3) ";
            // 
            // WorldRecord
            // 
            this.WorldRecord.AutoSize = true;
            this.WorldRecord.Font = new System.Drawing.Font("Microsoft Himalaya", 30F);
            this.WorldRecord.Location = new System.Drawing.Point(23, 446);
            this.WorldRecord.Name = "WorldRecord";
            this.WorldRecord.Size = new System.Drawing.Size(244, 40);
            this.WorldRecord.TabIndex = 10;
            this.WorldRecord.Text = "WorldRecord: 2.230s";
            // 
            // CurrentTime
            // 
            this.CurrentTime.AccessibleRole = System.Windows.Forms.AccessibleRole.MenuBar;
            this.CurrentTime.AutoSize = true;
            this.CurrentTime.Font = new System.Drawing.Font("Microsoft Himalaya", 30F);
            this.CurrentTime.Location = new System.Drawing.Point(48, 506);
            this.CurrentTime.Name = "CurrentTime";
            this.CurrentTime.Size = new System.Drawing.Size(168, 40);
            this.CurrentTime.TabIndex = 11;
            this.CurrentTime.Text = "Current Time:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.ClientSize = new System.Drawing.Size(1118, 745);
            this.Controls.Add(this.CurrentTime);
            this.Controls.Add(this.WorldRecord);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.EnterNameButton);
            this.Controls.Add(this.enterYourNameTextBox);
            this.Controls.Add(this.Number3Time);
            this.Controls.Add(this.Number2Time);
            this.Controls.Add(this.Number1Time);
            this.Controls.Add(this.TopTimeTitle);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Name = "Form1";
            this.Text = "b";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label TopTimeTitle;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label Number1Time;
        private System.Windows.Forms.Label Number2Time;
        private System.Windows.Forms.Label Number3Time;
        private System.Windows.Forms.Timer timer2;
        private System.Windows.Forms.TextBox enterYourNameTextBox;
        private System.Windows.Forms.Button EnterNameButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label WorldRecord;
        private System.Windows.Forms.Label CurrentTime;
    }
}


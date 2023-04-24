namespace Menu
{
    partial class option
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(option));
            this.isTraining = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // isTraining
            // 
            this.isTraining.AutoSize = true;
            this.isTraining.BackColor = System.Drawing.Color.Transparent;
            this.isTraining.Font = new System.Drawing.Font("NiseSegaSonic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.isTraining.ForeColor = System.Drawing.Color.Black;
            this.isTraining.Location = new System.Drawing.Point(21, 64);
            this.isTraining.Name = "isTraining";
            this.isTraining.Size = new System.Drawing.Size(475, 20);
            this.isTraining.TabIndex = 0;
            this.isTraining.Text = "Training Mode? (Should AI Fight Back?)";
            this.isTraining.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.isTraining.UseVisualStyleBackColor = false;
            this.isTraining.CheckedChanged += new System.EventHandler(this.isTraining_CheckedChanged);
            // 
            // option
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(508, 264);
            this.Controls.Add(this.isTraining);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "option";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Options";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private CheckBox isTraining;
    }
}
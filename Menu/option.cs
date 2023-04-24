using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Menu
{
    public partial class option : Form
    {
        public option()
        {
            InitializeComponent();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close(); // Close Form
        }

        private void isTraining_CheckedChanged(object sender, EventArgs e)
        {
            if(isTraining.Checked)
            {
                Process process = new Process();
                process.StartInfo.FileName = "C:\\Users\\Angel\\source\\repos\\Rockthestick\\x64\\Debug\\Game.exe"; 
                process.StartInfo.Arguments = isTraining.Checked.ToString();
            }
        }
    }
}

using System.Diagnostics;
using System.Media;

namespace Menu
{
    public partial class RockTheStick : Form
    {
        private SoundPlayer soundPlayer; // Declare as a class-level variable

        public RockTheStick()
        {
            InitializeComponent();
            soundPlayer = new SoundPlayer("sounds/MenuLoopable.wav"); // Initialize in the constructor
        }

        private void playMenuMusic()
        {
            soundPlayer.PlayLooping(); // Use PlayLooping() instead of Play()
        }

        private void menu_Load(object sender, EventArgs e)
        {

            if (checkAudio.Checked)
            {
                playMenuMusic();
            }

        }

        private void checkAudio_CheckedChanged(object sender, EventArgs e)
        {
            if (checkAudio.Checked)
            {
                playMenuMusic();
            }
            else if (!checkAudio.Checked)
            {
                soundPlayer.Stop();
            }
        }

        private void btnStartGame_Click(object sender, EventArgs e)
        {
            FormWindowState originalWindowState = this.WindowState;
            soundPlayer.Stop();

            // Start the compiled C++ executable
            Process process = new Process();
            process.StartInfo.FileName = @"..\..\..\..\Rockthestick\x64\Debug\main.exe";

            process.StartInfo.Arguments = checkAudio.Checked.ToString() + " ";

            process.Start();
            this.WindowState = FormWindowState.Minimized;

            process.WaitForExit();
            if (process.HasExited)
            {
                this.WindowState = originalWindowState;
                this.BringToFront();
                this.Activate();

                if (checkAudio.Checked)
                {
                    soundPlayer.Play();
                }
                // You can also close the process when you're done with it
                process.Close();
            }
        }
    }
}
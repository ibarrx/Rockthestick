using System.Diagnostics;
using System.Media;

namespace Menu
{
    public partial class menu : Form
    {
        private SoundPlayer soundPlayer; // Declare as a class-level variable

        public menu()
        {
            InitializeComponent();
            soundPlayer = new SoundPlayer(@"C:\Users\Angel\source\repos\Rockthestick\sounds\MenuLoopable.wav"); // Initialize in the constructor
        }

        private void playMenuMusic()
        {
            soundPlayer.PlayLooping(); // Use PlayLooping() instead of Play()
        }

        private void menu_Load(object sender, EventArgs e)
        {
            
            if(checkAudio.Checked)
            {
                playMenuMusic();
            }

        }

        private void checkAudio_CheckedChanged(object sender, EventArgs e)
        {
            if(checkAudio.Checked)
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
            // Specify the path of the compiled main.exe file
            string exePath = @"C:\Program Files (x86)\Google\Chrome\Application\chrome.exe";

            // Open the compiled .exe file with the default associated program
            Process.Start(exePath);
            this.Close();
        }
    }
}
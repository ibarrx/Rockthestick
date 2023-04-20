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
            // Start the compiled C++ executable
            Process process = new Process();
            process.StartInfo.FileName = "C:\\Users\\Angel\\source\\repos\\Rockthestick\\x64\\Debug\\RockTheStick.exe"; // Replace with the path to your compiled C++ executable
            process.Start();

            // Optionally, you can wait for the process to exit before continuing
            process.WaitForExit();

            // You can also close the process when you're done with it
            process.Close();

        }
    }
}
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Windows.Forms;

//namespace esruocelcatsbo
//{
//    public partial class Form2:Form
//    {
//        public Form2()
//        {

//        }

//        private void Form2_Load(object sender, EventArgs e)
//        {

//        }
//    }
//}


namespace ObstacleCourse
{
    public partial class Form1 : Form
    {
        SerialPort port = new SerialPort("COM5", 115200);

        double time = 0;

        int KeyRead = 0;

        Label[] PlayerTimeLabels = default;


        List<Player> players = new List<Player>();

        Player currentPlayer = new Player("", 0, 0); 

        public Form1()
        {
          

            InitializeComponent();
        }


        


        void swapPositions(int x, int y)
        {
            
            Point point = new Point(PlayerTimeLabels[x].Location.X, PlayerTimeLabels[x].Location.Y);
            PlayerTimeLabels[x].Location = PlayerTimeLabels[y].Location;
            PlayerTimeLabels[y].Location = point;
        }


        void sort(List<Player> array)
        {
            //int[] temp = new int[array.Length];
            for (int j = 0; j < array.Count; j++)
            {
                double smallestNumber = array[j].time;
                int index = j; 
                
                for (int i = j; i < array.Count; i++)
                {
                    if (array[i].time < smallestNumber)
                    {
                        smallestNumber = array[i].time;
                        index = i; 
                    }
                }
                Player temp = array[index];
                array[index] = array[j];
                array[j] = temp; 
                
            }
        //    return temp; 
        }


        private void Form1_Load(object sender, EventArgs e)
        { 
            PlayerTimeLabels = new[] { Number1Time, Number2Time, Number3Time };
            EnterNameButton.Enabled = true;
            enterYourNameTextBox.Enabled = true; 
            port.Open();
            time = (ulong)timer1.Interval;
            enterYourNameTextBox.Enabled = true;
        }


        private Dictionary<Keys, string> directionKeys = new Dictionary<Keys, string>()
        {
            [Keys.Left] = "l",
            [Keys.Right] = "r",
            [Keys.Up] = "u",
            [Keys.Down] = "d"
        };

        private Keys lastKeyPressed = Keys.None;

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            // If this is not a direction key, we don't care - return
            // This is called a "guard"
            if (!directionKeys.Keys.Contains(e.KeyCode)) return;

            lastKeyPressed = e.KeyCode;
            port.Write(directionKeys[lastKeyPressed]);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (port.BytesToRead > 0)
            {
                KeyRead = (char)port.ReadByte();// port.Read(bite, 0, port.BytesToRead); 
                if (KeyRead == 'a')
                {
                    Number1Time.ForeColor = Color.Black;
                    timer2.Enabled = true;
                    time = 0;
                }
                else if (KeyRead == 'b')
                {

                    players.Add(currentPlayer);
                    currentPlayer = new Player(enterYourNameTextBox.Text, 0, players.Count);
                    sort(players);
                    timer2.Enabled = false;
                    CurrentTime.ForeColor = Color.Black;
                    enterYourNameTextBox.Clear();
                    EnterNameButton.Enabled = true; 
                    enterYourNameTextBox.Enabled = true;

                }
                else if (KeyRead == 'j')
                {
                    timer2.Enabled = false;
                    CurrentTime.ForeColor = Color.Red;
                }
            }
   
            sort(players);
            for (int i = 0; i < PlayerTimeLabels.Length; i++)
            {
                if (i < players.Count)
                {
                    PlayerTimeLabels[i].Text = $"Player {players[i].playernumber + 1}: {players[i].name} with a time of {players[i].time / 1000}";

                }
            }
          
        }


       
        private void timer2_Tick(object sender, EventArgs e)
        {
            time += (ulong)timer2.Interval;
            CurrentTime.Text = $"Player {players.Count + 1}: {currentPlayer.name} with a time of {time / 1000} ";
            currentPlayer.time = time; 
        }

        private void EnterNameButton_Click(object sender, EventArgs e)
        {

            currentPlayer.name = enterYourNameTextBox.Text; 
            enterYourNameTextBox.Text.Remove(0, enterYourNameTextBox.Text.Length);
            enterYourNameTextBox.Clear();
            EnterNameButton.Enabled = false; 
            enterYourNameTextBox.Enabled = false;
        }

    }
}

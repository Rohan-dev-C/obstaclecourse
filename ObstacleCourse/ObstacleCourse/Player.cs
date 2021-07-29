using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObstacleCourse
{
    class Player
    {
        public string name;
        public double time;
        public int playernumber; 

        public Player (string name, double time, int playernumber)
        {
            this.name = name;
            this.time = time;
            this.playernumber = playernumber; 
        }
    }
}

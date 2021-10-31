using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public class ReadSomething
    {        
        public static int ReadInteger(string prompt, int min, int max)
        {
            do
            {
                Console.Write(prompt);
                string input = Console.ReadLine();
                if (int.TryParse(input, out int result) && (result >= min && result <= max))
                {
                    return result;
                }
                else
                {
                    Console.WriteLine("Please enter a valid number");
                }
            } while (true);
        }
        public static void ReadChoice(string prompt, string[] options, out int selection)
        {
            for (int sel = 0; sel < options.Length; sel++)
            {
                Console.WriteLine(options[sel]);
            }
            selection = ReadInteger(prompt, 1, options.Length);
        }
    }
}

using BlackJack_Lib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LAB_2__BLACKJACK_OBJECTS
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            string[] options = new string[] { "1. Play Blackjack", "2. Shuffle and Show Deck", "3. Exit" };
            int selection = 0;

            while (selection != 3)
            {
                ReadSomething.ReadChoice("Make your selection: ", options, out selection);
                Console.Clear();
                switch (selection)
                {
                    case 1:
                        {
                            BlackjackGame game = new BlackjackGame();
                            game.GameLoop();
                            Console.ReadKey();
                            break;
                        }

                    case 2:
                        {
                            Deck deck1 = new Deck();
                            deck1.Shuffle();
                            deck1.DisplayDeck(2, 1);
                            Console.ReadKey();

                            break;
                        }

                    case 3:
                        break;
                }

                Console.Clear();
            }
            {//Card card1 = new Card(CardFace.Two, CardSuit.Spades);
             //card1.Draw(0, 0);
             //Deck deck1 = new Deck();// Important
             //deck1.Shuffle();
             //deck1.DisplayDeck(0,0);
             //Hand h1 = new Hand();
             //for (int i = 0; i < 5; i++)
             //{
             //    h1.AddCard(deck1.Deal());
             //}
             //h1.Draw(5, 5);
             //h1.Draw(5, 7);
            }//notes
        }
    }
}

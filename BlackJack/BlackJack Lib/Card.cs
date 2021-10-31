using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public class Card : ICard
    {
        public CardSuit Suit { get; private set; }
        public CardFace Face { get; private set; }

        public Card(CardFace face, CardSuit suit)
        {
            Suit = suit;
            Face = face;

        }
        public void Draw(int x, int y)
        {
            Console.SetCursorPosition(x, y);
            if (Suit == CardSuit.Spades || Suit == CardSuit.Clubs)
            {
                Console.ForegroundColor = ConsoleColor.Black;
                Console.BackgroundColor = ConsoleColor.White;
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.BackgroundColor = ConsoleColor.White;
            }
            switch (Face)
            {
                case CardFace.Ace:
                    Console.Write(" A ");
                    break;
                case CardFace.Two:
                    Console.Write(" 2 ");
                    break;
                case CardFace.Three:
                    Console.Write(" 3 ");
                    break;
                case CardFace.Four:
                    Console.Write(" 4 ");
                    break;
                case CardFace.Five:
                    Console.Write(" 5 ");
                    break;
                case CardFace.Six:
                    Console.Write(" 6 ");
                    break;
                case CardFace.Seven:
                    Console.Write(" 7 ");
                    break;
                case CardFace.Eight:
                    Console.Write(" 8 ");
                    break;
                case CardFace.Nine:
                    Console.Write(" 9 ");
                    break;
                case CardFace.Ten:
                    Console.Write("10 ");
                    break;
                case CardFace.Jack:
                    Console.Write(" J ");
                    break;
                case CardFace.Queen:
                    Console.Write(" Q ");
                    break;
                case CardFace.King:
                    Console.Write(" K ");
                    break;
                default:
                    break;
            }
            switch (Suit)
            {
                case CardSuit.Spades:
                    Console.Write("♠ ");
                    break;
                case CardSuit.Hearts:
                    Console.Write("♥ ");
                    break;
                case CardSuit.Clubs:
                    Console.Write("♣ ");
                    break;
                case CardSuit.Diamonds:
                    Console.Write("♦ ");
                    break;
                default:
                    break;
            }
            Console.ResetColor();
            //Console.Write($"{Face} {Suit}");
        }
    }
}


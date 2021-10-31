using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public class BlackjackHand : Hand
    {
        public int Score { get; private set; }
        public bool IsDealer { get; set; }

        public BlackjackHand(bool isDealer = false)
        {
            IsDealer = isDealer;
        }
        
        public override void AddCard(ICard card)
        {            
            base.AddCard(card);
            bool lose = false;
            Score += ((BlackjackCard)card).Value;
            while (Score > 21 && lose == false)
            {
                for (int i = 0; i < _cards.Count; i++)
                {
                    BlackjackCard tempCard = ((BlackjackCard)_cards[i]);
                    if (_cards[i].Face == CardFace.Ace && tempCard.Value != 1 )
                    {
                        tempCard.Value = 1;
                        Score -= 10;
                        break;
                    }
                    if (i == _cards.Count-1)
                    {
                        lose = true;
                    }
                }
                
            }
            //add math here
            
        }
        public override void Draw(int x, int y)
        {
            base.Draw(x, y);
            int sub = 0;
            string space = "      ";
            if (IsDealer)
            {
                sub = ((BlackjackCard)_cards.First()).Value;
                Console.Write(space + (Score - sub));
                Console.SetCursorPosition(x, y);
                Console.BackgroundColor = ConsoleColor.White;
                Console.Write("     ");
                Console.ResetColor();
                
            }
        }
    }
}

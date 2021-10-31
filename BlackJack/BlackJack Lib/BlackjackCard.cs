using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public class BlackjackCard : Card
    {
        public int Value { get; set; }
        public BlackjackCard(CardFace face, CardSuit suit) : base(face, suit)
        {
            Value = Convert.ToInt32(face);
            if(Value == 1 )
            {
                Value = 11;
            }            
            else if(Value > 10)
            {
                Value = 10;
            }
            else
            {
                Value = Value;
            }
        }
    }
}

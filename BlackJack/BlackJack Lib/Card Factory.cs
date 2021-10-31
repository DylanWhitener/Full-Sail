using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public static class Card_Factory
    {
        public static ICard CreateCard(CardFace face, CardSuit suit)
        {
            ICard card = new Card(face, suit);

            return card;
        }
        public static ICard CreateBlackjackCard(CardFace face, CardSuit suit)
        {
            ICard card = new BlackjackCard(face, suit);

            return card;
        }
    }
}

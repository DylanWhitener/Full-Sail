using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public class Deck
    {
        private List<ICard> _cards = new List<ICard>();

        public Deck()
        {
            CreateDeck();
        }

        public void CreateDeck()
        {
            for (int i = 0; i <= 3; i++)
            {
                CardSuit suit = (CardSuit)i;
                for (int j = 1; j <= 13; j++)
                {
                    CardFace face = (CardFace)j;
                    _cards.Add(Card_Factory.CreateBlackjackCard(face, suit));
                }
            }
        }
        public void Shuffle()
        {
            Random rand = new Random();
            for (int i = 0; i < _cards.Count; i++)
            {
                int shift = rand.Next(52);
                ICard temp = _cards[i];
                _cards[i] = _cards[shift];
                _cards[shift] = temp;
            }
        }

        public ICard Deal()
        {
            //Return 1 card from top of the deck.
            ICard card = null;
            if (_cards.Count == 0)
            {
                CreateDeck();
                Shuffle();
            }
            
            card = _cards.FirstOrDefault();
            _cards.RemoveAt(0);

            return card;
        }

        public void DisplayDeck(int x, int y)
        {
            int startx = x;
            int starty = y;

            int spacing = 2;
            int width = 5 + spacing;
            int cardsInRow = 10;
            int lastx = startx + width * cardsInRow;           
                        
            foreach (ICard card in _cards)
            {             
                card.Draw(startx, starty);
                startx += width;
                if (startx >= lastx)
                {
                    startx = x;
                    starty += spacing;
                }
            }
        }
    }
}

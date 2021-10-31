using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public interface ICard
    {
        CardSuit Suit { get; }
        CardFace Face { get; }

        void Draw(int x, int y);
    }    
}

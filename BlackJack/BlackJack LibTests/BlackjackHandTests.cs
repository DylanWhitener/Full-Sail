using Microsoft.VisualStudio.TestTools.UnitTesting;
using BlackJack_Lib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib.Tests
{
    [TestClass()]
    public class BlackjackHandTests
    {
        [TestMethod()]
        public void AddCardTest()
        {
            BlackjackHand p1 = new BlackjackHand();

            p1.AddCard(Card_Factory.CreateBlackjackCard(CardFace.Ace, CardSuit.Spades));
            p1.AddCard(Card_Factory.CreateBlackjackCard(CardFace.Nine, CardSuit.Spades));

            Assert.AreEqual(20, p1.Score);

            //p1.AddCard(Card_Factory.CreateBlackjackCard(CardFace.Ten, CardSuit.Spades));
            //Assert.AreEqual(19, p1.Score);
        }
    }
}
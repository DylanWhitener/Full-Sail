using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlackJack_Lib
{
    public class BlackjackGame
    {
        BlackjackHand _player; 
        BlackjackHand _dealer; 
        Deck Deck; 
        public void DealInitialCards()
        {            
            Deck.Shuffle();
            for (int i = 0; i < 2; i++)
            {
                _player.AddCard(Deck.Deal());
                _dealer.AddCard(Deck.Deal());
            }
            Console.WriteLine("Dealers Hand");
            _dealer.Draw(0, 1);            
            _player.Draw(0, 3);            
        }
        public void PlayersTurn() 
        {
            string[] options = new string[] { "1. Hit", "2. Stand" };
            int selection = 0;
            //while players score is < 21 keep playing
            while (_player.Score < 21 && selection !=2)
            {
                Console.Clear();
                Console.WriteLine("Dealers Hand");
                _dealer.Draw(0, 1);
                Console.SetCursorPosition(0, 2);
                Console.WriteLine("Players Hand");
                _player.Draw(0, 3);
                Console.WriteLine("\t" + _player.Score);
                Console.SetCursorPosition(0, 5);
                //Ask hit/stand (use read choice to show a menu here)
                ReadSomething.ReadChoice("Would you like to Hit or Stand: ", options, out selection);                
                switch (selection)
                {
                    case 1:
                        {
                            //deal another card to the players hand 
                            _player.AddCard(Deck.Deal());                                                        
                            break;
                        }
                    case 2:
                        //if player chose to stand exit loop                       
                        break;                        
                }
                _player.Draw(0, 3);
                Console.WriteLine("\t" + _player.Score);
                Console.SetCursorPosition(0, 9);
                Console.WriteLine($"\nPlayer = {_player.Score}");
            }            
        }
        public void DealersTurn()
        {            
            _dealer.IsDealer = false;
            _dealer.Draw(0, 1);
            Console.WriteLine("\t " + _dealer.Score);
            while (_dealer.Score < 17 && _player.Score <= 21)
            {
                if(_dealer.Score >= 17)
                {
                    Console.WriteLine("Dealers Hand");
                    _dealer.Draw(0, 1);
                    break;
                }
                else
                { 
                    _dealer.AddCard(Deck.Deal());
                }
                _dealer.Draw(0, 1);
                Console.WriteLine("\t" + _dealer.Score);
            }
            _dealer.IsDealer = true;
            Console.SetCursorPosition(0,11);            
            Console.WriteLine($"Dealer = {_dealer.Score}\n");
        }
        public void DeclareWinner()
        {
            Console.Clear();
            if(_player.Score > 21)
            {
                Console.WriteLine("You Busted... The dealer is victorious!\n");
            }
            else if(_dealer.Score > 21)
            {
                Console.WriteLine("Dealer has Busted... You have won! You are the greatest blackjack player!!!\n");
            }
            else if(_player.Score == _dealer.Score)
            {
                Console.WriteLine("You have tied with the dealer... There is no victor here today...\n");
            }
            else if(_player.Score > _dealer.Score)
            {
                Console.WriteLine("You have a higher score than the dealer. Congrats you win!!!\n");
            }
            else
            {
                Console.WriteLine("Dealer is the victor\n");
            }
            Console.ReadKey();
        }
        public void PlayRound()
        {
            _player = new BlackjackHand();
            _dealer = new BlackjackHand(true);
            Deck = new Deck();
            DealInitialCards();
            PlayersTurn();
            DealersTurn();
            Console.ReadKey();
            DeclareWinner();
        }
        public void GameLoop()
        {
            string[] options = new string[] { "1. Play Again?", "2. Exit" };
            int selection = 0;
            while (true)
            {
                PlayRound();
                ReadSomething.ReadChoice("Would you like to play again or exit? ", options, out selection);

                if(selection == 2)
                {
                    break;
                }
                Console.Clear();
            }
            //Do you want to play again
            //if no exit
        }

    }
}

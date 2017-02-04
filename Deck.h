#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <iostream>
#include <ctime>
#include <vector>

#include"Card.h"
#include"functions.h"
using namespace std; // This is needed for the game to work.

class Deck
{
	private:
		vector<Card> deck;
	public:
		void setCard(int i, Card x){deck[i] = x;} Card getCard(int i){return deck[i];}
		void setDeck(vector<Card> x){deck = x;} vector<Card> getDeck(int i){return deck;}
		
		void setCardValue(int i, int x){getCard(i).setValue(x);} int getCardValue(int i){return getCard(i).getValue();}
		
		string toString()
		{
			string s=("");
			for (int i = 0; i<getSize(); i++)
			{
				s+= "Card rank : " + to_string(i+1) + ", value : " +to_string(getCardValue(i)) +"\n";
			}
			return s;
		}
		
		int getSize()
		{
			return deck.size();
		}
		void shuffle()
		{
			int val;
			Card temp;
			for (int i = 0; i<getSize(); i++)
			{
				val = RN(getSize());
				temp = getCard(i);
				setCard(i,getCard(val));
				setCard(val,temp);
			}
		}
		void setBladeDeck()
		{
			deck.clear();
			Card card;
			for (int i = 0; i<17; i++)
			{				
				if(i<2)
					card.setValue(1);
				else if(i<5)
					card.setValue(2);
				else if(i<9)
					card.setValue(3);
				else if(i<13)
					card.setValue(4);
				else
					card.setValue(5);
					
				addCard(card);
			}
			for (int i = 17; i<30; i++)
			{
				if(i<20)
					card.setValue(6);
				else if(i<22)
					card.setValue(7);
				else if(i<27)
					card.setValue(8);
				else
					card.setValue(9);
					
				addCard(card);
			}
		
		}
		
		void deleteCard(int i)
		{
			deck.erase(deck.begin() + i);
		}
		void clear()
		{
			deck.clear();
		}
		void addCard(Card card)
		{
			deck.push_back(card);
		}
		Card drawCard()
		{
			Card card;
			card = getCard(getSize()-1);
			deleteCard(getSize()-1);
			return card;
		}
		Card drawCard(int place)
		{
			Card card;
			card = getCard(place);
			deleteCard(place);
			return card;
		}
		
		int valueDeck()
		{
			int value = 0;
			return 0;
			//for(int i = 0; i<deck.getSize();i++)
		}
		
		
		
		
		
}deck;
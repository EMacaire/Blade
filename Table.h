#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <iostream>
#include <ctime>
#include <sstream>

#include"Deck.h"
#include <time.h>

using namespace std; // This is needed for the game to work.

class Table
{
	private:
		Deck deck[5];			// Place where undrawed cards are to be stored
		
	//		deck[0] -> Card deck
	//		deck[1] -> Player one's hand
	//		deck[2] -> Player two's hand
	//		deck[3] -> Player one's card field
	//		deck[4] -> Player two's card field
		
		
		
	public:
		void setDeck(int i,Deck x){deck[i] = x;} Deck getDeck(int i){return deck[i];}
		void addCard(int i,Card x){deck[i].addCard(x);}
		void drawCard(int i){deck[i].addCard(deck[0].drawCard());}
		void drawCard(int i, int j, int k){deck[i].addCard(deck[j].drawCard(k));}
		
		void shuffleDeck()
		{
			deck[0].shuffle();			// Shuffle va melanger le deck
		}
		Table()
		{
		}
		int value(int i)				//value renvoie la valeur total du deck (= addition de la valeur de chaque carte)
		{
			int value = 0;
			
			for(int j = 0; j<getDeck(i).getSize();j++)	
			{
				if(deck[i].getCardValue(j)<8)
					value += deck[i].getCardValue(j);				//Pour les cartes de 1 à 7, on ajoute leurs valeurs, pour 8 et 9, on ajoute rien.
			}
			return value;
		}
		void init()	// init will give each player 5 cards, then add 1 card to each player's field
		{
			int i;
			print("initialisation...");
			deck[0].setBladeDeck();				// Initialisation va vider tout les decks
			for(i = 1; i<5; i++)
				deck[i].clear();
			sleepcp(500);
			
			print("shuffling deck...");
			shuffleDeck();		//Ici on va mélanger la pioche
			sleepcp(500);
			
			print("giving cards...");
			for(i = 0; i<5; i++)
			{	drawCard(1);			// on va donner 5 cartes à chaque joueur.
				drawCard(2);
			}
			sleepcp(500);
			
			print("The player with the lowest card on his field will begin.");
			sleepcp(1000);
			
			print("initialisation étape de distribution..");
			do
			{
				sleepcp(500);
				initDistribution();
				drawCard(3);			// On dépose une carte de la pioche dans chaque "field". on vide les decks et on redistribue des cartes tant que les valeurs ne sont pas égales.
				drawCard(4);
			}
			while(compD(3,4)==0);
			//print(toString());
			print("Distribution done.");
			
		}
		
		string toString(int j)		//Print du deck "j"
		{
			string s=("");
			
			switch(j)
			{
				case 0:
					s+= "Deck contains "+to_string(deck[j].getSize())+" card(s): \n\n";
					for (int i = 0; i<deck[j].getSize(); i++)
					{
						s+= "Card rank : " + to_string(i+1) + ", value : " +to_string(deck[j].getCardValue(i)) +"\n";
					}
					s+= "\n";
				break;
				
				case 1:
					s+= "Player "+to_string(j)+" has "+to_string(deck[j].getSize())+" card(s): \n";
					for (int i = 0; i<deck[j].getSize(); i++)
					{
						s+= to_string(deck[j].getCardValue(i));
						if(i!=deck[j].getSize()-1)
							s+= +" and ";
						else
							s+=" .\n\n";
					}
				break;
				case 2:
					s+= "Player "+to_string(j)+" has "+to_string(deck[j].getSize())+" card(s): \n";
					for (int i = 0; i<deck[j].getSize(); i++)
					{
						s+= to_string(deck[j].getCardValue(i));
						if(i!=deck[j].getSize()-1)
							s+= +" and ";
						else
							s+=" .\n\n";
					}
				break;
					
				case 3:
					s+= "Field 1 contains "+to_string(deck[j].getSize())+" card(s): \n";
					for (int i = 0; i<deck[j].getSize(); i++)
					{
						s+= to_string(deck[j].getCardValue(i));
						if(i!=deck[j].getSize()-1)
							s+= +" and ";
						else
							s+=".\n";
					}
					s+= "Value = "+ to_string(value(j)) + ".\n";
				break;
				case 4:
					s+= "Field 2 contains "+to_string(deck[j].getSize())+" card(s): \n";
					for (int i = 0; i<deck[j].getSize(); i++)
					{
						s+= to_string(deck[j].getCardValue(i));
						if(i!=deck[j].getSize()-1)
							s+= +" and ";
						else
							s+=".\n";
					}
					s+= "Value = "+ to_string(value(j)) + ".\n";
				break;
				
				default:
				break;
			}
			
			return s;
		
		}
		string toString()	//toString() appelle toString pour chaque deck.
		{
			string s=("");
			for(int i = 0; i<5; i++)	
				s+= toString(i);
			return s;
			
		}
		
		int compD(int x, int y)				//compD renvoie 1 si deck"x" est plus petit, 2 si deck"y" est plus petit ou 0 si ils sont égaux
		{
			if(value(x)<value(y)){
			print(to_string(x)+" is lower than "+to_string(y));
				return 1;}
			
			if(value(y)<value(x)){
			print(to_string(x)+" is greater than "+to_string(y));
				return 2;}
			return 0;
		}
		
		void putCardDown(int x)			// prends en parametre le joueur qui joue.
		{
 			int num = 0;/*			//num sera le numero de la carte à selectionner
			if(x==1) 
			{*/
				print("Choose a card to play (enter the position from left)");
 				string input = "";

				while (true) {
					cout << "Please enter a valid number: ";					// on prends l'input du joueur et on le test.
					getline(cin, input);
					stringstream myStream(input);
				
					if (myStream >> num && num<deck[x].getSize()+1 &&  num>0)
						break;
					cout << "Invalid number, please try again" << endl;
				}
			/*}
			else
			{
				num=RN(deck[2].getSize());
			}
			print(toString(3));
			print(toString(4));*/
			if(deck[x].getCardValue(num-1) == 8)
			{
				rotate();
				deck[x].deleteCard(num-1);
			}
			else if (deck[x].getCardValue(num-1) == 9)
			{	
				deck[x].deleteCard(num-1);
				if(x==1)										// applique les effets des cartes 8 et 9
				{
					deck[4].deleteCard(deck[4].getSize());
				}
				else
				{
					deck[3].deleteCard(deck[3].getSize());
				}
			}
			else
			{
				drawCard(x+2,x,num-1);					// transfert de la carte de la main au field.
			}
			
			
			
			/*
			print(toString(3));
			print(toString(4));*/
		}
		void rotate()			// rotate interverti les fields entre eux
		{
			Deck temp;
						
			temp = getDeck(3);
			setDeck(3,getDeck(4));
			setDeck(4,temp);
		}
		
		void printTable(int player)
		{
			print(toString(4));		//print table va afficher les fields des deux joueurs
			print(toString(3));
			print("\n");
			//if(player == 1)
				print(toString(1));
			//else
				print(toString(2));
			
		}
		
		
		void initDistribution()		//initDistribution va remettre les cartes (si il y en à)
		{
				if(deck[3].getSize()!=0)	 
				{
					drawCard(3,0,0);
					deck[3].clear();
				}
				if(deck[4].getSize()!=0)	 
				{
					drawCard(4,0,0);
					deck[4].clear();
				}
				
		}
		
		
		
}table;
#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <iostream>
#include <ctime>
using namespace std; // This is needed for the game to work.


#include"Table.h"

int ask();

int ask()
{	
	print("Do thy wish to play again ?");
	string input = "";

	while (true) {
		cout << "Press y for yes and anything else for no: ";
		getline(cin, input);
		//stringstream myStream(input);
		
		if (input=="y")//(myStream >> num && num<deck[x].getSize() &&  num>=0)
			return 1;
		return 0;
	}

}

int main()
{	
	// xxxxx Initialisation de variables xxxxx//
	Table table;
	int play = 1; 			// Vaut 1 de base, on assume que le jou
	bool end = false;		// Vrai si la partie est finie
	int player;				// Contient le numéro du joueur jouant
	// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//
	
	while(play == 1)			// tant que le joueur veut jouer
	{
		table.init();			// On initialise la table de jeu
		end = false;
		player = table.compD(3,4);	// Le joueur sera celui qui a la plus petite valeur de deck
		
		while(end!=true)		// Tant que la partie n'est pas finie
		{
				print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
				table.drawCard(player);
				table.printTable(player);			// On affiche la table de jeu
				//print(player);
				
				table.putCardDown(player);	// On demande au joueur la carte qu'il veut jouer
				print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				table.printTable(player);
				//print(player);
			//
			if(table.compD(3,4) == player)
			{	
				print("Player "+to_string(player)+" has lost.");
				end=true;
			}
			else
			{
				if (player==1)
					player = 2;
				else
					player = 1;
			}
		}
	play = ask();
	}
}
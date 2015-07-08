//#include "card.h"
#include "board.h"
#include "deck.h"
#include <iostream>
#include <vector>

int main() {

	srand (time(NULL));

	//deck(3.0).displayDeck();

	



	//creates a deck of 10 cards with 0 attack and 1 health
	/*card card1 = card(0, 1, false);

	for (int i = 0; i < 10; i++){
		testVector.push_back(card1);
	}


	cout << "Vector: ";
	for (int i = 0; i < testVector.size(); i++){
		cout << testVector[i].displayCard() << " ";
	}
	cout << endl;*/

		

	//random list in order to test new deck constructor
	card deckOfCards[30];

	for (int i = 0; i < 13; i++){
		int r = rand() % 5;
		int r2 = rand() % 10;
		deckOfCards[i].setAttack(r);
		deckOfCards[i].setHealth(r2);
		deckOfCards[i].setSpell(false);
	}
	

	



	//shuffle(deckOfCards, 52);

	/*card player1Hand[5];
	card player2Hand[5];

	int topCard = 0;

	int p1Size = 0;
	int p2Size = 0;

	for (int i = 0; i < 5; i++){
		player1Hand[i] = deckOfCards[topCard];
		topCard++;
		p1Size++;

		player2Hand[i] = deckOfCards[topCard];
		topCard++;
		p2Size++;
	}

	cout << "Player one's hand" << endl;
	for (int i = 0; i < p1Size; i++){
		cout << player1Hand[i].displayCard();
	}
	cout << endl << "Player two's hand" << endl;
	for (int i = 0; i < p2Size; i++){
		cout << player2Hand[i].displayCard();
	}*/

	return 0;
}
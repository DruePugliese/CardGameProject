#include <vector>
#include <iostream>
#include "card.h"
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>

//#include "toInt.h"

using namespace std;

//function declarations
bool to_bool(std::string str);
bool convInput(int input);

class deck{

private:
	vector<card> cardDeck;
	//User given name of deck
	string title; 
	//internal identification of deck(need to write to a text file)
	int deckID;

public:
	

	//create a deck with 30 empty cards
	deck(){
		deck(30);
		title = "Blank City";
	}

	//Create an empty deck with "amount" of cards.
	deck(int amount){
		card card1 = card();

		for (int i = 0; i < amount; i++){
			cardDeck.push_back(card1);
		}

		title = "Blank City Harder";
		deckID = 0;

	}


	//Create a Vector list of cards using user input
	deck(double deckID){

		//local variables
		int cont = 0;
		int tAttack;
		int tHealth;
		int tIsSpell;

		//get user input for the title of deck
		cout << "Hello and welcome to the deck builder, please enter the title of your deck" << endl << "title: ";
		cin.clear();
		cin.sync();
		cin >> title;
		cout << endl;

		cout << "Thank you for creating " + title + ", now we can get to creating the cards!" << endl;
		cout << "Please enter whether the card is a spell or not," << endl << "and the attack and health of each card." << endl;

		//begin card creating process
		while (cont == 0){
			cout << "Spell or No?(enter 0 for yes, 1 for no) ";
			cin.clear();
			cin.sync();
			cin >> tIsSpell;
			cout << endl;
			//for creating a spell
			if (tIsSpell == 0){
				cout << "What is the damage of your spell?" << endl << "Damage: ";
				cin.clear();
				cin.sync();
				cin >> tAttack;
				cout << endl;
				tHealth = 0;
			}


			//for creating a creature
			else{
				cout << "What is the attack of your creature?" << endl << "Attack: ";
				cin.clear();
				cin.sync();
				cin >> tAttack;
				cout << endl;
				cout << "What is the health of your creature?" << endl << "Health: ";
				cin.clear();
				cin.sync();
				cin >> tHealth;
				cout << endl;
			}

			//creating card object based on user input
			card cardTemp = card(tAttack, tHealth, convInput(tIsSpell));
			//pushing card into deck
			cardDeck.push_back(cardTemp);

			cout << "Would you like to create another card?(0 for yes, 1 for no): ";
			cin.clear();
			cin.sync();
			cin >> cont;
			cout << endl;
		}
	}
	//global method for displaying all cards in a deck
	void displayDeck(){
		cout << "Vector: ";
		for (int i = 0; i < cardDeck.size(); i++){
			cout << cardDeck[i].displayCard() << " ";
		}
		cout << endl;
	}

};

bool to_bool(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	std::istringstream is(str);
	bool b;
	is >> std::boolalpha >> b;
	return b;
}

bool convInput(int input){
	if (input == 0)
		return true;
	else
		return false;
}


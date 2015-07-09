#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class card{

private:
	int health;
	int attack;
	bool isSpell;
	bool isDead;
	bool isEmpty;

public:
	//Contructor(default is empty slot for inserting an actual card)
	card() {
		isEmpty = true;
	}

	//Contructor for actual card
	card(int a, int h, bool s) {
		health = h;
		attack = a;
		isSpell = s;
		isDead = false;
	}

	//Display Function
	string displayCard(){
		string displayValue = "[";

		if (isEmpty == true)
			displayValue += "   ";
		else if (isSpell == true)
			displayValue += "S";
		else
			displayValue += to_string(attack) + "|" + to_string(health);

		//Ending String Visuals
		displayValue += "]";

		return displayValue;
	}



	//Helper Methods
	int getAttack(){
		return attack;
	}
	int getHealth(){
		return health;
	}
	void setHealth(int h){
		health = h;
	}
	void setAttack(int a){
		attack = a;
	}
	bool isCardSpell(){
		return isSpell;
	}
	void setSpell(bool b){
		isSpell = b;
	}
	bool isCardDead(){
		return isDead;
	}
	void cardState(bool b){
		isDead = b;
	}

};




void updateCard(card c){
	if (c.getHealth() <= 0)
		c.cardState(true);
}
bool isCardDead(card c){
	updateCard(c);
	if (c.isCardDead() == true)
		return true;
	else
		return false;
}


void fightCards(card attacker, card defender){
	defender.setHealth(defender.getHealth() - attacker.getAttack());
	attacker.setHealth(attacker.getHealth() - defender.getAttack());
}

/*void shuffle(card deck[], int len){
srand(time(NULL));

for (int i = 0; i < len; i++){
int r = rand() % (len - i) + i;

card temp = deck[i];
deck[i] = deck[r];
deck[r] = temp;
}
}*/
/*
  Name: Disease Sim
  Copyright: 2019
  Author: Daniel R. Collins
  Date: 30/07/19 02:30
  Description: Test D&D disease mechanic.
*/
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

const int NUM_TRIALS = 10000;
const int MEN_LEVEL = 1;
const int SAVE_TYPE = 1;

int dieRoll (int sides) {
	return rand() % sides + 1;	
}

int diceRoll (int num, int sides) {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += dieRoll(sides);	
	}	
	return sum;
}

bool oneManLives () {
	int timeUnits = diceRoll(2, 10)/7;
	int strength = diceRoll(3, 6);
	for (int i = 0; i < timeUnits; i++) {
		if (dieRoll(20) + MEN_LEVEL + SAVE_TYPE <  20) {
			int damage = dieRoll(8);
			strength -= damage;
		}
	}	
	return strength > 0;
}

void manyTrials () {
	int menDead = 0;
	for (int i = 0; i < NUM_TRIALS; i++) {
		if (!oneManLives()) {
			menDead++;	
		}
	}	
	float mortality = (float) menDead / NUM_TRIALS;
	cout << "Mortality " << mortality << endl;
}

int main(int argc, char *argv[])
{
	srand(time(0));
	manyTrials();
    system("PAUSE");
    return EXIT_SUCCESS;
}

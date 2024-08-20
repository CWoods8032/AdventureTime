#include <iostream>
#include <string>
#include <map>
using namespace std;

// Function Prototypes
void introduction(string& name);
void choosePath(string& path, map<string, string>& story);
void encounterDragon(bool& hasSword);
void findTreasure(bool hasSword, int& gold);
void finalOutcome(bool hasSword, int gold);
bool playAgain();

// Main Function
int main() { 
	do {
		// Variables
		string name;
		string path;
		bool hasSword = false;
		int gold = 0;

		// Pointers
		string* pName = &name;
		string* pPath = &path;
		int* pGold = &gold;

		// Story map
		map<string, string> story;
		story["forest"] = "You walk through the dense forest, hearing strange noises around you.";
		story["cave"] = "You enter a dark cave. It's cold and eerie, with echos of dripping water.";
		story["mountain"] = "You climb the steep mountain, the wind howling as you ascend.";

		// Introduction
		introduction(name);

		// First Choice: Choosing a path
		choosePath(path, story);

		// Second Choice: Encounter with a dragon
		encounterDragon(hasSword);

		// Third Choice: Finding treasure
		findTreasure(hasSword, gold);

		// Final Outcome
		finalOutcome(hasSword, gold);

	} while (playAgain()); // Loop to play again if the user wants 

	cout << "Thank you for playing the Adventure Game! Goodbye!\n";

	return 0;
}

// Function to introduce the game and get the user's name
void introduction(string& name) {
	cout << "Welcome to the Adventure Game!\n";
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Hello, " << name << "! Let's start your adventure.\n\n";
}

// Function to let the user choose a path and display the corresponding story
void choosePath(string& path, map<string, string>& story) {
	cout << "You are at a crossroads. You can choose to go to the forest, cave, or mountain.\n";
	cout << "Where would you like to go? ";
	cin >> path;

	// Convert path to lowercase for consistency
	for (auto& c : path) c = tolower(c);

	// Display the chosen path story
	if (story.find(path) != story.end()) {
		cout << story[path] << "\n\n";
	}
	else {
		cout << "You seem lost... Let's go back and choose a valid path.\n";
		choosePath(path, story);
	}
}

// Function to simulate an encounter with a dragon
void encounterDragon(bool& hasSword) {
	string choice;
	cout << "As you move forward, you suddenly encounter a dragon!\n";
	cout << "Do you want to fight the dragon or run away? (fight/run): ";
	cin >> choice;

	// Convert choice to lowercase for consistency
	for (auto& c : choice) c = tolower(c);

	if (choice == "fight") {
		cout << "You bravely decide to fight the dragon.\n";
		cout << "Fortunately, you find a sword on the ground and slay the dragon!\n";
		hasSword = true;
	}
	else if (choice == "run") {
		cout << "You decide to run away and manage to escape, but the dragon takes all your gold.\n";
	}
	else {
		cout << "Indecision could be dangerous... Let's try again.\n";
		encounterDragon(hasSword);
	}
	cout << "\n";
}

// Function to simulate finding treasure based on previous choices
void findTreasure(bool hasSword, int& gold) {
	if (hasSword) {
		cout << "After defeating the dragon, you find a hidden tresure chest!\n";
		cout << "You open it and find 100 gold coins!\n";
		gold += 100;
	}
	else {
		cout << "Without a sword, you hesitate to search further. You leave empty-handed.\n";
	}
	cout << "\n";
}

// Function to determine and display the final outcome of the game
void finalOutcome(bool hasSword, int gold) {
	cout << "Your adventure comes to an end.\n";
	if (hasSword) {
		cout << "With the sword in hand and " << gold << " gold coins, you return home a hero!\n";
	}
	else {
		cout << "Without any gold and feeling defeated, you head home empty-handed.\n";
	}
}

// Function to ask the user if they want to play again
bool playAgain() {
	string choice;
	cout << "Would you like to play again? (yes/no): ";
	cin >> choice;

	// Convert choice to lowercase for consistency
	for (auto& c : choice) c = tolower(c);

	return (choice == "yes");
}
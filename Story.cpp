#include <iostream>
#include <string>
#include <map>
using namespace std;

// Function Prototypes
void introduction(string& name);
void choosePath(string& path, map<string, string>& story);
void forestScenario(bool& hasSword, int& gold);
void caveScenario(bool& hasSword);
void mountainScenario(bool& hasSword, int& gold);
void finalOutcome(bool hasSword, int gold, const string& path);
bool playAgain();

// Main Function
int main() { 
	do {
		// Variables
		string name;
		string path;
		bool hasSword = false;
		int gold = 50;

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

		// Different scenarios based on the chosen path
		if (path == "forest") {
			forestScenario(hasSword, gold);
		}
		else if (path == "cave") {
			caveScenario(hasSword);
		}
		else if (path == "mountain") {
			mountainScenario(hasSword, gold);
		}

		// Final Outcome
		finalOutcome(hasSword, gold, path);

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

// Forest Scenario
void forestScenario(bool& hasSword, int& gold) {
	string choice;
	cout << "In the forest, you find an old man who offers you a magical sword for 50 gold coins.\n";
	cout << "Do you want to buy the sword? (yes/no): ";
	cin >> choice;

	for (auto& c : choice) c = tolower(c);

	if (choice == "yes" && gold >= 50) {
		cout << "You buy the sword and feel its power coursing through your veins.\n";
		hasSword = true;
		gold -= 50;
	}
	else if (choice == "yes" && gold < 50) {
		cout << "You don't have enough gold! The old man disappears into the forest.\n";
	}
	else {
		cout << "You decline the offer and continue your journey through the forest.\n";
	}

	cout << "As you move deeper into the forest, you encounter a group of bandits!\n";
	if (hasSword) {
		cout << "With your new sword, you easily defeat the bandits and find 100 gold coins!\n";
		gold += 100;
	}
	else {
		cout << "Without a sword, you are forced to flee, losing all your gold in the process.\n";
		gold = 0;
	}
	cout << "\n";
}

// Cave Scenario
void caveScenario(bool& hasSword) {
	string choice;
	cout << "In the cave, you stumble upon a sleeping dragon guarding a pile of treasure!\n";
	cout << "Do you want to try to steal some treasure or quietly leave? (steal/leave): ";
	cin >> choice;

	for (auto& c : choice) c = tolower(c);

	if (choice == "steal") {
		if (hasSword) {
			cout << "You quietly steal some treasure and sneak away without waking the dragon.\n";
		}
		else {
			cout << "The dragon wakes up and chases you out of the cave! You barely escape with your life.\n";
		}
	}
	else {
		cout << "You decide it's not worth the risk and quietly leave the cave.\n";
	}
	cout << "\n";
}

// Mountain Scenario
void mountainScenario(bool& hasSword, int& gold) {
	string choice;
	cout << "On the mountain, you find a treasure chest hidden in the rocks.\n";
	cout << "Do you want to open the chest? (yes/no): ";
	cin >> choice;

	for (auto& c : choice) c = tolower(c);

	if (choice == "yes") {
		cout << "You open the chest and find 200 gold coins!\n";
		gold += 200;
	}
	else {
		cout << "You decide to leave the chest untouched, respecting the mountain's secrets.\n";
	}

	cout << "As you continue climbing, you find an ancient sword stuck in a rock.\n";
	cout << "Do you want to try to pull it out? (yes/no): ";
	cin >> choice;

	for (auto& c : choice) c = tolower(c);

	if (choice == "yes") {
		cout << "With great effort, you pull the sword from the rock. You now have a powerful weapon!\n";
		hasSword = true;
	}
	else {
		cout << "You leave the sword in the rock, wondering about the hero who will someday claim it.\n";
	}
	cout << "\n";
}

// Function to determine and display the final outcome of the game
void finalOutcome(bool hasSword, int gold, const string& path) {
	cout << "Your adventure comes to an end.\n";
	if (hasSword && gold > 0) {
		cout << "With the sword in hand and " << gold << " gold coins, you return home a hero!\n";
	}
	else if (hasSword && gold == 0) {
		cout << "You have a mighty sword but no gold. You return home with mixed feelings.\n";
	}
	else if (!hasSword && gold > 0) {
		cout << "You have " << gold << " gold coins, but without a sword, your journey feels incomplete.\n";
	}
	else {
		cout << "Without any gold and feeling defeated, you head home empty-handed.\n";
	}

	cout << "You chose the " << path << " path, and this where your story ends for now.\n";
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
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <conio.h>
#include <typeinfo>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;



void Program_menu();
int LVL_constructor(int&, int&);
void Game();
void Info_about_game();
void Program_cycle();
bool is_user_input_right_num(int, int);
void Print_already_typed_V(const vector<int>);
void exit_to_menu(int);

void Program_menu() {
	cout << "_____GUESS THE NUMBER_____" << endl;
	cout << "__________________________\n\n";
	cout << "1 - start game" << endl;
	cout << "2 - info about game" << endl;
	cout << "0 - exit game" << endl;

}

int LVL_constructor(int& lvl_number, int& top_number) { // return how many attempts were spent to complete the level

	int user_guess_number;
	int count_of_attempts = 0;
	int rand_number = rand() % top_number;
	rand_number++;
	vector<int> already_typed;

	while (true) {
		cout << "\n************************************************************************" << endl;
		cout << "\t\t\t\t\t\t\t|type 0 to exit|" << endl;
		cout << "Level " << lvl_number << ". Range of numbers from 1 to " << (top_number + 1) << ".\n\n";
		if (already_typed.size() != 0) {
			Print_already_typed_V(already_typed);
		}
		cout << "Your guess: ";
		cin >> user_guess_number;
		exit_to_menu(user_guess_number);
		while (!is_user_input_right_num(user_guess_number, top_number)) {
			cout << "Re-enter! You entered not a number or a number which not included in the range!" << endl;
			cout << "Your guess: ";
			cin >> user_guess_number;
			exit_to_menu(user_guess_number);
			if (cin.fail()) { // if input has incorrent type
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("cls");
			}
		}
		if (user_guess_number == rand_number) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "You're right! Well done!" << endl;
			count_of_attempts++;
			cout << "Count of Attempts: " << count_of_attempts << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "The next level will start in 2 second..." << endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system("cls");
			lvl_number++;
			top_number += 5;
			return count_of_attempts;
		}
		else {
			cout << "Yo're wrong :( Try again" << endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			already_typed.push_back(user_guess_number);
			sort(already_typed.begin(), already_typed.end());
			user_guess_number = 0;
			count_of_attempts++;

		}

	}
}

void Game() {
	int lvl_number = 1;
	int top_number = 5;
	while (true) {
		LVL_constructor(lvl_number, top_number);
	}
}

void Info_about_game() {
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	cout << "A game the meaning of which is to guess the computer-guessed number in the least number of attempts\n" << endl;
	cout << "                                     @Nikita Krasilnikov 2020" << endl;
	cout << "\n\nType 0 to exit" << "\t";
	int query_to_exit;
	cin >> query_to_exit;
	while (true) {
		if (query_to_exit == 0) {
			system("cls");
			Program_cycle();
		}
		else {
			if (cin.fail()) { // if input has incorrent type
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			cin >> query_to_exit;
		}
	}
}

void Program_cycle() {
	Program_menu();
	cout << "Choose action: ";
	int user_choice = 0;
	cin >> user_choice;
	while (true) {
		while ((user_choice != 1) && (user_choice != 2) && (user_choice != 0)) {
			cout << "Re-enter! This command does not exist!" << endl;
			cin >> user_choice;
		}
		switch (user_choice) {
		case 1:
			system("cls");
			Game();
			break;
		case 2:
			system("cls");
			Info_about_game();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}

bool is_user_input_right_num(int user_choice, int top_number) {
	if ((user_choice >= 1) && (user_choice <= (top_number + 1))) {
		return true;
	}
	else {
		return false;
	}
}

bool is_try_unique(int user_choice) {
	return false;
}

void Print_already_typed_V(const vector<int> alreadyTyped) {
	cout << "\nAlready entered numbers:" << endl;
	cout << "[  ";
	for (int i = 0; i < alreadyTyped.size(); i++) {
		cout << alreadyTyped[i] << "  ";
	}
	cout << "]\n\n";
}

void exit_to_menu(int user_choice) {
	if (user_choice == 0) {
		system("cls");
		Program_cycle();
	}
}



int main() {
	srand(time(0));
	Program_cycle();
	system("pause");
	return 0;
}
#include <vector>
#include <windows.h>
#include <random>
#include <iomanip>
//#include <unistd.h>

#include "CharacterClass.h"

using namespace std;

void menuForSeelction() {
	cout << "Введите две цифры через пробел, чтобы выбрать стихию и персонажа" << endl;
	cout << "[1] - Земля\t[1] - Воин" << endl;
	cout << "[2] - Вода \t[2] - Лучник" << endl;
	cout << "[3] - Огонь\t[3] - Маг" << endl;
	cout << "[4] - Ветер\t[4] - Доктор" << endl;
}

Character* chooseCharacter(int32_t character, CharacterFactory* factory) {
	if (character == 1) return factory->createWarrior();
	else if (character == 2) return factory->createArcher();
	else if (character == 3) return factory->createMage();
	else if (character == 4) return factory->createDoctor();
	else throw runtime_error("");
}

CharacterFactory* chooseElement(int32_t element) {
	if (element == 1) return new EarthCharFactory();
	else if (element == 2) return new WaterCharFactory();
	else if (element == 3) return new FireCharFactory();
	else if (element == 4) return new WindCharFactory();
	else throw runtime_error("");
}

vector<Character*> characterSelection(const string& numberPlayer) {
	cout << numberPlayer + " игрок соберите команду из 4 персонажей: " << endl;
	vector<Character*> playerCharacters;
	for (int32_t i = 0; i < 4; i++) {
		menuForSeelction();
		int32_t element, character;
		cin >> element;
		cin >> character;
		CharacterFactory* factory = nullptr;
		factory = chooseElement(element);
		playerCharacters.push_back(chooseCharacter(character, factory));
		delete factory;
	}
	return playerCharacters;
}

string increasingLength(const string& inputStr, int32_t maxSize) {
	string result = inputStr;
	while (result.size() < maxSize) result += " ";
	return result;
}

void printCharacters(vector<Character*>& firstPlayerCharacters, vector<Character*>& secondPlayerCharacters) {
	for (int32_t i = 0; i < 4; i++) {
		string nameCharacter = increasingLength(firstPlayerCharacters[i]->getCharacter(), 7);
		cout << nameCharacter << " | " << fixed << setprecision(2) << firstPlayerCharacters[i]->getHealth() << " HP\t\t\t";
		nameCharacter = increasingLength(secondPlayerCharacters[i]->getCharacter(), 7);
		cout << nameCharacter << " | " << fixed << setprecision(2) << secondPlayerCharacters[i]->getHealth() << " HP" << endl;
	}
}

bool isAliveTeam(vector<Character*>& playerCharacters) {
	int32_t amountOfdeads = 0;
	for (int32_t i = 0; i < 4; i++) {
		if (playerCharacters[i]->IsDead()) amountOfdeads++;
	}
	if (amountOfdeads == 4) return false;
	return true;
}

void actions(vector<Character*>& firstPlayerCharacters, vector<Character*>& secondPlayerCharacters, vector<string>& logs) {
	random_device randNumber;
	mt19937 gen(randNumber());
	uniform_int_distribution<> dis(0, 3);
	while(isAliveTeam(firstPlayerCharacters) and isAliveTeam(secondPlayerCharacters)) {
		int32_t first = dis(gen), second = dis(gen);
		if (firstPlayerCharacters[first]->IsDead() or secondPlayerCharacters[second]->IsDead()) continue;
		firstPlayerCharacters[first]->useAbility(secondPlayerCharacters[second], logs, "1");
		secondPlayerCharacters[second]->useAbility(firstPlayerCharacters[first], logs, "2");
	}
}

void battle(vector<Character*>& firstPlayerCharacters, vector<Character*>& secondPlayerCharacters) {
	vector<string> logs;
	while (true) {
		system("cls");
		cout << "Игрок 1         \t\t\tИгрок 2" << endl;
		printCharacters(firstPlayerCharacters, secondPlayerCharacters);
		actions(firstPlayerCharacters, secondPlayerCharacters, logs);
		for (string log : logs) {
			cout << log << endl;
		}
		//sleep(2)
		Sleep(2);
	}
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	vector<Character*> firstPlayerCharacters = characterSelection("Первый");
	vector<Character*> secondPlayerCharacters = characterSelection("Второй");
	battle(firstPlayerCharacters, secondPlayerCharacters);
}

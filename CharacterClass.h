#pragma once

#include <iostream>
#include <string>

using namespace std;


class Character {
public:
	virtual void useAbility(Character* enemy, vector<string>& logs, const string& numberPlayer) = 0;
	virtual bool IsDead() = 0;
	virtual string getCharacter() = 0;
	virtual float getHealth() = 0;
	virtual string getElement() = 0;
	virtual void takeDamage(float damage) = 0;
	virtual ~Character() {}
};

class Warrior : public Character {
private:
	const string element;
	float health;
	float damage;
public:
	Warrior(const string& element_) : element(element_) {
		health = 80.0;
		damage = 18.0;
		if (element == "Earth") {
			health += 35.0;
		}
		if (element == "Water") {
			health += 25.0;
			damage -= 2.0;
		}
		if (element == "Fire") {
			health -= 12.0;
			damage += 2.0;
		}
		if (element == "Wind") {
			health -= 40.0;
			damage += 5.0;
		}
	}

	bool IsDead() override {
		return health == 0;
	}

	string getCharacter() override {
		return "Warrior";
	}

	float getHealth() override {
		return health;
	}

	string getElement() override {
		return element;
	}

	void takeDamage(float damage) override {
		health -= damage;
		if (health < 0) health = 0;
	}

	void useAbility(Character* enemy, vector<string>& logs, const string& numberPlayer) override {
		if (element == "Fire") {
			if (enemy->getElement() == "Water") {
				enemy->takeDamage(damage * 1.5);
				string damageStr = to_string(damage * 1.5);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Earth") {
			if (enemy->getElement() == "Wind") {
				enemy->takeDamage(damage * 2);
				string damageStr = to_string(damage * 2);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		if (element == "Water") {
			if (enemy->getElement() == "Fire") {
				enemy->takeDamage(damage * 1.75);
				string damageStr = to_string(damage * 1.75);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Wind") {
			if (enemy->getElement() == "Earth") {
				enemy->takeDamage(damage * 1.3);
				string damageStr = to_string(damage * 1.3);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Warrior наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
	}
};

class Archer : public Character {
private:
	const string element;
	float health;
	float damage;

public:
	Archer(const string& element_) : element(element_) {
		health = 100.0;
		damage = 25.0;
		if (element == "Earth") {
			health += 35.0;
		}
		if (element == "Water") {
			health += 25.0;
			damage -= 2.0;
		}
		if (element == "Fire") {
			health -= 12.0;
			damage += 2.0;
		}
		if (element == "Wind") {
			health -= 40.0;
			damage += 5.0;
		}
	}

	bool IsDead() override {
		return health == 0;
	}

	string getCharacter() override {
		return "Archer";
	}

	float getHealth() override {
		return health;
	}

	string getElement() override {
		return element;
	}

	void takeDamage(float damage) override {
		health -= damage;
		if (health < 0) health = 0;
	}

	void useAbility(Character* enemy, vector<string>& logs, const string& numberPlayer) override {
		if (element == "Fire") {
			if (enemy->getElement() == "Water") {
				enemy->takeDamage(damage * 1.2);
				string damageStr = to_string(damage * 1.2);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Earth") {
			if (enemy->getElement() == "Wind") {
				enemy->takeDamage(damage * 1.4);
				string damageStr = to_string(damage * 1.4);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		if (element == "Water") {
			if (enemy->getElement() == "Fire") {
				enemy->takeDamage(damage * 1.25);
				string damageStr = to_string(damage * 1.25);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Wind") {
			if (enemy->getElement() == "Earth") {
				enemy->takeDamage(damage * 1.1);
				string damageStr = to_string(damage * 1.1);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Archer наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
	}
};

class Mage : public Character {
private:
	const string element;
	float health;
	float damage;
public:
	Mage(const string& element_) : element(element_) {
		health = 70.0;
		damage = 17.0;
		if (element == "Earth") {
			health += 35.0;
		}
		if (element == "Water") {
			health += 25.0;
			damage -= 2.0;
		}
		if (element == "Fire") {
			health -= 12.0;
			damage += 2.0;
		}
		if (element == "Wind") {
			health -= 40.0;
			damage += 5.0;
		}
	}

	bool IsDead() override {
		return health == 0;
	}

	string getCharacter() override {
		return "Mage";
	}

	float getHealth() override {
		return health;
	}

	string getElement() override {
		return element;
	}

	void takeDamage(float damage) override {
		health -= damage;
		if (health < 0) health = 0;
	}

	void useAbility(Character* enemy, vector<string>& logs, const string& numberPlayer) override {
		random_device randNumber;
		mt19937 gen(randNumber());
		uniform_int_distribution<> dis(1, 2);
		float multiplier = dis(gen);
		if (element == "Fire") {
			if (enemy->getElement() == "Water") {
				enemy->takeDamage(damage * multiplier);
				string damageStr = to_string(damage * multiplier);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Earth") {
			if (enemy->getElement() == "Wind") {
				enemy->takeDamage(damage * multiplier);
				string damageStr = to_string(damage * multiplier);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		if (element == "Water") {
			if (enemy->getElement() == "Fire") {
				enemy->takeDamage(damage * multiplier);
				string damageStr = to_string(damage * multiplier);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Wind") {
			if (enemy->getElement() == "Earth") {
				enemy->takeDamage(damage * multiplier);
				string damageStr = to_string(damage * multiplier);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Mage наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
	}
};

class Doctor : public Character {
private:
	const string element;
	float health;
	float damage;
public:
	Doctor(const string& element_) : element(element_) {
		health = 150.0;
		damage = 10.0;
		if (element == "Earth") {
			health += 35.0;
		}
		if (element == "Water") {
			health += 25.0;
			damage -= 2.0;
		}
		if (element == "Fire") {
			health -= 12.0;
			damage += 2.0;
		}
		if (element == "Wind") {
			health -= 40.0;
			damage += 5.0;
		}
	}

	bool IsDead() override {
		return health == 0;
	}

	string getCharacter() override {
		return "Doctor";
	}

	float getHealth() override {
		return health;
	}

	string getElement() override {
		return element;
	}

	void takeDamage(float damage) override {
		health -= damage;
		if (health < 0) health = 0;
	}

	void useAbility(Character* enemy, vector<string>& logs, const string& numberPlayer) override {
		if (element == "Fire") {
			if (enemy->getElement() == "Water") {
				enemy->takeDamage(damage * 1.1);
				string damageStr = to_string(damage * 1.1);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Earth") {
			if (enemy->getElement() == "Wind") {
				enemy->takeDamage(damage * 1.05);
				string damageStr = to_string(damage * 1.05);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		if (element == "Water") {
			if (enemy->getElement() == "Fire") {
				enemy->takeDamage(damage * 1.1);
				string damageStr = to_string(damage * 1.1);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
		else if (element == "Wind") {
			if (enemy->getElement() == "Earth") {
				enemy->takeDamage(damage * 1.1);
				string damageStr = to_string(damage * 1.1);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
			else {
				enemy->takeDamage(damage);
				string damageStr = to_string(damage);
				while (damageStr[damageStr.size() - 1] == '0') damageStr.erase(damageStr.size() - 1, 1);
				logs.push_back("Игрок " + numberPlayer + ": Doctor наносит урон: " + damageStr + " " + enemy->getCharacter());
			}
		}
	}
};

class CharacterFactory {
public:
	virtual Character* createWarrior() = 0;
	virtual Character* createMage() = 0;
	virtual Character* createArcher() = 0;
	virtual Character* createDoctor() = 0;
	virtual ~CharacterFactory() {}
};

class EarthCharFactory: public CharacterFactory {
public:
	Character* createWarrior() override {
		return new Warrior("Earth");
	}
	Character* createMage() override {
		return new Mage("Earth");
	}
	Character* createArcher()  override {
		return new Archer("Earth");
	}
	Character* createDoctor() override {
		return new Doctor("Earth");
	}
};

class WaterCharFactory: public CharacterFactory {
public:
	Character* createWarrior() override {
		return new Warrior("Water");
	}
	Character* createMage() override {
		return new Mage("Water");
	}
	Character* createArcher()  override {
		return new Archer("Water");
	}
	Character* createDoctor() override {
		return new Doctor("Water");
	}
};

class FireCharFactory: public CharacterFactory {
public:
	Character* createWarrior() override {
		return new Warrior("Fire");
	}
	Character* createMage() override {
		return new Mage("Fire");
	}
	Character* createArcher()  override {
		return new Archer("Fire");
	}
	Character* createDoctor() override {
		return new Doctor("Fire");
	}
};

class WindCharFactory: public CharacterFactory {
public:
	Character* createWarrior() override {
		return new Warrior("Wind");
	}
	Character* createMage() override {
		return new Mage("Wind");
	}
	Character* createArcher()  override {
		return new Archer("Wind");
	}
	Character* createDoctor() override {
		return new Doctor("Wind");
	}
};

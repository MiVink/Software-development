#pragma once
#include <iostream>
#include <memory>
#include "Character.h"
#include "Weapons.h"

// =====================================================================
// Конкретні персонажі (4 класи). Кожен задає зброю "за замовчуванням"
// у конструкторі, але завдяки setWeapon() з базового класу
// може взяти БУДЬ-ЯКУ іншу зброю під час гри.
// Додати нового персонажа = створити 1 клас-нащадок. Код, що вже
// існує, редагувати НЕ потрібно.
// =====================================================================

class Knight : public Character {
public:
    Knight(const std::string& name = "Лицар")
        : Character(name, std::make_unique<Sword>()) {
    }
    void display() const override {
        std::cout << "Я — хоробрий " << name << " у блискучих обладунках." << std::endl;
    }
};

class Archer : public Character {
public:
    Archer(const std::string& name = "Лучник")
        : Character(name, std::make_unique<Bow>()) {
    }
    void display() const override {
        std::cout << "Я — влучний " << name << ", тінь лісу." << std::endl;
    }
};

class Troll : public Character {
public:
    Troll(const std::string& name = "Троль")
        : Character(name, std::make_unique<Axe>()) {
    }
    void display() const override {
        std::cout << "Я — лютий " << name << ", гроза гір!" << std::endl;
    }
};

class Wizard : public Character {
public:
    Wizard(const std::string& name = "Маг")
        : Character(name, std::make_unique<MagicStaff>()) {
    }
    void display() const override {
        std::cout << "Я — мудрий " << name << ", повелитель стихій." << std::endl;
    }
};

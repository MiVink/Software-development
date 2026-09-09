// Практична робота №1: Паттерн "Стратегія" (Strategy)
// Тема: Пригодницька гра — персонажі та зброя.
//
// Структура для діаграми класів:
//   ІНТЕРФЕЙС (1):        IWeapon
//   АБСТРАКТНИЙ КЛАС (1): Character (тут живе setWeapon())
//   КЛАСИ ЗБРОЇ (4):      Sword, Bow, Axe, MagicStaff  -> реалізують IWeapon
//   КЛАСИ ПЕРСОНАЖІВ (4): Knight, Archer, Troll, Wizard -> наслідують Character
// Разом: 1 + 1 + 8 = 10 типів, як вимагається.

#include <iostream>
#include <memory>
#include <vector>
#include <windows.h>

#include "Characters.h"
#include "Weapons.h"

int main() {
    // Українська мова в консолі Windows (UTF-8)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "=== Пригодницька гра. Паттерн СТРАТЕГІЯ ===" << std::endl << std::endl;

    // 1. Створюємо героїв. Кожен має "свою" стартову зброю.
    std::vector<std::unique_ptr<Character>> heroes;
    heroes.push_back(std::make_unique<Knight>("Артур"));
    heroes.push_back(std::make_unique<Archer>("Леголас"));
    heroes.push_back(std::make_unique<Troll>("Грим"));
    heroes.push_back(std::make_unique<Wizard>("Гендальф"));

    // 2. Представлення + перший бій
    std::cout << "--- Знайомство та перший бій ---" << std::endl;
    for (const auto& h : heroes) {
        h->display();
        h->fight();
    }

    // 3. ГОЛОВНА ДЕМОНСТРАЦІЯ: зміна зброї ПІД ЧАС ГРИ.
    // Жодних if/else і жодного редагування класів персонажів!
    std::cout << std::endl << "--- Герої знаходять нову зброю... ---" << std::endl;
    heroes[0]->setWeapon(std::make_unique<Axe>());        // Лицар бере сокиру
    heroes[1]->setWeapon(std::make_unique<Sword>());      // Лучник бере меч
    heroes[2]->setWeapon(std::make_unique<MagicStaff>()); // Троль бере посох
    heroes[3]->setWeapon(std::make_unique<Bow>());        // Маг бере лук

    std::cout << std::endl << "--- Другий бій (після зміни зброї) ---" << std::endl;
    for (const auto& h : heroes) {
        h->fight();
    }

    // 4. Розширюваність: "нова" зброя без редагування старого коду.
    // Досить було б створити клас Knife : public IWeapon.
    // Тут показуємо, що персонаж прийме БУДЬ-ЯКИЙ IWeapon:
    std::cout << std::endl << "--- Лицар знову міняє зброю ---" << std::endl;
    heroes[0]->setWeapon(std::make_unique<MagicStaff>());
    heroes[0]->fight();

    std::cout << std::endl << "Гру завершено. Натисніть Enter для виходу...";
    std::cin.get();
    return 0;
}

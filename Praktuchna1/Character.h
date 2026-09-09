#pragma once
#include <iostream>
#include <memory>
#include <string>
#include "IWeapon.h"

// =====================================================================
// Character — АБСТРАКТНИЙ клас-контекст паттерну "Стратегія".
//
// Містить посилання на стратегію (IWeapon*) і делегує їй роботу.
// Персонаж у будь-яку мить використовує ЛИШЕ ОДИН вид зброї,
// але може вільно міняти її під час гри через setWeapon().
//
// Метод setWeapon() розташовано САМЕ ТУТ (у базовому класі),
// щоб усі нащадки успадкували можливість зміни стратегії.
// =====================================================================
class Character {
protected:
    std::string name;
    std::unique_ptr<IWeapon> weapon; // зв'язок "має" (агрегація/композиція)

public:
    Character(const std::string& name, std::unique_ptr<IWeapon> startingWeapon)
        : name(name), weapon(std::move(startingWeapon)) {
    }

    virtual ~Character() = default;

    // Абстрактний метод — робить клас абстрактним.
    // Кожен персонаж представляється по-своєму.
    virtual void display() const = 0;

    // Виконати атаку: делегуємо роботу поточній стратегії
    void fight() const {
        std::cout << "[" << name << " | " << weapon->getName() << "] ";
        weapon->useWeapon();
    }

    // ЗМІНА СТРАТЕГІЇ ПІД ЧАС ВИКОНАННЯ — ключ паттерну "Стратегія"
    void setWeapon(std::unique_ptr<IWeapon> newWeapon) {
        weapon = std::move(newWeapon);
        std::cout << ">> " << name << " змінив зброю на: "
                  << weapon->getName() << std::endl;
    }

    std::string getName() const { return name; }
};

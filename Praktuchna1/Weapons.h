#pragma once
#include <iostream>
#include "IWeapon.h"

// =====================================================================
// Конкретні стратегії (4 класи зброї).
// Кожен клас інкапсулює СВІЙ алгоритм атаки.
// =====================================================================

class Sword : public IWeapon {
public:
    void useWeapon() const override {
        std::cout << "Рубає мечем! *вжух-вжух*" << std::endl;
    }
    std::string getName() const override { return "Меч"; }
};

class Bow : public IWeapon {
public:
    void useWeapon() const override {
        std::cout << "Стріляє з лука! *свист стріли*" << std::endl;
    }
    std::string getName() const override { return "Лук"; }
};

class Axe : public IWeapon {
public:
    void useWeapon() const override {
        std::cout << "Трощить сокирою! *БУМ*" << std::endl;
    }
    std::string getName() const override { return "Сокира"; }
};

class MagicStaff : public IWeapon {
public:
    void useWeapon() const override {
        std::cout << "Чаклує посохом! *фаєрбол полетів*" << std::endl;
    }
    std::string getName() const override { return "Магічний посох"; }
};

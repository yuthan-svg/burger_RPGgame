#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Effect.h"
#include "Abillity.h"

static constexpr int MAX_ABILITIES = 5;

class Character {
private:
    std::string name;
    int hp;
    int maxHp;
    int baseDamage;
    int stamina;
    int maxStamina;
    int staminaRegen;
    int block;

    std::vector<int> abillityIds;
    std::vector<std::unique_ptr<Effect>> activeEffects;

public:
    Character(std::string name, int maxHp, int baseDamage, int maxStamina, int staminaRegen);

    // Стан та ресурси
    bool isAlive() const;
    bool canUse(const Abillity& ability) const;
    void spendStamina(int amount);
        
    // Бойові дії
    void takeDamage(int amount);
    void heal(int amount);
    void addBlock(int amount);
    

    // Ефекти та хід
    void addEffect(std::unique_ptr<Effect> effect);
    void startTurn();
    bool isStunned() const;

    // Здібності
    bool learnAbility(int abilityId);
    const std::vector<int>& getAbilityIds() const;

    // Геттери для інтерфейсу та бою
   const std::string& getName() const;
    int getHp() const;
    int getMaxHp() const;
    int getBaseDamage() const;
    int getStamina() const;
    int getMaxStamina() const;
    int getBlock() const;
};
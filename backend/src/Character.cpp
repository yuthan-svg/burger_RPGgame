#include "Character.h"
#include <algorithm>

Character::Character(std::string name, int maxHp, int baseDamage, int maxStamina, int staminaRegen)
    : name(std::move(name)),
    hp(maxHp),
    maxHp(maxHp),
    baseDamage(baseDamage),
    stamina(maxStamina),
    maxStamina(maxStamina),
    staminaRegen(staminaRegen),
    block(0) {}

bool Character::isAlive() const {
    return hp > 0;
}
bool Character::canUse(const Abillity& ability) const {
    return stamina >= ability.getStaminaCost();
}

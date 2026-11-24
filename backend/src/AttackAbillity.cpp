#include "AttackAbillity.h"
#include "Character.h"

AttackAbillity::AttackAbillity(int id, std::string name, std::string word, int power, int staminaCost,
    std::vector<EffectInfo> appliedEffect)
    : Abillity(id, std::move(name), std::move(word), power, staminaCost, std::move(appliedEffect)) {}

void AttackAbillity::use(Character& user, Character& target) { 
    target.takeDamage(getPower());
}
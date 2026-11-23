#include "AttackAbillity.h"

AttackAbillity::AttackAbillity(int id, std::string name, std::string word, int power, int staminaCost,
    std::vector<EffectInfo> appliedEffect)
    : Abillity(id, std::move(name), std::move(word), power, staminaCost, std::move(appliedEffect)) {}

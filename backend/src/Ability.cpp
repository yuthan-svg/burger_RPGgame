#include "Ability.h"

Ability::Ability(int id, std::string name,
	std::string word, int power,
	int staminaCost, ActionType aType,
	std::vector<EffectInfo> appliedEffect) :
	id(id),
	name(name),
	word(word),
	power(power),
	staminaCost(staminaCost),
	aType(aType),
	appliedEffect(appliedEffect) {}

std::string Ability::getName() const { return name; }
std::string Ability::getWord() const { return word; }
int Ability::getStaminaCost() const { return staminaCost; }
int Ability::getPower() const { return power; }
ActionType Ability::getType() const { return aType; }
std::vector<EffectInfo> Ability::getEffects() const { return appliedEffect; }






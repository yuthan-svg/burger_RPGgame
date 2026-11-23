#include "Abillity.h"

Abillity::Abillity(int id, std::string name,
	std::string word, int power,
	int staminaCost,
	std::vector<EffectInfo> appliedEffect) :
	id(id),
	name(std::move(name)),
	word(std::move(word)),
	power(power),
	staminaCost(staminaCost),
	appliedEffect(std::move(appliedEffect)) {}

std::string Abillity::getName() const { return name; }
std::string Abillity::getWord() const { return word; }
int Abillity::getStaminaCost() const { return staminaCost; }
int Abillity::getPower() const { return power; }
const std::vector<EffectInfo>& Abillity::getEffects() const { return appliedEffect; }
int Abillity::getId() const { return id; }







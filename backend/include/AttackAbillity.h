#pragma once
#include <iostream>
#include "Abillity.h"

class AttackAbillity : public Abillity {
	AttackAbillity(int id, std::string name, std::string word, int power, int staminaCost,
		std::vector<EffectInfo> appliedEffect);

	std::vector<std::string> use(Character& user, Character& target) override;
};
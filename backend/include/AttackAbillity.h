#pragma once
#include <iostream>
#include "Abillity.h"

class AttackAbillity : public Abillity {
public:
	AttackAbillity(int id, std::string name, std::string word, int power, int staminaCost,
		std::vector<EffectInfo> appliedEffect);
	void use(Character& user, Character& target) override;
};
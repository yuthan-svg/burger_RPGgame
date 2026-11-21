#pragma once
#include <string>
#include <vector>
#include "Ability.h"

class AbillityDatabase {
public:
	Ability getById(int id);
};

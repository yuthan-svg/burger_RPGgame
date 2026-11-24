#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "Abillity.h"
#include "AttackAbillity.h"

class AbillityDatabase {
private:
	static std::map<int, std::unique_ptr<Abillity>> allAbillity;
public:
	static void add(std::unique_ptr<Abillity> abillity);
	static void init();
	static const Abillity& getById(int id);
};

#include "AbillityDatabase.h"


std::map<int, std::unique_ptr<Abillity>> AbillityDatabase::allAbillity;

void AbillityDatabase::init()
{
	add(std::make_unique<AttackAbillity>(1, "attack", "attack", 10, 25, std::vector<EffectInfo>{}));
}

const Abillity& AbillityDatabase::getById(int id) 
{
	auto it = allAbillity.find(id);
	if (it == allAbillity.end() || it->second == nullptr) {
		throw std::invalid_argument("No abillity on this id");
	}
	
	return *(it->second);
}

bool AbillityDatabase::exists(int id) {
	auto it = allAbillity.find(id);
	return it != allAbillity.end() && it->second != nullptr;
}

void AbillityDatabase::add(std::unique_ptr<Abillity> abillity)
{
	if (!abillity) {
		throw std::invalid_argument("No abillity");
	}
	int id = abillity->getId();

	if (allAbillity.find(id) != allAbillity.end()) {
		throw std::invalid_argument("No id in allAbillity");
	}
	allAbillity.emplace(id, std::move(abillity));
}



#include "AbillityDatabase.h"

std::map<int, std::unique_ptr<Abillity>> AbillityDatabase::allAbillity;

void AbillityDatabase::init()
{
}

const Abillity& AbillityDatabase::getById(int id) 
{
	auto it = allAbillity.find(id);
	if (it == allAbillity.end() || !it->second) {
		throw std::out_of_range("Ability with requested id not found in AbillityDatabase");
	}
	return *(it->second);
}

void AbillityDatabase::add(std::unique_ptr<Abillity> abillity) 
{	
	if (!abillity) {
		return;
	}
	int id = abillity->getId();

	if (allAbillity.find(id) != allAbillity.end()) {
		return;
	}
	allAbillity.emplace(id, std::move(abillity));
}



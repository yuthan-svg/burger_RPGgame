#include "Character.h"
#include <stdexcept>
#include <algorithm>
#include "AbillityDatabase.h"

Character::Character(std::string name, int maxHp, int baseDamage, int maxStamina, int staminaRegen)
	: name(std::move(name)),
	hp(maxHp),
	maxHp(maxHp),
	baseDamage(baseDamage),
	stamina(maxStamina),
	maxStamina(maxStamina),
	staminaRegen(staminaRegen),
	block(0) {}

// Стан та ресурси
bool Character::isAlive() const {
	return hp > 0;
}
bool Character::canUse(const Abillity& ability) const {
	return stamina >= ability.getStaminaCost();
}

void Character::spendStamina(int amount) {
	if (amount < 0) {
		throw std::out_of_range("spendStamina: amount must be > 0");
	}
	stamina -= amount;
}

// Бойові дії
void Character::takeDamage(int amount) {
	if (amount < 0) {
		throw std::out_of_range("takeDamage: amount must be > 0");
	}
	hp -= amount;
}

void Character::heal(int amount) {
	if (amount < 0) {
		throw std::out_of_range("heal: amount must be > 0");
	}
	hp += amount;
}

void Character::addBlock(int amount) {
	if (amount < 0) {
		throw std::out_of_range("addBlock: amount must be > 0");
	}
	block += amount;
}

// Ефекти та хід
void Character::addEffect(std::unique_ptr<Effect> effect) {
	activeEffects.emplace_back(effect);
	//дописати class effect тоді дописувати цей блок, додати id в векотр персонажа 
}

bool Character::isStunned() const {
	// перевірити чи є ефектах на персонажові ефект stun
}

//Здібності
bool Character::learnAbility(int abilityId) {
	if (abillityIds.size() >= MAX_ABILITIES || !AbillityDatabase::exists(abilityId)) {
		return false;
	}
	if (std::find(abillityIds.begin(), abillityIds.end(), abilityId) != abillityIds.end()) {
		return false;
	}
	abillityIds.push_back(abilityId);
	return true;
}

//гетери
const std::string& Character::getName() const {
	return name;
}

int Character::getHp() const {
	return hp;
}

int Character::getMaxHp() const {
	return maxHp;
}

int Character::getBaseDamage() const {
	return baseDamage;
}

int Character::getStamina() const {
	return stamina;
}

int Character::getMaxStamina() const {
	return maxStamina;
}

int Character::getBlock() const {
	return block;
}


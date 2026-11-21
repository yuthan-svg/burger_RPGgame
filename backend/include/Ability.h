#pragma once
#include <string>
#include <vector>
#include <memory>
class Character;

enum class ActionType {
    Damage,
    Heal,
    Block
};

enum class EffectType {
    Poison,
    Burn,
    Stun
};

struct EffectInfo {
    EffectType type;
    int power;
    float duration;
};

class Ability {
private:
	int id;
	std::string name;
	std::string word;
	int power;
	int staminaCost;
    ActionType aType;
    std::vector<EffectInfo> appliedEffect;
public:
    Ability(int id, std::string name, std::string word, int power, int staminaCost, ActionType aType, std::vector<EffectInfo> appliedEffect);
    virtual std::vector<std::string> use(Character& user, Character& target) = 0;
    int getId() const;
    std::string getName() const;
    std::string getWord() const;
    int getStaminaCost() const;
    int getPower() const;
    ActionType getType() const;
    EffectType getEfType();
    virtual ~Ability() = default;
};




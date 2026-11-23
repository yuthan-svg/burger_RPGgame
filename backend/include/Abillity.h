#pragma once
#include <string>
#include <vector>
#include <memory>
class Character;


struct EffectInfo {
    int power;
    float duration;
    float tickInterval;
};

class Abillity {
protected:
	int id;
	std::string name;
	std::string word;
	int power;
	int staminaCost;
    std::vector<EffectInfo> appliedEffect;
public:
    Abillity(int id, std::string name, std::string word, int power, int staminaCost,  std::vector<EffectInfo> appliedEffect);
    virtual std::vector<std::string> use(Character& user, Character& target) = 0;
    int getId() const;
    std::string getName() const;
    std::string getWord() const;
    int getStaminaCost() const;
    int getPower() const;
    const std::vector<EffectInfo>& getEffects() const;
    virtual ~Abillity() = default;
};




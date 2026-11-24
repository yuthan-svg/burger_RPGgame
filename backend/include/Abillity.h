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
    //метод який просто виконує а не знімає ману і не перевіряє
    virtual void use(Character& user, Character& target) = 0; // тип повернення можна змінити на std::vector<структура, яка повертає як рядок даних шо ми зробили в методі>
    int getId() const;
    std::string getName() const;
    std::string getWord() const;
    int getStaminaCost() const;
    int getPower() const;
    const std::vector<EffectInfo>& getEffects() const;
    virtual ~Abillity() = default;
};




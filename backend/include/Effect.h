#pragma once
class Effect {
protected:
    int damage;
    int duration;
public:
    Effect(int damage, int duration);
    virtual void onTick(Character& other) = 0;
    virtual bool isExpired() = 0;
};

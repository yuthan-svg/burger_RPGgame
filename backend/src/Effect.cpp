
class Effect {
protected:
    int damage;
    int duration;
public:
    Effect(int damage, int duration)
        : damage(damage), duration(duration) {};
   virtual void onTick(Character& other) = 0;
   virtual bool isExpired() = 0;
};

class PoisonEffect : public Effect {
public:
    PoisonEffect(int damage, int duration) 
        : Effect(damage, duration) {};

    void onTick(Character& other) override {
        other.receiveDamage(damage);
        duration--;
    }
    bool isExpired() override {
        return duration <= 0;
    }
};

class BurnEffect : public Effect {

};

class RegenEffect : public Effect {

};

class StunEffect : public Effect {

};


#include <iostream>
#include <string>


using namespace std;
class fighter {
public:
	int xp;
	int damage;
	fighter(int a, int b) {
		xp = a;
		damage = b;
	}
	void hit(int a){
		xp = xp - a;
		cout << xp << endl;
	}
	fighter operator + (const fighter& Fighter) const {
		return fighter{ xp + Fighter.xp, damage + Fighter.damage };
	}
	
};
class horse : public fighter{
public:
	horse() : fighter(100, 10) {};
	void leg_hit(fighter& target){
		target.hit(damage);
	}
};
class knight: public fighter
{
public:
	knight() : fighter(60, 30) {};
	knight(const fighter& f) : fighter(f.xp, f.damage) {};
	void strike(fighter& target) {
		target.hit(damage);
	}
};
class horseman:public knight, public horse{
public:
	horseman() :knight(), horse(){};
	void combo_attack(fighter& target) {
		horse::leg_hit(target);
		knight::strike(target);
	}
	void print_stats() {
		cout << "Horseman Stats" << endl;
		cout << "Horse: " << horse::xp << " HP, " << horse::damage << " damage" << endl;
		cout << "Knight: " << knight::xp << " HP, " << knight::damage << " damage" << endl;
		cout << "Combo damage: " << horse::damage + knight::damage << endl;
		cout << "Total HP: " << horse::xp + knight::xp << endl;
	}
};
int main(){
	horseman rider;
	knight dima;
	horse kostya;
	fighter orc(100, 20);

	cout << "Horseman combo attacks orc" << endl;
	rider.combo_attack(orc);

	cout << "\nKnight attacks orc" << endl;
	dima.strike(orc);

	rider.combo_attack(dima);

	rider.knight::hit(kostya.damage); // тут немного костыль извините
	rider.print_stats();



	knight petr;
	knight rasul = petr + dima;
	cout << rasul.xp << endl;
	cout << rasul.damage << endl;
}

#include <iostream>
#include <vector>
using namespace std;

class Monsieur {
public:
	Monsieur() : speed(0), jumpHeight(0), dodgeResponse(0), attackRange(0) {};
	Monsieur(double si, double jhi, double dri, double ari) : speed(si), jumpHeight(jhi), dodgeResponse(dri), attackRange(ari) {};
	string move();
	string jump();
	string dodge();
	string attack();
	Monsieur* makeClone();
	virtual string ability1();
	virtual string ability2();
	virtual string ability3();
	virtual string ability4();
protected:
	double speed;
	double jumpHeight;
	double dodgeResponse;
	double attackRange;
};

class LoveChild {
public:
	LoveChild(Monsieur* p1i, Monsieur* p2i);
	string move();
	string jump();
	string dodge();
	string attack();
	Monsieur* makeClone();
	string ability1();
	string ability2();
	string ability3();
	string ability4();
private:
	Monsieur* parent0; // not mother and father
	Monsieur* parent1; // this is 2016
	bool turn;
};

LoveChild::LoveChild(Monsieur* p0i, Monsieur* p1i) {
	turn = false;
	parent0 = p0i;
	parent1 = p1i;
}
string LoveChild::move() {
	turn = !turn;
	return (turn) ? (parent1 -> move()) : (parent0 -> move());
}
string LoveChild::jump() {
	turn = !turn;
	return (turn) ? (parent1 -> jump()) : (parent0 -> jump());
}
string LoveChild::dodge() {
	turn = !turn;
	return (turn) ? (parent1 -> dodge()) : (parent0 -> dodge());
}
string LoveChild::attack() {
	turn = !turn;
	return (turn) ? (parent1 -> attack()) : (parent0 -> attack());
}

Monsieur* LoveChild::makeClone() {
	turn = !turn;
	return (turn) ? (parent1 -> makeClone()) : (parent0 -> makeClone());
}
string LoveChild::ability1() {
	turn = !turn;
	return (turn) ? (parent1 -> ability1()) : (parent0 -> ability1());
}
string LoveChild::ability2() {
	turn = !turn;
	return (turn) ? (parent1 -> ability2()) : (parent0 -> ability2());
}
string LoveChild::ability3() {
	turn = !turn;
	return (turn) ? (parent1 -> ability3()) : (parent0 -> ability3());
}
string LoveChild::ability4() {
	turn = !turn;
	return (turn) ? (parent1 -> ability4()) : (parent0 -> ability4());
}

string Monsieur::move() {
	// do something using speed
	return "moved";
}
string Monsieur::jump() {
	// do something using jumpHeight
	return "jumped";
}
string Monsieur::dodge() {
	// do something using dodgeResponse
	return "dodged";
}
string Monsieur::attack() {
	// do something using attackRange
	return "attacked";
}

class Moony : public Monsieur {
public:
	Moony() {Monsieur(1.5, 3, 2, 9);}; // arbitrary numbers
	string ability1() {
		// do something
		return "checked for moon - became wolf";
	}
	string ability2() {
		// do something
		return "howled";
	}
	string ability3() {
		// do something
		return "ate person";
	}
	string ability4() {
		// do something
		return "became human";
	}
};

class Wormtail : public Monsieur {
public:
	Wormtail() {Monsieur(8, 0.5, 5.25, 1);}; // arbitrary numbers
	string ability1() {
		// do something
		return "became rat";
	}
	string ability2() {
		// do something
		return "turned off Whomping Willow";
	}
	string ability3() {
		// do something
		return "cut off finger";
	}
	string ability4() {
		// do something
		return "became human";
	}
};

class Padfoot : public Monsieur {
public:
	Padfoot() {Monsieur(5, 2.8, 7, 2.1);}; // arbitrary numbers
	string ability1() {
		// do something
		return "became dog";
	}
	string ability2() {
		// do something
		return "fought off Snape";
	}
	string ability3() {
		// do something
		return "survived Azkaban";
	}
	string ability4() {
		// do something
		return "became human";
	}
};

class Prongs : public Monsieur {
public:
	Prongs() {Monsieur(2, 6, 0.3, 4);}; // arbitrary numbers
	string ability1() {
		// do something
		return "became stag";
	}
	string ability2() {
		// do something
		return "got betrayed :(";
	}
	string ability3() {
		// do something
		return "got married";
	}
	string ability4() {
		// do something
		return "became human";
	}
};

Monsieur* Monsieur::makeClone() {
	if (Moony* ptr = dynamic_cast<Moony*>(this)) {
	    Moony* clone = new Moony[1];
		clone -> speed = speed;
		clone -> jumpHeight = jumpHeight;
		clone -> dodgeResponse = dodgeResponse;
		clone -> attackRange = attackRange;
		return clone;
	}
	if (Wormtail* ptr = dynamic_cast<Wormtail*>(this)) {
		Wormtail* clone = new Wormtail[1];
		clone -> speed = speed;
		clone -> jumpHeight = jumpHeight;
		clone -> dodgeResponse = dodgeResponse;
		clone -> attackRange = attackRange;
		return clone;
	}
	if (Padfoot* ptr = dynamic_cast<Padfoot*>(this)) {
		Padfoot* clone = new Padfoot[1];
		clone -> speed = speed;
		clone -> jumpHeight = jumpHeight;
		clone -> dodgeResponse = dodgeResponse;
		clone -> attackRange = attackRange;
		return clone;
	}
	if (Prongs* ptr = dynamic_cast<Prongs*>(this)) {
		Prongs* clone = new Prongs[1];
		clone -> speed = speed;
		clone -> jumpHeight = jumpHeight;
		clone -> dodgeResponse = dodgeResponse;
		clone -> attackRange = attackRange;
		return clone;
	}
	return this; // will never happen
}


class Driver {
public:
	Driver(vector<Monsieur*> messieursI);
	void runTurn (vector<string> moves);
	void doAbility1();
private:
	vector<Monsieur*> messieurs;
};

void Driver:: doAbility1() {
	for (int i = 0; i < messieurs.size(); i++) {
		cout << messieurs[i] -> ability1() << endl;
	}
}

int main() {
	;
}
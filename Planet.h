#ifndef PLANET_H
#define PLANET_H

class Planet{
private:
    Planet* id;
	unsigned int pos;
	unsigned int distance;
	char type;
public:
	Planet(unsigned int);
	unsigned int orbit();
	unsigned long getID(){ return (unsigned long)this; }
	unsigned int getDistance(){ return this->distance; }
	unsigned int getPos(){ return this->pos; }
	char getType(){ return this->type; }
	void printPlanetInfo();

	//you may add any additional methods you may need.
};

#endif

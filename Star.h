#ifndef STAR_H
#define STAR_H
#include "Planet.h"
#include "List.h"
#include "Vector.h"

class Starlist{
public:
    List* list;
    Starlist();
    ~Starlist();
    unsigned long addPlanet();
    bool removePlanet(unsigned long);
    Planet* getPlanet(unsigned long);
    void orbit();
    void printStarInfo();
    unsigned int getCurrentNumPlanets();
};

class Starvector{
private:
    Vector* vector;
    unsigned int nextIndex;
public:
    Starvector();
    ~Starvector();
    unsigned long addPlanet();
    bool removePlanet(unsigned long);
    Planet* getPlanet(unsigned long);
    void orbit();
    void printStarInfo();
    unsigned int getCurrentNumPlanets();
};
#endif

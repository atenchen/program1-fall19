#include "Star.h"
#include <cstdlib>

Starlist::Starlist(){
	list = new List();
}

Starlist::~Starlist(){
    delete list;
}

unsigned long Starlist::addPlanet(){
	Planet* newPlanet = new Planet(rand());
    list->insert(0,newPlanet);
	return newPlanet->getID();
}

bool Starlist::removePlanet(unsigned long id){
    Node* traversal = list->head;
  	for(int i = 0; traversal != NULL; i++, traversal = traversal->next){
      	if(traversal->planet->getID() == id){
          	return(this->list->remove(i));
        }
    }
	return false;
}

Planet* Starlist::getPlanet(unsigned long id){
	Node* traversal = list->head;
  	while(traversal != NULL){
		if(traversal->planet->getID() == id){
			return traversal->planet;
        }
      	traversal = traversal->next;
    }
  	return NULL;
}
void Starlist::orbit(){
	Node* traversal = list->head;
  	while(traversal != NULL){
		traversal->planet->orbit();
      	traversal = traversal->next;
    }
}
void Starlist::printStarInfo(){
	Node* traversal = list->head;
  	while(traversal != NULL){
		traversal->planet->printPlanetInfo();
      	traversal = traversal->next;
    }
}
unsigned int Starlist::getCurrentNumPlanets(){
	unsigned int i = 0;
  	Node* traversal = list->head;
  	while(traversal != NULL){
		i++;
      	traversal = traversal->next;
    }
	return i;
}

/*
          __
     w  c(..)o   (
      \__(-)    __)
          /\   (
         /(_)___)
         w /|
          | \
ejm97    m  m
*/

Starvector::Starvector(){
	this->nextIndex = 0;
	this->vector = new Vector();
}

Starvector::~Starvector(){
	delete vector;
}

unsigned long Starvector::addPlanet(){
  Planet* newPlanet = new Planet(rand());
  vector->insert(nextIndex,newPlanet);
  nextIndex++;
  return newPlanet->getID();
}

bool Starvector::removePlanet(unsigned long id){
	for(unsigned int i =0; i < nextIndex; i++){
      unsigned long indexId = vector->read(i)->getID();
      if(indexId == id){
        vector->remove(i);
        return true;
      }
    }
	return false;
}

Planet* Starvector::getPlanet(unsigned long id){
	for(unsigned i =0; i < nextIndex; i++){
      unsigned long indexId = vector->read(i)->getID();
      if(indexId == id){
        return vector->read(i);
      }
    }
  return NULL;
}

void Starvector::orbit(){
  for(unsigned int i = 0; i < nextIndex; i ++){
    Planet* planetPointer = vector->read(i);
    if(planetPointer != NULL){
      planetPointer->orbit();
    }
  }
}

void Starvector::printStarInfo(){
  for(unsigned int i = 0; i < nextIndex; i ++){
        Planet* planetPointer = vector->read(i);
        if(planetPointer != NULL){
          planetPointer->printPlanetInfo();
      }
  }
}

unsigned int Starvector::getCurrentNumPlanets(){
  unsigned int numPlanets = 0;
  for(unsigned int i = 0; i < nextIndex; i ++){
    Planet* planetPointer = vector->read(i);
    if(planetPointer != NULL){
      numPlanets++;
    }
  }
  return numPlanets;
}

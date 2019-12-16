#include "Vector.h"


Vector::Vector(){
    this->totalSize = 0;
    this->vectors = NULL;
}
Vector::~Vector(){
    for(unsigned int i = 0; i < totalSize; i ++){
    if(vectors[i]!= NULL) delete vectors[i];
    }
    delete[] vectors;
}
void Vector::insert(unsigned int index,Planet * p){
    unsigned int previousSize = totalSize;
    if(index >= totalSize){
        totalSize = index + 1;
    }
    else{
        totalSize++;
    }

    Planet ** newVectors = new Planet*[totalSize];
    for(unsigned int i = 0; i < index; i++){
        if(i < previousSize){
            newVectors[i] = vectors[i];
        }
        else{
            newVectors[i] = NULL;
        }
    }
    newVectors[index] = p;
    for(unsigned int i = index+1; i < totalSize;i++){
        if(i < previousSize+1){
            newVectors[i]=vectors[i-1];
        }
        else{
            newVectors[i] = NULL;
        }
    }
    delete[] vectors;
    vectors = newVectors;
}
Planet* Vector::read(unsigned int index){
  if(index >= totalSize){
    return NULL;
  }
  return vectors[index];
}
bool Vector::remove(unsigned int index){
  if(index >= totalSize){
    return false;
  }
  else{
    Planet ** newVectors = new Planet*[totalSize];
    for(unsigned int i = 0; i < index; i++){
      newVectors[i] = vectors[i];
    }
    for(unsigned int i = index+1; i < totalSize;i++){
      newVectors[i-1]=vectors[i];
    }
    totalSize--;
    delete vectors[index];
    delete[] vectors;
    vectors = newVectors;
    return true;
  }
}

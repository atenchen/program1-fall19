#ifndef VECTOR_H
#define VECTOR_H
#include "Planet.h"
#include <iostream>
#include <cstdlib>

class Vector{
 public:
  unsigned int totalSize;
  Planet ** vectors;
  Vector();
  ~Vector();
  void insert(unsigned int index, Planet * p);
  Planet* read(unsigned int index);
  bool remove(unsigned int index);
  unsigned int size(){return totalSize;};
};

#endif

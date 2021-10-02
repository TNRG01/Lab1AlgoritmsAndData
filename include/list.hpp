#ifndef LIST_HPP
#define  LIST_HPP
#include "nodes.hpp"
#include <iostream>

using T=long;

class list {
private:
unsigned m_size;
nodes *m_head;

public:
//Constructors
list ();
list (unsigned size);
list (unsigned size, const T &val);
//Destructor
virtual ~list ();
//methods
unsigned size ();
void resize (unsigned  nsize);
T &operator[] (unsigned index);
void push_back(const T& value);
bool contains(const T& val);
int find(const T& val);
void print();
};

#endif //LIST_HPP

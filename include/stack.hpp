#ifndef STACK_HPP
#define STACK_HPP
#include "nodes.hpp"
#include <iostream>

using T=long;

class stack {
private:
  nodes* m_head;

public:
  //Constructor
  stack();
  //Destructor
  virtual ~stack ();
  //Methods
  void push_up(const T &val);
  void pop_up();
  void head();
  void print();
};


#endif //STACK_HPP

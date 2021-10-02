#include "stack.hpp"
#include "nodes.hpp"
#include <iostream>

stack::stack() : m_head(NULL) {};

void stack::push_up(const T &val){
  nodes *tmp = new nodes();
  tmp->data = val;
  tmp->next = m_head;
  m_head = tmp;
  std::cout << "Value added." << '\n';
}

void stack::pop_up(){
  nodes *tmp;
  T x;
  if(m_head ==NULL){
    std::cout << "Empty stack." << '\n';
  }else{
    tmp = m_head;
    x = tmp->data;
    m_head = m_head->next;
    delete tmp;
    }
}

void stack::head(){
  if(m_head ==NULL){
    std::cout << "Stack empy." << '\n';
  }else{
    std::cout << "Head is: " << m_head->data << '\n';;
  }
}

void stack::print(){
  nodes *tmp = m_head;
  while (tmp != NULL) {
    std::cout << "-" << tmp->data;
    tmp = tmp->next;
  }
  std::cout  << '\n';
}

stack::~stack () {
  delete m_head;
}

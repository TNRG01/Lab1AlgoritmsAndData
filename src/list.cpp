#include <list.hpp>
#include <nodes.hpp>
#include <iostream>


list::list () : m_size(0) {
  m_head = new nodes();
  m_head->next = nullptr;
}

list::list (unsigned size): m_size(size) {

  m_head = new nodes();

  // The m_head and the rest of elements of the list are initialized is the
  // size is greater than 0.
  if (size > 0) {

    // Set the value for m_head.
    m_head->data = T();

    // Set the m_head as the previous node.
    nodes *prev_node = m_head;

    // Fill the other elements of the list.
    for (unsigned i = 1; i < size; i++) {
      // Create the node.
      nodes *next_node = new nodes();

      // Initialize the node.
      next_node->data = T();

      // Connect the previous node with the next.
      prev_node->next = next_node;

      // Update the previous node.
      prev_node = next_node;
    }
    prev_node->next = nullptr;

  } else {
    m_head->next = nullptr;
  }

}

list::list (unsigned size, const T &val): m_size(size) {

  m_head = new nodes();

  // The m_head and the rest of elements of the list are initialized if the
  // size is greater than 0.
  if (size > 0) {

    // Set the value for m_head.
    m_head->data = val;

    // Set the m_head as the previous node.
    nodes *prev_node = m_head;

    // Fill the other elements of the list.
    for (unsigned i = 1; i < size; i++) {
      // Create the node.
      nodes *next_node = new nodes();

      // Initialize the node.
      next_node->data = val;

      // Connect the previous node with the next.
      prev_node->next = next_node;

      // Update the previous node.
      prev_node = next_node;
    }
    prev_node->next = nullptr;

  } else {
    m_head->next = nullptr;
  }

}

list::~list () {
  delete m_head;
}

unsigned list::size() {
  // Go to the private object
  return m_size;
}

T &list::operator[] (unsigned index) {
  nodes *asked_node = m_head;

  for (unsigned i = 0; i < index; i++) {
    asked_node = asked_node->next;
  }

  return asked_node->data;

}
void list::push_back(const T& value){

  nodes* m = m_head;

  while (m->next) {

    m = m->next;
  }

  m->next = new nodes();

  m->next->data = value;

  m_size++;

}

void list::resize(unsigned n_size) {

  nodes* ptr = m_head;

  if (n_size < m_size) {

    for (unsigned i = 0; i < n_size; i++) {

      ptr = ptr->next;

    }

    delete ptr;

  } else if (n_size > m_size) {
    //In this if statememt the program adds space for new elements

    for (unsigned i = 0; i < n_size; i++) {

      if (i+1 >= m_size && i+1 != n_size)

      ptr->next = new nodes;

      ptr = ptr->next;
    }
  }
  m_size = n_size;
}

bool list::contains(const T& val) {

  nodes* ptr = m_head;

  for (unsigned i = 0; i < m_size; i++) {

    if (ptr->data == val){

      return true;
    }
    else{
      ptr = ptr->next;
    }
  }
  return false;
}


int list::find(const T& val) {

  nodes* ptr = m_head;
  //this cicle is for look for the position of the value we want
  for (int i = 0; i < m_size; i++) {


    if (ptr-> data == val){

      return i;
    }
    else{

      ptr = ptr->next;
    }
  }
  return -1;
}

void list::print(){

  nodes *ptr = m_head;

  for (size_t i = 0; i < m_size; i++) {
    std::cout << "Element " << i << " : " << ptr->data << '\n';

    ptr = ptr->next;
  }

}

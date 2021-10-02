#include "array.hpp"
#include "list.hpp"
#include "nodes.hpp"
#include "stack.hpp"
#include <iostream>

bool menuSimpleList();
bool menuDynamicArray();
bool menuStack();

int main(int argc, char const *argv[]) {
  unsigned option1;
  std::cout << "Do you want to use: " << '\n';
  std::cout << "1. Simple linked list." << '\n';
  std::cout << "2. Dynamic Array." << '\n';
  std::cout << "3. Stack." << '\n';
  std::cout << "4. Exit." << '\n';
  std::cin >> option1;
  switch (option1) {
    case 1:
    {
      std::cout << "Simple linked list" << '\n';
      bool choice_simplelinkedlist {true};
      while(choice_simplelinkedlist)
      {
        choice_simplelinkedlist = menuSimpleList();
      }
    }
    break;
    case 2:
    {
      bool choice_dynamicarray {true};
      while(choice_dynamicarray)
      {
        choice_dynamicarray = menuDynamicArray();
      }
    }
    break;
    case 3:
    {
      std::cout << "Stack" << '\n';
      bool choice_stack {true};
      while(choice_stack)
      {
        choice_stack = menuStack();
      }
    }
    break;
    default:
    break;
  }
  std::cout << "bye" << '\n';
  return 0;
}


bool menuSimpleList()
{
  list b = list();
  unsigned option_menuSimpleList;
  bool choice_menuSimpleList {true};
  while (choice_menuSimpleList)
  {
    std::cout << "1. Size" << '\n';
    std::cout << "2. Resize" << '\n';
    std::cout << "3. Push back" << '\n';
    std::cout << "4. Contains" << '\n';
    std::cout << "5. Find" << '\n';
    std::cout << "6. Print" << '\n';
    std::cout << "7. Exit" << '\n';
    std::cin >> option_menuSimpleList;
    switch (option_menuSimpleList) {
      case 1:
      std::cout << "The size is: " << b.size() << '\n';
      break;
      case 2:
      unsigned new_size;
      std::cout << "Insert the new size: ";
      std::cin >> new_size;
      b.resize(new_size);
      std::cout << "The new size is: " << new_size << '\n';
      break;
      case 3:
      T value;
      std::cout << "Insert the new value: ";
      std::cin >> value;
      b.push_back(value);
      std::cout << "Value added" << '\n';
      break;
      case 4:
      T contains;
      std::cout << "Insert the element to look for: " << '\n';
      std::cin >> contains;
      if (b.contains(contains)) {
        std::cout << "The element is in the list." << '\n';
      } else {
        std::cout << "The element is not in the list" << '\n';
      }
      break;
      case 5:
      T find;
      std::cout << "Insert the element to find: ";
      std::cin >> find;
      std::cout << "The element is in the position: " << b.find(find) << '\n';
      break;
      case 6:
      b.print();
      break;
      case 7:
      choice_menuSimpleList = false;
      break;
      default:
      choice_menuSimpleList = false;
      break;
    }
  }
  return false;
}


bool menuDynamicArray(){
  array<long> a(0);
  unsigned option_menuDynamicArray;
  bool choice_menuDynamicArray {true};
  while (choice_menuDynamicArray)
  {
    std::cout << "1. Size" << '\n';
    std::cout << "2. Resize" << '\n';
    std::cout << "3. Push back" << '\n';
    std::cout << "4. Remove (the last element)" << '\n';
    std::cout << "5. Remove (specific position)" << '\n';
    std::cout << "6. Print" << '\n';
    std::cout << "7. Exit" << '\n';
    std::cin >> option_menuDynamicArray;
    switch (option_menuDynamicArray) {
      case 1:
      std::cout << "Size of the array: " << a.size() << '\n';
      break;
      case 2:
      unsigned new_size;
      std::cout << "Insert the new size: ";
      std::cin >> new_size;
      a.resize(new_size);
      std::cout << "The new size is: " << new_size << '\n';
      break;
      case 3:
      long value;
      std::cout << "Insert the new value: ";
      std::cin >> value;
      a.add(value);
      std::cout << "Value added" << '\n';
      break;
      case 4:
      if(a.size() != 0)
      {
        a.remove();
        std::cout << "The last element was removed" << '\n';
      }else
      {
        std::cout << "It could not be removed." << '\n';
      }
      break;
      case 5:
      unsigned remove_index;
      std::cout << "Insert the position to be removed: ";
      std::cin >> remove_index;
      a.remove(remove_index);
      std::cout << "The element was removed" << '\n';
      break;
      case 6:
      a.print();
      break;
      case 7:
      choice_menuDynamicArray =false;
      break;
      default:
      choice_menuDynamicArray =false;
    }
  }
  return false;
}

bool menuStack(){
  stack c = stack();
  unsigned option_menuStack;
  bool choice_menuStack {true};
  while (choice_menuStack)
  {
    std::cout << "1. Push up" << '\n';
    std::cout << "2. Pop up" << '\n';
    std::cout << "3. Head" << '\n';
    std::cout << "4. Print stack" << '\n';
    std::cout << "5. Exit" << '\n';
    std::cin >> option_menuStack;
    switch (option_menuStack) {
      case 1:
      T value;
      std::cout << "Insert the new value: ";
      std::cin >> value;
      c.push_up(value);
      break;
      case 2:
      c.pop_up();
      break;
      case 3:
      c.head();
      break;
      case 4:
      c.print();
      break;
      case 5:
      choice_menuStack = false;
      break;
      default:
      choice_menuStack = false;
      break;
    }
  std::cout << "*\t*\t*\t*" << '\n';
  }
  return false;
  }

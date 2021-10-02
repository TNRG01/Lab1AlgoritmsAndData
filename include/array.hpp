#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class array {
public:
  // Contructors.
  array ();
  array (size_t size);
  array (size_t size, T value);

  // Destructor
  virtual ~array ();

  // Modifiers
  void add(T value);
  void remove();
  void remove(size_t index);

  // Size
  size_t size() {return this->m_size;}

  // Operator []
  T &operator[] (size_t index);

  // print
  void print();

  //resize
  void resize(size_t n_size);

private:
  T *m_data;
  size_t m_size;

};

/*
*Constructor array() -- Sets default size to 0.
*/

template <typename T>
array<T>::array()
: m_size(0),
m_data(nullptr) { }

/*
* Constructor array(size) -- Sets array's size and fills  all data to 0.
*/
template <typename T>
array<T>::array(size_t size)
: m_size(size) {

  m_data = new T[m_size];

  for (size_t i = 0; i < m_size; i++) {
    m_data[i] = T();
  }

}

/*
* Constructor array(size, T) --
* Specify the size and fills all the spaces with the same value/
*/
template <typename T>
array<T>::array(size_t size, T value)
: m_size(size) {

  m_data = new T[m_size];

  for (size_t i = 0; i < m_size; i++) {
    m_data[i] = value;
  }

}

/*
* Destructor ~array() -- Delete all data from the array
*/

template <typename T>
array<T>::~array() {
  delete m_data;
}
/*
**
** Method add
** @param T value the value to add
*/

template <class T>
void array<T>::add(T value) {
  m_size++;

  T *temp_array = new T[m_size];

  for (size_t i = 0; i < m_size - 1; i++) {
    temp_array[i] = m_data[i];
  }

  temp_array[m_size - 1] = value;

  delete m_data;

  m_data = temp_array;

}

/*
* Method remove() - Delete last element
*/

template <typename T>
void array<T>::remove() {
  m_size--;

  T *temp_array = new T[m_size];

  for (size_t i = 0; i < m_size; i++) {
    temp_array[i] = m_data[i];
  }

  delete m_data;

  m_data = temp_array;

}

/*
* Method remove(index) -- Delete data specified index.
*/

template <typename T>
void array<T>::remove(size_t index) {
  if (index >= m_size) throw;

  m_size--;

  T *temp_array = new T[m_size];

  for (size_t i = 0; i < m_size + 1; i++) {
    if (index==i) continue;
    temp_array[i] = m_data[i];
  }

  delete m_data;

  m_data = temp_array;

}

/*
* Method operator []
*/

template <typename T>
T &array<T>::operator[] (size_t index) {
  return m_data[index];
}

/*
* Method print
*/

template <typename T>
void array<T>::print() {
  for (size_t i = 0; i < m_size; i++) {

    std::cout << "Position " << i << ": " << m_data[i] << '\n';
  }
}

/*
* Method resize
*/

template <typename T>
void array<T>::resize(size_t n_size){
  if (n_size == 0) {
    T *temp = new T[0];

    delete m_data;

    m_data = temp;

    m_size = 0;

  } else if (m_size > n_size) {

    T *temp = new T[n_size];

    for (size_t i = 0; i < n_size; i++) {

      m_data[i] = temp[i];
    }

    delete m_data;

    m_data = temp;

    m_size = n_size;

  } else if (n_size > m_size) {

    T *temp = new T[m_size];

    for (size_t i = 0; i < m_size; i++) {

      temp[i] = m_data[i];
    }

    for (size_t i = m_size; i < n_size; i++){

      temp[i] = 0;
    }

    delete[] m_data;

    m_data = temp;

    m_size = n_size;

  }

  }



#endif //ARRAY_H

/*
array dynamic

add **
size **
[] **
remove**
print**
resize**

*/

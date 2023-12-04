/**
 * @file deque.h
 * @author Jesse Warren
 * @date 2023-12-04
 * @brief The class file.
 * 
 * Holds the class which yields the implemented functions and variables.
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

using namespace std;

template <typename T>

class Deque {
 private:
  //Stores the deque elements.
  T** blockmap;
  //Necessary indexes and sizes for the array.
  int front, back, capacity, size;

 public:
  Deque();
  /* Description:
   *    Constructor which initializes the variables in private.
   */
  ~Deque();
  /* Description:
   *    Destructor which iterates through the array and deletes the necessary items.
   */
  void push_front(T value);
  /* Description:
   *    Adds a element to the front of the deque.
   */
  void push_back(T value);
  /* Description:
   *    Adds a element to the back of the deque.
   */
  void pop_front();
  /* Description:
   *    Removes an element from the front of the deque.
   */
  void pop_back();
  /* Description:
   *    Removes an element from the back of the deque.
   */
  T& Front();
  /* Description:
   *    Access the front element.
   */
  T& Back();
  /* Description:
   *    Access the back element.
   */
  bool empty() const;
  /* Description:
   *    Checks if the deque is empty and returns a bool based off the answer.
   */
  int blocksize() const;
  /* Description:
   *    Obtains the size of the deque.
   */
  T& operator[](int value);
  /* Description:
   *    Operator overload function that uses the [] to properly access the index of the deque.
   */
};

#endif
  

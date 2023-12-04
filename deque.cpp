/**
 * @file deque.cpp
 * @author Jesse Warren
 * @date 2023-12-04
 * @brief Holds the functions.
 * 
 * This file holds the functions that are defined in the .h file, as well as every needed implementation.
 */

#include "deque.h"
#include <iostream>

using namespace std;

template <typename T>
Deque<T>::Deque(){
  blockmap = NULL;
  front = 0;
  back = -1;
  capacity = 1;
  size = 1;

  blockmap = new T*[capacity];
  blockmap[0] = new T[size];
}

template <typename T>
Deque<T>::~Deque(){
    for(int i = 0; i < capacity; i++){
      delete[] blockmap[i];
    }
    delete[] blockmap;
}

template <typename T>
void Deque<T>::push_front(T val){
  //Checks if front is at the start.
  if (front == 0) {
    //Checks if the deque is empty, and if so it initializes it. 
    if (capacity == 0) {
      blockmap = new T*[1];
      blockmap[0] = new T[blocksize];
      capacity = 1;
    }
    else {
      //If it isn't empty, it resizes it.
      T** newmap = new T*[capacity + 1];
      newmap[0] = new T[blocksize];

      //Moves already existing blocks to make space.
      for(int i = 0; i < capacity; ++i) {
	newmap[i + 1] = blockmap[i];
      }
      
      delete[] blockmap;
      blockmap = newmap;
      ++capacity;
    }
    front = blocksize - 1;
    back = blocksize;
  }
  else 
      --front;
  //Stores the new value to the front position. 
  blockmap[0][front] = val;
}


template <typename T>
void Deque<T>::push_back(T val){
  //Checks if the back has reached the end.
  if(back == size * capacity - 1){
    T** newmap = new T*[capacity + 1];

    for(int i = 0; i < capacity; i++){
      newmap[i] = blockmap[i];
    }
    
    newmap[capacity] = new T[size];
    delete[] blockmap;
    blockmap = newmap;
    capacity++;

    //Updates back index.
    back = (back + 1) % (size * capacity); 
    front = 0;
  }
  //If there's any space, it will increment.
  else 
    back = (back + 1) % (size * capacity); 

  //Assigns value to back index.
  blockmap[back / size][back % size] = val;
}

template <typename T>
void Deque<T>::pop_front(){
  //Checks if the front has reached the end of the block.
  if(front == size - 1){
    delete[] blockmap[0];

    //Shifts all blocks one position forward.
    for(int i = 0; i < capacity - 1; i++){
      blockmap[i] = blockmap[i + 1];
    }
    
    capacity--;
    front = 0;
    back = size*capacity;
  }
  else
    //If there's space, it increments.
    front++;
}

template <typename T>
void Deque<T>::pop_back(){
  //Checks if the back index points at the last element.
  if (back % size == 0) {
    delete[] blockmap[capacity - 1];

    //Decreases capacity and makes the proper adjustments to front and back.
    capacity--;
    back = (size * capacity) - 1;
    front = back - 1;
  }
  else 
   --back;
}

template <typename T>
T& Deque<T>::Front(){
  return blockmap[0][front];
}

template <typename T>
T& Deque<T>::Back(){
  return blockmap[capacity - 1][back % size];
}

template <typename T>
bool Deque<T>::empty() const {
  if(capacity == 0 || front == back){
    return true;
  }
  else
    return false;
}

template <typename T>
int Deque<T>::blocksize() const {
  if(empty()){
    return 0;
  }

  if(front <= back){
    return back - front + 1;
  }
  else
    return (capacity * size - front + back + 1) & (size * capacity);
}
template <typename T>
T& Deque<T>::operator[](int val){
  //Out of bounds check.
  if(val >= blocksize() || val < 0){
    throw;
  }
  //Calculates index.
  int index = (front + val)%(size*capacity);

  //Returns the requested index.
  return blockmap[index / size][index % size];
}

  
  

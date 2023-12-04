/**
 * @file main.cpp
 * @author Jesse Warren
 * @date 2023-12-04
 * @brief Holds the main.
 * 
 * Holds the main function and the user interface which uses the deque.h and .cpp files.
 */

#include "deque.h"
#include "deque.cpp"
#include <iostream>

using namespace std;

int main() {

  Deque<int> deque;

  cout << "Do you wish to do the automated 1000 integer test? (y or n): ";
  char answer; cin >> answer; cout << endl;

  if(answer == 'y'){

    for(int i = 0; i < 1000; i++){
      deque.push_back(i);
    }

    cout << "Here is the contents of the deque:";

    for(int i = 0; i < deque.blocksize(); i++){
      cout << deque[i] << " ";
    }

    cout << deque.blocksize() << endl;
  } 
  else if(answer == 'n'){

    cout << "How many numbers do you wish to add?:";
    int size; cin >> size; cout << endl;

    int numbers[size];
    
    if(size <= 0){
      cout << "You must pick a number greater than 0." << endl;
      return 0;
    }

    for(int x = 0; x < size; x++){
      cout << "Enter a number: ";
      cin >> numbers[x]; cout << endl;
    }

    for(int y = 0; y < size; y++){
      deque.push_back(numbers[y]);
    }

    int choice;
    while(choice != 7){
    cout << "\nHere is the output. From here, choose an operation you wish to preform." << endl
	 << "1. Pop front" << endl
	 << "2. Pop back" << endl
	 << "3. Access the front" << endl
	 << "4. Access the back" << endl
	 << "5. Check an index" << endl
	 << "6. Print" << endl
	 << "7. Quit the program" << endl
	 << "Chose one of the following: ";
    cin >> choice;

    if(choice == 1){
      deque.pop_front();
      cout << "Front deleted." << endl;
    }
    else if(choice == 2){
      deque.pop_back();
      cout << "Back deleted." << endl;
    }
    else if(choice == 3){
      cout << "Front element: " << deque.Front() << endl;
    }
    else if(choice == 4){
      cout << "Back element: " << deque.Back() << endl;
    }
    else if(choice == 5){
      cout << "Enter a position in the deque: ";
      int pos; cin >> pos;
      if(pos < size){
	cout << "Element at positon " << pos << ": " << deque[pos] << endl;
      }
      else
	break;
    }
    else if(choice == 6){
      for(int y = 0; y < deque.blocksize(); y++){
	cout << " " << deque[y];
      }
      cout << endl;
    }
    else if(choice == 7){
      break;
    }
    }
  }
}

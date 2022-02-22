// Code by: Myles Stelling
// Created: 3/14/2021
// Last Edited: 2/22/2022
// Function: Application file for bubble sort function demonstration.
// Outputs the original unsorted vector of values, followed by the values in 
// acsendingand then descending order.

#include <iostream>

#include <vector>

#include "Sorting.h"

using namespace std;

// auto print_vector = [](auto& vector) { //commented out because it wasnt
//    for (auto element : vector) {       //working properly
//      cout << element << endl;
//    }
//  }

int main() {
  // Creating numbers vector and passing it its values
  std::vector<int> numbers(10);  
  numbers = {11, 4, 1, 8, 3, 3, 7, 0, 9, 5};  

  bool ascending = 1;   // Declaring boolean variables for ascending or
                        // descending
  bool descending = 0;  

  auto ascend = Bubble(numbers, ascending);    // Getting ascending/descending
  auto descend = Bubble(numbers, descending);  // vector results

  int i;

  // Printing the text and vectors involved in the sort(original, ascending &
  // descending)
  cout << "Original vector ..." << endl;
  for (i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << endl;
  }
  cout << "Sorted vector (ascending) ..." << endl;
  for (i = 0; i < numbers.size(); i++) {
    cout << ascend[i] << endl;
  }
  cout << "Sorted vector (descending) ..." << endl;
  for (i = 0; i < numbers.size(); i++) {
    cout << descend[i] << endl;
  }

  return 0;
}

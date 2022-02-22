// Code by: Myles Stelling
// Created: 3/14/2021
// Last Edited: 2/22/2022
// Function: Houses the logic for a 10 integer bubble sort which sorts the
// values in the original vector ascending of descending order

#include <vector>

// Declaring template typename
template <typename T>

// Declaring function Bubble which will sort the given vector into ascending
// and descending order
std::vector<T> Bubble(std::vector<T> numbers, bool ascending) {
  int temp_var;

  bool swapped = 1;  // Declaring boolean variable which signals whether numbers
                     // have been swapped or not

  // Using a while loop to continue through iterations until there are no more
  // numbers being swapped (when swapped = 0)
  while (swapped) {
    swapped = 0;
    // For loop to cycle through the values of the vector
    for (int i = 0; i < numbers.size() - 1; i++) {
      // If statement to create the ascending order of values
      if (numbers[i] > numbers[i + 1] && ascending) {  // Logic that determines
        temp_var = numbers[i];                         // whether or not to swap
        numbers[i] = numbers[i + 1];                   //(just the opposite for
        numbers[i + 1] = temp_var;                     // descending)
        swapped = 1;
        // Else if statement to create the descending order of values
      } else if (numbers[i] < numbers[i + 1] && !ascending) {  // Uses else if
        temp_var = numbers[i];        // Basic number swap     // if ascending
        numbers[i] = numbers[i + 1];  // using a temporary     // isnt true
        numbers[i + 1] = temp_var;    // variable
        swapped = 1;
      }
    }
  }
  return numbers;  // Returns the newly ascending or descending vector
}

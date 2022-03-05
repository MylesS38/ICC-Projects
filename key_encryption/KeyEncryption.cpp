/** Implementation file for key encryption
 *
 *  \file imgs/ipcv/key_encryption/KeyEncryption.cpp
 *  \author Carl Salvaggio, Ph.D. (salvaggio@cis.rit.edu)
 *  \co-author Myles Stelling (mcs2868@g.rit.edu)
 *  \date created 10 January 2020
 *  \date edited 5 March 2022
 */

#include "imgs/ipcv/key_encryption/KeyEncryption.h"

namespace ipcv {

// Encrypting function
std::string Encrypt(const std::string& key, const std::string& str) {
  std::string encrypted_str;
  encrypted_str.resize(str.size());

  // Declaring variables for the characters of the encrypted, key, and original
  // strings respectively
  int ecode;
  int kcode;
  int scode;

  // Logic variable that will be used in both for loops
  size_t i;

  // Counter variable that will increase by one with every iteration in the
  // key for loop
  size_t counter = 0;

  // Declaring the string for the repeated key (result of the key for loop)
  std::string repeat_key;

  repeat_key.resize(str.size());

  // For loop to loop the key string as the key will be less characters than the
  // original string
  for (i = 0; i < str.size(); i++) {
    repeat_key.at(i) = key.at(counter);

    counter++;  // Increases the counter variable by 1 with each iteration

    // Logic that resets the counter back to zero when it reaches the size of
    // the key, resulting in the characters looping over and over
    if (counter == key.size()) {
      counter = 0;
    }
  }

  // For loop that applies the encryption equation to each variable of the
  // original string
  for (i = 0; i < str.size(); i++) {
    scode = str.at(i);

    kcode = repeat_key.at(i);

    ecode = ((scode - 32) + (kcode - 32)) % 95 + 32;

    // Sets each character of ecode = to each character of the encrypted string
    // at i
    encrypted_str.at(i) = ecode;
  }

  return encrypted_str;  // Returns encrypted string
}

// Decrypting fucntion
std::string Decrypt(const std::string& key, const std::string& encrypted_str) {
  std::string decrypted_str;
  decrypted_str.resize(encrypted_str.size());

  // Declaring same variables as encrypt function except with a decrypt this
  // time as well as a determinate variable to be used in the decryption process
  int ecode;
  int dcode;
  int kcode;
  int determinate;

  // Logic variable that will be used in both loops
  size_t i;

  // Same key for loop and variables as above in encryption function
  size_t counter = 0;

  std::string repeat_key;

  repeat_key.resize(encrypted_str.size());

  for (i = 0; i < encrypted_str.size(); i++) {
    repeat_key.at(i) = key.at(counter);

    counter++;

    if (counter == key.size()) {
      counter = 0;
    }
  }

  // For loop that applies the decryption equation to each variable of the
  // encrypted string
  for (i = 0; i < encrypted_str.size(); i++) {
    ecode = encrypted_str.at(i);

    kcode = repeat_key.at(i);

    // Determinate for whether or not the inside of the equation is positive
    // or neagative
    determinate = (ecode - 32) - (kcode - 32);

    // Logic tree to determine which equation to use for decryption based on
    // whether the determinate (inside part fo the equation) is a negative
    // number or not
    if (determinate < 0) {
      dcode = ((ecode - 32) - (kcode - 32)) + 95 + 32;

    } else {
      dcode = ((ecode - 32) - (kcode - 32)) + 32;
    }

    // Sets each character of dcode = to each character of the decrypted string
    // at i
    decrypted_str.at(i) = dcode;
  }

  return decrypted_str;  // Returns decrypted string (should be same as
                         // original)
}
}

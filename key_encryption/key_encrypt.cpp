// Code by: Myles Stelling & Carl Salvaggio
// Created: 2 April 2021
// Last edited: 5 March 2022
// Function: Application file for key encryption app that intakes a hardcoded
// original string and key, encodes the string, then decodes it and shows the
// output of those two strings along with the original string and key.

#include <iostream>
#include <string>

#include "imgs/ipcv/key_encryption/KeyEncryption.h"

using namespace std;

int main() {
  // Various pairs of keys and phrases used to test function
  // string key = "buffalo";
  // string str = "This is a test of the key encryption system";
  // string key = "imgs";
  // string str = "Hello World!!!";
  string key = "Salvaggio";
  string str = " !\"#$%&'()*+,-./"
               "0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`"
               "abcdefghijklmnopqrstuvwxyz{|}~";

  // Encrypting then decrypting the input string using the key
  auto encrypted_str = ipcv::Encrypt(key, str);
  auto decrypted_str = ipcv::Decrypt(key, encrypted_str);

  // Printing key, original string, encypted string, and decrypted string
  cout << "Encryption Key:   " << endl << key << endl;
  cout << endl;
  cout << "Original String:  " << endl << str << endl;
  cout << endl;
  cout << "Encrypted String: " << endl << encrypted_str << endl;
  cout << endl;
  cout << "Decrypted String: " << endl << decrypted_str << endl;
  cout << endl;
}

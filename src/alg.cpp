// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  int capToLow = 'a' - 'A';
  std::string word = "";
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char ch = file.get();
    if (ch >= 'A' && ch <= 'Z')
      ch = capToLow;
    bool inWord = false;
    if (ch >= 'a' && ch <= 'z' && inWord == false) {
      inWord = true;
      word += ch;
    } else if (ch >= 'a' && ch <= 'z' && inWord == true) {
      word += ch;
    } else if (!(ch >= 'a' && ch <= 'z') && inWord == true) {
      inWord = false;
      tree.add(word);
      word = "";
    }
  }
  file.close();
  return tree;
}

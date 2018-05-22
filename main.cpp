#include <iostream>

#include "member.h"

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

void displayInstructions() {
  std::cout << "Welcome to Member Manager!\n"
  "Choose a number from the following:\n"
  "1. Add Member\n"
  "2. Remove Member\n"
  "3. View Member Info\n"
  "4. Edit Member Info\n"
  "5. In/Out Menu\n"
  "6. Quit\n";
}

bool inputAndExecute() {
  clearScreen();
  displayInstructions();
  std::string input;
  std::cout << "> ";
  std::cin >> input;
  if (!input.compare("1")) {
    clearScreen();
    std::cout << "Add Member" << std::endl;
    addMember();
  } else if (!input.compare("2")) {
    std::cout << "Option 2" << std::endl;
  } else if (!input.compare("3")) {
    clearScreen();
    std::cout << "View Member Info" << std::endl;
    viewMemberInfo();
  } else if (!input.compare("4")) {
    clearScreen();
    std::cout << "Edit Member Info" << std::endl;
    editMemberInfo();
  } else if (!input.compare("5")) {
    std::cout << "Option 5" << std::endl;
  } else if (!input.compare("6")) { 
    std::cout << "Quitting..." << std::endl;
    return false;
  } else {
    std::cout << "Option Unknown" << std::endl;
  }
  return true;
}



int main() {
  while(inputAndExecute());
  return 0;
}
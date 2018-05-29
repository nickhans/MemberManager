#include <iostream>

#include "member.h"

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

void displayInstructions() {
  std::cout << "Welcome to Member Manager!" << std::endl;
  std::cout << "Main Menu" << std::endl;
  std::cout << "Choose a number from the following:\n"
  "1. Add Member\n"
  "2. Remove Member\n"
  "3. View Member Info\n"
  "4. Edit Member Info\n"
  "5. In/Out Menu\n"
  "0. Quit\n";
}

void displayInOutInstructions() {
  std::cout << "Choose a number from the following:\n"
  "1. Set Individual Member In/Out Status\n"
  "2. Set All Members In\n"
  "3. Set All Members Out\n"
  "4. View In Members\n"
  "5. View Out Members\n"
  "0. Return to Main Menu\n";
}

bool inOutMenu() {
  displayInOutInstructions();
  std::string input;
  std::cout << "> ";
  std::cin >> input;
  if (!input.compare("1")) {
    clearScreen();
    std::cout << "Set Member In/Out Status" << std::endl;

    clearScreen();
  } else if (!input.compare("2")) {
    clearScreen();
    std::cout << "All Members In" << std::endl;
    clearScreen();
  } else if (!input.compare("3")) {
    clearScreen();
    std::cout << "All Members Out" << std::endl;
    clearScreen();
  } else if (!input.compare("4")) {
    clearScreen();
    std::cout << "In Members" << std::endl;
    clearScreen();
  } else if (!input.compare("5")) {
    clearScreen();
    std::cout << "Out Members" << std::endl;
    clearScreen();
  } else if (!input.compare("0")) {
    std::cout << "Returning to main menu..." << std::endl;
    return false;
  } else {
    std::cout << "\nInvalid Option\n" << std::endl;
  }
  return true;
}

bool inputAndExecute() {
  displayInstructions();
  std::string input;
  std::cout << "> ";
  std::cin >> input;
  if (!input.compare("1")) {
    clearScreen();
    std::cout << "Add Member" << std::endl;
    addMember();
    clearScreen();
  } else if (!input.compare("2")) {
    clearScreen();
    std::cout << "Remove Member" << std::endl;
    removeMember();
    clearScreen();
  } else if (!input.compare("3")) {
    clearScreen();
    std::cout << "View Member Info" << std::endl;
    viewMemberInfo();
    clearScreen();
  } else if (!input.compare("4")) {
    clearScreen();
    std::cout << "Edit Member Info" << std::endl;
    editMemberInfo();
    clearScreen();
  } else if (!input.compare("5")) {
    clearScreen();
    std::cout << "In/Out Menu" << std::endl;
    while(inOutMenu());
    clearScreen();
  } else if (!input.compare("0")) { 
    std::cout << "Quitting..." << std::endl;
    return false;
  } else {
    std::cout << "\nInvalid Option\n" << std::endl;
  }
  return true;
}



int main() {
  clearScreen();
  while(inputAndExecute());
  return 0;
}
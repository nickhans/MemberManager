#include <iostream>

#include "member.h"

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

void displayInstructions() {
  std::cout << "Welcome to Member Manager!\n" << std::endl;
  std::cout << "Main Menu" << std::endl;
  std::cout << "Choose a number from the following:\n"
  "1. Add Member\n"
  "2. Remove Member\n"
  "3. View Member Info\n"
  "4. Edit Member Info\n"
  "5. In/Out Menu\n"
  "6. Save\n"
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
    setInOut();
    clearScreen();
  } else if (!input.compare("2")) {
    clearScreen();
    // std::cout << "All Members In" << std::endl;
    setAllInOut(true);
    
  } else if (!input.compare("3")) {
    clearScreen();
    // std::cout << "All Members Out" << std::endl;
    setAllInOut(false);
    
  } else if (!input.compare("4")) {
    clearScreen();
    // std::cout << "In Members" << std::endl;
    viewInOut(true);
    
  } else if (!input.compare("5")) {
    clearScreen();
    // std::cout << "Out Members" << std::endl;
    viewInOut(false);
   
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
  } else if (!input.compare("6")) {
    clearScreen();
    std::cout << "Saving..." << std::endl;
    save();
  } else if (!input.compare("0")) { 
    std::cout << "Saving and quitting..." << std::endl;
    save();
    return false;
  } else {
    std::cout << "\nInvalid Option\n" << std::endl;
  }
  return true;
}

int main() {
  clearScreen();
  load();
  while(inputAndExecute());
  return 0;
}

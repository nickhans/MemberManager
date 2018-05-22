#include "member.h"

#include <iostream>

Member newMember;
std::vector<Member> members;

Member::Member() {
  Member::setBusiness("");
  Member::setName("");
  Member::setPhoneNumber("");
  Member::setEmail("");
  Member::setMembershipPlan("");
  Member::setInOutStatus(false);
}

Member::Member(std::string business, std::string membershipPlan) {
  Member::setBusiness(business);
  Member::setName(NULL);
  Member::setPhoneNumber(NULL);
  Member::setEmail(NULL);
  Member::setMembershipPlan(membershipPlan);
  Member::setInOutStatus(false);
}

Member::Member(std::string name, std::string business, std::string phoneNumber, std::string email, std::string membershipPlan, bool isIn) {
  Member::setBusiness(business);
  Member::setName(name);
  Member::setPhoneNumber(phoneNumber);
  Member::setEmail(email);
  Member::setMembershipPlan(membershipPlan);
  Member::setInOutStatus(isIn);
}

// set functions for member class
void Member::setName(std::string name) { Member::name = name; }
void Member::setBusiness(std::string business) { Member::business = business; }
void Member::setPhoneNumber(std::string phoneNumber) { Member::phoneNumber = phoneNumber; }
void Member::setEmail(std::string email) { Member::email = email; }
void Member::setMembershipPlan(std::string membershipPlan) { Member::membershipPlan = membershipPlan; }
void Member::setInOutStatus(bool isIn) { Member::isIn = isIn; }

// get functions for member class
std::string Member::getName() { return Member::name; }
std::string Member::getBusiness() { return Member::business; }
std::string Member::getPhoneNumber() { return Member::phoneNumber; }
std::string Member::getEmail() { return Member::email; }
std::string Member::getMembershipPlan() { return Member::membershipPlan; }
bool Member::getInOutStatus() { return Member::isIn; }

void addMember() {
  std::string business, name, phoneNumber, email, membershipPlan, response;
  bool isIn;
  bool validResponse = false;
  std::cout << "Business: ";
  std::cin >> business;
  std::cout << "Member Name: ";
  std::cin >> name;
  std::cout << "Phone Number: ";
  std::cin >> phoneNumber;
  std::cout << "Email: ";
  std::cin >> email;
  std::cout << "Membership Plan: ";
  std::cin >> membershipPlan;
  while (!validResponse) {
    std::cout << "In the office currently? (y for yes, n for no): ";
    std::cin >> response;
    if (!response.compare("y")) {
      isIn = true;
      validResponse = true;
    } else if (!response.compare("n")) {
      isIn = false;
      validResponse = true;
    } else {
      validResponse = false;
    }
  }
  newMember.setBusiness(business);
  newMember.setName(name);
  newMember.setPhoneNumber(phoneNumber);
  newMember.setEmail(email);
  newMember.setMembershipPlan(membershipPlan);
  newMember.setInOutStatus(isIn);
  members.push_back(newMember);
}

void viewMemberInfo() {
  bool finished = false;
  while (!finished) {
    std::cout << "Choose the Member you would like to view" << std::endl;
    for (int i = 0; i < members.size(); i++) {
      std::cout << i + 1<< ". " << members[i].getBusiness() << std::endl;
    }
    std::cout << "0. Return to main menu" << std::endl;
    int response;
    bool validResponse = false;
    // std::cout << "Vector Size: " << members.size() << std::endl;
    while (!validResponse) {
      std::cout << "> ";
      std::cin >> response;
      if (response <= members.size() && response > 0) {
        validResponse = true;
      } else if (response == 0) {
        finished = true;
        validResponse = true;
        return;
      } else {
        validResponse = false;
        std::cout << "Please enter a valid response" << std::endl;
      }
    }
    int index = response - 1;
    std::cout << std::endl;
    std::cout << "Business: " << members[index].getBusiness() << std::endl;
    std::cout << "Member Name: " << members[index].getName() << std::endl;
    std::cout << "Phone Number: " << members[index].getPhoneNumber() << std::endl;
    std::cout << "Email: " << members[index].getEmail() << std::endl;
    std::cout << "Membership Plan: " << members[index].getMembershipPlan() << std::endl;
    std::cout << "In/Out Status: " << members[index].getInOutStatus() << std::endl;
    std::cout << std::endl;
    std::cout << "To view another members info please press 1, to return to the main menu press 0" << std::endl;
    validResponse = false;
    while (!validResponse) {
      std::cout << "> ";
      std::cin >> response;
      if (response == 0) {
        finished = true;
        validResponse = true;
      } else if (response == 1) {
        finished = false;
        validResponse = true;
      } else {
        validResponse = false;
      }
    }
  }
}

void editMemberInfo() {
  bool finished = false;
  while (!finished) {
    std::cout << "Choose the Member you would like to edit" << std::endl;
    for (int i = 0; i < members.size(); i++) {
      std::cout << i + 1<< ". " << members[i].getBusiness() << std::endl;
    }
    std::cout << "0. Return to main menu" << std::endl;
    int response;
    bool validResponse = false;
    // std::cout << "Vector Size: " << members.size() << std::endl;
    while (!validResponse) {
      std::cout << "> ";
      std::cin >> response;
      if (response <= members.size() && response > 0) {
        validResponse = true;
      } else if (response == 0) {
        finished = true;
        validResponse = true;
        return;
      } else {
        validResponse = false;
        std::cout << "Please enter a valid response" << std::endl;
      }
    }
    bool finishedMember = false;
    while (!finishedMember) {
      int index = response - 1;
      std::cout << std::endl;
      std::cout << "Choose what you would like to edit" << std::endl;
      std::cout << "1. Business" << std::endl;
      std::cout << "2. Member Name" << std::endl;
      std::cout << "3. Phone Number" << std::endl;
      std::cout << "4. Email" << std::endl;
      std::cout << "5. Membership Plan" << std::endl;
      std::cout << "0. Choose different member" << std::endl;
      std::cout << std::endl;
      validResponse = false;
      while (!validResponse) {
        std::cout << "> ";
        std::cin >> response;
        if (response <= members.size() && response > 0) {
          validResponse = true;
          std::string input;
          switch(response) {
            case 1 :
              std::cout << "Input new business: ";
              std::cin >> input;
              members[index].setBusiness(input);
              break;
            case 2 :
              std::cout << "Input new member name: ";
              std::cin >> input;
              members[index].setName(input);
              break;
            case 3 :
              std::cout << "Input new phone number: ";
              std::cin >> input;
              members[index].setPhoneNumber(input);
              break;
            case 4 :
              std::cout << "Input new email: ";
              std::cin >> input;
              members[index].setEmail(input);
              break;
            case 5 :
              std::cout << "Input new membership plan: ";
              std::cin >> input;
              members[index].setMembershipPlan(input);
              break;
          }
        } else if (response == 0) {
          finishedMember = true;
          validResponse = true;
        } else {
          validResponse = false;
        }
      }
      if (response != 0) {
        std::cout << "Edit Complete! Press 1 to edit more or 0 to return to main menu" << std::endl;
        validResponse = false;
      } else {
        validResponse = true;
      }
      while (!validResponse) {
        std::cout << "> ";
        std::cin >> response;
        if (response == 0) {
          finished = true;
          validResponse = true;
          return;
        } else if (response == 1) {
          finished = false;
          validResponse = true;
        } else {
          validResponse = false;
        }
      }
    }
  }
}
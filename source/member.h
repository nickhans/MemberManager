#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <vector>

class Member {
  private:
    
    // member info
    std::string name;
    std::string business;
    std::string phoneNumber;
    std::string email;
    std::string membershipPlan;
    // in/out status
    bool isIn;
  
  public:
    // constructors
    Member();
    Member(std::string name, std::string business, std::string phoneNumber, std::string email, std::string membership, bool isIn);

    // set/get functions
    void setName(std::string name);
    std::string getName();

    void setBusiness(std::string business);
    std::string getBusiness();

    void setPhoneNumber(std::string phoneNumber);
    std::string getPhoneNumber();

    void setEmail(std::string email);
    std::string getEmail();

    void setMembershipPlan(std::string membership);
    std::string getMembershipPlan();

    void setInOutStatus(bool isIn);
    bool getInOutStatus();
};

// save/load functions
extern void save();
extern void load();

// in/out functions
extern void setInOut();
extern void viewInOut(bool in);
extern void setAllInOut(bool in);

// member functions
extern void addMember();
extern void viewMemberInfo();
extern void editMemberInfo();
extern void removeMember();

#endif

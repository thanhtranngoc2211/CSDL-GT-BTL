#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "LinkedIn.h"
using namespace std;

void register_user(vector<Node>a, LinkedIn g){
    Node man;
    g.addNode();
    cout << "Your name: "; std::getline(std::cin,man.name);
    cout << "Date of birth: "; std::getline(std::cin,man.dob);
    cout << "Your email: "; std::getline(std::cin,man.email);
    cout << "Your field: "; std::getline(std::cin,man.field);
    cout << "Your number: "; std::getline(std::cin,man.number);
    cout << "Your work: "; std::getline(std::cin,man.work);
    man.id = a.size();
    a.push_back(man);
    cout << "Register successfully";
}


#endif

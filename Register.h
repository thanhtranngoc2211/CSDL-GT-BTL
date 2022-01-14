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
    cout << "Ten cua ban: "; std::getline(std::cin,man.name);
    cout << "Ngay thang nam sinh: "; std::getline(std::cin,man.dob);
    cout << "Email: "; std::getline(std::cin,man.email);
    cout << "Chuyen nganh: "; std::getline(std::cin,man.field);
    cout << "So dien thoai: "; std::getline(std::cin,man.number);
    cout << "Noi lam viec: "; std::getline(std::cin,man.work);
    man.id = a.size();
    a.push_back(man);
    cout << "Register successfully";
}

#endif

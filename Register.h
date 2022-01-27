#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "LinkedIn.h"
#include <fstream>
#include <tuple>
using namespace std;

std::tuple<vector<Node>, LinkedIn>register_user(vector<Node> a, LinkedIn g){
    Node man;
    g.addNode();
    fstream outfile;
    outfile.open("data.txt", ios::out | ios::app);
    cout << "Your name: "; std::getline(std::cin,man.name);
    outfile << man.name << endl;
    cout << "Date of birth: "; std::getline(std::cin,man.dob);
    outfile << man.dob << endl;
    cout << "Your email: "; std::getline(std::cin,man.email);
    outfile << man.email << endl;
    cout << "Your field: "; std::getline(std::cin,man.field);
    outfile << man.field << endl;
    cout << "Your number: "; std::getline(std::cin,man.number);
    outfile << man.number << endl;
    cout << "Your work: "; std::getline(std::cin,man.work);
    outfile << man.work << endl;
    outfile.close();
    man.id = a.size();
    a.push_back(man);
    cout << "Register successfully";
    return std::make_tuple(a,g);
}


#endif

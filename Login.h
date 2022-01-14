#ifndef LOGIN_H
#define LOGIN_H

#include<iostream>
#include<string>
#include<vector>
#include"Node.h"

using namespace std;

int SearchEmail(std::string email, std::vector<Node> a){
    for (int i = 0; i < a.size(); i++){
        if (email == a.at(i).email){
            return i;
        }
    }
    return -1;
}

void showInfo(std::vector<Node> a, int id){
    cout << "Your info" <<endl;
    cout << "----------------------------------" << endl;
    cout << "Name: " << a.at(id).name << endl;
    cout << "Date of Birth: " << a.at(id).dob << endl;
    cout << "Email: " << a.at(id).email << endl;
    cout << "Number: " << a.at(id).number << endl;
    cout << "Field: " << a.at(id).field << endl;
    cout << "Work: " << a.at(id).work << endl;
}


#endif

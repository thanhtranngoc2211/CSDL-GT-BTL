#ifndef LINKEDIN_H
#define LINKEDIN_H

#include <vector>
#include "Node.h"
#include "Weight.h"
#include <string>
#include <iostream>

using namespace std;

class LinkedIn {
  public:
    std::vector<std::vector<Weight>> adjMatrix;
    int size;
    Node a;

  LinkedIn(int asize=0){
    adjMatrix.resize(asize);
    for (int count = 0; count < asize; count++){
      adjMatrix[count].resize(asize);
    }
    size = asize;
  }

  //Initialize the matrix to -1
  void _init_(){
    if (size != 0){
      for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
          adjMatrix.at(i).at(j) = {-1,-1};
        }
      }
    }
  }

  // Add nodes
  void addNode(){
    size = size + 1;
    adjMatrix.resize(size);
    // Initialize new adjMatrix
    for (int count = 0; count < size; count++){
      adjMatrix[count].resize(size);
    }
    for (int i = 0; i < size - 1; i++){
      adjMatrix[i][size-1] = {-1,-1};
    }
    for (int i = 0; i < size; i++){
      adjMatrix[size-1][i] = {-1,-1};
    }
  }

  // Add edges
  void addEdge(std::string i, std::string j, std::vector<Node> a, Weight w) {
    int node_1 = -1, node_2 = -1;
    string name_1, name_2;
    // Not add if input same node
    if (i == j){
      printf("Can't execute. Error: Same node\n");
      return;
    }
    // Check id
    for (int ite = 0; ite < a.size(); ite++){
      if ((i == a.at(ite).name || j == a.at(ite).name) && node_1 == -1){
        node_1 = a.at(ite).id;
        name_1 = a.at(ite).name;
      }
      else if (i == a.at(ite).name || j == a.at(ite).name)
        node_2 = a.at(ite).id;
        name_2 = a.at(ite).name;
    }
    // Check successfully, add
    if (node_1 != -1 && node_2 != -1){
      adjMatrix.at(node_1).at(node_2) = w;
      adjMatrix.at(node_2).at(node_1) = w;
      cout << "Successfully add relation between" + name_1 + "and" + name_2<<endl;
    }
    else { 
      printf("Error");
    }
  }

  // Remove edges
  void removeEdge(std::string i, std::string j, std::vector<Node>a) {
    string name_1, name_2;
    int node_1 = -1, node_2 = -1;
    for (int ite = 0; ite < a.size(); ite++){
      if (i == a[ite].name && node_1 == -1){
        node_1 = a[ite].id;
        name_1 = a.at(ite).name;
      }
      else
        node_2 = a[ite].id;
        name_2 = a.at(ite).name;
    }
    if (node_1 != -1 && node_2 != -1){
      adjMatrix.at(node_1).at(node_2) = {-1,-1};
      adjMatrix.at(node_2).at(node_1) = {-1,-1};
      cout << "Successfully delete relation between" + name_1 + "and" + name_2;
    }
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < size; i++) {
      std::cout << i << " : ";
      for (int j = 0; j < size; j++)
        std::cout << "{" << adjMatrix[i][j].years << "," << adjMatrix[i][j].papers <<"}" << " ";
      std::cout << "\n";
    }
  }

  vector<int> dfs(std::vector<Node> a, int node_id, std::vector<bool> isChecked, vector<int> stack){
    isChecked.at(node_id) = true;
      for (int ite = 0; ite < a.size(); ite++){
        if (stack.size() > a.size() - 2)
          break;
        if (adjMatrix.at(node_id).at(ite).years != -1 && !isChecked.at(a[ite].id)){
          isChecked.at(a[ite].id) = true;
          stack.push_back(a[ite].id);
          stack = dfs(a, a[ite].id, isChecked, stack);
        }
    }
    return stack;
  }

  void searchFellow(std::vector<Node> a, std::string nameSearch){
    std::vector<int> stack;
    std::vector<bool> isChecked;
    std::vector<string> fellows;
    isChecked.assign(a.size(), false);
    int node_id;
    bool found = false;
    // nameSearch id
    for (int ite = 0; ite < a.size(); ite++){
      if (a[ite].name == nameSearch){
        node_id = a[ite].id;
        found = true;
        break;
      }
    }
    if (found == true){
      stack = dfs(a, node_id, isChecked, stack);
      // Search each node from stack
      for (int ite = 0; ite < stack.size(); ite++){
        if (a[node_id].work == a[stack.at(ite)].work){
          fellows.push_back(a[stack.at(ite)].name);
        }
      }
      if (fellows.size() == 0)
        cout << "No fellow found" << endl;
      else {
        cout << "Fellows: ";
        for (int ite =  0; ite < fellows.size(); ite++){
          cout << fellows.at(ite) << " ";
        }
        cout << endl;
      }
    }
    else {
      printf("Not found name");
    }
  }

  void SearchInfo(std::vector<Node> a, std::string nameSearch){
    bool exist = false;
    for (int i = 0; i < a.size(); i++){
      if (nameSearch == a[i].name){
        cout << "Thong tin cua " << nameSearch << ":" << endl;
        cout << "- DOB: " + a[i].dob << endl;
        cout << "- Email: " + a[i].email <<endl;
        cout << "- So dien thoai: " + a[i].number << endl;
        cout << "- Field: " + a[i].field << endl;
        cout << "- Noi lam viec: " + a[i].work << endl;
        cout << "- " ; searchFellow(a,nameSearch);
        exist = true;
        break;
      }
      if(nameSearch == a[i].work){
        cout << "People work at here: ";
        for (int ite = i; ite < a.size(); ite++){
          if (nameSearch == a[ite].work)
           cout << a[ite].name + " ";
        }
        cout << endl;
        exist = true;
        break;
      }
    }
    if(!exist)
      cout << "Khong ton tai" <<endl;
  }

  void relationship(std::vector<Node> a, std::string i, std::string j){
    int node_1 = -1, node_2 = -1;
    // Not add if input same node
    if (i == j){
      printf("Can't execute. Error: Same node\n");
      return;
    }
    // Search id
    for (int ite = 0; ite < a.size(); ite++){
      if ((i == a[ite].name || j == a[ite].name) && node_1 == -1){
        node_1 = a[ite].id;
      }
      else if (i == a[ite].name || j == a[ite].name)
        node_2 = a[ite].id;
    }
    // Found ids
    if(node_1 != -1 && node_2 != -1){
      if(adjMatrix[node_1][node_2].years == -1){
        cout << i << " va " << j << ":" <<" Khong quen nhau"<< endl;
      }
      else{
        cout << i << " va " << j << ":" << endl;
        cout << "- So nam lam viec: "<< adjMatrix[node_1][node_2].years <<" nam" <<endl;
        cout << "- So bai bao thuc hien cung nhau: " << adjMatrix[node_1][node_2].papers <<" bai"<<endl ;
      }
    }
    else
      cout << "Not found human\n";
  }
};

#endif

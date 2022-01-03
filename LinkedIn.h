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
    // Not add if input same node
    if (i == j){
      printf("Can't execute. Error: Same node\n");
      return;
    }
    // Check id
    for (int ite = 0; ite < a.size(); ite++){
      if ((i == a[ite].name || j == a[ite].name) && node_1 == -1){
        node_1 = a[ite].id;
      }
      else if (i == a[ite].name || j == a[ite].name)
        node_2 = a[ite].id;
    }
    // Check successfully, add
    if (node_1 != -1 && node_2 != -1){
      adjMatrix.at(node_1).at(node_2) = w;
      adjMatrix.at(node_2).at(node_1) = w;
    }
    else { 
      printf("Error");
    }
  }

  // Remove edges
  void removeEdge(std::string i, std::string j, std::vector<Node>a) {
    int node_1 = -1, node_2 = -1;
    for (int ite = 0; ite < a.size(); ite++){
      if (i == a[ite].name && node_1 == -1){
        node_1 = a[ite].id;
      }
      else
        node_2 = a[ite].id;
    }
    if (node_1 != -1 && node_2 != -1){
      adjMatrix.at(node_1).at(node_2) = {-1,-1};
      adjMatrix.at(node_2).at(node_1) = {-1,-1};
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

  // Search fellow
  void searchFellow(std::vector<Node> a, std::string nameSearch){
    std::string work;
    std::vector<string> fellow;
    // Search work
    for (int i = 0; i < a.size(); i++){
      if (nameSearch == a[i].name){
        work = a[i].work;
        break;
      }
    }
    // If work together & nameSearch is not vector[i].name --> print out
    for (int i = 0; i < a.size(); i++){
      if (work == a[i].work && nameSearch != a[i].name){
        fellow.push_back(a[i].name);
      }
    }
    // No fellow found
    if (fellow.size() == 0){
      cout << "Not found any fellow\n";
    }
    else {
      cout << "Fellows: ";
      for (int i = 0; i < fellow.size(); i++){
        cout << fellow[i] + " ";
      }
      cout << endl;
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
    // Check id
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
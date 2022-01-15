#ifndef LINKEDIN_H
#define LINKEDIN_H

#include <vector>
#include "Node.h"
#include "Weight.h"
#include <string>
#include <iostream>
#include <tuple>

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

  tuple <vector<int>, vector<int>> bfs(std::vector<Node> a, int node_id, std::vector<bool> visited, vector<int> queue, vector<int> searchOrder){
    int next_node;
    visited.at(node_id) = true;
      for (int ite = 0; ite < a.size(); ite++){
        //if (queue.size() == a.size() - 1){
        //  break;
        //  return queue;
        //}
        if (adjMatrix.at(node_id).at(ite).years != -1 && !visited.at(a[ite].id)){
          visited.at(a[ite].id) = true;
          queue.push_back(a[ite].id);
        }
    }
    if (queue.size() == 0) 
      return make_tuple(queue, searchOrder);
    else {
      next_node = queue.at(0);
      searchOrder.push_back(next_node);
      queue.erase(queue.begin());
      tie(queue, searchOrder) = bfs(a, next_node, visited, queue, searchOrder);
    }
    return make_tuple(queue, searchOrder);
  }

  void searchFellow(std::vector<Node> a, std::string nameSearch){
    std::vector<int> queue;
    std::vector<bool> isChecked;
    vector<int> searchOrder;
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
      tie(queue, searchOrder) = bfs(a, node_id, isChecked, queue, searchOrder);
      for (int ite = 0; ite < searchOrder.size(); ite++) {
        cout << searchOrder.at(ite) << " ";
      }
      cout <<endl;
      // Search each node from queue
      for (int ite = 0; ite < searchOrder.size(); ite++){
        if (a.at(node_id).work == a.at(searchOrder.at(ite)).work){
          fellows.push_back(a.at(searchOrder.at(ite)).name);
        }
      }
      if (fellows.size() == 0)
        cout << "No fellow found" << endl;
      else {
        cout << "Fellows: ";
        for (int ite = 0; ite < fellows.size(); ite++){
          cout << fellows.at(ite) << " ";
        }
        cout << endl;
      }
    }
    else {
      printf("Not found name");
    }
  }

  std::vector<Node> SearchCompany(std::vector<Node> a, std::string nameSearch){
    std::vector<Node> companiers;
    for (int i = 0; i < a.size(); i++){
      if(nameSearch == a[i].work){
        cout << "People work at here: ";
        for (int ite = i; ite < a.size(); ite++){
          if (nameSearch == a[ite].work)
           cout << a.at(ite).name << "(" << a.at(ite).id << ")" << " ";
           companiers.push_back(a.at(ite));
        }
        cout << endl;
        return companiers;
      }
    }
    cout << "Khong ton tai" <<endl;
    return companiers;
  }

  void relationship(std::vector<Node> a,int id, std::string name){
    int nodeId = -1;
    // Search id
    for (int ite = 0; ite < a.size(); ite++){
      if (name == a[ite].name){
        nodeId = ite;
      }
    }
    // Found id
    if(nodeId != -1){
      if(adjMatrix[id][nodeId].years == -1){
        cout << "ban va " << a.at(nodeId).name << ":" <<" Khong quen nhau"<< endl;
      }
      else{
        cout << "ban va " << a.at(nodeId).name << ":" << endl;
        cout << "- So nam lam viec: "<< adjMatrix[id][nodeId].years <<" nam" <<endl;
        cout << "- So bai bao thuc hien cung nhau: " << adjMatrix[id][nodeId].papers <<" bai"<<endl ;
      }
    }
    else
      cout << "Not found human\n";
  }

  void showBrief(vector<Node> companiers, int id){
    for (int i = 0; i < companiers.size(); i++){
      if (id == companiers.at(i).id){
        cout << "Name: " << companiers.at(i).name << endl;
        cout << "Field: " << companiers.at(i).field << endl;
        cout << "Number: " << companiers.at(i).number << endl;
        return;
      }
    }
    cout << "Not found id" << endl;
  }
};

#endif

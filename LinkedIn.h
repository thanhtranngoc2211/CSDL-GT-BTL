#ifndef LINKEDIN_H
#define LINKEDIN_H

#include <vector>
#include "Node.h"
#include "Weight.h"
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

struct searchOrder{
  int id;
  int parent;
};


class LinkedIn {
  public:
    std::vector<std::vector<Weight>> adjMatrix;
    int size;
    std::vector<Node> a;

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
      cout << "Successfully add relation between" << " " << name_1 <<" " << "and" << " " << name_2 <<endl;
    }
    else { 
      printf("Error");
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

  // BFS
  tuple <vector<searchOrder>, vector<searchOrder>> bfs(std::vector<Node> a, int node_id, std::vector<bool> visited, vector<searchOrder> queue, vector<searchOrder> order){
    searchOrder next_node;
    searchOrder current_node;
    visited.at(node_id) = true;
      for (int ite = 0; ite < a.size(); ite++){
        //if (queue.size() == a.size() - 1){
        //  break;
        //  return queue;
        //}
        if (adjMatrix.at(node_id).at(ite).years != -1 && !visited.at(a[ite].id)){
          visited.at(a[ite].id) = true;
          current_node.id = a.at(ite).id;
          current_node.parent = node_id;
          queue.push_back(current_node);
        }
    }
    if (queue.size() == 0) 
      return make_tuple(queue, order);
    else {
      next_node = queue.at(0);
      order.push_back(next_node);
      queue.erase(queue.begin());
      tie(queue, order) = bfs(a, next_node.id, visited, queue, order);
    }
    return make_tuple(queue, order);
  }

  void searchFellow(std::vector<Node> a, std::string nameSearch){
    std::vector<searchOrder> queue;
    std::vector<bool> isChecked;
    vector<searchOrder> order;
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
      tie(queue, order) = bfs(a, node_id, isChecked, queue, order);
      // Search each node from queue
      for (int ite = 0; ite < order.size(); ite++){
        if (a.at(node_id).work == a.at(order.at(ite).id).work){
          fellows.push_back(a.at(order.at(ite).id).name);
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
    int node_id = -1;
    int order_id = -1;
    std::vector<searchOrder> queue;
    std::vector<bool> isChecked;
    isChecked.assign(a.size(), false);
    vector<searchOrder> order;
    // Search name
    tie(queue, order) = bfs(a, id, isChecked, queue, order);
    for (int ite = 0; ite < order.size(); ite++){
      cout << order.at(ite).parent << " ";
    }
    cout << endl;
    for (int ite = 0; ite < order.size(); ite++){
      if (name == a.at(order.at(ite).id).name){
        node_id = order.at(ite).id;
        order_id = ite;
        break;
      }
    }
    // Found id
    if(node_id != -1){
      if(adjMatrix[id][node_id].years == -1){
        cout << "You and " << a.at(node_id).name <<" don't know each other"<< endl;
        cout << "Mutual friend: " << a.at(order.at(order_id).parent).name << endl;
      }
      else{
        cout << "You and " << a.at(node_id).name << ":" << endl;
        cout << "- Years work: "<< adjMatrix[id][node_id].years <<" years" <<endl;
        cout << "- Papers collaborated: " << adjMatrix[id][node_id].papers <<" papers"<<endl ;
      }
    }
    else
      cout << "Haven't known each other\n";
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

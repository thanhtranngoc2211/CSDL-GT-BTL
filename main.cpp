//LinkedIn là một đồ thị mà mỗi node là một người với các thông tin định danh
//(ảnh, ngày tháng năm sinh, email, số điện thoại, chuyên môn, nơi làm việc),
//mỗi cạnh thể hiện hai người có quan hệ công việc với nhau trong học tập, trong công việc.
//Trọng số của cạnh thể hiện mức độ thân thiết trong công việc
//(số năm làm việc cùng nhau, số bài báo/công trình/dự án xuất bản / thực hiện cùng nhau)

//Định nghĩa và cài đặt cấu trúc đồ thị.
//
//Chèn một node vào trong đồ thị và xác định liên hệ với các node đã có trong đồ thị theo công ty mà họ đã từng làm việc với nhau
//
//Tìm những người từng làm việc ở một công ty nào đó
//
//Xác định mối liên hệ giữa hai người A và B trong mạng

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "LinkedIn.h"
#include "Login.h"
#include "Weight.h"
#include "Register.h"
#include "data.h"
using namespace std;

int main() {
  LinkedIn g;
  Node man;
  int id;
  bool found;
  std::vector<Node> companiers;
  std::string email;
  std::string name_1, name_2;
  std::string name;
  // Store mans
  std::vector<Node> a;
  Weight w;
  int control;
  bool open = true, logIn = true;

  // Load data
  cout << "-----------Fetching Data----------" <<endl;
  tie(g,a) = fetchData(g,a);

  while (open){
    cout << "-------------LinkedIn-------------" <<endl;
    cout << "1. Login"<<endl;
    cout << "2. Register" <<endl;
    cout << "3. Search company" <<endl;
    cout << "4. Show matrix" <<endl;
    cout << "0. ShutDown" <<endl;
    cout << "----------------------------------" <<endl;
    cin >> control;
    fflush(stdin);
    if (control == 1){
      logIn = true;
      cout << "--------------Your email--------------" <<endl;
      getline(std::cin,email);
      fflush(stdin);
      id = SearchEmail(email, a);
      if(SearchEmail(email, a) == -1){
        cout << "Not found user" << endl;
      }
      else {
        while (logIn) {
          cout << "1. Show infomation" << endl;
          cout << "2. Add relation" << endl;
          cout << "3. Show fellows" << endl;
          cout << "4. Search people" << endl;
          cout << ". Delete this user" <<endl;
          cout << "11. Log out" << endl;
          cin >> control;
          fflush(stdin);
          if (control == 1){
            showInfo(a, id);
          }
          if (control == 2){
            cout << "Nhap ten ban cua ban: " << endl;
            getline(std::cin,name);
            fflush(stdin);
            cout << "Nhap so nam lam viec cung nhau: " <<endl;
            cin >> w.years;
            fflush(stdin);
            cout << "Nhap so bai bao cung thuc hien: " <<endl;
            cin >>w.papers;
            fflush(stdin);
            g.addEdge(id, name, a, w);
          }
          if (control == 3){
            g.searchFellow(a, a.at(id).name);
          }
          if (control == 4){
            cout << "Nhap ten nguoi ban muon tim: " << endl;
            getline(std::cin,name);
            fflush(stdin);
            g.relationship(a, id, name);
          }
          if (control == 11){
            logIn = false;
          }
        }
      }
    }
    if(control == 2){
      register_user(a, g);
    }
    if(control == 3){
      cout << "Nhap ten cong ty: " <<endl;
      getline(std::cin,name);
      fflush(stdin);
      companiers = g.SearchCompany(a, name);
      if (companiers.size() != 0){
        cout << "Do you want to see someone's infomation?" <<endl;
        cout << "Type in his/her id in or Type 12 to get back" <<endl;
        cin >> control;
        while (control != 12) {
          g.showBrief(companiers, control);
          cout << "Type other id" <<endl;
          cout << "12. Back" <<endl;
          cin >> control;
        }
      }
    }
    if(control == 4){
      g.toString();
    }
    if(control == 0){
      open = false;
    }
  }
  return 0;
}

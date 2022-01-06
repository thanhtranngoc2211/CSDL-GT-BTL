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
#include "Weight.h"
using namespace std;

int main() {
  LinkedIn g;
  Node man;
  string name_1,name_2;
  vector<Node> a;
  Weight w;
  int control;
  g._init_();
  bool open = true;

  g.addNode();
  man.id = 0;
  man.name = "thanh";
  man.dob = "22/11/2000";
  man.email = "thanhtranngoc2211@gmail.com";
  man.number = "0822455477";
  man.field = "AI";
  man.work = "NAVER";
  a.push_back(man);

  g.addNode();
  man.id = 1;
  man.name = "linh";
  man.dob = "10/11/2003";
  man.email = "linh.ngu@gmail.com";
  man.number = "0915273456";
  man.field = "law";
  man.work = "NAVER";
  a.push_back(man);

  g.addNode();
  man.id = 2;
  man.name = "huyen";
  man.dob = "17/09/2000";
  man.email = "huyen.dt@gmail.com";
  man.number = "0335428632";
  man.field = "marketing";
  man.work = "PG";
  a.push_back(man);

  g.addNode();
  man.id = 3;
  man.name = "van";
  man.dob = "30/10/1996";
  man.email = "van@gmail.com";
  man.number = "0915874352";
  man.field = "home";
  man.work = "NAVER";
  a.push_back(man);

  g.addNode();
  man.id = 4;
  man.name = "la";
  man.dob = "1/10/2000";
  man.email = "laviethai@gmail.com";
  man.number = "0912514567";
  man.field = "dev";
  man.work = "lotus";
  a.push_back(man);

  w.papers = 10;
  w.years = 18;
  name_1 = "thanh";
  name_2 = "linh";
  g.addEdge(name_1,name_2,a,w);
  w.papers = 15;
  w.years = 3;
  g.addEdge("thanh","huyen",a,w);
  w.papers = 0;
  w.years = 3;
  g.addEdge("linh","van",a,w);
  w.papers = 3;
  w.years = 3;
  g.addEdge("la","huyen",a,w);
  w.papers = 0;
  w.years = 3;
  g.addEdge("thanh","van",a,w);
  w.papers = 0;
  w.years = 2;
  g.addEdge("la","van",a,w);

  while (open){
    cout << "----------------------------------" <<endl;
    cout << "an 1 de them nut"<<endl;
    cout << "an 2 de them canh" <<endl;
    cout << "an 3 de xoa canh" <<endl;
    cout << "an 4 de tim thong tin" <<endl;
    cout << "an 5 de tim lien he" << endl;
    cout << "an 6 de show matrix" <<endl;
    cout << "an 0 de thoat" << endl;
    cout << "----------------------------------" <<endl;
    cout << "Nhap: "; cin >> control;
    fflush(stdin);
    if (control == 1){
        g.addNode();
        man.id = a.size();
        cout << "Nhap thong tin: "<<endl;
        cout << "Nhap ten: "; cin >> man.name;
        cout << "Nhap dob: "; cin >> man.dob;
        cout << "Nhap email: "; cin >> man.email;
        cout << "Nhap sdt: "; cin >> man.number;
        cout << "Nhap field: "; cin >> man.field;
        cout << "Nhap noi lam viec: "; cin >> man.work;
        a.push_back(man);
    }
    if(control == 2){
        cout << "Node thu nhat: "; cin >> name_1;
        cout << "Node thu hai: ";cin >> name_2;
        cout << "Nhap weight: "<<endl;
        cout << "- so nam: ";cin >> w.years;
        cout << "- so bai bao: ";cin >> w.papers;
        g.addEdge(name_1,name_2,a,w);
    }
    if(control == 3){
        cout << "Node thu nhat: "; cin >> name_1;
        cout << "Node thu hai: ";cin >> name_2;
        g.removeEdge(name_1,name_2,a);
    }
    if(control == 4){
        cout << "Nhap ten nguoi/ten noi lam viec: "; cin >> name_1;
        g.SearchInfo(a,name_1);
    }
    if(control == 5){
      cout << "Nhap ten nguoi thu nhat: "; cin >> name_1;
      cout << "Nhap ten nguoi thu hai : "; cin >> name_2;
      g.relationship(a, name_1, name_2);
    }
    if(control == 6){
        g.toString();
    }
    if(control == 0){
        open = false;
    }
  }
  return 0;
}

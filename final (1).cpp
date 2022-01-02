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
using namespace std;

struct Node{
  int id;
  string name;
  string dob;
  string email;
  string number;
  string field;
  string work;
};

struct Weight{
    int years;
    int papers;
};

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

  //Initialize the matrix to zero
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
  void addEdge(int i, int j, vector<Node> a, Weight w) {
    // Not add if input same node
    if (i == j){
      printf("Can't execute. Error: Same node\n");
      return;
    }
    int num_node_exist = 0;
    // Count node exist
    for (int ite = 0; ite < a.size(); ite++){
      if (a[ite].id == i || a[ite].id == j){
        num_node_exist++;
      }
    }
    // Check successfully, add
    if (num_node_exist == 2){
      adjMatrix.at(i).at(j) = w;
      adjMatrix.at(j).at(i) = w;
    }
  }

//  void addEdge(string name1,string name2,vector<Node> a, Weight w){
//      int x,y;
//    if (name1 == name2){
//      printf("Can't execute. Error: Same node\n");
//      return;
//    }
//    int num_node_exist = 0;
//    // Count node exist
//    for (int i = 0; i < a.size(); i++){
//        for (int j = 0; j < a.size();j++){
//            if (a[i].name == name1 && a[j].name == name2){
//                x = i; y = j;
//                num_node_exist++;
//            }
//        }
//    }
//    // Check successfully, add
//    if (num_node_exist == 1){
//      adjMatrix.at(x).at(y) = w;
//      adjMatrix.at(y).at(x) = w;
//    }
//  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix.at(i).at(j) = {-1,-1};
    adjMatrix.at(j).at(i) = {-1,-1};
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < size; i++) {
      cout << i << " : ";
      for (int j = 0; j < size; j++)
        cout << "{" << adjMatrix[i][j].years << "," << adjMatrix[i][j].papers <<"}" << " ";
      cout << "\n";
    }
  }

  // Search
  void searchDOB(vector<Node> a, string nameSearch){
    for (int i = 0; i < a.size(); i++){
      if (nameSearch == a[i].name){
        cout << "DOB: " + a[i].dob << endl;
      }
    }
  }

  // Search fellow
  void searchFellow(vector<Node> a, string nameSearch){
    string work;
    vector<string> fellow;
    bool found = false;
    // Check node validity
    for (int i = 0; i < a.size(); i++){
      if (nameSearch == a[i].name){
        work = a[i].work;
        found = true;
        break;
      }
    }
    if (found){
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
    else {
      cout << "Not found searched name\n";
    }
  }

  void SearchInfo(vector<Node> a, string nameSearch){
    bool exist = false;
    for (int i = 0; i < a.size(); i++){
      if (nameSearch == a[i].name){
        cout << "Thong tin cua " << nameSearch << ":" << endl;
        cout << "- DOB: " + a[i].dob << endl;
        cout << "- Email: " + a[i].email <<endl;
        cout << "- So dien thoai: " + a[i].number << endl;
        cout << "- Field: " + a[i].field << endl;
        cout << "- Noi lam viec: " + a[i].work << endl;
        cout << "- " ;
        searchFellow(a,nameSearch);
        exist = true;
      }
      if(nameSearch == a[i].work){
        cout << a[i].name << " ";
        exist = true;
      }
    }
    if(exist){}
    else cout << "Khong ton tai" <<endl;
  }

    void relationship(vector<Node> a, string nameSearch1,string nameSearch2){
        bool found = false;
        for (int i = 0; i < a.size(); i++){
            for(int j = 0;j < a.size();j++){
                if(a[i].name == nameSearch1 && a[j].name == nameSearch2){
                    if(adjMatrix[i][j].years == -1){
                        cout << nameSearch1 << " va " << nameSearch2 << ":" <<" Khong quen nhau"<< endl;
                    }
                    else{
                    cout << nameSearch1 << " va " << nameSearch2 << ":" << endl;
                    cout << "- So nam lam viec: "<< adjMatrix[i][j].years <<" nam" <<endl;
                    cout << "- So bai bao thuc hien cung nhau: " << adjMatrix[i][j].papers <<" bai"<<endl ;
                    }
                    found = true;
                    break;
                }
            }
        }
        if(found){

        }
        else cout << "Not found human\n";
    }
};



int main() {
  LinkedIn g;
  Node man;
  int x,y;
  vector<Node> a;
  string z;
  Weight w;
  int control;
  g._init_();
  bool open = true;

  while (open){
    cout << "----------------------------------" <<endl;
    cout << "an 1 de them nut"<<endl;
    cout << "an 2 de them canh" <<endl;
    cout << "an 3 de xoa canh" <<endl;
    cout << "an 4 de tim thong tin" <<endl;
    cout << "an 5 de show matrix" <<endl;
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
        cout << "Node dau: "; cin >> x;
        cout << "Node cuoi: ";cin >> y;
        cout << "Nhap weight: "<<endl;
        cout << "- so nam: ";cin >> w.years;
        cout << "- so bai bao: ";cin >> w.papers;
        g.addEdge(x,y,a,w);
        cout << "Da them canh giua Node " << x << " va " << y << endl;
    }
    if(control == 3){
        cout << "Node dau: "; cin >> x;
        cout << "Node cuoi: ";cin >> y;
        g.removeEdge(x,y);
        cout << "Da xoa canh giua Node " << x << " va " << y << endl;
    }
    if(control == 4){
        cout << "Nhap ten nguoi/ten noi lam viec: "; cin >> z;
        g.SearchInfo(a,z);
    }
    if(control == 5){
        g.toString();
    }
    if(control == 0){
        open = false;
    }
  }

  g.addNode();
  man.id = 0;
  man.dob = "22/11/2000";
  man.name = "thanh";
  man.email = "thanhtranngoc2211@gmail.com";
  man.field = "AI";
  man.number = "0822455477";
  man.work = "NAVER";
  a.push_back(man);
  // 2
  g.addNode();
  man.id = 1;
  man.dob = "17/09/2000";
  man.name = "huyen";
  man.email = "huyen.dt@gmail.com";
  man.field = "Marketing";
  man.number = "0335428632";
  man.work = "PG";
  a.push_back(man);
  // 3
  g.addNode();
  man.id = 2;
  man.dob = "10/11/2003";
  man.name = "linh";
  man.email = "linh.ngu@gmail.com";
  man.field = "Law";
  man.number = "0915234856";
  man.work = "PG";
  a.push_back(man);
  w.years = 2;
  w.papers = 3;

  // Action
  g.addEdge(0,1,a,w);
  g.relationship(a,"huyen","thanh");
  g.toString();
  g.searchDOB(a, "huyen");
  g.searchFellow(a, "linh");
  printf("No more to display");
  return 0;
}

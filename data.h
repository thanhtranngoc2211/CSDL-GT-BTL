#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include <tuple>
#include "LinkedIn.h"
#include "Weight.h"
#include "Node.h"

tuple <LinkedIn, vector<Node>> fetchData(LinkedIn g, vector<Node> a) {
    Node man;
    Weight w;
    g.addNode();
    man.id = 0;
    man.name = "Tran Ngoc Thanh";
    man.dob = "22/11/2000";
    man.email = "thanhtranngoc2211@gmail.com";
    man.number = "0822455477";
    man.field = "AI";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 1;
    man.name = "Tran Mai Linh";
    man.dob = "10/11/2003";
    man.email = "linh.ngu@gmail.com";
    man.number = "0915273456";
    man.field = "law";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 2;
    man.name = "Dao Thi Huyen";
    man.dob = "17/09/2000";
    man.email = "huyen.dt@gmail.com";
    man.number = "0335428632";
    man.field = "Marketing";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 3;
    man.name = "Nguyen Ngoc Mai Van";
    man.dob = "30/10/1996";
    man.email = "van@gmail.com";
    man.number = "0915874352";
    man.field = "Accountance";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 4;
    man.name = "La Viet Hai";
    man.dob = "1/10/2000";
    man.email = "laviethai@gmail.com";
    man.number = "0912514567";
    man.field = "developer";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 5;
    man.name = "Nguyen Ngoc An";
    man.dob = "1/10/2000";
    man.email = "annn@gmail.com";
    man.number = "0912514567";
    man.field = "Education";
    man.work = "Pineapple";
    a.push_back(man);
    
    g.addNode();
    man.id = 6;
    man.name = "Tran Manh Thang";
    man.dob = "1/10/2000";
    man.email = "thangtm@gmail.com";
    man.number = "0912514567";
    man.field = "developer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 7;
    man.name = "Tran Thi Kim Que";
    man.dob = "1/10/2000";
    man.email = "quettk@gmail.com";
    man.number = "0912514567";
    man.field = "host";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 8;
    man.name = "Tran Van Cac";
    man.dob = "1/10/2000";
    man.email = "cactv@gmail.com";
    man.number = "0912514567";
    man.field = "host";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 9;
    man.name = "Nguyen Thi Kim Dung";
    man.dob = "1/10/2000";
    man.email = "dungntk@gmail.com";
    man.number = "0912514567";
    man.field = "host";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 10;
    man.name = "Hoang Duc Viet";
    man.dob = "1/10/2000";
    man.email = "viethd@gmail.com";
    man.number = "0912514567";
    man.field = "AI";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 11;
    man.name = "Nguyen Tuan Hung";
    man.dob = "1/10/2000";
    man.email = "hungnt@gmail.com";
    man.number = "0912514567";
    man.field = "host";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 12;
    man.name = "Do Duc Viet";
    man.dob = "1/10/2000";
    man.email = "vietdd@gmail.com";
    man.number = "0912514567";
    man.field = "developer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 13;
    man.name = "Nguyen Lam Tung";
    man.dob = "1/10/2000";
    man.email = "tungnl@gmail.com";
    man.number = "0912514567";
    man.field = "host";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 14;
    man.name = "Do Phuong Trinh";
    man.dob = "1/10/2000";
    man.email = "trinhdp@gmail.com";
    man.number = "0912514567";
    man.field = "Accountance";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 15;
    man.name = "Nguyen Hai Long";
    man.dob = "1/10/2000";
    man.email = "longnh@gmail.com";
    man.number = "0912514567";
    man.field = "developer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 16;
    man.name = "Tran Bien";
    man.dob = "1/10/2000";
    man.email = "bient@gmail.com";
    man.number = "0912514567";
    man.field = "developer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 17;
    man.name = "Vu Thi Trang";
    man.dob = "1/10/2000";
    man.email = "trangvt@gmail.com";
    man.number = "0912514567";
    man.field = "host";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 18;
    man.name = "Pham Ngoc Thien";
    man.dob = "1/10/2000";
    man.email = "thienpn@gmail.com";
    man.number = "0912514567";
    man.field = "developer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 19;
    man.name = "Pham Van Dung";
    man.dob = "1/10/2000";
    man.email = "dungvp@gmail.com";
    man.number = "0912514567";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 20;
    man.name = "Nguyen Duc An";
    man.dob = "28/07/2001";
    man.email = "an.nd01@gmail.com";
    man.number = "0775834279";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);
    
    g.addNode();
    man.id = 21;
    man.name = "Nguyen Ngoc Duong";
    man.dob = "04/11/2001";
    man.email = "duong.nn@gmail.com";
    man.number = "0383458354";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);
  
    g.addNode();
    man.id = 22;
    man.name = "Quang Thanh Dat";
    man.dob = "23/05/2001";
    man.email = "datqt@gmail.com";
    man.number = "0756151836";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);
    
    g.addNode();
    man.id = 23;
    man.name = "Nguyen Minh Hieu";
    man.dob = "24/12/2001";
    man.email = "hieu.nm@gmail.com";
    man.number = "0383458354";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);
    
    g.addNode();
    man.id = 24;
    man.name = "Nguyen Thi Dao";
    man.dob = "1/07/2001";
    man.email = "dao.nt@gmail.com";
    man.number = "0393275621";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 25;
    man.name = "Phung Ba Truong Giang";
    man.dob = "29/09/2001";
    man.email = "giang.pbt@gmail.com";
    man.number = "0989265154";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 26;
    man.name = "Ho Ngoc Man";
    man.dob = "26/04/2001";
    man.email = "man.hn@gmail.com";
    man.number = "0519542233";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 27;
    man.name = "Pham Khuong Duy";
    man.dob = "29/04/2001";
    man.email = "duy.pk@gmail.com";
    man.number = "0870253795";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 28;
    man.name = "Bui Duc Duc";
    man.dob = "10/03/2001";
    man.email = "duc.bd@gmail.com";
    man.number = "0402997864";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 29;
    man.name = "Le Minh Duc";
    man.dob = "6/12/2001";
    man.email = "duc.lm@gmail.com";
    man.number = "0901471563";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 30;
    man.name = "Nguyen Huy Hieu";
    man.dob = "19/05/2001";
    man.email = "hieu.nh@gmail.com";
    man.number = "0837034234";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 31;
    man.name = "Vu Van Linh";
    man.dob = "3/12/2001";
    man.email = "linh.vv@gmail.com";
    man.number = "0371449804";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 32;
    man.name = "Pham Minh Hung";
    man.dob = "12/06/2001";
    man.email = "hung.pm@gmail.com";
    man.number = "0686060142";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 33;
    man.name = "Dong Minh Thai";
    man.dob = "27/09/2001";
    man.email = "thai.dm@gmail.com";
    man.number = "0373746887";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 34;
    man.name = "Nguyen Tien Thanh";
    man.dob = "23/06/2001";
    man.email = "thanh.nt@gmail.com";
    man.number = "0513828339";
    man.field = "Engineer";
    man.work = "NAVER";
    a.push_back(man);

    g.addNode();
    man.id = 35;
    man.name = "Hua Hoang Vu";
    man.dob = "23/09/2001";
    man.email = "vu.hh@gmail.com";
    man.number = "0764309784";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 36;
    man.name = "Nguyen Van Quang";
    man.dob = "01/04/2001";
    man.email = "quang.nv@gmail.com";
    man.number = "0897530105";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);

    g.addNode();
    man.id = 37;
    man.name = "Tran Minh Tuan";
    man.dob = "2/03/2001";
    man.email = "tuan.tm@gmail.com";
    man.number = "0795665243";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 38;
    man.name = "Le Minh Tuan";
    man.dob = "13/11/2001";
    man.email = "tuan.lm@gmail.com";
    man.number = "0364579563";
    man.field = "Engineer";
    man.work = "Pineapple";
    a.push_back(man);

    g.addNode();
    man.id = 39;
    man.name = "Nguyen Van Minh";
    man.dob = "21/09/2001";
    man.email = "m.nv@gmail.com";
    man.number = "0872747169";
    man.field = "Engineer";
    man.work = "Samsing";
    a.push_back(man);

    // em up phan
    
    w.papers = 10;
    w.years = 18;
    g.addEdge(0,"Tran Mai Linh",a,w);
    w.papers = 15;
    w.years = 3;
    g.addEdge(0,"Dao Thi Huyen",a,w);
    w.papers = 0;
    w.years = 3;
    g.addEdge(1,"Nguyen Ngoc Mai Van",a,w);
    w.papers = 3;
    w.years = 3;
    g.addEdge(4,"Dao Thi Huyen",a,w);
    w.papers = 0;
    w.years = 3;
    g.addEdge(0,"Nguyen Ngoc Mai Van",a,w);
    w.papers = 0;
    w.years = 2;
    g.addEdge(4,"Nguyen Ngoc Mai Van",a,w);


    return make_tuple(g, a);
}

#endif

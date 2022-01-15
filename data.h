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

    w.papers = 10;
    w.years = 18;
    g.addEdge("Tran Ngoc Thanh","Tran Mai Linh",a,w);
    w.papers = 15;
    w.years = 3;
    g.addEdge("Tran Ngoc Thanh","Dao Thi Huyen",a,w);
    w.papers = 0;
    w.years = 3;
    g.addEdge("Tran Mai Linh","Nguyen Ngoc Mai Van",a,w);
    w.papers = 3;
    w.years = 3;
    g.addEdge("La Viet Hai","Dao Thi Huyen",a,w);
    w.papers = 0;
    w.years = 3;
    g.addEdge("Tran Ngoc Thanh","Nguyen Ngoc Mai Van",a,w);
    w.papers = 0;
    w.years = 2;
    g.addEdge("La Viet Hai","Nguyen Ngoc Mai Van",a,w);


    return make_tuple(g, a);
}

#endif

#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <vector>
#include "LinkedIn.h"
#include "Weight.h"
#include "Node.h"

void fetchData(LinkedIn g, vector<Node> a) {
    Node man;
    Weight w;
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
    g.addEdge("thanh","linh",a,w);
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
};

#endif

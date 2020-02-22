#ifndef HEADER_H_
#define HEADER_H_


#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<stack>
#include<algorithm>

using namespace std;

struct symbol {
    bool value;
    bool sign;
    bool pure;
    int name;
    bool assigned;
};

struct symbolCounter {
    int trueTimes;
    int falseTimes;
    int times;
};

struct clause {
    vector<symbol> Clause;
};

struct formulae {
    bool satisfiable;
    bool result;
    vector<clause> Formulae;
};


extern int clause_num;
extern int symbol_num;
extern symbolCounter* symbol_times;


#endif
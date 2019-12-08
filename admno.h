#include<bits/stdc++.h>
using namespace std;

#ifndef ADMNO_H
#define ADMNO_H

class Admno
 {public:
        int year;
        string branch;
        int rlno;
        Admno() 
        {
            year = 0;
            rlno =0;
            branch = "NIL";
        }
        Admno(int year, string branch, int rlno)
        {
            this->year = year;
            this->branch = branch ;
            this->rlno = rlno;
        }
  };

  #endif

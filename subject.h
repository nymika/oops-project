#include<bits/stdc++.h>
using namespace std;

#ifndef SUBJECT_H
#define SUBJECT_H

#include "prof.h"

class Subject
{public:
  string sname;
	string sid;
	Prof Proffesor;
	float marks;
	Subject(string sn,string si,Prof cProffesor,float cm)
	:sname(sn),sid(si),Proffesor(cProffesor),marks(cm)
	{
	}
};

#endif
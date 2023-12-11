#include <iostream>
#include<vector>
#include"main.h"
#include "Matrix.h"
using namespace std;


// Phase one in step one: primary assignment
void primary(vector<task>&ini, Numeric_lib::Matrix<int, 2>&ta,int t)
{
	int min;
	unsigned int i;
	unsigned int j;
	for (i = 0; i < ta.dim1(); i++)
	{
		ini[i].id = i + 1;
		min = ta(i, 0);
		for (j = 0; j < ta.dim2(); j++)
			if (ta(i, j) < min)
				min = ta(i, j);
		if (min > t)
			ini[i].ct = 1;
		else
			ini[i].ct = 0;
	}
}

// Phase two in step one: task prioritizing 
void prioritize(vector<task>&ini, Numeric_lib::Matrix<int, 2>&ta, Numeric_lib::Matrix<int, 2>&G,int t)
{
	unsigned int i;
	unsigned int j,m;
	int k ;
	double w;
	double max;
	m = ini.size() - 1;
	for (i = 0; i < ini.size(); i++)
	{
		k = 0;
		for (j = 0; j < G.dim2(); j++)
			if (G(m - i, j) == 1)
				k = k + 1;
		if (k == 0)
			ini[m - i].exit = 1;
		k = 0;
		for (j = 0; j < G.dim2(); j++)
			if (G(j, m - i) == 1)
				k = k + 1;
		if(k==0)
			ini[m - i].entry = 1;
		max = 0;
		w = 0;
		if (!(ini[m - i].ct))
		{
			for (j = 0; j < ta.dim2(); j++)
				w = w + ta(m - i, j);
			w = w /ta.dim2();
		}
		else
			w = t;
		for (j = 0; j < G.dim2(); j++)
			if ((G(m - i, j) == 1) && (max < ini[j].pri))
				max = ini[j].pri;
		ini[m - i].pri = w + max;
	}
}
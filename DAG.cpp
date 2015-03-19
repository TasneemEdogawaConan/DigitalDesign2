#include<iostream>
#include<fstream>
#include "DAG.h"

using namespace std;

DAG::DAG()
{
	for(int i=0; i<10000; i++)
	{
		for(int j=0; j<10000; j++)
		{
			adjMatrix[i][j]=0;
		}
	}
}
DAG::~DAG()
{}
void DAG::Read(string fileName)
{
	ifstream in;
	in.open(fileName);
}

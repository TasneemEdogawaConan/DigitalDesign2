#include<iostream>
#include<fstream>
#include<sstream>
#include "DAG.h"

using namespace std;

DAG::DAG()
{
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			adjMatrix[i][j]=0;
		}
	}
}
DAG::~DAG()
{}
void DAG::Read(string fileName) //sample.v
{
	ifstream in;
	in.open(fileName,std::fstream::in | std::fstream::out | std::fstream::app);
	if (in.is_open())
	{
		string s;
		getline(in,s);
		cout<<s<<endl;
		while(!in.eof())
		{
			getline(in,s);
			cout<<s<<endl;
		}
	}
	else
	{
		cout<<"ERROR! CANNOT OPEN SUCH A FILE!"<<endl;
	}
	in.close();
}

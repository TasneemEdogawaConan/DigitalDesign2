#include<iostream>
#include<fstream>
#include<string>
#include "DAG.h"

using namespace std;

int main()
{
	//Project1 Degital Design2 **Logic Circuit Schematic Beautifier
	int n= 741;// got this num from testing by knowing the number of nodes
	DAG d(n);
	d.Read("sample.v");
	d.PrintV(n);
	//d.PrintM(n);
	//d.PrintADJ(n);
	vector <string> sorted; 
	sorted=d.sort(n);
	for(int i=0; i<sorted.size();i++)
		{
			cout<<sorted[i]<<"   ";
		}
	
	system("PAUSE");
	return 0;
}


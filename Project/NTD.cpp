#include<iostream>
#include<fstream>
#include<string>
#include "DAG.h"

using namespace std;

int main()
{
	//Project1 Degital Design2 **Logic Circuit Schematic Beautifier
	int n= 21;// got this num from testing by knowing the number of nodes
	DAG d(n);
	d.Read("sam.v");
	//d.PrintV(n);
	//d.PrintM(n);
	//d.PrintADJ(n);
	d.BFS(n);
	system("PAUSE");
	return 0;
}


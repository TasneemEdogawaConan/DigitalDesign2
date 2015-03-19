#include<iostream>
#include<map>
#include<vector>

using namespace std;

#ifndef DAG_H
#define DAG_H
class DAG
{
public:
	DAG();
	~DAG();
	void Read(string fileName);
	//void Print();
private:
	map<string, int> Mapping; // mapping each gate to a number
	vector <string> gates; // names of gates
	int adjMatrix [100][100]; //adjacency matrix if the value is 1, then node i and j are connected
	};

#endif

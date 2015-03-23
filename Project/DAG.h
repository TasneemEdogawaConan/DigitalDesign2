#include<iostream>
#include<map>
#include<vector>
#include <queue> 

using namespace std;

#ifndef DAG_H
#define DAG_H
class DAG
{
public:
	struct LEVEL
	{
		string gate;
		int level;
	};
	DAG(int n);
	~DAG();
	void Read(string fileName);//sample.v
	string removeSpaces(string s);//remove spaces within string
	bool IsInput(string s);
	bool IsOutput(string s);
	void PrintV(int n);
	void PrintM(int n);
	void PrintADJ(int n);
	queue<LEVEL> BFS(int n);
	
private:
	map<string, int> Mapping; // mapping each gate to a number
	vector <string> gates; // names of gates
	int** adjMatrix; //adjacency matrix if the value is 1, then node i and j are connected
	vector<string> inputs;
	vector<string> outputs;
	};

#endif

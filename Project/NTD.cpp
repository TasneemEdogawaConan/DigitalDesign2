#include<iostream>
#include<fstream>
#include<string>
#include "DAG.h"

using namespace std;


vector<string> sort(int** Two_D_Array,vector<string> nodes, int n)
{
	int count;
	vector<string> sorted;
	vector<bool> check;
	for(int i=0; i<nodes.size();i++)
	{
		check.push_back(false);
	}
	cout<<"before: "<<endl;
	for(int i=0; i<n;i++)
		{
			for(int j=0;j<n;j++)
		{
			cout<<Two_D_Array[i][j]<<" ";
		}
			cout<<endl;
	}
	cout<<"*************************"<<endl;
	for(int z=0; z<n;z++)
			{
		for(int i=0; i<n;i++)
			{
				count=0;
				for(int j=0;j<n;j++)
				{
					if(Two_D_Array[j][i]==0)
						count++;
				}
				if (count==n && !check[i])
				{
					cout<<"node: "<<i<<" : "<<nodes[i]<<endl;
					sorted.push_back(nodes[i]);
					check[i]=true;
					for(int t=0; t<n;t++)
						Two_D_Array[i][t]=0;
							//////
				for(int i=0; i<n;i++)
				{
					for(int j=0;j<n;j++)
				{
					cout<<Two_D_Array[i][j]<<" ";
				}
					cout<<endl;
				}
				cout<<"*************************"<<endl;
			/////
				}
		}
	}
	
	cout<<"after: "<<endl;
	for(int i=0; i<n;i++)
		{
			for(int j=0;j<n;j++)
		{
			cout<<Two_D_Array[i][j]<<" ";
		}
			cout<<endl;
	}
	return sorted;
	}
int main()
{
	//Project1 Degital Design2 **Logic Circuit Schematic Beautifier
	//int n= 741;// got this num from testing by knowing the number of nodes
	//DAG d(n);
	//d.Read("sample.v");
	//d.PrintV(n);
	//d.PrintM(n);
	//d.PrintADJ(n);
	/////////////
	int k=5;
	int** D2Array= new int*[k];
	for(int i=0; i<k; i++)
	{
		D2Array[i]= new int [k];
	}
	//////
	D2Array[0][0]=0; D2Array[0][1]=1; D2Array[0][2]=1; D2Array[0][3]=1; D2Array[0][4]=0;
	D2Array[1][0]=0; D2Array[1][1]=0; D2Array[1][2]=1; D2Array[1][3]=1; D2Array[1][4]=1;
	D2Array[2][0]=0; D2Array[2][1]=0; D2Array[2][2]=0; D2Array[2][3]=1; D2Array[2][4]=0;
	D2Array[3][0]=0; D2Array[3][1]=0; D2Array[3][2]=0; D2Array[3][3]=0; D2Array[3][4]=1;
	D2Array[4][0]=0; D2Array[4][1]=0; D2Array[4][2]=0; D2Array[4][3]=0; D2Array[4][4]=0;
	//////
	vector<string>nodes;
	nodes.push_back("A");
	nodes.push_back("B");
	nodes.push_back("C");
	nodes.push_back("D");
	nodes.push_back("E");
	vector<string> sorted;

	sorted=sort(D2Array,nodes,k);
	for(int i=0;i<sorted.size();i++)
		{
			cout<<sorted[i]<<" ";
		}
	cout<<endl;
	system("PAUSE");
	return 0;
}


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
	string s;
	string word;
	in.open(fileName.c_str());
	int inp=0;
	int out=0;
	int INV=0;
	int OR=0;
	int XOR=0;
	int NOR=0;
	int XNOR=0;
	int AND=0;
	int NAND=0;
	if (in.is_open())
	{
		while(!in.eof())
		{
			getline(in,s,' ');
			if(s=="input")
			{
					getline(in,s);
					s.erase(s.length()-1,1);//remove semicolon
					s=removeSpaces(s); //remove space within the name
					cout<<"input "<<inp++<<" is "<<s<<endl;
					inputs.push_back(s);
			}
			else if (s=="output")
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"output "<<out++<<" is "<<s<<endl;
				outputs.push_back(s);
			}
			else if(s=="INVX1")//invertor
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"invertor "<<INV++<<" is "<<s<<endl;
			}
			else if(s=="NOR2X1")//nor
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"nor "<<NOR++<<" is "<<s<<endl;
			}
			else if(s=="XNOR2X1")//xnor
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"xnor "<<XNOR++<<" is "<<s<<endl;
			}
			else if(s=="OR2X2")//or
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"or "<<OR++<<" is "<<s<<endl;
			}
			else if(s=="XOR2X1")//xor
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"xor "<<XOR++<<" is "<<s<<endl;
			}
			else if(s=="AND2X2")//and
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"and "<<AND++<<" is "<<s<<endl;
			}
			else if(s=="NAND2X1")//nand
			{
				getline(in,s);
				s.erase(s.length()-1,1);//remove semicolon
				s=removeSpaces(s); //remove space within the name
				cout<<"nand "<<NAND++<<" is "<<s<<endl;
			}
			}
	}
	else
	{
		cout<<"ERROR! CANNOT OPEN SUCH A FILE!"<<endl;
	}
	in.close();
}
string DAG:: removeSpaces(string s)
{
  for (int i = (s.length())-1; i >= 0; --i) 
  {
   if(s[i] == ' ')
      s.erase(i, 1);
 }  
  return s;
}

bool DAG::IsInput(string s)
{
	for(int i=0; i<inputs.size();i++)
		if(s==inputs[i])
			return true;
	return false;
}
bool DAG::IsOutput(string s)
{
	for(int i=0; i<outputs.size();i++)
		if(s==outputs[i])
			return true;
	return false;
}

#include<iostream>
#include<fstream>
#include<sstream>

#include "DAG.h"

using namespace std;

DAG::DAG(int n)
{
	adjMatrix= new int*[n];
	for(int i=0; i<n; i++)
	{
		adjMatrix[i]= new int [n];
	}
	for(int i=0; i<n;i++)
		for(int j=0;j<n;j++)
			adjMatrix[i][j]=0;
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
	int gate=0;
	string gateName="";
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
			else
			{
				
				if(s=="INVX1")
				{
					///////////////
					word=s;
					getline(in,s);
					s.erase(s.length()-1,1);//remove semicolon
					s=removeSpaces(s); //remove space within the name
					s=word+s;
					gateName=s;
					///////////////
					if(Mapping.count(s)==0)
					{
						gates.push_back(s);
						Mapping[s]=gates.size()-1;
					}
					
					////first_input
					getline(in,s);
					s.erase(0,7);//remove .A(
					s.erase(s.length()-2,2);//remove ),
					s=removeSpaces(s);
						if(Mapping.count(s)==0) //if the node does not exist in the map, it is added
						{
							gates.push_back(s);
							Mapping[s]=gates.size()-1;
						}
						adjMatrix[Mapping[s]][Mapping[gateName]]=1;
						//cout<<"A connect from node: "<<gates[Mapping[s]]<<" to Node: "<<gates[Mapping[gateName]]<<endl;
					cout<<"input1 "<<s<<endl;
					////output
					getline(in,s);
					s.erase(0,7);//remove .A(
					s.erase(s.length()-1,1);//remove ),
					s=removeSpaces(s);
						if(Mapping.count(s)==0)
						{
							gates.push_back(s);
							Mapping[s]=gates.size()-1;
						}
						adjMatrix[Mapping[gateName]][Mapping[s]]=1;
						//cout<<"A connect from node: "<<gates[Mapping[gateName]]<<" to Node: "<<gates[Mapping[s]]<<endl;
					cout<<"output "<<s<<endl;
					getline(in,s);
				}
				else if( s=="NOR2X1" ||s=="XNOR2X1"||s=="OR2X2"||s=="XOR2X1"||s=="AND2X2"||s=="NAND2X1")
				{
					///////////////
					word=s;
					getline(in,s);
					s.erase(s.length()-1,1);//remove semicolon
					s=removeSpaces(s); //remove space within the name
					s=word+s;
					gateName=s;
					///////////////
					if(Mapping.count(s)==0)
					{
						gates.push_back(s);
						Mapping[s]=gates.size()-1;
					}
					////first_input
					getline(in,s);
					s.erase(0,7);//remove .A(
					s.erase(s.length()-2,2);//remove ),
					s=removeSpaces(s);
						if(Mapping.count(s)==0) //if the node does not exist in the map, it is added
						{
							gates.push_back(s);
							Mapping[s]=gates.size()-1;
						}
						adjMatrix[Mapping[s]][Mapping[gateName]]=1;
						//cout<<"A connect from node: "<<gates[Mapping[s]]<<" to Node: "<<gates[Mapping[gateName]]<<endl;
					cout<<"input1 "<<s<<endl;
					////second_input
					getline(in,s);
					s.erase(0,7);//remove .A(
					s.erase(s.length()-2,2);//remove ),
					s=removeSpaces(s);
						if(Mapping.count(s)==0) //if the node does not exist in the map, it is added
						{
							gates.push_back(s);
							Mapping[s]=gates.size()-1;
						}
						adjMatrix[Mapping[s]][Mapping[gateName]]=1;
						//cout<<"A connect from node: "<<gates[Mapping[s]]<<" to Node: "<<gates[Mapping[gateName]]<<endl;
					cout<<"input2 "<<s<<endl;
					////output
					getline(in,s);
					s.erase(0,7);//remove .A(
					s.erase(s.length()-1,1);//remove )
					s=removeSpaces(s);
						if(Mapping.count(s)==0)
						{
							gates.push_back(s);
							Mapping[s]=gates.size()-1;
						}
						adjMatrix[Mapping[gateName]][Mapping[s]]=1;
						//cout<<"A connect from node: "<<gates[Mapping[gateName]]<<" to Node: "<<gates[Mapping[s]]<<endl;
					cout<<"output "<<s<<endl;
					getline(in,s);					
				}
				
			}
			}
	}
	else
	{
		cout<<"ERROR! CANNOT OPEN SUCH A FILE!"<<endl;
	}
	///connecting root node with all inputs
	gates.push_back("root");
	Mapping["root"]=gates.size()-1;
	for(int i=0; i<inputs.size();i++)
		adjMatrix[Mapping["root"]][Mapping[inputs[i]]]=1;
	
	
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

void DAG::PrintV(int n)
{
	//Representing nums with gates
	cout<<"Representing nums with gates, Vector"<<endl;
	for(int i=0; i<gates.size();i++)
		cout<<i<<" "<<gates[i]<<endl;
}

void DAG::PrintM(int n)
{
	int i=0;
	cout<<"Mapping gates to num, Map"<<endl;
	for (map<string,int>:: const_iterator it= Mapping.begin(); it!=Mapping.end(); ++it)
		{
			cout << i++<<" "<<it->first << " => " << it->second << '\n';
				}
}

void DAG::PrintADJ(int n)
{
	cout<<"Adjecency Matrix"<<endl;
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)
			if(adjMatrix[i][j]==1)
				{
					cout<<"A connect from node: "<<gates[i]<<" to Node: "<<gates[j]<<endl;
					//cout<<"adjMatrix[i][j]"<<adjMatrix[i][j]<<endl;
				}
}


queue<DAG::LEVEL> DAG::BFS(int n)
{
	int count;
	int lev=-1;
	queue<LEVEL> order;
	queue<LEVEL> out;
	vector<bool> check;
	LEVEL node, v,z;
	bool flag=true;
	for(int i=0; i<gates.size();i++)
	{
		check.push_back(false);
	}
	node.gate=gates[gates.size()-1];
	node.level=lev++;
	order.push(node);
	check[gates.size()-1]=true;
	int i;
	while(!order.empty())
	{
		v=order.front();
		i=Mapping[v.gate];
		order.pop();
		out.push(v);
		lev++;
		if(!flag)
			lev--;
		flag=false;
		for(int j=0;j<gates.size(); j++)
		{
			if(adjMatrix[i][j]==1)
			{
				if(!check[j])
				{
					node.gate=gates[j];
					node.level=lev;
					order.push(node);
					check[j]=true;
					flag=true;
				}
			}
		}

	}
	//lev++;
	/*for(int m=0; m<outputs.size();m++)
	{
		node.gate=outputs[m];
		node.level=lev;
		out.push(node);
	}*/
	for(int i=0; i<out.size();i++)
		{
			z=out.front();
			out.pop();
			cout<<"GATE: "<< z.gate<<" in level "<<z.level<<endl;
		}
	lev=z.level+1;
	//outputs
	for(int m=0; m<outputs.size();m++)
	{
		node.gate=outputs[m];
		node.level=lev;
		cout<<"GATE: "<< node.gate<<" in level "<<node.level<<endl;
	}
		return order;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::vector<std::string> > combination (std::vector<std::string> states);
std::vector<std::vector<std::string> > newTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > nStates);
std::vector<std::vector<std::string> > FillnewTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > ntable);
std::string findSt(int y, std::string tmp, std::vector<std::vector<std::string>> table);
void insert (std::string ins, std::string &where, bool dash);
int findPos(std::string tmp, std::vector<std::vector<std::string>> table);

int main ()
{
	//infile
		std::ifstream input;
		int tp;
		char a, TN;
		std::string NFA, tmp, IS, fs;
		std::vector <int> n;
		std::vector <std::string> states, FS, nFS;
		std::vector<std::vector<std::string> > table, ntable, nStates;
		input.open("ex.txt");
		if (!input.fail())
		{
			input>>NFA;
			input.ignore(64, '=');
			input.ignore(64, '(');
			input.ignore(64, '{');
			input>>tmp;
			while(tmp != "}")
			{
				states.push_back(tmp);
				input>>tmp;
			}
			input.ignore(64, '{');
			input>>a;
			tp=a-48;
			while(a != '}')
			{
				n.push_back(tp);
				input>>a;
				tp=a-48;
			}
			input>>TN;
			input>>IS;
			input.ignore(64, '{');
			input>>tmp;
			while(tmp != "})")
			{
				FS.push_back(tmp);
				input>>tmp;
			}
			std::vector<std::string> tlp;
			for (int i = 0; i < n.size(); i++)
			{
				for (int j = 0; j <= states.size(); j++)
				{
					input>>tmp;
					tlp.push_back(tmp);
				}
				table.push_back(tlp);
				tlp.clear();
			}		
			nStates = combination (states);
			ntable = newTable(table, nStates);
			/*for (int i = 0; i < table.size(); i++)
			{
				for (int j = 0; j < table[i].size(); j++)
				{
					std::cout<<table[i][j]<<" ";
				}
				std::cout<<std::endl;
			}*/
			ntable=FillnewTable(table, ntable);
			for (int i = 0; i < ntable.size(); i++)
			{
				for (int j = 0; j < ntable[i].size(); j++)
				{
					std::cout<<ntable[i][j]<<" | ";
					if(j==0)
						std::cout<<"||";
				}
				std::cout<<std::endl;
			}
		}
		else
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
}
std::vector<std::vector<std::string> > combination (std::vector<std::string> states)
{
	//std::cout<<states.size();
	std::vector<std::string> tmp;
	std::vector<std::vector<std::string> > rtrn;
	for (int i = 0; i < states.size(); i++)
	{
		//std::cout<<std::endl<<i;
		for (int j = 0; j < states.size(); j++)
		{
			//std::cout<<std::endl<<j;
			if (i==0 && j==0)
				tmp.push_back("/");
			else if (i==0 && j==1)
				tmp.push_back(states[0]);
			else if (i==1 && j==0)
				tmp.push_back(states[1]);
			else if (i==1 && j==1)
			{
				tmp.push_back(states[0]);
				tmp.push_back(states[1]);
			}
			rtrn.push_back(tmp);
			tmp.clear();
		}
	}
	return rtrn;
}
std::vector<std::vector<std::string> > newTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > nStates)
{
	std::vector<std::string> tlp;
	std::vector<std::vector<std::string> > ntable;
	std::string tmp;
	for (int j = 0; j < nStates.size(); j++)
	{
		if(nStates[j].size()==1)
			tlp.push_back(nStates[j][0]);
		else
		{
			tmp="";
			for (int k = 0; k < nStates[j].size(); k++)
			{
				tmp=tmp+nStates[j][k];
				if(k<nStates[j].size()-1)
					tmp=tmp+"-";
			}
			tlp.push_back(findSt(nStates.size(), tmp, table));
		}
		ntable.push_back(tlp);
		tlp.clear();
	}
	return ntable;
}
std::string findSt(int y, std::string tmp, std::vector<std::vector<std::string>> table)
{
	//std::string tmp;
	for (int i = 0; i <= y; i++)
	{
		if(table[0][i]==tmp)
		{
			return table[0][i];
		}
	}
}
int findPos(std::string tmp, std::vector<std::vector<std::string>> table)
{
	for (int i = 0; i < table.size(); i++)
	{
		if(table[i][0]==tmp)
		{
			return i;
		}
	}
}
std::vector<std::vector<std::string> > FillnewTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > ntable)
{
	std::string tmp, var, fn;
	int x;
	for (int i = 1; i < ntable.size(); i++)
	{
		for (int j = 0; j < table.size(); j++)
		{
			//std::cout<<ntable[i][0]<<"<ntable "<<table[j][0]<<std::endl;
			for (int k = 1; k < table[j].size(); k++)
			{
				ntable[i].push_back("");
			}
			if(ntable[i][0].find("-"))
			{
				var=ntable[i][0];
				std::istringstream ss(var);
				ntable[i].push_back("");
				while(std::getline(ss, tmp, '-')) 
				{
					x=findPos(tmp, table);
					for (int k = 1; k < table[x].size(); k++)
					{
						if(k<table[x].size()-1)
							insert(table[x][k], ntable[i][k], true);
						else
							insert(table[x][k], ntable[i][k], false);
					}
				}
			}
			else
			{
				if(ntable[i][0]==table[j][0])
				{
					for (int k = 1; j < table[j].size(); k++)
					{
						insert(table[j][k], ntable[i][k], false);
					}
				}
			}
		}
	}
	return ntable;
}
void insert (std::string ins, std::string &where, bool dash)
{
	where=where+ins;
	if(dash)
		where=where+"-";
}
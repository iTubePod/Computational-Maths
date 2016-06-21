#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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
			for (int i = 0; i < n.size(); i++)
			{
				for (int j = 0; j <= states.size(); j++)
				{
					std::cout<<table[i][j]<<" ";
				}
				std::cout<<std::endl;
			}			
			nStates = combination (states);
			for (int i = 0; i < nStates.size(); i++)
			{
				for (int j = 0; j < nStates[i].size(); j++)
				{
					std::cout<<nStates[i][j]<<" ";
				}
				std::cout<<" | ";
			}
			std::cout<<std::endl;
			//std::string ntable [n.size()+1] [nStates.size()+1];
			tlp.clear();
			for (int i = 0; i < n.size(); i++)
			{
				for (int j = 0; j < nStates.size(); j++)
				{
					tlp.push_back("");
				}
				ntable.push_back(tlp);
			}

			for (int j = 0; j < nStates.size(); j++)
			{
				if(j==0)
				{
					ntable[0][j]="/";
				}
				else
				{
					if(nStates[j].size()==1)
						ntable[0][j]=nStates[j][0];
					else
					{
						tmp="";
						for (int k = 0; k < nStates[j].size(); k++)
						{
							tmp=tmp+nStates[j][k];
							if(k<nStates[j].size()-1)
								tmp=tmp+"-";
						}
						ntable[0][j]=findSt(nStates.size(), tmp, table);
					}
				}
			}
			for (int i = 0; i < ntable.size(); i++)
			{
				for (int j = 0; j < ntable[i].size(); j++)
				{
					std::cout<<ntable[i][j]<<std::endl;
				}
			}
		}
		else
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
}
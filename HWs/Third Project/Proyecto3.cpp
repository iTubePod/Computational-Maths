#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

std::vector<std::vector<std::string> > combination (std::vector<std::string> states);
std::vector<std::vector<std::string> > newTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > nStates);
std::vector<std::vector<std::string> > FillnewTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > ntable, std::vector <int> n);
std::string findSt(int y, std::string tmp, std::vector<std::vector<std::string>> table);
void insert (std::string ins, std::string &where, bool dash);
int findPos(std::string tmp, std::vector<std::vector<std::string>> table);
void cleanup(std::vector<std::vector<std::string> > &final);
void printT(std::vector<int> n, std::vector<std::vector<std::string> >ntable);
void printQ(std::vector<std::vector<std::string> >ntable);
void printF(std::vector<std::vector<std::string> >ntable, std::vector<std::string> final);

int main ()
{
	//infile
		std::ifstream input;
		int tp;
		char a, TN;
		std::string NFA, tmp, IS, fs;
		std::vector <int> n;
		std::vector <std::string> states, FS;
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
			ntable=FillnewTable(table, ntable, n);
			cleanup(ntable);
			printQ(ntable);
			printF(ntable, FS);
			printT(n, ntable);
		}
		else
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
}
std::vector<std::vector<std::string> > combination (std::vector<std::string> states)
{
	//std::cout<<states.size();
	std::string tp;
	std::vector<std::string> tmp;
	std::vector<std::vector<std::string> > rtrn;
    rtrn.push_back( tmp );

    for (int i = 0; i < states.size(); i++)
    {
        std::vector< std::vector<std::string> > rtrnTemp = rtrn;

        for (int j = 0; j < rtrnTemp.size(); j++)
            rtrnTemp[j].push_back( states[i] );

        for (int j = 0; j < rtrnTemp.size(); j++)
            rtrn.push_back( rtrnTemp[j] );
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
			tlp.push_back(tmp);
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
std::vector<std::vector<std::string> > FillnewTable(std::vector<std::vector<std::string> > table, std::vector<std::vector<std::string> > ntable, std::vector <int> n)
{
	std::string tmp, var, fn;
	int x;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < n.size(); j++)
		{
				ntable[i].push_back("/");
		}
	}
	for (int i = 1; i < ntable.size(); i++)
	{
		for (int j = 0; j < table.size(); j++)
		{
			if(j==0)
			{
				for (int k = 1; k <= n.size(); k++)
				{
					ntable[i].push_back("");
				}
			}
			if(ntable[i][0].find("-"))
			{
				var=ntable[i][0];
				std::istringstream ss(var);
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
	if(ins=="/"&&where!="")
	{
		where=where;
	}
	else
	{
		if(where.find(ins)==std::string::npos)
		{
			if(ins.find(where)!=std::string::npos)
				where="";
			if(dash&&where!="")
				where=" "+where;
			where=where+ins;
		}
	}
}
void cleanup(std::vector<std::vector<std::string> > &final)
{
	final[0][0]="n";
	for (int i = 0; i < final.size(); ++i)
	{
		for (int j = 0; j < final[i].size(); j++)
		{
			std::replace( final[i][j].begin(), final[i][j].end(), '-', ' ');
			std::replace( final[i][j].begin(), final[i][j].end(), '/', 'n');
		}
	}
}
void printT(std::vector<int> n, std::vector<std::vector<std::string> >ntable)
{
	std::cout<< '|' << std::setw(10) << "S'"<<'|';
	for (int i = 0; i < n.size(); i++)
	{
		std::cout << std::setw(10) << n[i]<<'|';
	}
	std::cout<<std::endl;
	for (int i = 0; i < ntable.size(); i++)
	{
		for (int j = 0; j < ntable[i].size(); j++)
		{
			std::cout << '|' << std::setw(10) << ntable[i][j];
		}
		std::cout<< '|' << std::endl;
	}
}
void printQ(std::vector<std::vector<std::string> >ntable)
{
	std::cout<<"Q' = { ";
	for (int i = 0; i < ntable.size(); i++)
	{
		if(i==ntable.size()-1)
			std::cout<<ntable[i][0]<<" }"<<std::endl;
		else
			std::cout<<ntable[i][0]<<", ";
	}
}
void printF(std::vector<std::vector<std::string> >ntable, std::vector<std::string> final)
{
	std::cout<<"F' = { ";
	for (int i = 0; i < ntable.size(); i++)
	{
		for (int j = 1; j < ntable[i].size(); j++)
		{
			for (int k = 0; k < final.size(); k++)
			{
				if(ntable[i][j].find(final[k])==std::string::npos)
				{
					if(ntable[i][0]!="n")
						std::cout<<ntable[i][0];
					k=final.size();
					j=ntable[i].size();
				}
			}
		}
	}
	std::cout<<" }"<<std::endl;
}
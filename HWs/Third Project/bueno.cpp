#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main ()
{
	//infile
		std::ifstream input;
		int tp;
		char a;
		std::string NFA, tmp;
		std::vector <int> n;
		std::vector <std::string> states;
		char TN;
		std::string IS;
		std::vector <std::string> FS;
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
			for (int i = 0; i < states.size(); i++)
			{
				std::cout<<states[i]<<" ";
			}
			std::cout<<std::endl;
			input.ignore(64, '{');
			input>>a;
			tp=a-48;
			while(a != '}')
			{
				n.push_back(tp);
				input>>a;
				tp=a-48;
			}
			for (int i = 0; i < n.size(); i++)
			{
				std::cout<<n[i]<<" ";
			}
			input>>TN;
			input>>IS;
			std::cout<<std::endl<<"TN "<<TN<<" IS "<<IS<<std::endl;
			input.ignore(64, '{');
			input>>tmp;
			while(tmp != "})")
			{
				FS.push_back(tmp);
				input>>tmp;
			}
			for (int i = 0; i < FS.size(); i++)
			{
				std::cout<<FS[i]<<" ";
			}
			/*std::string table [n] [y];
			std::cout<<"Table imported correctly"<<std::endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < y; j++)
				{
					input>>table[i][j];
				}
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < y; j++)
				{
					std::cout<<table[i][j]<<" ";
				}
				std::cout<<std::endl;
			}*/
		}
		else
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
}
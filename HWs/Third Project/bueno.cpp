#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
void combine (std::vector<std::string> *comb)
{

}
int main ()
{
	//infile
		std::ifstream input;
		int tp;
		char a, TN;
		std::string NFA, tmp, IS;
		std::vector <int> n;
		std::vector <std::string> states, FS;
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
			std::string table [n.size()+1] [states.size()+1];
			for (int i = 0; i <= n.size(); i++)
			{
				for (int j = 0; j <= states.size(); j++)
				{
					input>>table[i][j];
				}
			}
		}
		else
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main ()
{
	//infile
		int n, y, tmp;
		std::ifstream input;
		input.open("ex.txt");
		std::string str;
		std::string cse;
		int EA, EF;
		if (input.fail())
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
		else
		{
			input>>n;
			input >> y;
			input>>EA;
			input>>EF;
			int table [n] [y];
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
			}
			std::cout<<EA<<" "<<EF<<std::endl;
			std::cout<<"Dame la entrada > ";
			std::cin>>str;
			for (int i = 0; i < str.size(); i++)
			{
				tmp=str[i]-48;
				EA=table[tmp+1][EA];
				std::cout<<tmp<<" "<<EA<<std::endl;
			}
			if (EA==EF)
				std::cout<<"ACEPTADO"<<std::endl;
			else
				std::cout<<"RECHAZADO"<<std::endl;
		}
}
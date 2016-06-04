#include <iostream>
#include <string>
bool tc(std::string x);
int main ()
{
	std::string x;
	std::cout<<"Enter a phrase"<<std::endl;
	std::getline (std::cin,x);
	if (tc(x))
		std::cout<<"TRUE"<<std::endl;
	else
		std::cout<<"FALSE"<<std::endl;
}
bool tc (std::string x)
{
	std::string f = "computacion";
	std::size_t found = x.find(f);
	if (found!=std::string::npos)
		return true;
	return false;
}
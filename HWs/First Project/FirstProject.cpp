#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main ()
{
	std::ifstream input;
	int tmp, ltmp;
	int x;
	bool unique=true;
	bool Reflexive = true;
	bool Transitive = true;
	bool Symmetric = true;
	std::vector <int> pairs;
	std::vector <int> members;

	input.open("relations.txt");

	if (input.fail())
	{
		std::cout<<"Fatal Error, unable to open file"<<std::endl;
	}
	input >> x;
	std::cout<<x<<std::endl;
	//Reads all the pairs from the file
	for (int i=1;i<=x;i++)
	{
		for (int j=0;j<2;j++)
		{
			input>>tmp;
			pairs.push_back(tmp);
		}
	}
	/*for (int j=0;j<pairs.size();)
	{
		std::cout<<pairs[j]<<" "<<pairs[j++]<<std::endl;
		j++;
	}*/
	//detects all the members of the relation
	for (int j=0;j<pairs.size();j++)
	{
		tmp=pairs[j];
		unique=true;
		for(int k=0; k<members.size();k++)
		{
			if (tmp==members[k])
			{
				k=members.size();
				unique=unique*false;
			}
			else
				unique=unique*true;
		}
		if (unique)
			members.push_back(tmp);
	}
	//prints the members of the relation
	std::cout<<"El conjunto S es: {"<<members[0];
	for(int i=1;i<members.size();i++)
	{
		std::cout<<", "<<members[i];
	}
	std::cout<<"}"<<std::endl;

	//Reflexive test
	for (int i=0; i<members.size();i++)
	{
		tmp=members[i];
		//std::cout<<tmp<<std::endl;
		for (int j=0;j<pairs.size(); j++)
		{
			if(tmp==pairs[j] && tmp==pairs[j+1])
				Reflexive=Reflexive*true;
			else
			{
				if (j==(pairs.size()-2))
					Reflexive=Reflexive*false;
			}
			//std::cout<<pairs[j]<<pairs[j+1]<<std::endl;
			j++;
		}
	}
	if (Reflexive)
		std::cout<<"REFLEXIVE"<<std::endl;
	else
		std::cout<<"IRREFLEXIVE"<<std::endl;
	/*//Transitive test
	for (int i=0; i<pairs.size();i++)
	{
		ltmp=pair
		tmp=pair[i+1];
		if(tmp==pair[i])
		{
			for (int j = 0; j < pairs.size(); i++)
			{
				/* code
			}
		}
	}
	if (Reflexive)
		std::cout<<"REFLEXIVE"<<std::endl;
	else
		std::cout<<"IRREFLEXIVE"<<std::endl;*/

}
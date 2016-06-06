#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool Reflexive (std::vector<int> pairs, std::vector<int> members);
bool Transitive (std::vector<int> pairs, std::vector<int> members);
bool Symmetric (std::vector<int> pairs, std::vector<int> members);

int main ()
{
	std::ifstream input;
	int tmp;
	int x;
	bool unique=true;
	std::vector <int> pairs;
	std::vector <int> members;

	input.open("relations.txt");

	if (input.fail())
	{
		std::cout<<"Fatal Error, unable to open file"<<std::endl;
	}
	input >> x;
	//Reads all the pairs from the file
	for (int i=1;i<=x;i++)
	{
		for (int j=0;j<2;j++)
		{
			input>>tmp;
			pairs.push_back(tmp);
		}
	}
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

	//prints the properties that the relation meets
	std::cout << "La relacion es: " <<( (Reflexive(pairs, members)) ? "REFLEXIVA " : "IRREFLEXIVA ") <<( (Transitive(pairs, members)) ? "TRANSITIVA " : "")<<( (Symmetric(pairs, members)) ? "SIMETRICA " : "ASIMETRICA ")<< std::endl;
	if(!Reflexive && !Transitive && !Symmetric)
		std::cout<< "“NO CUMPLE NINGUNA" <<std::endl;

}
bool Reflexive (std::vector<int> pairs, std::vector<int> members)
{
	//Reflexive test
	bool Reflexive = true;
	int tmp, ltmp;
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
	return Reflexive;
}
bool Transitive (std::vector<int> pairs, std::vector<int> members)
{
	//Transitive test
	bool Transitive = true;
	int fpair, spair;
	for (int i=0; i<pairs.size()-1;i++)
	{
		fpair=pairs[i];
		spair=pairs[i+1];
		//std::cout<<"Pair "<<fpair<<", "<<spair<<std::endl;
		for (int j=0; j<pairs.size()-1;j++)
		{
			if(spair==pairs[j])
			{
				spair=pairs[j+1];
				//std::cout<<"Looking for pair "<<fpair<<", "<<spair<<std::endl;
				for (int k=0;k<pairs.size(); k++)
				{
					if(fpair==pairs[k] && spair==pairs[k+1])
					{
						Transitive=Transitive*true;
						//std::cout<<"FOUND!"<<std::endl; 
						j=pairs.size();
						i++;
						i++;
					}
					else
					{
						if (k==(pairs.size()-2))
						{
							Transitive=Transitive*false;
							//std::cout<<"NOT FOUND!"<<std::endl;
						}
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return Transitive;
}
bool Symmetric (std::vector<int> pairs, std::vector<int> members)
{
	//Symmetric test
	bool Symmetric = true;
	int fpair, spair;
	for (int i=0;i<pairs.size();i++)
	{
		fpair=pairs[i];
		spair=pairs[i+1];
		//std::cout<<"Looking for pair "<<spair<<", "<<fpair<<std::endl;
		for (int j = 0; j < pairs.size(); j++)
		{
			if(spair==pairs[j] && fpair==pairs[j+1])
			{
				Symmetric=Symmetric*true;
				//std::cout<<"FOUND!"<<std::endl;
				j=pairs.size();
			}
			else
			{
				if(j==(pairs.size()-2))
				{
					Symmetric=Symmetric*false;
					//std::cout<<"NOT FOUND!"<<std::endl;
				}
			}
			j++;
		}
		i++;		
	}
	return Symmetric;
}
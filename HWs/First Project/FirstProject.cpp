/*
	Hector Mauricio Gonzalez Coello
	A01328258
	ITC
	6/6/2016
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool Reflexive (std::vector<int> pairs, std::vector<int> members);
bool Irreflexive (std::vector<int> pairs, std::vector<int> members);
bool Transitive (std::vector<int> pairs);
bool Asymmetric (std::vector<int> pairs);
bool Symmetric (std::vector<int> pairs);

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
	std::cout << "La relacion es: " <<( (Reflexive(pairs, members)) ? "REFLEXIVA " : "") << ( (Irreflexive(pairs, members)) ? "IRREFLEXIVA " : "") << ( (Transitive(pairs)) ? "TRANSITIVA " : "")<<( (Symmetric(pairs)) ? "SIMETRICA " : "")<<( (Asymmetric(pairs)) ? "ASIMETRICA " : "")<< std::endl;
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
		for (int j=0;j<pairs.size(); j++)
		{
			if(tmp==pairs[j] && tmp==pairs[j+1])
				Reflexive=Reflexive*true;
			else
			{
				if (j==(pairs.size()-2))
					Reflexive=Reflexive*false;
			}
			j++;
		}
	}
	return Reflexive;
}
bool Irreflexive (std::vector<int> pairs, std::vector<int> members)
{
	//Irreflexive test
	bool Irreflexive = true;
	int tmp, ltmp;
	for (int i=0; i<members.size();i++)
	{
		tmp=members[i];
		for (int j=0;j<pairs.size(); j++)
		{
			if(tmp!=pairs[j] && tmp!=pairs[j+1])
			{
				Irreflexive=Irreflexive*true;
			}

			else
			{
				if (j==(pairs.size()-2))
					Irreflexive=false;
			}
			j++;
		}
	}
	return Irreflexive;

}

bool Transitive (std::vector<int> pairs)
{
	//Transitive test
	bool Transitive = true;
	int fpair, spair;
	for (int i=0; i<pairs.size()-1;i++)
	{
		fpair=pairs[i];
		spair=pairs[i+1];
		for (int j=0; j<pairs.size()-1;j++)
		{
			if(spair==pairs[j])
			{
				spair=pairs[j+1];
				for (int k=0;k<pairs.size(); k++)
				{
					if(fpair==pairs[k] && spair==pairs[k+1])
					{
						Transitive=Transitive*true;
						k=pairs.size();
						i++;
						i++;
					}
					else
					{
						if (k==(pairs.size()-2))
						{
							Transitive=Transitive*false;
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

bool Symmetric (std::vector<int> pairs)
{
	//Symmetric test
	bool Symmetric = true;
	int fpair, spair;
	for (int i=0;i<pairs.size();i++)
	{
		fpair=pairs[i];
		spair=pairs[i+1];
		for (int j = 0; j < pairs.size(); j++)
		{
			if(spair==pairs[j] && fpair==pairs[j+1])
			{
				Symmetric=Symmetric*true;
				break;
			}
			else
			{
				if(j==(pairs.size()-2))
				{
					Symmetric=false;
					break;
				}
			}
			j++;
		}
		i++;		
	}
	return Symmetric;
}
bool Asymmetric (std::vector<int> pairs)
{
	bool Asymmetric = true;
	int fpair, spair;
	for (int i=0;i<pairs.size();i++)
	{
		fpair=pairs[i];
		spair=pairs[i+1];
		for (int j = 0; j < pairs.size(); j++)
		{
			if(spair!=pairs[j] || fpair!=pairs[j+1])
			{
				Asymmetric=Asymmetric*true;
			}
			else
			{
				if(j==(pairs.size()-2))
				{
					Asymmetric=false;
					break;
				}
			}
			j++;
		}
		i++;		
	}
	return Asymmetric;
}
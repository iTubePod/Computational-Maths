#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 
sint sol (std::string x)
{
	for (int k=0; k < rs[j].size(); k++)
	{
		if(tmp[k]=='u'||tmp[k]=='v'||tmp[k]=='w'||tmp[k]=='x'||tmp[k]=='y'||tmp[k]=='z')
			return k;
	}	
}

int main ()
{
	//Reading from file
		int b, r;
		std::string base, tmp, otmp;
		std::vector <std::string> bc, rs, lang, out, vtmp, ptmp;
		std::vector<int> sol;
		int n;
		std::ifstream input;
		input.open("definitions.txt");
		if (input.fail())
		{
			std::cout<<"Fatal Error, unable to open file"<<std::endl;
		}
		input>>b;
		input>>r;
		if(b!=0)
		{
			for(int i=1; i<=b;i++)
			{
				input>>base;
				bc.push_back(base);
			}
		}
		else
			bc.push_back("/");
		for(int i=1; i<=r;i++)
		{
			input>>tmp;	
			rs.push_back(tmp);		
		}
		for (int i = 0; i < rs.size(); i++)
		{
			std::cout<<rs[i]<<" ";
		}
		std::cout<<std::endl;
		input>>n;
		while (! input.eof() )
		{
			input>>tmp;
			lang.push_back(tmp);
		}
	//recursive string creation
		bool inv = false;
		std::string L;
		std::cout<<"Aplicando el paso recursivo:"<<std::endl;
		vtmp=lang;
		bool cont = true;
		for (int i = 0; i <= n; i++)
		{
			inv = false;
			out.clear();
			if(i==0)
				out=bc;
			else if(i>0)
			{
				for (int j = 0; j < rs.size(); j++)
				{
					tmp=rs[j];
					for (int k = 0; k < vtmp.size(); k++)
					{
						otmp=tmp;
						for (int l = 0; l < sol.size(); l++)
						{
							otmp.replace(sol[l], sol[l]+1, vtmp[k]);
						}
						out.push_back(otmp);
					}					
				}
			}
			for (int i = 0; i < out.size(); i++)
			{
				for (int j = 0; j < out[i].size(); j++)
				{
					if(out[i][j]=='/')
						out[i].erase(j);
				}
			}
			std::sort(out.begin(), out.end());
			out.erase(std::unique(out.begin(), out.end()),out.end());
			std::cout<<i<<" veces: ";
			for (int i = 0; i < out.size(); i++)
			{
				std::cout<<out[i]<<" ";
			}
			std::cout<<std::endl;
			vtmp=out;
		}
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 

int main ()
{
	//Reading from file
		int b, r;
		std::string base, tmp;
		std::vector <std::string> bc, rs, lang, out, vtmp;
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
		int l, m;
		std::string L;
		std::cout<<"Aplicando el paso recursivo:"<<std::endl;
		vtmp=lang;
		for (int i = 0; i <= n; i++)
		{
			out.clear();
			l=0;
			m=0;
			if(i==0)
				out=bc;
			else if(i>0)
			{
					for (int j = 0; j < rs.size(); j++)
					{
						for (int k = 0; k < rs[j].size(); k++)
						{
							if(rs[j][k]=='u'||rs[j][k]=='v'||rs[j][k]=='w'||rs[j][k]=='x'||rs[j][k]=='y'||rs[j][k]=='z')
							{
								//std::cout<<"TMP: "<<tmp<<std::endl<<std::endl;
								//std::cout<<"Found "<<rs[j][k]<<" in "<<rs[j]<<" in space "<<k<<" | vtmp size "<<vtmp.size()<<std::endl;
								for (l; l < vtmp.size(); l++)
								{
									tmp=rs[j];
									tmp.erase(k,k+1);
									//std::cout<<vtmp[l]<<" + "<<rs[j]<<" = ";
									tmp = vtmp[l] + tmp;
									//std::cout<<tmp;
									out.push_back(tmp);
								}
								//std::cout<<std::endl;
							}
							else if(rs[j][k]=='0'||rs[j][k]=='1'||rs[j][k]=='2'||rs[j][k]=='3'||rs[j][k]=='4'||rs[j][k]=='5'||rs[j][k]=='6'||rs[j][k]=='7'||rs[j][k]=='8'||rs[j][k]=='9'||rs[j][k]=='/')
							{
								if(rs[j].size()>=k+1)
								{
									for (int l = k+1; l < rs[j].size(); l++)
									{
										if(rs[j][l]=='u'||rs[j][l]=='v'||rs[j][l]=='w'||rs[j][l]=='x'||rs[j][l]=='y'||rs[j][l]=='z')
										{
											//std::cout<<"TMP: "<<tmp<<std::endl<<std::endl;
											//std::cout<<"Found "<<rs[j][k]<<" in "<<rs[j]<<" in space "<<k<<" | vtmp size "<<vtmp.size()<<std::endl;
											for (m; m < vtmp.size(); m++)
											{
												tmp=rs[j];
												tmp.erase(l,l+1);
												//std::cout<<vtmp[m]<<" + "<<rs[j]<<" = ";
												tmp = tmp + vtmp[m];
												//std::cout<<tmp;
												out.push_back(tmp);
											}
											//std::cout<<std::endl;
										}	
									}
								}
								k=rs[j].size();
							}
						}						
					}
				
					std::cout<<std::endl;
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

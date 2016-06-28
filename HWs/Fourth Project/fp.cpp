#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

void rfile(std::vector<std::vector<std::string> > &in, std::vector<std::string> &var, std::vector<std::string> &end, std::string &grm, std::string &start);
void print(std::vector<std::vector<std::string> > &in, std::vector<std::string> &var, std::vector<std::string> &end, std::string &grm, std::string &start);
void test(std::string tst, std::vector<std::vector<std::string> > &gramm);

int main ()
{
	char ans = 'a';
	std::vector<std::vector<std::string> > gramm;
	std::vector<std::string> var, end;
	std::string in, grm, start;
    while (ans != 'q')
    {
        std::cout << "\n==	 Project 4 Matematicas Computacionales 	  ==";
        std::cout << "\n==	     Mauricio G. Coello A01328258      	  ==\n\n";
        std::cout << "\tl. Leer Gramatica desde archivo\n";
        std::cout << "\tc. Comprobar string\n";
        std::cout << "\tq. Salir\n";
        std::cout << "Opcion> ";
        std::cin >> ans;

        switch (ans)
        {
        	case 'l':
        		rfile(gramm, var, end, grm, start);
        		print(gramm, var, end, grm, start);
        		break;
        	case 'c':
        		std::cout<<"Dame el string a evaluar"<<std::endl;
        		std::cout<<"	>";
        		std::cin>>in;
        		break;
            case 'q':
                std::cout << "Closing..." << std::endl;
                gramm.clear();
                break;
            default:
                std::cout << "Invalid option ..." << std::endl;
                break;
        }
    }
}

void rfile(std::vector<std::vector<std::string> > &in, std::vector<std::string> &var, std::vector<std::string> &end, std::string &grm, std::string &start)
{
	std::string tmp;
	std::vector<std::string> tp;
	int n;
	std::ifstream input;
	input.open("gram.txt");
	if (!input.fail())
	{
		std::cout<<"Loading data from file..."<<std::endl;
		input.ignore(1, 'G');
		input.ignore(1, '=');
		input.ignore(1, '(');
		input.ignore(1, '{');
		input>>tmp;
		std::cout<<"First tmp"<<tmp<<std::endl;
		var.push_back(tmp);
		input>>tmp;
		while(tmp!="}")
		{
			if(tmp=="}")
			{
			}
			else
			{
				var.push_back(tmp);
			}
			input>>tmp;
		}
		input.ignore(1, '{');
		input>>tmp;
		end.push_back(tmp);
		input>>tmp;
		while(tmp!="}")
		{
			if(tmp=="}")
			{
			}
			else
			{
				end.push_back(tmp);
			}
			input>>tmp;
		}
		input>>grm;
		input>>start;
		input.ignore(64, ')');				
		for (int i = 0; i < var.size(); i++)
		{
			input>>tmp;
			tp.push_back(tmp);
			input>>tmp;
			while(tmp!="?")
			{
				if(tmp=="="||tmp=="|"||tmp=="?")
				{
				}
				else
				{
					tp.push_back(tmp);
				}
				input>>tmp;
			}
			in.push_back(tp);
			tp.clear();
		}
	}
	else
	{
		std::cout<<"Error while loading file"<<std::endl;
	}
	tp.clear();	
}
void print(std::vector<std::vector<std::string> > &in, std::vector<std::string> &var, std::vector<std::string> &end, std::string &grm, std::string &start)
{
	std::cout<<"TRANS"<<std::endl;
	for (int i = 0; i<in.size(); i++)
	{
		for (int j = 0; j< in[i].size(); j++)
		{
			std::cout<<in[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"VARS"<<std::endl;
	for (int i = 0; i<var.size(); i++)
	{
		std::cout<<var[i]<<" ";
	}
	std::cout<<std::endl<<"END"<<std::endl;
	for (int i = 0; i<end.size(); i++)
	{
		std::cout<<end[i]<<" ";
	}
	std::cout<<std::endl<<"GRM: "<<grm<<std::endl;
	std::cout<<"START: "<<start<<std::endl;
}
void test(std::string tst, std::vector<std::vector<std::string> > &gramm)
{

}

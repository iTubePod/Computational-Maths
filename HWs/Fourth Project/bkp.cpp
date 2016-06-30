#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class delta {
	public:
		char var;
		std::vector<std::string> subs;
		std::string varsearch(char var);
		delta (){}
		delta (char _var, std::vector<std::string> _subs){var=_var;}
		void setVar(char _var);
		void setSubs(std::vector<std::string> _subs);
		void printClass();
		std::vector<std::string> ifvar(char _var, bool &x);
};
std::vector<std::string> delta::ifvar(char _var, bool &x)
{
	std::vector<std::string> l;
	if (_var==var)
	{
		x=true;
		return subs;
	}
	else 
	{
		x=false;
		return l;
	}
}
void delta::setVar(char _var)
{
	var=_var;
}
void delta::setSubs(std::vector<std::string> _subs)
{
	subs=_subs;
}
void delta::printClass()
{
	std::cout<<var<<" -> ";
	for (int i = 0; i < subs.size(); i++)
	{
		std::cout<<subs[i]<<" | ";
	}
	std::cout<<std::endl;
}

void rfile(std::vector<delta> &in, std::vector<std::string> &var, char &start);
void print(std::vector<delta> &in, std::vector<std::string> &var, char &start);
void leftS(std::vector<delta> &in, std::string test, std::vector<std::string> generated, char &start);

int main ()
{
	bool test=false;
	char ans = 'a';
	std::vector<std::string> var, generated;
	std::vector<delta> delta;
	int lim;
	//std::vector<std::vector<std::string> > delta;
	std::string in;
	char start;
	std::cout << "\n==	 Project 4 Matematicas Computacionales 	  ==";
    std::cout << "\n==	     Mauricio G. Coello A01328258      	  ==\n";

    while (ans != 'q')
    {
    	std::cout<<std::endl;
        std::cout << "==	     		MENU      	  	  ==\n\n";
        std::cout << "\tl. Load grammar from file\n";
        std::cout << "\tt. Test string\n";
        std::cout << "\tq. Quit\n";
        std::cout << "Option> ";
        std::cin >> ans;
        std::cout<<std::endl;
        switch (ans)
        {
        	case 'l':
        		if(delta.size()==0)
        		{
	        		delta.clear();
	        		var.clear();
	        		rfile(delta, var, start);
        		}
        		else
        			std::cout<<"File already loaded!"<<std::endl;
        		if(test)
        			print(delta, var, start);
        		break;
        	case 't':
        		std::cout<<"Enter string to evaluate"<<std::endl;
        		std::cout<<"	>";
        		std::cin>>in;
        		std::cout<<"Give me the limit of recursions"<<std::endl;
        		std::cout<<"	>";
        		std::cin>>lim;
        		leftS(delta, in, generated, start);
        		//std::cout<<"LEFT "<<left(delta, in, "", 3, 0, start)<<std::endl;
        		break;
            case 'q':
                std::cout << "Closing..." << std::endl;
                delta.clear();
                var.clear();
                break;
            case 'd':
               
                if(!test)
                {
                	std::cout << "Enabling debug..." << std::endl;
                	test=true;
                }
                else
                {
                	std::cout << "Disabling debug..." << std::endl;
                	test=false;
                }
                break;
            default:
                std::cout << "Invalid option ..." << std::endl;
                break;
        }
    }
}

void rfile(std::vector<delta> &in, std::vector<std::string> &var, char &start)
{
	delta x;
	char l;
	std::string tmp;
	std::vector<std::string> tp;
	int n;
	std::ifstream input;
	input.open("gram.txt");
	if (!input.fail())
	{
		std::cout<<"Loading data from file .";
		input.ignore(1, 'G');
		input.ignore(1, '=');
		std::cout<<".";
		input.ignore(1, '(');
		input.ignore(1, '{');
		std::cout<<".";
		input>>tmp;
		var.push_back(tmp);
		input>>tmp;
		std::cout<<".";
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
		std::cout<<".";
		input.ignore(1, '{');
		input>>tmp;
		std::cout<<".";
		input>>tmp;
		std::cout<<".";
		while(tmp!="}")
		{
			input>>tmp;
		}
		std::cout<<".";
		input>>tmp;
		input>>start;
		std::cout<<".";
		input.ignore(64, ')');				
		for (int i = 0; i < var.size(); i++)
		{
			x=delta();
			tp.clear();
			input>>l;
			x.setVar(l);
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
			x.setSubs(tp);
			in.push_back(x);
			tp.clear();
		}
		std::cout<<".";
		std::cout<<" DONE"<<std::endl;
	}
	else
	{
		std::cout<<"Error while loading file"<<std::endl;
	}
	tp.clear();	
}
void print(std::vector<delta> &in, std::vector<std::string> &var, char &start)
{
	for (int i = 0; i < in.size(); i++)
	{
		in[i].printClass();
	}
	std::cout<<"____________________"<<std::endl;
	std::cout<<"Start "<<start<<std::endl;
}
std::vector<std::string> lookforvar(std::vector<delta> &in, char act, bool &x)
{
	std::vector<std::string> tp;
	for (int i = 0; i < in.size(); i++)
	{
		tp=in[i].ifvar(act, x);
		if(x)
		{
			x=true;
			return tp;
		}
	}
	x=false;
	return tp;
}
void leftS(std::vector<delta> &in, std::string test, std::vector<std::string> generated, char &start)
{
	std::string tmp;
	std::vector<std::string> tp;
	bool x = false;
	if(generated.size()==0)
	{
		generated.push_back(" ");
		generated[0][0]=start;
		std::cout<<generated[0]<<" -> ";
		leftS(in, test, generated, start);
	}
	else
	{
		if(generated[generated.size()-1]==test)
		{
			return;
		}
		else
		{
			for (int j = 0; j < generated[generated.size()-1].size(); j++)
			{
				x=false;
				//std::cout<<"Hola"<<std::endl;
				tp=lookforvar(in, generated[generated.size()-1][j], x);
				//std::cout<<"Adios"<<std::endl;
				if(x)
				{
					for (int l = 0; l < tp.size(); l++)
					{
						tmp=generated[generated.size()-1];
						tmp.replace(j, j+1, tp[l]);
						//std::cout<<tmp<<" -> ";
						generated.push_back(tmp);
						leftS(in, test, generated, start);
					}
				}
			}
		}
	}
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BinaryTree.h"

void menu()
{
	std::ifstream input;
	int n;
    BinaryTree<std::string> tree;
    TreeNode<std::string> * node;
    std::string str;
    char ans = 'a';
    bool found = false;

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
                std::cout << "\tLeyendo... ";
                input.open("gram.txt");
                if (!input.fail())
				{
					tree.clear();
					input>>n;
					input>>str;
					tree.insert(str);
					for(int i=0;i<n;i++)
					{
						input>>str;
						while(str!="?")
						{
							if(str=="="||str=="|"||str=="?")
							{
							}
							else
							{
							tree.insert(str);
							}
							input>>str;
						}
					}
					std::cout<<"TREE:"<<std::endl;
					tree.printInOrder();
				}
				else
				{
					std::cout<<"Error al leer archivo..."<<std::endl;
				}
                std::cout << std::endl;
                break;
            case 'c':
                std::cout << "\tEnter the new number to insert: ";
                std::cin >> str;
                break;
            case 'q':
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida ..." << std::endl;
                break;
        }
    }
}

int main()
{
    menu();
    
    return 0;
}

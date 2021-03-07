#include "Map.hpp"
#include<iostream>
#include<map>

int main()
{
	ft::map<int, char> t;
	
	t.insert(ft::pair<int, char>(5, '5'));
	t.insert(ft::pair<int, char>(3, '3'));
	t.insert(ft::pair<int, char>(2, '2'));
	t.insert(ft::pair<int, char>(4, '4'));
	t.insert(ft::pair<int, char>(10, 'Z'));
	t.insert(ft::pair<int, char>(8, '8'));
	t.insert(ft::pair<int, char>(6, '6'));
	
	t.insert(ft::pair<int, char>(9, '9'));
	t.insert(ft::pair<int, char>(20, 'M'));
	ft::map<int, char>::iterator it = t.begin();
	
	ft::map<int, char>::iterator ite = t.end();

	// while(it != ite)
	// {
	//  	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << "\n";
	// for(int i = 0; i < 3; i++)
	// 	it--;
	// std::cout << "IT to erase: " << *it << std::endl;
	// t.erase(it);
	// it = t.begin();
	// ite = t.end();
	// while(it != ite)
	// {
	//  	std::cout << *it << " ";
	// 	it++;
	// }

	ft::map<int, char> second;
	second.insert(ft::pair<int, char>(200, 'X'));
	second.insert(ft::pair<int, char>(300, 'Y'));
	second.insert(ft::pair<int, char>(400, 'Z'));
	
	// ft::map<int, char>::iterator itsec = second.begin();
	// ft::map<int, char>::iterator itesec = second.end();
	// while(itsec != itesec)
	// {
	//  	std::cout << *itsec << "\n" << std::flush;
	// 	itsec++;
	// }

	t.swap(second);

	it = t.begin();
	ite = t.end();

	std::cout << "FIRST LIST: " << std::endl;
	while(it != ite)
	{
		std::cout << *it;
		it++;
		if (it != ite)
			std::cout << " - ";
		else
			std::cout << "\n";
	}
	ft::map<int, char>::iterator itsec = second.begin();
	ft::map<int, char>::iterator itesec = second.end();
	while(itsec != itesec)
	{
	 	std::cout << *itsec;
		itsec++;
		if (itsec != itesec)
			std::cout << " - ";
		else
			std::cout << "\n";
	}

	std::cout << "found: " <<  *(second.find(4)) << std::endl;


	t.clear();
	it = t.begin();
	ite = t.end();
	while(it != ite)
	{
		std::cout << "HERE\n";
	 	std::cout << *it << " ";
		it++;
	}
	std::cout << "size: " << t.size() << std::endl;
	//std::cout << it.node() << std::endl;
	// std::map<char, char> second_real;
	// std::map<char, char> first_real;
	// first_real.swap(second_real);
}

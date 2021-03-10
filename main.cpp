#include<iostream>
#include<map>
#include "MapTest.hpp"
#include "Map.hpp"

// template <typename Key, typename T> class MapTest;

int main()
{
	MapTest<int, int> testor;
	//testor.begin();
	//testor.end();
		testor.size();
	testor.insert();
	testor.equal();
	testor.not_equal();
	testor.less();
	testor.less_or_equal();
	testor.greater();
	testor.greater_or_equal();
	testor.reverse();
	// testor.size();
	// testor.insert2();
	// testor.insert3();
	// testor.begin();
	// testor.end();
	// testor.erase();
	// testor.size();
	// testor.empty();
	// testor.max_size();
	// testor.operator_access();
	// testor.swap();
	// testor.erase2();
	// testor.erase3();
	// testor.empty();
	// testor.insert();
	
	// testor.key_compare();
	// testor.value_compare();
	// testor.find();
	// testor.count();
	// testor.lower_bound();
	// testor.upper_bound();
	// testor.equal_range();
	// testor.constructor2();
	// testor.constructor3();
	// testor.clear();

	// t.insert(ft::pair<int, int>(5, 5));
	// t.insert(ft::pair<int, int>(3, 3));
	// t.insert(ft::pair<int, int>(2, 2));
	// t.insert(ft::pair<int, int>(4, 4));
	// t.insert(ft::pair<int, int>(10, 10));
	// t.insert(ft::pair<int, int>(8, 8));
	// t.insert(ft::pair<int, int>(6, 6));
	// t.insert(ft::pair<int, int>(9, 9));
	// t.insert(ft::pair<int, int>(20, 20));
	// ft::map<int, char>::iterator it = t.begin();
	
	// ft::map<int, char>::iterator ite = t.end();

	// while(it != ite)
	// {
	//  	std::cout << *it << " ";
	// 	it++;
	// }
	// // std::cout << "\n";
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

	// ft::map<int, char> second;
	// second.insert(ft::pair<int, char>(200, 'X'));
	// second.insert(ft::pair<int, char>(300, 'Y'));
	// second.insert(ft::pair<int, char>(400, 'Z'));
	
	// // ft::map<int, char>::iterator itsec = second.begin();
	// // ft::map<int, char>::iterator itesec = second.end();
	// // while(itsec != itesec)
	// // {
	// //  	std::cout << *itsec << "\n" << std::flush;
	// // 	itsec++;
	// // }

	// t.swap(second);

	// it = t.begin();
	// ite = t.end();

	// std::cout << "FIRST LIST: " << std::endl;
	// while(it != ite)
	// {
	// 	std::cout << *it;
	// 	it++;
	// 	if (it != ite)
	// 		std::cout << " - ";
	// 	else
	// 		std::cout << "\n";
	// }
	// ft::map<int, char>::iterator itsec = second.begin();
	// ft::map<int, char>::iterator itesec = second.end();
	// while(itsec != itesec)
	// {
	//  	std::cout << *itsec;
	// 	itsec++;
	// 	if (itsec != itesec)
	// 		std::cout << " - ";
	// 	else
	// 		std::cout << "\n";
	// }

	// std::cout << "found: " <<  *(second.find(4)) << std::endl;


	// t.clear();
	// it = t.begin();
	// ite = t.end();
	// while(it != ite)
	// {
	// 	std::cout << "HERE\n";
	//  	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << "size: " << t.size() << std::endl;
	//std::cout << it.node() << std::endl;
	// std::map<char, char> second_real;
	// std::map<char, char> first_real;
	// first_real.swap(second_real);
}

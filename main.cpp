#include "Map.hpp"

int main()
{
	ft::map<int, char> t;
	
	// t.insert(ft::pair<int, char>(5, 'e'));
	// t.insert(ft::pair<int, char>(6, 'f'));
	// t.insert(ft::pair<int, char>(7, 'a'));
	// t.insert(ft::pair<int, char>(8, 'a'));
	// t.insert(ft::pair<int, char>(9, 'a'));
	// t.insert(ft::pair<int, char>(1, 'a'));
	// t.insert(ft::pair<int, char>(2, 'b'));
	
	// t.insert(ft::pair<int, char>(3, 'c'));
	// t.insert(ft::pair<int, char>(4, 'd'));

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

	while(it != ite)
	{
	 	std::cout << *it << " ";
		it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
		// it++;
		// std::cout << *it << " ";
	}
	std::cout << "\n";
	for(int i = 0; i < 3; i++)
		it--;
	std::cout << "IT to erase: " << *it << std::endl;
	t.erase(it);
	it = t.begin();
	ite = t.end();
	while(it != ite)
	{
	 	std::cout << *it << " ";
		it++;
	}
}

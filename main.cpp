#include "list.hpp"

int main()
{
	ft::List<int> list;
	//typedef ft::Iterator<ft::List<int> > iterator;
	list.push_back(33);
	ft::ListIterator<int> it = list.begin();
	std::cout << it.node()->value() << std::endl;

	ft::List<int> numbers;
 	ft::ListIterator<int> itNumbers = numbers.begin();
	ft::ListIterator<int> iteNumbers = numbers.end();
    for (;itNumbers != iteNumbers; itNumbers++)
	{
		std::cout << *itNumbers << std::endl;
	}
 
    // numbers.push_back(5);
    // numbers.push_back(3);
    // numbers.push_back(4);
	//  numbers.push_back(6);
 
 //	std::cout << "Front:" <<  numbers.front() << std::endl;
   
    numbers.pop_back();
	itNumbers = numbers.begin();
	// itNumbers++;
	
	std::cout << "nb:"<< *itNumbers << std::endl;
	iteNumbers = numbers.end();
   	for (;itNumbers != iteNumbers; ++itNumbers )
	{
		std::cout << "nb: " <<  *itNumbers << std::endl;
		
	}
//	std::cout << "back:" << numbers.back() << std::endl;
   
}
// template <typename T>
// void testList(void)
// {
//     std::list<T> lBase;
//     ft::List<T> lCustom;

//     /* Test size(), front(), back() and element comparison at initialization */
//     std::cout << std::endl << "======= TEST 1 =======" << std::endl;
//     (lBase.size() == lCustom.size()) ? fOK("size()") : fKO("size()");
//     (lBase.front() == lCustom.front()) ? fOK("front()") : fKO("front()");
//     (lBase.back() == lCustom.back()) ? fOK("back()") : fKO("back()");
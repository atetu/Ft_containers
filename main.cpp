#include "list.hpp"
#include <list>
#include <iostream>
#include "ListTest.hpp"

// template<typename T>
// void setList(T* array)
// {
// 	ft::List<T> ft_list;
// 	std::list<T> list;
// 	int i = 0;

// 	while (array[i])
// 	{
// 		ft_list.push_back(array[i]);
// 		list.push_back(array[i]);
// 		i++;
// 	}
// }

// template<typename T>
// void checkPushBack(ft::List<T> ft_list,std::list<T> list)
// {
// 	ft::ListIterator<typename T> itFtList = ft_list.begin();
// 	ft::ListIterator<typename T> iteFtList = ft_list.end();
// 	ft::ListIterator<typename T> itList = ist.begin();
// 	ft::ListIterator<typename T> iteList = list.end();

// 	while (itFtList != iteFtList && itList != iteList)
// 	{
// 		if (*itFtList != *iteFtList)
// 		{
// 			std::cout << "Error with CheckPush"<< std::endl;
// 			return
// 		}
// 		itFtList++;
// 		iteFtList++;
// 	}
// 	if (itFtList != iteFtList || itList != iteList)
// 	{
// 		std::cout << "Error with CheckPush"<< std::endl;
// 	}
// }

int main()
{
	int array[6] ={0, 1, 2, 3, 4, 5};
	std::cout << "INITIALISATION - LIST<INT>(0, 1, 2, 3, 4, 5)\n";
	ListTest<int> testor(array, 6);
	testor.checkIdenticalLists("INIT");
	testor.begin();
	testor.end();
	testor.front();
	testor.back();
	testor.empty();
	testor.size();
	// testor.assign();
	testor.push_back();
	testor.pop_back();
	testor.init(array, 6);
	testor.insert();
	testor.insert2();
	testor.erase();
	testor.erase2();
	testor.clear();
	

	

	//typedef ft::Iterator<ft::List<int> > iterator;
// 	list.push_back(33);
// 	ft::ListIterator<int> it = list.begin();
// 	std::cout << it.node()->value() << std::endl;

// 	ft::List<int> numbers;
//  	ft::ListIterator<int> itNumbers = numbers.begin();
// 	ft::ListIterator<int> iteNumbers = numbers.end();
//     for (;itNumbers != iteNumbers; itNumbers++)
// 	{
// 		std::cout << *itNumbers << std::endl;
// 	}
 
//     numbers.push_back(5);
//     numbers.push_back(3);
//     numbers.push_back(4);
// 	numbers.push_back(6);
 
//  	std::cout << "Front:" <<  numbers.front() << std::endl;
   
//     //numbers.pop_back();
// 	itNumbers = numbers.begin();
// //	itNumbers++;
	
// //	std::cout << "nb:"<< *itNumbers << std::endl;
// 	iteNumbers = numbers.end();
//    	for (;itNumbers != iteNumbers; ++itNumbers )
// 	{
// 		std::cout << "nb: " <<  *itNumbers << std::endl;
		
// 	}
// 	std::cout << "back:" << numbers.back() << std::endl;

// 	numbers.pop_back();
//  	 itNumbers = numbers.begin();
// //	itNumbers++;
	
// //	std::cout << "nb:"<< *itNumbers << std::endl;
// 	iteNumbers = numbers.end();
//    	for (;itNumbers != iteNumbers; ++itNumbers )
// 	{
// 		std::cout << "nb: " <<  *itNumbers << std::endl;
		
// 	}
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
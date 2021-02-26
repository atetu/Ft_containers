#include "list.hpp"
#include <list>
#include <iostream>
#include "ListTest.hpp"
#include "VectorTest.hpp"

bool mycomparison (int first, double second)
{
	return (int(first)<int(second));
}
		
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


void listTestor()
{
	int array[6] ={0, 1, 2, 3, 4, 5};
	std::cout << "INITIALISATION - LIST<INT>(0, 1, 2, 3, 4, 5)\n";
	ListTest<int> testor(array, 6);
	if (testor.checkIdenticalLists("INIT"))
		ListTest<int>::print("INIT2", "OK");
	testor.begin();
	testor.end();
	testor.front();
	testor.back();
	testor.empty();
	testor.size();
	testor.push_front();
	testor.push_back();
	testor.pop_back();
	testor.pop_front();
	testor.init(array, 6);
	testor.resize();
	testor.insert();
	testor.insert2();
	testor.erase();
	testor.erase2();
	testor.splice();
	testor.sort();
	testor.merge();
	testor.reverse();
	testor.rendIncrement();
	testor.maxSize();
	testor.clear();

// ft::list<int> ftl(24, 3);
	ListTest<int> testor2(24, 3);
	if (testor2.checkIdenticalLists("INIT2"))
		ListTest<int>::print("INIT2", "OK");

	ListTest<int> testor3(3, 24, 3, 7);
	if (testor3.checkIdenticalLists("INIT3"))
		ListTest<int>::print("INIT3", "OK");
	
	ListTest<int> testor4(3, 24, "copy");
	if (testor4.checkIdenticalLists("INIT4"))
		ListTest<int>::print("INIT4", "OK");

	// ListTest<int> testor3(24, 3);
	// if (testor2.checkIdenticalLists("INIT2"))
	// 	ListTest<int>::print("INIT2", "OK");

	std::list<int> first;
	std::list<int> second;
	ft::list<int> ft_first;
	ft::list<int> ft_second;
	first.push_back(5);
	first.push_back(44);
	first.push_back(35);
	second.push_back(6);
	second.push_back(36);
	second.push_back(21);
	second.push_back(2);
	ft_first.push_back(5);
	ft_first.push_back(44);
	ft_first.push_back(35);
	ft_second.push_back(6);
	ft_second.push_back(36);
	ft_second.push_back(21);
	ft_second.push_back(2);
	swap(first, second);
	ft::swap(ft_first, ft_second);
	if(ListTest<int>::checkIdenticalLists(first, ft_first, "SWAP", 0))
		ListTest<int>::print("SWAP", "OK");
	if(ListTest<int>::checkIdenticalLists(second, ft_second, "SWAP2", 0))
		ListTest<int>::print("SWAP2", "OK");

	if ((ft_first < ft_second) == (first < second))
		ListTest<int>::print("<", "OK");
	if ((ft_first == ft_second) == (first == second))
		ListTest<int>::print("==", "OK");
	if ((ft_first != ft_second) == (first != second))
		ListTest<int>::print("!=", "OK");
	if ((ft_first <= ft_second) == (first <= second))
		ListTest<int>::print("<=", "OK");
	if ((ft_first > ft_second) == (first > second))
		ListTest<int>::print(">", "OK");
	if ((ft_first >= ft_second) == (first >= second))
		ListTest<int>::print(">=", "OK");
}

void vectorTestor()
{
// 	std::vector<int> vec;
// 	std::vector<int>::iterator it = vec.begin();
// std::cout << "True it : " << *it<< std::endl;
// 	std::cout << "VECTOR TEST\n";
	VectorTest<int> testor1;
	VectorTest<int> testor2(24, 3);
	VectorTest<int> testor3(3, 24, 3, 7);
	VectorTest<int> testor4(3, 24, "copy");
	testor4.size();
	testor4.maxSize();
	testor4.capacity();
	testor4.resize();
	testor4.empty();
	testor3.push_back();
	testor3.insert();
	testor3.insert1();
	// testor3.insert2();

	// int array[6] ={0, 1, 2, 3, 4, 5};
	// std::cout << "INITIALISATION - LIST<INT>(0, 1, 2, 3, 4, 5)\n";
	// VectorTest<int> testor(array, 6);
	// if (testor.checkIdenticalLists("INIT"))
	// 	VectorTest<int>::print("INIT2", "OK");
	// testor.begin();
	// testor.end();
	// testor.front();
	// testor.back();
	// testor.empty();
	// testor.size();
	// testor.push_front();
	// testor.push_back();
	// testor.pop_back();
	// testor.pop_front();
	// testor.init(array, 6);
	// testor.resize();
	// testor.insert();
	// testor.insert2();
	// testor.erase();
	// testor.erase2();
	// testor.splice();
	// testor.sort();
	// testor.merge();
	// testor.reverse();
	// testor.rendIncrement();
	// testor.maxSize();
	// testor.clear();
}

int main()
{
	// listTestor();
	vectorTestor();
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
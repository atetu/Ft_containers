// #include "list.hpp"
// #include <list>
#include <iostream>
#include "ListTest.hpp"
#include "VectorTest.hpp"
// #include "DequeTest.hpp"
#include "MapTest.hpp"
// #include "Map.hpp"

bool mycomparison (int first, double second)
{
	return (int(first)<int(second));
}
		

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
	VectorTest<int> testor1;
	VectorTest<int> testor2(24, 3);
	VectorTest<int> testor3(3, 24, 3, 7);
	VectorTest<int> testor4(3, 24, "copy");
	
	testor4.begin();
	testor4.end();
	testor4.beginconst();
	testor4.endconst();
	testor4.size();
	testor4.maxSize();
	testor4.capacity();
	testor4.resize();
	testor4.empty();
	testor3.push_back();
	testor3.pop_back();
	testor3.insert();
	testor3.insert1();
	testor3.insert2();
	testor3.swap();
	testor3.operator_access();
	testor3.at();
	testor3.front();
	testor3.back();
	testor3.erase();
	testor3.erase2();

	
	

	std::vector<int> first;
	std::vector<int> second;
	ft::vector<int> ft_first;
	ft::vector<int> ft_second;
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
	if(VectorTest<int>::checkIdenticalvectors(first, ft_first, "SWAP", 0))
		VectorTest<int>::print("SWAP", "OK");
	if(VectorTest<int>::checkIdenticalvectors(second, ft_second, "SWAP2", 0))
		VectorTest<int>::print("SWAP2", "OK");

	if ((ft_first < ft_second) == (first < second))
		VectorTest<int>::print("<", "OK");
	if ((ft_first == ft_second) == (first == second))
		VectorTest<int>::print("==", "OK");
	if ((ft_first != ft_second) == (first != second))
		VectorTest<int>::print("!=", "OK");
	if ((ft_first <= ft_second) == (first <= second))
		VectorTest<int>::print("<=", "OK");
	if ((ft_first > ft_second) == (first > second))
		VectorTest<int>::print(">", "OK");
	if ((ft_first >= ft_second) == (first >= second))
		VectorTest<int>::print(">=", "OK");
}

void dequeTestor()
{
	DequeTest<int> testor1;
	DequeTest<int> testor2(24, 3);
//	std::cout << "start\n" << std::flush;
	DequeTest<int> testor3(3, 24, 3, 7);
	DequeTest<int> testor4(3, 24, "copy");

// 	testor2.push_back();
// 	testor2.pop_back();
// 	testor1.push_front();
	// testor1.pop_back();
	// std::deque<int> deq;
	// deq.push_back(56);
	// deq.push_back(90);
	// deq.pop_front();
	// std::deque<int>::iterator it = deq.begin();
	// // it--;
	// std::cout << *it << std::endl;
	// deq.push_back(1000);
	// deq.pop_back();
	// deq.push_front(21);
	// deq.push_front(31);
	// deq.push_front(500);
	// deq.pop_front();
	// std::deque<int>::iterator it = deq.begin();
	// it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// 	it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// std::cout << *it << std::endl;
	// it--;
	// std::cout << *it << std::endl;
	// 	it--;
	// int n = 0;
	// while(*it == 0)
	// {
	// 	it--;
	// 	n++;
	// 	std::cout << "HERE\n";
	// }
	// std::cout << *it << std::endl;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
}

void mapTestor()
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
	testor.reverse_relational();
	testor.size();
	testor.insert2();
	testor.insert3();
	testor.begin();
	testor.end();
	testor.erase();
	testor.size();
	testor.empty();
	testor.max_size();
	testor.operator_access();
	testor.swap();
	testor.erase2();
	testor.erase3();
	testor.empty();
	testor.insert();
	
	testor.key_compare();
	testor.value_compare();
	testor.find();
	testor.count();
	testor.lower_bound();
	testor.upper_bound();
	testor.equal_range();
	testor.constructor2();
	testor.constructor3();
	testor.clear();
}

int main()
{
	listTestor();
	vectorTestor();
	dequeTestor();

	mapTestor();
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
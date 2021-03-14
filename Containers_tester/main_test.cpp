#include <iostream>
#include <list>
#include <vector>
#include <map>

#define	assert(e) \
    (__builtin_expect(!(e), 0) ? __assert_rtn(__func__, __FILE__, __LINE__, #e) : (void)0)

int main ()
{
//   std::list<int> mylist;
//   for (int i=1; i<=5; ++i) mylist.push_back(i);
// 	std::list<int>::reverse_iterator rit=mylist.rbegin();
// 	std::cout << *rit << std::endl;
// 	++rit;
// 	std::cout << *rit << std::endl;
// 		++rit;
// 	std::cout << *rit << std::endl;
//   std::cout << "mylist backwards:";
//   for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
//     std::cout << ' ' << *rit;

//   std::cout << '\n';

	//std::vector<int> vector;
	//assert(vector.size() == 0);
	// vector.push_back(5);
	// assert(vector.size() == 1);
	// int n = 0;
	// for (int i = 0; i < 14; ++i)
	// { 
	// 	n++;
	// 	vector.push_back(45); 
	// }
	// std::cout << "Cap[acity: " << vector.capacity() <<  " - n: " << n << std:: endl;
	// //ssert(vector.capacity() == 1);
	// vector.assign(2, 50);
	// assert(vector.size() == 2);

	typedef std::map<int, int>::iterator iterator;
//	typedef typename Map::const_iterator const_iterator;
	std::map<int, int> map;
	for (int i = 0; i < 10; ++i)
	{
		map[i] = i * 5;
	}
	iterator lb = map.lower_bound(5);
	iterator ub = map.upper_bound(5);
	// const_iterator clb = map.lower_bound(5);
	// const_iterator cub = map.upper_bound(5);
	std::pair<iterator, iterator> er = map.equal_range(5);
	//std::pair<const_iterator, const_iterator> cer = map.equal_range(5);
	std::cout << "LB : " << lb->second << std::endl;
	assert(lb->second == 25);
  return 0;
}
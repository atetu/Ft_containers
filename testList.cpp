#include <list>
#include "../includes/sequence_containers/List.hpp"
#include "test.hpp"

template <typename T>
void testBasics(const std::list<T>& lBase, const ft::List<T>& lCustom)
{
    (lBase.size() == lCustom.size()) ? fOK("size()") : fKO("size()");
    (lBase.front() == lCustom.front()) ? fOK("front()") : fKO("front()");
    (lBase.back() == lCustom.back()) ? fOK("back()") : fKO("back()");

    typename std::list<T>::const_iterator itBase = lBase.begin();
    typename ft::List<T>::const_iterator itCustom = lCustom.begin();
    if (lCustom.size() > 0)
    {
        while (itBase != lBase.end() && itCustom != lCustom.end())
        {
            if (*itBase != *itCustom)
            {
                fKO("list's elements comparison");
                break;
            }
            itBase++;
            itCustom++;
        }
        if (itBase != lBase.end() || itCustom != lCustom.end())
            fKO("list's elements number");
        else
            fOK("list's elements");
    }
}

template <typename T>
void testRelationalOperators(const std::list<T>& lBase, const std::list<T>& cmp_lBase,
                            const ft::List<T>& lCustom, const ft::List<T>& cmp_lCustom)
{
    ((lBase == cmp_lBase) == (lCustom == cmp_lCustom)) ? fOK("==") : fKO("==");
    ((lBase != cmp_lBase) == (lCustom != cmp_lCustom)) ? fOK("!=") : fKO("!=");
    ((lBase < cmp_lBase) == (lCustom < cmp_lCustom)) ? fOK("<") : fKO("<");
    ((lBase <= cmp_lBase) == (lCustom <= cmp_lCustom)) ? fOK("<=") : fKO("<=");
    ((lBase > cmp_lBase) == (lCustom > cmp_lCustom)) ? fOK(">") : fKO(">");
    ((lBase >= cmp_lBase) == (lCustom >= cmp_lCustom)) ? fOK(">=") : fKO(">=");
}

template <typename T>
void testIterator(std::list<T> lBase, ft::List<T> lCustom)
{
    bool verif = true;
    typename std::list<T>::iterator itBase;
    typename ft::List<T>::iterator itCustom;
    itBase = lBase.begin();
    itCustom = lCustom.begin();

    (*(lBase.begin()) == *(lCustom.begin())) ? fOK("begin()") : fKO("begin()");
    (*(lBase.cbegin()) == *(lCustom.cbegin())) ? fOK("cbegin()") : fKO("cbegin()");
    (*(--lBase.end()) == *(--lCustom.end())) ? fOK("end()") : fKO("end()");
    (*(--lBase.cend()) == *(--lCustom.cend())) ? fOK("cend()") : fKO("cend()");

    while (itBase != lBase.end())
    {
        if (*itBase++ != *itCustom++)
            verif = false;
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    itBase = --lBase.end();
    itCustom = --lCustom.end();
    while (itBase != lBase.begin())
    {
        if (*itBase-- != *itCustom--)
            verif = false;
    }
    (verif == true) ? fOK("Operator--(int)") : fKO("Operator--(int)");

    verif = true;
    itBase = lBase.begin();
    itCustom = lCustom.begin();
    while (itBase != --lBase.end())
    {
        if (*++itBase != *++itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    verif = true;
    itBase = lBase.end();
    itCustom = lCustom.end();
    while (itBase != lBase.begin())
    {
        if (*--itBase != *--itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator--()") : fKO("Operator--()");

    ((lBase.begin() == lBase.begin()) == (lCustom.begin() == lCustom.begin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((lBase.begin() != lBase.begin()) == (lCustom.begin() != lCustom.begin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
}


template <typename T>
void testReverseIterator(std::list<T> lBase, ft::List<T> lCustom)
{
    bool verif = true;
    typename std::list<T>::reverse_iterator itBase;
    typename ft::List<T>::reverse_iterator itCustom;
    itBase = lBase.rbegin();
    itCustom = lCustom.rbegin();

    (*(lBase.rbegin()) == *(lCustom.rbegin())) ? fOK("rbegin()") : fKO("rbegin()");
    (*(lBase.crbegin()) == *(lCustom.crbegin())) ? fOK("crbegin()") : fKO("crbegin()");
    (*(--lBase.rend()) == *(--lCustom.rend())) ? fOK("rend()") : fKO("rend()");
    (*(--lBase.crend()) == *(--lCustom.crend())) ? fOK("crend()") : fKO("crend()");

    while (itBase != lBase.rend())
    {
        if (*itBase++ != *itCustom++)
            verif = false;
    }
    (verif == true) ? fOK("Operator++(int)") : fKO("Operator++(int)");

    verif = true;
    itBase = --lBase.rend();
    itCustom = --lCustom.rend();
    while (itBase != lBase.rbegin())
    {
        if (*itBase-- != *itCustom--)
            verif = false;
    }
    (verif == true) ? fOK("Operator--(int)") : fKO("Operator--(int)");

    verif = true;
    itBase = lBase.rbegin();
    itCustom = lCustom.rbegin();
    while (itBase != --lBase.rend())
    {
        if (*++itBase != *++itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator++()") : fKO("Operator++()");

    verif = true;
    itBase = lBase.rend();
    itCustom = lCustom.rend();
    while (itBase != lBase.rbegin())
    {
        if (*--itBase != *--itCustom)
            verif = false;
    }
    (verif == true) ? fOK("Operator--()") : fKO("Operator--()");

    ((lBase.rbegin() == lBase.rbegin()) == (lCustom.rbegin() == lCustom.rbegin())) ? fOK("Operator==()") : fKO("Operator==()");
    ((lBase.rbegin() != lBase.rbegin()) == (lCustom.rbegin() != lCustom.rbegin())) ? fOK("Operator!=()") : fKO("Operator!=()"); 
}


bool remove_function_int(const int& val) {
    return (val == 3);
}

bool unique_function_int(const int& val1, const int& val2) {
    return (val1 == val2);
}

template <typename T>
void testList(void)
{
    std::list<T> lBase;
    ft::List<T> lCustom;

    /* Test size(), front(), back() and element comparison at initialization */
    std::cout << std::endl << "======= TEST 1 =======" << std::endl;
    (lBase.size() == lCustom.size()) ? fOK("size()") : fKO("size()");
    (lBase.front() == lCustom.front()) ? fOK("front()") : fKO("front()");
    (lBase.back() == lCustom.back()) ? fOK("back()") : fKO("back()");

    
    /* Test max_size() */
    std::cout << std::endl << "======= TEST 2 =======" << std::endl;
    (lBase.max_size() == lCustom.max_size()) ? fOK("max_size()") : fKO("max_size()");


    /* Test size(), front(), back() and element comparison 
    after adding one element with push_front() */
    lBase.push_front(33);
    lCustom.push_front(33);
    std::cout << std::endl << "======= TEST 3 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison 
    after adding one element with push_back() */
    lBase.push_back(44);
    lCustom.push_back(44);
    std::cout << std::endl << "======= TEST 4 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison 
    after pop_front() */
    lBase.pop_front();
    lCustom.pop_front();
    std::cout << std::endl << "======= TEST 5 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison 
    after pop_back() */
    lBase.pop_back();
    lCustom.pop_back();
    std::cout << std::endl << "======= TEST 6 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison after superior resize() */
    lBase.resize(10);
    lCustom.resize(10);
    std::cout << std::endl << "======= TEST 7 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison after clear() */
    lBase.clear();
    lCustom.clear();
    std::cout << std::endl << "======= TEST 8 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison after inferior resize() */
    for (int count = 0; count < 10; count++)
    {
        lBase.push_back(count);
        lCustom.push_back(count);
    }
    lBase.resize(5);
    lCustom.resize(5);
    std::cout << std::endl << "======= TEST 9 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), front(), back() and element comparison after equal resize() */
    lBase.resize(5);
    lCustom.resize(5);
    std::cout << std::endl << "======= TEST 10 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test empty() before clear() */
    std::cout << std::endl << "======= TEST 11 =======" << std::endl;
    (lBase.empty() == lCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test empty() after clear() */
    lBase.clear();
    lCustom.clear();
    std::cout << std::endl << "======= TEST 12 =======" << std::endl;
    (lBase.empty() == lCustom.empty()) ? fOK("empty()") : fKO("empty()");


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with n value (1) */
    lBase.assign(1, 15);
    lCustom.assign(1, 15);
    std::cout << std::endl << "======= TEST 13 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with n value (100) */
    lBase.assign(100, 15);
    lCustom.assign(100, 15);
    std::cout << std::endl << "======= TEST 14 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with another list's iterators */
    std::list<T> lBase2;
    for (int count = 0; count < 5; count++)
        lBase2.push_back(count);
    typename std::list<T>::iterator it = lBase2.end();
    it--;
    it--;
    lBase.assign(lBase2.begin(), it);
    lCustom.assign(lBase2.begin(), it);
    std::cout << std::endl << "======= TEST 15 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after assign() with same list's iterators */
    typename std::list<T>::iterator itBase = lBase.begin();
    itBase++;
    itBase++;
    typename ft::List<T>::iterator itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.assign(itBase, (lBase.end()));
    lCustom.assign(itCustom, (lCustom.end()));
    std::cout << std::endl << "======= TEST 16 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison after pop_back() */
    lBase.pop_back();
    lCustom.pop_back();
    std::cout << std::endl << "======= TEST 17 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at begin() */
    lBase.clear();
    lCustom.clear();
    lBase.insert(lBase.begin(), 3);
    lCustom.insert(lCustom.begin(), 3);
    lBase.insert(lBase.begin(), 4);
    lCustom.insert(lCustom.begin(), 4);
    std::cout << std::endl << "======= TEST 18 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at end() */
    lBase.insert(lBase.end(), 5);
    lCustom.insert(lCustom.end(), 5);
    lBase.insert(lBase.end(), 6);
    lCustom.insert(lCustom.end(), 6);
    std::cout << std::endl << "======= TEST 19 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() at begin() + 2 */
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.insert(itBase, 1);
    lCustom.insert(itCustom, 1);
    std::cout << std::endl << "======= TEST 20 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() */
    lBase.clear();
    lCustom.clear();
    lBase.insert(lBase.begin(), 2, 4);
    lCustom.insert(lCustom.begin(), 2, 4);
    lBase.insert(lBase.begin(), 2, 3);
    lCustom.insert(lCustom.begin(), 2, 3);
    std::cout << std::endl << "======= TEST 21 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() */
    lBase.insert(lBase.begin(), 0, 5);
    lCustom.insert(lCustom.begin(), 0, 5);
    std::cout << std::endl << "======= TEST 22 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at end() */
    lBase.insert(lBase.end(), 10, 5);
    lCustom.insert(lCustom.end(), 10, 5);
    lBase.insert(lBase.end(), 10, 6);
    lCustom.insert(lCustom.end(), 10, 6);
    std::cout << std::endl << "======= TEST 23 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements at begin() + 2 */
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.insert(itBase, 4, 1);
    lCustom.insert(itCustom, 4, 1);
    std::cout << std::endl << "======= TEST 24 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from another vector at begin() */
    lBase.clear();
    lCustom.clear();
    lBase.insert(lBase.begin(), lBase2.begin(), lBase2.end());
    lCustom.insert(lCustom.begin(), lBase2.begin(), lBase2.end());
    std::cout << std::endl << "======= TEST 25 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from another vector at begin() + 2 */
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.insert(itBase, lBase2.begin(), lBase2.end());
    lCustom.insert(itCustom, lBase2.begin(), lBase2.end());
    std::cout << std::endl << "======= TEST 26 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from same vector at begin() */
    lBase.insert(lBase.begin(), lBase.begin(), lBase.end());
    lCustom.insert(lCustom.begin(), lCustom.begin(), lCustom.end());
    std::cout << std::endl << "======= TEST 27 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() n elements from same vector at begin() + 2*/
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.insert(itBase, lBase.begin(), lBase.end());
    lCustom.insert(itCustom, lCustom.begin(), lCustom.end());
    std::cout << std::endl << "======= TEST 28 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after insert() 0 elements from same vector at begin() */
    lBase.insert(lBase.begin(), lBase.begin(), lBase.begin());
    lCustom.insert(lCustom.begin(), lCustom.begin(), lCustom.begin());
    std::cout << std::endl << "======= TEST 29 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison after erase() at begin() */
    lBase.erase(lBase.begin());
    lCustom.erase(lCustom.begin());
    std::cout << std::endl << "======= TEST 30 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison after erase() at begin() + 2 */
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.erase(itBase);
    lCustom.erase(itCustom);
    std::cout << std::endl << "======= TEST 31 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after erase() from begin() to begin() */
    lBase.erase(lBase.begin(), lBase.begin());
    lCustom.erase(lCustom.begin(), lCustom.begin());
    std::cout << std::endl << "======= TEST 32 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after erase() from begin() to end() */
    lBase.erase(lBase.begin(), lBase.end());
    lCustom.erase(lCustom.begin(), lCustom.end());
    std::cout << std::endl << "======= TEST 33 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after splice an entire other at begin() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    std::list<T> spliceBase = lBase;
    ft::List<T> spliceCustom = lCustom;
    lBase.splice(lBase.begin(), spliceBase);
    lCustom.splice(lCustom.begin(), spliceCustom);
    std::cout << std::endl << "======= TEST 34 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- spliced list -----" << std::endl;
    testBasics(spliceBase, spliceCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after splice an empty list at begin() */
    lBase.splice(lBase.begin(), spliceBase);
    lCustom.splice(lCustom.begin(), spliceCustom);
    std::cout << std::endl << "======= TEST 35 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- spliced list -----" << std::endl;
    testBasics(spliceBase, spliceCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after splice one elem from another list at begin() */
    spliceBase.push_back(7);
    spliceCustom.push_back(7);
    lBase.splice(lBase.begin(), spliceBase, spliceBase.begin());
    lCustom.splice(lCustom.begin(), spliceCustom, spliceCustom.begin());
    std::cout << std::endl << "======= TEST 37 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- spliced list -----" << std::endl;
    testBasics(spliceBase, spliceCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after splice one elem from same list at begin() */
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.splice(lBase.begin(), lBase, itBase);
    lCustom.splice(lCustom.begin(), lCustom, itCustom);
    std::cout << std::endl << "======= TEST 38 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- spliced list -----" << std::endl;
    testBasics(spliceBase, spliceCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after splice a range of elem from another list at begin() */
    for (int count = 0; count < 5; count++)
    {
        spliceBase.push_back(count + 10);
        spliceCustom.push_back(count + 10);
    }
    lBase.splice(lBase.begin(), spliceBase, spliceBase.begin(), spliceBase.end());
    lCustom.splice(lCustom.begin(), spliceCustom, spliceCustom.begin(), spliceCustom.end());
    std::cout << std::endl << "======= TEST 39 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- spliced list -----" << std::endl;
    testBasics(spliceBase, spliceCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after splice a range of elem from same list at begin() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    itBase = lBase.begin();
    itBase++;
    itBase++;
    itCustom = lCustom.begin();
    itCustom++;
    itCustom++;
    lBase.splice(lBase.begin(), lBase, itBase, lBase.end());
    lCustom.splice(lCustom.begin(), lCustom, itCustom, lCustom.end());
    std::cout << std::endl << "======= TEST 40 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- spliced list -----" << std::endl;
    testBasics(spliceBase, spliceCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after remove() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    lBase.remove(3);
    lCustom.remove(3);
    std::cout << std::endl << "======= TEST 41 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after remove() (no corresponding value) */
    lBase.remove(10);
    lCustom.remove(10);
    std::cout << std::endl << "======= TEST 42 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after remove_if() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    lBase.remove_if(&remove_function_int);
    lCustom.remove_if(&remove_function_int);
    std::cout << std::endl << "======= TEST 43 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after remove() (no corresponding value) */
    lBase.remove_if(remove_function_int);
    lCustom.remove_if(remove_function_int);
    std::cout << std::endl << "======= TEST 44 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after unique() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    lBase.unique();
    lCustom.unique();
    std::cout << std::endl << "======= TEST 45 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after unique() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    lBase.unique(&unique_function_int);
    lCustom.unique(&unique_function_int);
    std::cout << std::endl << "======= TEST 46 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after unique() (no corresponding value) */
    lBase.unique(unique_function_int);
    lCustom.unique(unique_function_int);
    std::cout << std::endl << "======= TEST 47 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after merge() */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 5; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    std::list<T> mergeBase(lBase);
    ft::List<T> mergeCustom(lCustom);
    lBase.merge(mergeBase);
    lCustom.merge(mergeCustom);
    std::cout << std::endl << "======= TEST 48 =======" << std::endl;
    testBasics(lBase, lCustom);
    std::cout << "----- merged list -----" << std::endl;
    testBasics(mergeBase, mergeCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after sort() */
    lBase.clear();
    lCustom.clear();
    lBase.push_back(10);
    lCustom.push_back(10);
    lBase.push_back(5);
    lCustom.push_back(5);
    lBase.push_back(20);
    lCustom.push_back(20);
    lBase.push_back(15);
    lCustom.push_back(15);
    lBase.sort();
    lCustom.sort();
    std::cout << std::endl << "======= TEST 49 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after reverse() */
    lBase.reverse();
    lCustom.reverse();
    std::cout << std::endl << "======= TEST 50 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after reverse() */
    lBase.push_back(30);
    lCustom.push_back(30);
    lBase.reverse();
    lCustom.reverse();
    std::cout << std::endl << "======= TEST 51 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test relational operators with empty vectors */
    // lBase.clear();
    // lCustom.clear();
    std::list<T> cmp_lBase(lBase);
    ft::List<T> cmp_lCustom(lCustom);
    std::cout << std::endl << "======= TEST 52 =======" << std::endl;
    testRelationalOperators(lBase, cmp_lBase, lCustom, cmp_lCustom);


    /* Test relational operators with one element in vectors */
    lBase.push_back(1);
    lCustom.push_back(1);
    std::cout << std::endl << "======= TEST 53 =======" << std::endl;
    testRelationalOperators(lBase, cmp_lBase, lCustom, cmp_lCustom);


    /* Test relational operators with same element number and same values in vectors */
    cmp_lBase.push_back(1);
    cmp_lCustom.push_back(1);
    std::cout << std::endl << "======= TEST 54 =======" << std::endl;
    testRelationalOperators(lBase, cmp_lBase, lCustom, cmp_lCustom);


    /* Test relational operators with same element number but different values in vectors */
    cmp_lBase.push_back(1);
    cmp_lCustom.push_back(1);
    lBase.push_back(2);
    lCustom.push_back(2);
    std::cout << std::endl << "======= TEST 55 =======" << std::endl;
    testRelationalOperators(lBase, cmp_lBase, lCustom, cmp_lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after swap() of same size vectors */
    lBase.swap(cmp_lBase);
    lCustom.swap(cmp_lCustom);
    std::cout << std::endl << "======= TEST 56 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after swap() of different size vectors (inferior size) */
    cmp_lBase.push_back(3);
    cmp_lCustom.push_back(3);
    lBase.swap(cmp_lBase);
    lCustom.swap(cmp_lCustom);
    std::cout << std::endl << "======= TEST 57 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test size(), capacity(), front(), back() and element comparison
    after swap() of different size vectors (superior size) */
    lBase.insert(lBase.end(), 3, 4);
    lCustom.insert(lCustom.end(), 3, 4);
    lBase.swap(cmp_lBase);
    lCustom.swap(cmp_lCustom);
    std::cout << std::endl << "======= TEST 58 =======" << std::endl;
    testBasics(lBase, lCustom);


    /* Test normal iterators */
    lBase.clear();
    lCustom.clear();
    for (int count = 0; count < 10; count++)
    {
        lBase.push_back(count + 1);
        lCustom.push_back(count + 1);
    }
    std::cout << std::endl << "======= TEST 59 =======" << std::endl;
    testIterator(lBase, lCustom);


    /* Test reverse iterators */
    std::cout << std::endl << "======= TEST 60 =======" << std::endl;
    testReverseIterator(lBase, lCustom);


    /* Test iterator constructor */
    std::list<T> itBaseList(lBase.begin(), lBase.end());
    ft::List<T> itCustomList(lCustom.begin(), lCustom.end());
    std::cout << std::endl << "======= TEST 47 =======" << std::endl;
    testBasics(itBaseList, itCustomList);
}


void testLists()
{
    std::cout <<  std::endl << "\033[38;5;202m******************************************************" << std::endl;
    std::cout << "***************        TEST LIST        **************" << std::endl;
    std::cout << "******************************************************\033[0m" << std::endl;
    testList<int>();
}
// hw15.cpp
// to illustrate stl containers & iterators
/*************************************************************************
 * AUTHOR     : Justin Gea
 * HW15       : stl containers & iterators
 * CLASS      : CS 1C
 * SECTION    : 7/26/2022
*************************************************************************/
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
// function & class definitions go into hw15.cpp:
// hw15.cpp
namespace hw15 {
//
// list conainter, iterator example code adapted from Chapter 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
//------------------------------------------------------------------------------
template<typename Elem>
struct Link
{
    Link* prev;    // previous link
    Link* succ;    // successor (next) link
    Elem  val;     // the value
    Link(const Elem& v = Elem(), Link* p = 0, Link* s = 0) : val{v}, prev{p}, succ{s} { }
};
//--Q#3-------------------------------------------------------------------------
template<typename Elem>
class list
{
    // representation and implementation details
public:
    class iterator;         // forward declaration of member type: class iterator
    class const_iterator;   // forward declaration of member type: class const_iterator
    list() : first(new Link<Elem>()), last{first} { }
    ~list()
    {
        while (first != last)
        {
            Link<Elem> *next = first->succ;
            delete first;
            first = next;
        }
        delete last;
    }
    iterator begin();   // iterator to first element
    iterator end();     // iterator to one beyond last element
    // add missing const iterators begin, end here
    // ...  // constant iterator to first element
	const_iterator begin() const;	// constant iterator to first element
	const_iterator end() const;		// constant iterator to one beyond last element
    // ...  // constant iterator to one beyond last element
    iterator insert(iterator p, const Elem& v); // insert v into list after p
    iterator erase(iterator p);                 // remove p from the list
    void push_back(const Elem& v);  // insert v at end
    void push_front(const Elem& v); // insert v at front
    void pop_front();   // remove the first element
    void pop_back();    // remove the last element
    Elem& front();      // the first element
    Elem& back();       // the last element
    Link<Elem>* first;
    Link<Elem>* last;   // one-beyond-the-last link
};
//--Q#4-------------------------------------------------------------------------
template<typename Elem>
class list<Elem>::iterator // definition for class iterator
{
    Link<Elem>* curr;   // current node
public:
    iterator(Link<Elem>* p) : curr{p} { }
    iterator& operator++() // forward
    {
		curr = curr->succ;
                        // temp, replace when defining function
        return *this; // included so that incomplete lab code will compile
    }
    iterator& operator--() // backwards
    {
		curr = curr->prev;
						// temp, replace when defining function
		return *this; // included so that incomplete lab code will compile
    }
    Elem& operator*() // get value (dereference)
    {
		return curr->val;
    }
    bool operator==(const iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
    {
		return curr == rhs.curr;
    }
    bool operator!=(const iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
    {
		return curr != rhs.curr;
    }
};
//--Q#4-------------------------------------------------------------------------
template<typename Elem>
class list<Elem>::const_iterator // definition for class const_iterator
{
    const Link<Elem>* curr;   // current node
                              // node pointed to by curr is immutable (i.e. can't be changed)
                              // fine to modify curr pointer itself (i.e. pointer value stored in curr)
                              // refer to const correctness reading
public:
    // add missing constructor, overloaded ++, --, *, ==, != operators here
    const_iterator(const Link<Elem>* p) : curr{p} { }
	const_iterator& operator++() // forward
	{
		curr = curr->succ;
								// temp, replace when defining function
		return *this; // included so that incomplete lab code will compile
	}
	const_iterator& operator--() // backwards
	{
		curr = curr->prev;
								// temp, replace when defining function
		return *this; // included so that incomplete lab code will compile
	}
	const Elem& operator*() // get value (dereference)
	{
		return curr->val;
	}
	bool operator==(const const_iterator& rhs) const // lhs, rhs iterators point to the same node (equal)
	{
		return curr == rhs.curr;
	}
	bool operator!=(const const_iterator& rhs) const // lhs, rhs iterators do not point to the same node (not equal)
	{
		return curr != rhs.curr;
	}
};
//------------------------------------------------------------------------------
template<typename Elem> 
typename list<Elem>::iterator list<Elem>::begin()  // iterator to first element
{ 
    return iterator(first); 
}
//--Q#3-------------------------------------------------------------------------
// constant iterator to first element
// ... add missing constant iterator begin here
template<typename Elem>
typename list<Elem>::const_iterator list<Elem>::begin() const
{
	return const_iterator(first);
}
//------------------------------------------------------------------------------
template<typename Elem> 
typename list<Elem>::iterator list<Elem>::end() // iterator to one beyond last element
{ 
    return iterator(last); 
}
//--Q#3-------------------------------------------------------------------------
// constant iterator to last element
// ... add missing constant iterator end here
template<typename Elem>
typename list<Elem>::const_iterator list<Elem>::end() const
{
	return const_iterator(last);
}
//------------------------------------------------------------------------------
template<typename Elem> 
void list<Elem>::push_front(const Elem& v) // insert v at front
{
    first = new Link<Elem>(v,0,first);
}
//
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
//--Q#5-------------------------------------------------------------------------
double* low_doubles(double* first, double* last)
    // return a pointer to the element in [first,last) that has the lowest value
{
    double l = -1;
    double* low;
    for(double* p = first; p!=last; ++p)
        if (*p < l) { low = p; l = *p; }
    return low;
}
//--Q#5-------------------------------------------------------------------------
// implement templated low algorithm here
template<typename Iter>
Iter low(Iter first, Iter last)
{
	Iter l = first;
	for(Iter p = first; p!=last; ++p)
		if (*p < *l) { l = p; }
	return l;
}
//------------------------------------------------------------------------------
} // hw15
//------------------------------------------------------------------------------
using namespace hw15;
//
// list conainter, iterator example code adapted from Chapter 20.4
// low algorithms adapted from Chapter 20.1, 20.4
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

template<typename T>
void find_list_value(const list<T>& myList);

int main()
{
    // console header
cout << endl;
cout << "************************************** " << endl;
cout << "*           Running HW15             * " << endl;
cout << "*      Programmed by First Last      * " << endl;
cout << "*         CS1C Date & Time           * " << endl;
cout << "************************************** " << endl;
cout << endl;
// Q#3,4 - containters & iterators
    list<int> myList;
    int x;
    while (cin >> x) myList.push_front(x);
// Q#5 - low_doubles algorithm
    double d[] = {1,2,3,4,5,-99.25,100,10,500.123,5};       // init array of doubles
    vector<double> v = {1,2,3,4,5,-99.25,100,10,500.123,5}; // init identical vector of doubles
    double* lowa = low_doubles(&d[0], &d[9]); // min of array
    cout << endl << "low_doubles alg: double array min value is " << *lowa << endl << endl;
    double* middle = &v[0] + v.size()/2;
    double* lowv1 = low_doubles(&v[0], middle);          // min of vector first half
    double* lowv2 = low_doubles(middle, &v[0]+v.size()); // min of vector second half
    //cout << "low_doubles alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low_doubles alg: double vector min value second half is " << *lowv2 << endl << endl;
    lowa = low(&d[0], &d[9]); // min of array
    cout << "low alg: double array min value is " << *lowa << endl << endl;
    lowv1 = low(&v[0], middle);          // min of vector first half
    lowv2 = low(middle, &v[0]+v.size()); // min of vector second half
    cout << "low alg: double vector min value first half is " << *lowv1 << endl;
    cout << "low alg: double vector min value second half is " << *lowv2 << endl << endl;
    const list<int>& constList = myList;
    auto p = low(constList.begin(), constList.end());
    if (p==constList.end())
        cout << "low alg: the list is empty";
    else
        cout << "low alg: the lowest value in the list is " << *p << endl;
    return 0;
}

template<typename T>
void find_list_value(const list<T>& l)
{
    auto p = low(l.begin(), l.end()); 
    if (p==l.end()) 
        cout << "low alg: the list is empty";
    else
        cout << "low alg: the lowest value in the list is " << *p << endl;
}
//------------------------------------------------------------------------------
// WRITTEN ANSWERS
// Q#1
// What is an stl container? stl iterator? stl algorithm? Give examples of each. 
// stl container is a data structure that contains a collection of elements.
// stl iterator is a pointer to an element in a container.
// stl algorithm is a function that operates on a container.
// an example of an stl container is a vector.
// an example of an stl iterator is a vector iterator.
// an example of an stl algorithm is a low algorithm.

// Q#2
// Explain how the iterator architecture makes it possible to decouple algorithms from containers. Why is this important?
// The iterator architecture makes it possible to decouple algorithms from containers because the iterator is a pointer to an element in a container.
// This is important because it allows the algorithms to operate on the elements in the container without having to know the underlying structure of the container.

// Q#5
/*
The low_doubles algorithm will find 
the lowest value in an array of doubles. low_doubles has 
local variables l and low which are a source of errors. What 
kinds of issues might arise? Implement the generic (i.e. 
templated) low algorithm. low takes iterator arguments 
which point to the beginning, iterator first, and one past the 
end, iterator last, of a sequence of container elements. Take
advantage of the type parameter iterator to eliminate local 
variables l and low in writing the low algorithm. In what ways 
are the algorithms low_doubles and low similar? different? 
In main the output for finding the lowest value in the first 
half of vector v differs for low_doubles vs low. What is 
happening here?
*/
// The issue is that low_doubles has local variables l and low which are a source of errors.
// both the low_doubles & low find the lowest value in the first half of vector v.
// However, low is a generic algorithm and low_doubles is a specific algorithm.
// Due to this, only when there is a value less then -1 does the low_doubles algorithm return the value.
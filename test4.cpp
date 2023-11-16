#include "test.hpp"





#include <iostream>

using namespace std;

// implementation of linked list w/ templates
// example w/ list<int>
// fns stored at end of pgm as individual templates

// multiple forward declarations needed

template <class T>
class node;

template <class T>
class list;

template <class T>
   ostream& operator<< (ostream &, const list<T> &);  
                                              // overloaded print op.

template <class T>
class list
  {
  public:
    node<T>* head;                           // ptr to head of list
    list<T>();                                  // default constructor
    list<T>(const T[]);                         // another constructor
    ~list<T>();                                 // destructor
    list<T>(const list<T>& in_list);               // copy constructor
    list<T>& operator=(const list<T>& in_list);    // overloaded asgt op
    int count_e_iter() const;                // iterative traversal
    int count_e_recr() const;                // recursive traversal
  private:
    friend ostream& operator<< <>(ostream &, const list<T> &);  // overloaded print op.
    void reset();                            // reset to null
  };
  
template <class T>
class node
  {
  public:
    T item;                                  // content
    node<T>* link;                              // ptr to next node
    node<T>();                                  // default constructor
    node<T>(T, node<T>*);                          // another constructor
  private:
    friend class list<T>;                       // 'list' fns can see all of node
    int count_e_private();                   // rec. trav. helper fn
    friend ostream& operator<< <>(ostream &, const node<T> &);  
                                             // overloaded print op.

  };
  
// ***********************************


int main() 

{

  char my_string[80] = "i love peeps";
  int e_count;

  // constructor creates dynamic memory
  list<char> list1(my_string);

  cout << "list1 is at " << list1 << endl;

  // iterative traversal
  e_count = list1.count_e_iter();
  cout << "Counting iteratively, there are " << e_count << " e's" << endl;

  // recursive traversal
  e_count = list1.count_e_recr();
  cout << "Counting recursively, there are " << e_count << " e's" << endl << endl;

  // testing copy constructor
  list<char> list2(list1);
  cout << "list2 is at " << list2 << endl;

  // testing overloaded asgt op
  list2 = list1;
  cout << "list2 is at " << list2 << endl;

  return 0;
}

  
// ***********************************

template <class T>
list<T>::list()                        // default constructor
  {
    head = 0;
    cout << "Called default constructor for list " << *this << endl;
  }

template <class T>
list<T>::list(const T* in_str)          // another constructor
  {
    int sub;
    node<T>* p = 0;
    node<T>* prev_p;

    head = 0;
    for (sub = 0; sub < strlen(in_str); sub++)
      {
	prev_p = p;
	p = new node<T>(in_str[sub], 0);
	if (sub == 0)
	  head = p;
        else
          prev_p -> link = p;
      }

    cout << "Called constructor for list at " << *this << endl;
  }

template <class T>
list<T>::~list()                       // destructor
  {

    cout << "Called destructor for list at " << this << endl;

    if (head != 0)                        // reset list to null
      reset();

  }

template <class T>
void list<T>::reset()                       // reset list to null
  {
    node<T>* p;
    node<T>* p_next;

    if (head != 0)
      {
        p = head;
        while (p != 0)
          {
            p_next = p -> link;     // get next link while it's still available
            cout << "Freeing memory at " << p << endl;
            delete p;
            p = p_next;
          }
        cout << endl;
        head = 0;
      }
  }

template <class T>
list<T>::list(const list<T>& in_list)            // copy constructor
  {
    node<T>* p;
    node<T>* q;
    node<T>* prev_q;

    cout << "Called copy constructor to copy list at " << &in_list << endl;
    head = 0;
    if (in_list.head != 0)
      {
	p = in_list.head;
	while (p != 0)
	  {
	    q = new node<T>(*p);        // get new node, copy data members
	    q -> link = 0;           // ... zero out new link,
            if (head == 0)           // ... and make someone point to it
	      head = q;
            else
	      prev_q -> link = q;
	    p = p -> link;
	    prev_q = q;
	  }
      }
    cout << "New list is at " << *this << endl;
  }

template <class T>
list<T>& list<T>::operator=(const list<T>& in_list)    // overloaded asgt op
  {
    node<T>* p;
    node<T>* q;
    node<T>* prev_q;

    cout << "Called overloaded asgt op from list at " << &in_list << endl;
    if (this != &in_list)                        // Make sure not same object
     {

       if (head != 0)                            // free old result
         reset();

       if (in_list.head != 0)
	 {
	   p = in_list.head;                     // create & fill new list
	   while (p != 0)
	     {
	       q = new node<T>(*p);        // get new node, copy data members
	       q -> link = 0;           // ... zero out new link,
               if (head == 0)           // ... and make someone point to it
	         head = q;
               else
	         prev_q -> link = q;
	       p = p -> link;
	       prev_q = q;
	     }
	 }
     }
    cout << "Result is at " << *this << endl << endl;
    return *this;                          // return ref for chained asgt
  }

template <class T>
ostream& operator<< (ostream& ostr, const list<T>& in_list)
{
  node<T>* p;

  ostr << &in_list << endl;                    // address of object
  ostr << "head is " << in_list.head << endl;

  p = in_list.head;
  while (p != 0)
    {
      ostr << *p << endl;
      p = p -> link;
    }
 
  return ostr;
}


template <class T>
int list<T>::count_e_iter() const
{
  node<T>* p;
  int count;

  p = head;
  count = 0;

  while (p != 0)
    {
      if (p -> item == 'e')
	count++;
      p = p -> link;
    }
  return count;
}

template <class T>
int list<T>::count_e_recr() const
{
  int count = -99;
  cout << "beginning recursive traversal " << endl;
  if (head == 0)
    count = 0;
  else
    count = head -> count_e_private();
  cout << "ending recursive traversal " << endl << endl;
  return count;
}


template <class T>
node<T>::node()                        // default constructor
  {
    link = 0;
    cout << "Called default constructor for node " << *this << endl;
  }

template <class T>
node<T>::node(T in_item, node<T>* in_link)          // another constructor
  {
    item = in_item;
    link = in_link;

    cout << "Called constructor for node " << *this << endl;
  }

template <class T>
ostream& operator<< (ostream& ostr, const node<T>& in_node)
{
  ostr << &in_node                             // address of object
       << ": "
       << in_node.item
       << " "
       << in_node.link;

  return ostr;
}

template <class T>
int node<T>::count_e_private()
{
  int count = -99;
  cout << "entering count_e_private: item = " << item 
       << " count = " << count << endl;
  if (link == 0)
    count = 0;
  else
    count = link -> count_e_private(); 
  if (item == 'e')
    count++;
  cout << "leaving count_e_private:  item = " << item 
       << " count = " << count << endl;
  return count;      
}


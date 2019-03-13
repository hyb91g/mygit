#pragma once

#include <iostream>
using namespace std;

template<class T>
struct ListNode
{
	T _val;
	ListNode<T>* _prev;
	ListNode<T>* _next;

	ListNode(const T& val = T())
		: _val(val)
		, _prev(nullptr)
		, _next(nullptr)
	{}
};


template<class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;
	Node* pNode;

	ListIterator(Node* node):pNode(node)
	{}

	Ref operator*()     //返回引用
	{
		return pNode->_val;
	}
	Ptr operator->()
	{
		return &(operator*());
	}
	//++it
	Self& operator++()
	{
		pNode = pNode->_next;
		return *this;
	}
	//it++
	Self& operator++(int)
	{
		Self tmp(*this);      // 若没写拷贝构造，调用默认的（值拷贝）
		pNode = pNode->_next;
		return tmp;
	}
	//--it
	Self& operator--()
	{
		pNode = pNode->_prev;
		return *this;
	}
	//it--
	Self& operator--(int)
	{
		Self tmp(*this);
		pNode = pNode->_prev;
		return tmp;

	}

	// it1 != it2
	bool operator!=(const Self& it)
	{
		return pNode != it.pNode;
	}
};


template<class T>
class List
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;


public:
	typedef ListIterator<T, T&, T*> Iterator;
	typedef ListIterator<T, const T&, const T*> ConstIterator;

	List()
	{
		CreateHand();
	}
	List(size_t n, const T& val = T())
	{
		CreateHand();
		while (n--)
		{
			PushBack(val);
		}
	}
	List(Iterator first, Iterator last)
	{
		CreateHand();
		while (first != last)
		{
			PushBack(*first++);
		}
	}
	List(const List<T>& l)       
	{
		CreateHand();
		Iterator it = begin();
		while (it != end())
		{
			PushBack(it.pNode->_val);
			++it;
		}
	}
	List<T>& operator=(List<T> l)  
	{
		CreateHand();
		swap(this->_phand, l._phand);
		return *this;
	}
	~List()
	{
		Clear();
		delete _phand;
		_phand = nullptr;
	}

	void PushBack(const T& val)
	{
		//pNode last = _phand->_prev;
		//pNode newnode = new Node(val);

		//// hand  last  new
		//last->_next = newnode;
		//newnode->_prev = last;
		//newnode->_next = _phand;
		//_phand->_prev = newnode;

		Insert(end(), val);
	}
	void PopBack()
 	{
		//pNode del = _phand->_prev;
		//pNode last = del->_prev;

		//last->_next = _phand;
		//_phand->_prev = last;

		//delete del;

		Erase(--end());
		
	}

	void PushFront(const T& val)
	{
		//pNode newnode = new Node(val);
		//pNode first = _phand->_next;

		//newnode->_next = first;
		//first->_prev = newnode;
		//newnode->_prev = _phand;
		//_phand->_next = newnode;

		Insert(begin(), val);
	}

	void PopFront()
	{
		//pNode del = _phand->_next;
		//pNode first = del->_next;

		//_phand->_next = first;
		//first->_prev = _phand;

		//delete del;
		Erase(begin());
	}

	void Insert(Iterator pos, const T& val)
	{
		pNode newnode = new Node(val);
		pNode cur = pos.pNode;
		pNode prev = cur->_prev;

		//prev newnode cur
		newnode->_next = cur;
		cur->_prev = newnode;
		newnode->_prev = prev;
		prev->_next = newnode;
	}

	Iterator Erase(Iterator pos)
	{
		pNode del = pos.pNode;
		pNode next = del->_next;
		pNode prev = del->_prev;

		next->_prev = prev;
		prev->_next = next;

		delete del;
		return Iterator(next);
	}

	size_t Size() const    //不常调用，O(n)
	{
		size_t count = 0;
		pNode cur = _phand->_next;
		while (cur != _phand)
		{
			count++;
			cur = cur->_next;
		}
		return count;
	}

	bool Empty() const
	{
		return _phand == _phand->_next;
	}

	Iterator begin()
	{
		return (Iterator)_phand->_next;
	}
	Iterator end()
	{
		return (Iterator)_phand;
	}
	ConstIterator begin() const
	{
		return (ConstIterator)_phand->_next;
	}
	ConstIterator end() const
	{
		return (ConstIterator)_phand;
	}
	void Clear()
	{
		//size_t size = Size();
		//while (size--)
		//{
		//	PopBack();
		//}
		pNode cur = _phand->_prev;
		pNode del = cur;
		while (cur != _phand)
		{
			cur = cur->_prev;
			delete del;
			del = cur;
		}
		_phand->_next = _phand;
		_phand->_prev = _phand;
	}


private:
	void CreateHand()
	{
		_phand = new Node;
		_phand->_next = _phand;
		_phand->_prev = _phand;
	}

private:
	pNode _phand;
};
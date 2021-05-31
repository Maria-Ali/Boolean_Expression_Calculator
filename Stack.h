#ifndef MY_CLASS_HH // include guard
#define MY_CLASS_HH
#include<iostream>
#include "DSA.h"
//#include "DSA.cpp"
using namespace std;
	template <class M>
	class Stack{
		int top;
		DynamicSafeArray<M> *stk;
		public:
			Stack(int s);
			bool isFull();
			bool isEmpty();
			void Push(M d);
			M Pop();
			M Peek();
	};
	#endif

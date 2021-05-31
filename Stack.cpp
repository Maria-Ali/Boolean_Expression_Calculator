#include <iostream>
#include "Stack.h"
#include<math.h>
using namespace std;
template <class M>
Stack<M>::Stack(int s)
{
	stk=new DynamicSafeArray<M>(s);
				top=-1;
}
template <class M>
bool Stack<M>::isFull()
{
	return(top==stk->Size()-1);
}
template <class M>
bool Stack<M>::isEmpty()
{
	return(top==-1);
}
template <class M>
void Stack<M>::Push(M d)
{
		if(!isFull())
				{
					top++;
					stk->operator [](top)=d;	
				}
}
template <class M>
M Stack<M>::Peek()
{
	M temp;
				if(!isEmpty())
				{
					temp=stk->operator[](top);
				}
				return temp;
}
template <class M>
M Stack<M>::Pop()
{
				M temp;
				if(!isEmpty())
				{
					temp=stk->operator[](top);
					top--;
				}
				return temp;
}

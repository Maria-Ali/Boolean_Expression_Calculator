#include <iostream>
#include<sstream>
#include "Stack.h"
#include "Stack.cpp"
#include "DSA.h"
#include "DSA.cpp"
#include <math.h>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool Precedence(char a , char b);
bool validation(string str);
string Convert_to_postfix(string str);
string ReadString(string str);
bool AND(int a,int b)
{
	return a&&b;
}

bool OR(int a,int b)
{
	return a||b;
}

bool NOT(int a)
{
	return !a;
}

bool NAND(int a,int b)
{
	return !(a&&b);
}

bool NOR(int a,int b)
{
	return !(a||b);
}

bool XOR(int a,int b)
{
	return ((!a)&&b)||(a&&(!b));
}

bool XNOR(int a,int b)
{
	return !( ( (!a)&&b ) || ( a&&(!b) ) );
}

bool Greater(int a  ,int b)
{
	return(a>b);
}
bool GreaterEqual(int a  ,int b)
{
	return(a>=b);
}
bool Less(int a  ,int b)
{
	return(a<b);
}
bool LessEqual(int a  ,int b)
{
	return(a<=b);
}
bool Equal(int a  ,int b)
{
	return(a==b);
}
bool NotEqual(int a  ,int b)
{
	return(a!=b);
}

bool validation(string str)
{
	int count1 = 0,count2 = 0,count3  = 0,count = 0;
	for(int i = 0;i < str.length();i++)
	{
		if(str[i] == '(')
		{
			count1++;
		}
		else if(str[i] == '{')
		{
			count2++;
		}
		else if(str[i] == '[')
		{
			count3++;
		}
		else if(str[i] == ')')
		{
			count1--;
		}
		else if(str[i] == '}')
		{
			count2--;
		}
		else if(str[i] == ']')
		{
			count3--;
		}
		else if(str[i] >= '0' && str[i] <= '9')
		{
			count++;
		}
	}
	if(count1 == 0 && count2 == 0 && count3 == 0 && count != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//PostFix
string Convert_to_postfix(string str)
			{
			Stack <char>*stack=new Stack<char>(str.length());
				string postfix;
				int n;
				int i;
				for(int i=0;i<str.length();i++)
				{
					if(str[i]>='0' && str[i]<='9')
					{
						while(str[i]>='0' && str[i]<='9' && i<=str.length()-1)
						{
							postfix=postfix+str[i];
							i++;
						}
						i--;
						postfix=postfix+" ";
					}
					else
					{
						if(stack->isEmpty() || str[i]=='(')
						{
							stack->Push(str[i]);
						}
						else if(str[i]==')')
						{
							//i=j;
							while(!stack->isEmpty())
							{
							if(stack->Peek()=='(')
							{
								char c = stack->Pop();
								break;
							}
							char m=stack->Pop();
							postfix=postfix+m;
							}
						}
							else if(str[i]==']')
						{
							//i=j;
							while(!stack->isEmpty())
							{
							if(stack->Peek()=='[')
							{
								char c = stack->Pop();
								break;
							}
							char m=stack->Pop();
							postfix=postfix+m;
							}
						}
							else if(str[i]=='}')
						{
							//i=j;
							while(!stack->isEmpty())
							{
							if(stack->Peek()=='{')
							{
								char c = stack->Pop();
								break;
							}
							char m=stack->Pop();
							postfix=postfix+m;
							
							}
						}
						else if(str[i] == stack->Peek())
						{
							stack->Push(str[i]);
						}
						else if(Precedence(stack->Peek() , str[i]))
						{	
							stack->Push(str[i]);
						}
						else
						{
							while(!Precedence(stack->Peek() , str[i]) && !stack->isEmpty())
							{
								    postfix=postfix+stack->Peek();
								    char c=stack->Pop();
								    char b=stack->Peek();
									if(b=='(' || b=='[' || b=='{')
									{
										break;
									} 
							}
							stack->Push(str[i]);
						}
					}
				}
				while(!stack->isEmpty())
				postfix=postfix+stack->Pop();
				return postfix;
			}






 // Read String
 string ReadString(string str)
			{
				string mystr;
				for(int i=0;i<str.length();i++)
				{
					 if(str[i]=='>' && str[i+1]=='=')
					{
						mystr=mystr+"I";
						i++;
					}
					else if(str[i]=='<' &&str[i+1]=='=')
					{
						mystr=mystr+"K";
						i++;
					}
					else if(str[i]=='<' && str[i+1]=='>')
					{
						mystr=mystr+"M";
						i++;
					}
					else if(str[i]=='=' &&str[i+1]=='=')
					{
						mystr=mystr+"L";
						i++;
					}
					else if(str[i]=='>')
					{
						mystr=mystr+"H";
						
					}
					else if(str[i]=='<')
					{
						mystr=mystr+"J";
						
					}
					else if(str[i]=='N' && str[i+1]=='O' &&str[i+2]=='T')
					{
						mystr=mystr+"A";
						i=i+2;
					}
					else if(str[i]=='A' && str[i+1]=='N' &&str[i+2]=='D')
					{
					mystr=mystr+"B";
						i=i+2;	
					}
					else if(str[i]=='O' && str[i+1]=='R')
					{
					mystr=mystr+"C";
						i=i+1;	
					}
					else if(str[i]=='N' && str[i+1]=='A' &&str[i+2]=='N'&&str[i+3]=='D')
					{
					mystr=mystr+"D";
						i=i+3;	
					}
					else if(str[i]=='N' && str[i+1]=='O' &&str[i+2]=='R')
					{
					mystr=mystr+"E";
						i=i+2;	
					}
					else if(str[i]=='X' && str[i+1]=='O' &&str[i+2]=='R')
					{
					mystr=mystr+"F";
						i=i+2;	
					}
					else if(str[i]=='X' && str[i+1]=='N' &&str[i+2]=='O'&&str[i+3]=='R')
					{
					mystr=mystr+"G";
						i=i+3;	
					}
					else
					{
						if(str[i]!=' ')
						mystr=mystr+str[i];
					}
					
				}
				//return mystr;
				//cout<<mystr<<endl;
				return Convert_to_postfix(mystr);
			}
			
			//Precedence
			bool Precedence(char a , char b)//returns true if precedence of b is greater than a , a is the stacks peek operator and b is the operator from string
			{
				if(a =='(' &&(b!='[' && b!='{'))
				{
					return true;
				}
				if(a=='[' && b!='(')
				{
					return true;
				}
				if(a=='{' &&(b!='(' && b!='['))
				{
					return true;
				}
				if(b=='^')
				{
					return true;
				}
				if(a!='^' && b=='/')
				{
					return true;
				}
				if(b=='%' && (a!='/' && a!='^'))
		       {
			    return true;
		       }
				if(b=='*' && (a!='^' && a!='/' &&a!='%'))
				{
					return true;
				}
				if(b=='/' && (a=='-' || a=='+'||a=='%'||(a>='A' && a<='M')))
				{
					return true;
				}
				if(b=='%' && (a=='+' || a=='-' ||(a>='A' && a<='M')))
				{
					return true;
				}
				if(b=='-' && a=='+')
				{
					return true;
				}
				if(b=='+' &&(a>='A' && a<='M'))
				{
					return true;
				}
				if(b=='-' &&(a>='A' && a<='M'))
				{
					return true;
				}
				
				if((b>='H' && b<='K') &&((a>='A' && a<='G')||( a=='L'||a=='M')))
				{
					return true;
				}
				if(b=='L' &&((a>='A' && a<='G') || a=='M'))
				{
					return true;
				}
				if(b=='M' && (a>='A' && a<='G'))
				{
					return true;
				}
				if(b=='A' && (a>='B' && a<='G' ))
				{
					return true;
				}
				if(b=='B' && (a>='C' && a<='G'))
				{
					return true;
				}
				if(b=='C' &&(a>='D' && a<='G'))
				{
					return true;
				}
				if(b=='D' && (a=='E' ||a=='F'||a=='G'))
				{
					return true;
				}
				if(b=='E' && (a=='D' ||a=='F'||a=='G'))
				{
					return true;
				}
				if(b=='F' && (a=='E' ||a=='D'||a=='G'))
				{
					return true;
				}
				if(b=='G' && (a=='E' ||a=='F'||a=='D'))
				{
					return true;
				}
				return false;
			}
			
			
			//Evaluation
			
			int Evaluate(string str)
			{
				Stack <int> *stack =new Stack<int> (str.length());
				int n;
				for(int i=0;i<str.length();i++)
				{
					string number;
					if(str[i]>='0' && str[i]<='9')
					{
					while((str[i]>='0' &&str[i] <='9' )&& i<=str.length()-1)
					{
						number=number+str[i];
						i++;
					}	
					stringstream obj(number);
					obj>>n;
					stack->Push(n);
					//cout<<n<<endl;
					i--;
					}
					else if(str[i]=='+')
					{
						int a=stack->Pop();
						int b=stack->Pop();
						stack->Push(b+a);
					}
					else if(str[i]=='^')
					{
						int a=stack->Pop();
						int b=stack->Pop();
						stack->Push(pow(b,a));
					}
					else if(str[i]=='-')
					{
						int a=stack->Pop();
						int b=stack->Pop();
						stack->Push(b-a);
					}
					else if(str[i]=='/')
					{
						int a=stack->Pop();
						int b=stack->Pop();
						stack->Push(b/a);
					}
					else if(str[i]=='%')
					{
						int a=stack->Pop();
						int b=stack->Pop();
						stack->Push(b%a);
					}
					else if(str[i]=='*')
					{
						int a=stack->Pop();
						int b=stack->Pop();
						stack->Push(b*a);
					}
					else if(str[i]=='H')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=Greater(a,b);
						stack->Push(j);
					}
					else if(str[i]=='I')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=GreaterEqual(a,b);
						stack->Push(j);
					}
					else if(str[i]=='J')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=Less(a,b);
						stack->Push(j);
					}
					else if(str[i]=='K')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=LessEqual(a,b);
						stack->Push(j);
					}
					else if(str[i]=='L')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=Equal(a,b);
						stack->Push(j);
					}
					else if(str[i]=='M')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=NotEqual(a,b);
						stack->Push(j);
					}
						else if(str[i]=='A')
					{
						
						int a=stack->Pop();
						int j=NOT(a);
						stack->Push(j);
					}
						else if(str[i]=='B')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=AND(a,b);
						stack->Push(j);
					}
						else if(str[i]=='C')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=OR(a,b);
						stack->Push(j);
					}
						else if(str[i]=='D')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=NAND(a,b);
						stack->Push(j);
					}
						else if(str[i]=='E')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=NOR(a,b);
						stack->Push(j);
					}
						else if(str[i]=='F')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=XOR(a,b);
						stack->Push(j);
					}
						else if(str[i]=='G')
					{
						int b=stack->Pop();
						int a=stack->Pop();
						int j=XNOR(a,b);
						stack->Push(j);
					}
				}
				return stack->Pop();
			}
			
		
			
int main(int argc, char** argv) 
{	
string str , postfix;
int check,i=0;
bool answer;
cout << "                                                              BOOLEAN EXPRESSION CALCULATOR" << endl << endl;
	fstream ptr;
ptr.open("expressions.txt" , ios::in);
while(getline(ptr  ,str))
{
i++;
cout << i << " .Expression is: " << endl;
cout << str << endl;
int valid = validation(str);
if(valid == 0)
{
	cout << "Invalid Expression, Cannot be Evaluated" << endl << endl << endl;
}
else if(valid == 1)
{
cout << "Valid Expression"<< endl;
cout << "Answer is: " << endl;
postfix=ReadString(str);
check = Evaluate(postfix);
if(check == 0)
{
	cout << "False" << endl;
}
else if(check == 1)
{
	cout << "True" << endl;
	}	
	cout << endl << endl;
}
}
	ptr.close();
	cout << "Made By:" << endl;
	cout << "1. Maria AliAsghar 18k-0161" << endl;
	cout << "2. Izaan Sohail    18k-0162" << endl;
	return 0;
}

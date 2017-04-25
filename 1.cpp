#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

template<class T>
class Stack
{
	struct node
	{
		T data;
		node *next;
	};
	node *top;
public:
	Stack()
	{
		top = NULL;
	}
	bool isfull();
	bool isempty();
	void push(T);
	T pop();
	void display();
	string intopost(string);
	string intopre(string);
	int evaluate(char,int,int);
	int precedence(char);
	int posteval(string);
	int preeval(string);
};
template <class T>
bool Stack<T> :: isfull()
{
	node *temp = new node;
	if(temp!=NULL)
	{
		delete temp;
		return false;
	}
	return true;
}
template <class T>
bool Stack<T> :: isempty()
{
	if(top == NULL)
		return true;
	return false;
}
template <class T>
void Stack<T> :: push(T d)
{
	if(isfull())
		cout<<"\nStack Full";
	else
	{
		node *newnode = new node;
		newnode->data =  d;
		newnode->next = top;
		top = newnode;
	}
}
template <class T>
T Stack<T> :: pop()
{
	if(isempty())
	{
		cout<<"\nStck empty! Underflow";
	}
	else
	{
		T val;
		node *temp;
		temp = top;
		val = top->data;
		top = temp->next;
		delete temp;
		return val;
	}
}
template <class T>
void Stack<T> :: display()
{
	node *temp;
	temp = top;
	while(temp!=NULL)
	{
		cout<<temp->data<<" <- ";
		temp = temp->next;
	}
}
template <class T>
string Stack<T> :: intopost(string instr)
{
	T op,  ch;
	Stack<char> st;
	string poststr("");
	for(int i=0; i<instr.length(); i++)
	{
		ch = instr.at(i);
		if(isalnum(ch))
		{
			poststr.append(1, ch);
		}
		else
		{
			if(ch == '(')
				st.push(ch);
			else if(ch == ')')
			{
				while((op = st.pop()) != '(')
				{
					poststr.append(1,op);
				}
			}
			else if((st.isempty()!=true) && precedence(ch)<=precedence(st.top->data))
			{
				op = st.pop();
				poststr.append(1,op);
			}
			if(ch != '(' && ch != ')')
				st.push(ch);
		}
	}
	while(st.isempty() != true )
	{
		op = st.pop();
		poststr.append(1,op);
	}
	return poststr;
}
template <class T>
string Stack<T> :: intopre(string instr)
{
	string poststr, revstr, prestr;
	Stack<char> st;
	char ch;
	for(int i=0; i<instr.length(); i++)
	{
			st.push(instr.at(i));
	}
	while(st.isempty()!= true)
	{
		ch = st.pop();
		if(ch == '(')
			revstr.append(1,')');
		if(ch == ')')
			revstr.append(1,'(');
		else
			revstr.append(1,ch);
	}
	poststr = st.intopost(revstr);
	for(int i=0; i<poststr.length(); i++)
	{
		st.push(poststr.at(i));
	}
	while(st.isempty()!=true)
		prestr.append(1, st.pop());
	return prestr;
}
template <class T>
int Stack<T> :: evaluate(char op, int op2, int op1)
{
	if(op == '+')
		return (op1+op2);
	if(op == '-')
		return (op1-op2);
	if(op == '*')
		return (op1*op2);
	if(op == '/')
		return (op1/op2);
	if(op == '%')
		return (op1%op2);
	if(op == '^')
		return pow(op1,op2);
}
template <class T>
int Stack<T> :: precedence(char ch)
{
	if(ch == '(')
		return 0;
	if(ch == '+' || ch == '-')
		return 1;
	if(ch == '*' || ch == '/' || ch == '%')
		return 2;
	return 3;
}
template <class T>
int Stack<T> :: posteval(string poststr)
{
	Stack<int> st;
	int op1, op2, result, val;
	char ch;

	for(int i=0; i<poststr.length(); i++)
	{
		ch = poststr.at(i);

		if(isalpha(ch))
		{
			cout<<"\nEnter value for"<<ch<<" :";
			cin>>val;
			st.push(val);
		}
		else if(isdigit(ch))
		{
			st.push(((int)ch)-48);
		}
		else
		{
			op1 = st.pop();
			op2 = st.pop();
			result = evaluate(ch, op1, op2);
			st.push(result);
		}
	}
    result = st.pop();
    return result;
}
template <class T>
int Stack<T> :: preeval(string prestr)
{
	Stack<int> st;
	string poststr;
	int result;

	for(int i=0; i<prestr.length(); i++)
		st.push(prestr.at(i));
	while(st.isempty()!=true)
		poststr.append(1,st.pop());

	result = posteval(poststr);
	return result;
}

int main()
{
	Stack<int> s1;
	Stack<char> s2;
	int ch, temp, i, count;
	char ch1, temp1;

	cout<<"******************STACK OPERATIONS***********************";
	cout<<"\nMenu";

	do
	{
		cout<<"\n1.Push\n2.Pop\n3.Display\n4.Infix to Postfix\n5.Postfix Evaluation\n6.Infix to Prefix\n7.Prefix Evaluation"
				"\n8.Exit\n>>";
		cin>>ch;

		switch(ch)
		{
		case 1:
			cout<<"\nPush element in \na.Integet Stack\nb.Character stack";
			cin>>ch1;
			switch(ch1)
			{
			case 'a':
				cout<<"How many integer elements want to push: ";
				cin>>count;
				cout<<"Enter "<<count<<" elements:\n ";
				for(i=0; i<count; i++)
				{
					cin>>temp;
					s1.push(temp);
				}
				break;
			case 'b':
				cout<<"How many character elements want to push: ";
				cin>>count;
				cout<<"Enter "<<count<<" elements:\n ";
				for(i=0; i<count; i++)
				{
					cin>>temp1;
					s2.push(temp1);
				}
				break;
			}
			break;
		case 2:
			cout<<"\npop element from \na.Integet Stack\nb.Character stack";
			cin>>ch1;
			switch(ch1)
			{
			case 'a':
				do
				{
					temp = s1.pop();
					cout<<"\nPoped Element: "<<temp;
					cout<<"\nContinue pop (Y/N)";
					cin>>temp1;
				}while(temp1 == 'Y' || temp1 == 'y');
				break;
			case 'b':
				do
				{
					temp1 = s2.pop();
					cout<<"\nPoped Element: "<<temp1;
					cout<<"\nContinue pop (Y/N)";
					cin>>temp1;
				}while(temp1 == 'Y' || temp1 == 'y');
				break;
			}
			break;
		case 3:
			cout<<"\nInteger Stack: \n";
			s1.display();
			cout<<"\nCharacter Stack: ";
			s2.display();
			break;
		case 4:
			{
				string input, output;
				cout<<"\nEnter Infix expression: ";
				cin>>input;
				output = s2.intopost(input);
				cout<<output;
			}
			break;
		case 5:
			{
				string input, poststr;
				int output;
				cout<<"\nEnter Infix expression: ";
				cin>>input;
				poststr = s2.intopost(input);
				cout<<"\nPostfix Expression : "<<poststr;
				output = s2.posteval(poststr);
				cout<<endl<<output;
			}
			break;
		case 6:
			{
				string input, output;
				cout<<"\nEnter Infix expression: ";
				cin>>input;
				output = s2.intopre(input);
				cout<<output;
			}
			break;
		case 7:
			{
				string input, prestr;
				int output;
				cout<<"\nEnter Infix expression: ";
				cin>>input;
				prestr = s2.intopre(input);
				cout<<"\nPrefix Expression : "<<prestr;
				output = s2.preeval(prestr);
				cout<<endl<<output;
			}
			break;
		case 8:
			exit(0);
		}
	}while(1);


}


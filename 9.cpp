#include<iostream>				//Header files
#include<stdlib.h>
#include<string.h>
using namespace std;

class node{				//Class for element of an array
public:
	int key;
	int tel;
	char name[20];
	int chain;
	node()
	{
		key=-1;
		tel=-1;
		chain=-1;
		name[0]='\0';
	}
};

class hash{						//Class for hashing
	node arr[10];
	char name1[20];
	int tel1;
	int key1;
public:
	hash()						//Default constructor
	{
		name1[0]='\0';
		tel1=-1;
		key1=-1;
	}
	void accept();				//Member Functions
	void display();
	void replacement();
	void wreplacement();
	void swap1(node *,node *);
};
void hash::accept(){
	cout<<"Enter the name of student"<<endl;
	cin>>name1;
	cout<<"Enter the n telephone number"<<endl;
	cin>>tel1;
}
void hash::wreplacement(){//Hashing without replacement
	int i=0;
	int flag=0;
	key1=tel1%10;
	int n=tel1%10;
	int n1=1;
	int key2;

	while(arr[key1].key!=-1)
	{
		if(key1==9)
			key1=0;
		key1=(tel1+i)%10;
		i++;
		flag=1;
	}
	if(i>9)
	{
		cout<<"The chain is full"<<endl;
		return;
	}

	key2=key1;
	arr[key1].key=key1;
	if(flag==0)
	{
		strcpy(arr[key1].name,name1);
		arr[key1].tel=tel1;
		arr[key1].chain=-1;
	}
	else
	{
		arr[key2].tel=tel1;
		strcpy(arr[key2].name,name1);
		if(key1==0)
			key1=10;
		while(n!=(arr[--key1].tel)%10 && n1!=10)
		{
			if(key1==0)
			{
				key1=10;
			}
			n1++;
		}
		if(n1==10)
		{
			arr[n+1].chain=-1;
		}
		else
		{
			arr[key1].chain=key2;
		}
	}
	display();
}
void hash::replacement(){		//Hashing with replacement
	int i=0;
	int flag=0;
	key1=tel1%10;
	int n=tel1%10;
	int n1=1;
	int key2;

	while(arr[key1].key!=-1)
	{
		if(key1==9)
			key1=0;
		key1=(tel1+i)%10;
		i++;
		flag=1;
	}
	if(i>9)
	{
		cout<<"The chain is full"<<endl;
		return;
	}
	key2=key1;
	arr[key1].key=key1;
	if(key1==0)
		key1=10;
	if(flag==0)
	{
		strcpy(arr[key1].name,name1);
		arr[key1].tel=tel1;
		arr[key1].chain=-1;
	}
	else
	{
		arr[key2].tel=tel1;
		strcpy(arr[key2].name,name1);
		while(n!=(arr[--key1].tel)%10 && n1!=10)
		{
			if(key1==0)
				key1=10;
			n1++;
		}
		if(n1==10)
		{
			arr[n+1].chain=-1;
		}
		else
		{
			arr[key1].chain=key2;
		}
	}
	n=tel1%10;
	key1=key2;

	if((arr[n].tel)%10!=n)
	{
		swap1(&arr[n],&arr[key1]);
		while((arr[key2].tel)%10!=(arr[--key1].tel)%10)
		{
			if(key1==0 || key1==-1)
				key1=10;
		}
		arr[key1].chain=arr[key2].key;
	}
	display();
}
void hash::swap1(node *a,node *b)
//Swapping elements in array
{
	node *temp=new node();
	temp->tel=a->tel;
	a->tel=b->tel;
	b->tel=temp->tel;
	temp->chain=a->chain;
	a->chain=b->chain;
	b->chain=temp->chain;
	strcpy(temp->name,a->name);
	strcpy(a->name,b->name);
	strcpy(b->name,temp->name);
}
void hash::display(){
	int i;
	cout<<"Key\t"<<"Name \t"<<"Tel No\t"<<"Chain\t"<<endl;
	for(i=0;i<10;i++)
	{
		cout<<i<<"\t";
		cout<<arr[i].name<<"\t";
		cout<<arr[i].tel<<"\t";
		cout<<arr[i].chain<<"\t";
		cout<<endl;
	}
}
int main()					//main function
{
	hash h;					//object of class
	int ch;
	do
	{
		cout<<"Menu"<<endl;
		cout<<"1.Chaining Without Replacement"<<endl;
		cout<<"2.Chaining With Replacement"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:h.accept();
			   h.wreplacement();
		break;
		case 2:h.accept();
			   h.replacement();
		break;
		case 3:h.display();
		break;
		case 4:exit(0);
		break;
		}
	}while(ch<=4);
}


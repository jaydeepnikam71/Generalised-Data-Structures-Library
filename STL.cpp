#include <iostream>

using namespace std;

#pragma pack(1)


template <class T>
struct snode
{
	T data;
	struct snode * next;

};

template <class T>
struct dnode 
{
	T data;
	struct dnode * next;
	struct dnode *prev;

};


template <class T>

class SinglyLinear
{
	public:
		snode<T> * First;
		int Counter;

	SinglyLinear();

	void InsertFirst(T);
	void InsertLast(T);

	void InsertAtPos(T , int); 

	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);

	void Display();
	int Count();

};

template <class T>
SinglyLinear<T>:: SinglyLinear()
{
	First = NULL;
	Counter = 0;
}

template <class T>
void SinglyLinear<T> :: InsertFirst(T no)
{
	snode<T> * newn = new snode<T>;
	newn->next = NULL;
	newn->data = no;

	if(First == NULL)
	{
		First = newn;

	}
	else if(First != NULL)
	{
		newn->next = First;
		First = newn;
	}
	Counter++;
}

template <class T>
void SinglyLinear<T> :: InsertLast(T no)
{
	snode<T> * newn = new snode<T>;
	newn->next = NULL;
	newn->data = no;

	if(First == NULL)
	{
		First = newn;

	}
	else if(First != NULL)
	{
		snode<T> * temp = First;

		while((temp->next) != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	Counter++;
}

template <class T>
void SinglyLinear<T>  :: InsertAtPos(T no , int pos)
{

	if(pos < 1 || pos > Counter+1  )
	{
		cout<<"invalid postion"<<"\n";
		return;
	}

	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == Counter+1)
	{
		InsertLast(no);
	}
	else
	{
		snode<T> * temp = First;

		snode<T> * newn = new snode<T>;
		newn->data = no;
		newn->next = NULL;

		for(int iCnt = 1 ; iCnt < pos-1 ; iCnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		Counter++;
	}

	
}

template <class T>
void SinglyLinear<T> :: DeleteFirst()
{
	if(First == NULL)
	{
		return;
	}
	else if(First->next == NULL)
	{
		delete First;
	}
	else 
	{
		snode<T> * temp = First;

		First =  First->next;

		delete temp;
		
	}

	Counter--;
}

template <class T>
void SinglyLinear<T> :: DeleteLast()
{
	if(First == NULL)
	{
		return;
	}
	else if(First->next == NULL)
	{
		delete First;
	}
	else 
	{
		snode<T> * temp = First;

		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		delete temp->next;

		temp->next = NULL;
	}

	Counter--;
}

template <class T>
void SinglyLinear<T> :: DeleteAtPos(int pos)
{

	if(pos < 1 || pos > Counter)
	{
		cout<<"invalid position"<<"\n";
		return;
	}

	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == Counter)
	{
		DeleteLast();
	}
	else
	{
		snode<T> * temp1 = First;
		snode<T> * temp2 = NULL;

		for(int Cnt = 1 ; Cnt < pos-1 ; Cnt++)
		{
			temp1 = temp1->next;
		}

		temp2 = temp1->next;

		temp1->next = temp2->next;

		delete temp2;

		Counter--;

	}

	
}


template <class T>
void SinglyLinear<T>  :: Display()
{
	if(First == NULL)
	{
		cout<<"Linked List is Empty"<<"\n";
		return;
	}
	else
	{
		snode<T> * temp = First;

		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp = temp->next;
		}
		cout<<"NULL"<<"\n";
	}
}

template <class T>
int SinglyLinear<T> :: Count()
{
	return Counter;
}




template <class T>
class SinglyCircular
{
	public:

		snode<T> * First;
		snode<T> * Last;
		int Counter;

	SinglyCircular();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);

	void Display();
	int Count();
};

template <class T>
SinglyCircular<T> :: SinglyCircular()
{
	First = NULL;
	Last = NULL;
	Counter = 0;
}

template <class T>
void SinglyCircular<T> :: InsertFirst(T no)
{
	snode<T> * newn = new snode<T>;
	newn->data = no;
	newn->next = NULL;

	if((First == NULL) && (Last == NULL))
	{
		First = Last =  newn;
		Last->next = First;
	}
	else 
	{
		newn->next = First;
		First = newn;
		Last->next = First;
	}
	Counter++;
}

template <class T>
void SinglyCircular<T> :: InsertLast(T no)
{
	snode<T> * newn = new snode<T>;
	newn->data = no;
	newn->next = NULL;

	if((First == NULL) && (Last == NULL))
	{
		First = Last =  newn;
		Last->next = First;
	}
	else 
	{	
		Last->next = newn;
		Last = newn;
		Last->next = First;
			
	}

	Counter++;	
}

template <class T>
void SinglyCircular<T> :: InsertAtPos(T no , int pos)
{
	if(pos < 1 || pos > Counter+1)
	{
		cout<<"Invalid position"<<"\n";
		return;
	}

	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == Counter+1)
	{
		InsertLast(no);
	}
	else
	{
		snode<T> * temp = First;
		snode<T> * newn= new snode<T>;
		newn->data = no;
		newn->next = NULL;

		for(int Cnt = 1 ; Cnt < pos-1; Cnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

		Counter++;

	}
}

template <class T>
void SinglyCircular<T> :: DeleteFirst()
{
	if((First == NULL) && (Last == NULL))
	{
		return;
	}
	else if(First->next == First)
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else
	{	
		First = First->next;
		delete Last->next;
		Last->next = First;
	}

	Counter--;
}

template <class T>
void SinglyCircular<T> :: DeleteLast()
{
	if((First == NULL) && (Last == NULL))
	{
		return;
	}
	else if(First->next == First)
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else
	{	
		snode<T> * temp = First;

		while(temp->next != Last)
		{
			temp = temp->next;
		}
		delete temp->next;
		Last = temp;
		Last->next = First;
	}

	Counter--;

	
}

template <class T>
void SinglyCircular<T> :: DeleteAtPos(int pos)
{
	if(pos < 1 || pos > Counter)
	{
		cout<<"invalid position"<<"\n";
		return;
	}

	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == Counter)
	{
		DeleteLast();
	}
	else
	{
		snode<T> * temp1 = First;
		snode<T> * temp2 = NULL;
		for(int Cnt = 1 ; Cnt < pos-1; Cnt++)
		{
			temp1 = temp1->next;
		}
		temp2 =  temp1->next;
		temp1->next = temp2->next;
		delete temp2;
		
		Counter--;

	}
}
	

template <class T>
void SinglyCircular<T> :: Display()
{
	snode<T> * temp = First;

	if(First == NULL)
	{
		return;
	}

	else
	{
		do
		{
			cout<<"|"<<temp->data<<"|->";
			temp = temp->next;
		}
		while(temp != Last->next);

		cout<<"\n";
	}
}

template <class T>
int SinglyCircular<T> :: Count()
{
	return Counter;
}


template <class T>
class DoublyLinear
{
	public:

		dnode<T> * First;
		int Counter;

	DoublyLinear();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T , int);

	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);

	void Display();
	int Count();
};

template <class T>
DoublyLinear<T> :: DoublyLinear()
{
	First = NULL;
	Counter = 0;
}

template <class T>
void DoublyLinear<T> :: InsertFirst(T no)
{
	dnode<T> * newn = new dnode<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		newn->next = First;
		First = newn;
	}

	Counter++;
}

template <class T>
void DoublyLinear<T> :: InsertLast(T no)
{
	dnode<T> * newn = new dnode<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		dnode<T> * temp = First;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
		newn->prev = temp;

	}

	Counter++;
}

template <class T>
void DoublyLinear<T> :: InsertAtPos(T no , int pos)
{
	int Cnt = Count();

	if(pos < 1 || pos > Cnt+1)
	{
		cout<<"Invalid Position"<<"\n";
		return;
	}

	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == Counter+1)
	{
		InsertLast(no);
	}
	else
	{
		dnode<T> * temp = First;

		dnode<T> * newn = new dnode<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		for(int Cnt = 1; Cnt < pos-1; Cnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;

		Counter++;
	}
}

template <class T>
void DoublyLinear<T> :: DeleteFirst()
{
	if(First == NULL)
	{
		return;
	}
	else if(First->next == NULL)
	{
		delete First;
	}
	else
	{
		dnode<T> * temp = First;

		First = temp->next;

		delete temp;
	}
	Counter--;
}

template <class T>
void DoublyLinear<T> :: DeleteLast()
{
	if(First == NULL)
	{
		return;
	}
	else if(First->next == NULL)
	{
		delete First;
	}
	else
	{
		dnode<T> * temp = First;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->prev->next = NULL;
		delete temp;
		

	}
	Counter--;
}

template <class T>
void DoublyLinear<T> :: DeleteAtPos(int pos)
{
	if(pos < 1 || pos > Counter)
	{
		cout<<"invalid position"<<"\n";
		return;
	}

	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == Counter)
	{
		DeleteLast();
	}
	else
	{
		dnode<T> * temp = First;

		for (int Cnt = 1 ; Cnt < pos-1; Cnt++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;

		delete temp->next->prev;

		temp->next->prev = temp;

		Counter--;

	}
}
	

template <class T>
void DoublyLinear<T> :: Display()
{
	dnode<T> * temp = First;

	if(First == NULL)
	{
		return;
	}

	else
	{
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|<=>";
			temp = temp->next;
		}
		cout<<"NULL\n";
	}
}

template <class T>
int DoublyLinear<T> :: Count()
{
	return Counter;
}


template <class T>
class DoublyCircular
{
	public:
		dnode<T> * First;
		dnode<T> * Last;
		int Counter;

	DoublyCircular();

	void InsertFirst(T);

	void InsertLast(T);

	void InsertAtPos(T,int);

	void DeleteFirst();

	void DeleteLast();

	void DeleteAtPos(int);

	void Display();

	int Count();
};

template <class T>
DoublyCircular<T> :: DoublyCircular()
{
	First = NULL;
	Last = NULL;
	Counter = 0;
}

template <class T>
void DoublyCircular<T> :: InsertFirst(T no)
{
	dnode<T> * newn = new dnode<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((First == NULL) && (Last == NULL))
	{
		First = Last = newn;
		Last->next = First;
	}
	else
	{
		First = newn;
		First->next = Last->next;
		First->prev = Last;
		Last->next = First;

	}
	Counter++;
}

template <class T>
void DoublyCircular<T> :: InsertLast(T no)
{
	dnode<T> * newn = new dnode<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((First == NULL) && (Last == NULL))
	{
		First = Last = newn;
		Last->next = First;
	}
	else
	{
		Last->next = newn;
		newn->prev = Last;
		newn->next = First;
		First->prev = newn;
		Last = newn;
	}
	Counter++;
}


template <class T>
void DoublyCircular<T> :: InsertAtPos(T no , int pos)
{
	if(pos < 1 || pos > Counter+1)
	{
		cout<<"invalid Position"<<"\n";
		return ;
	}

	if(pos == 1)
	{
		InsertFirst(no);
	}
	else if(pos == Counter+1)
	{
		InsertLast(no);
	}
	else
	{
		dnode<T> * temp = First;

		dnode<T> * newn = new dnode<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		for(int Cnt = 1 ; Cnt < pos-1 ; Cnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;


		Counter++;
	}
}

template <class T>
void DoublyCircular<T> :: DeleteFirst()
{
	if((First == NULL) && (Last == NULL))
	{
		return;
	}
	else if(First == First->next)
	{	
		delete First;
		delete Last;
		First = NULL;
		Last = NULL;
	}
	else
	{
		First = First->next;
		First->prev = Last;
		delete Last->next;
		Last->next = First;
	}
	Counter--;
}

template <class T>
void DoublyCircular<T> :: DeleteLast()
{
	if((First == NULL) && (Last == NULL))
	{
		return;
	}
	else if(First == First->next)
	{	
		delete First;
		delete Last;
		First = NULL;
		Last = NULL;
	}
	else
	{
		Last = Last->prev;
		Last->next = First;
		delete First->prev;
		First->prev = Last;
	}
	Counter--;
}

template <class T>
void DoublyCircular<T> :: DeleteAtPos(int pos)
{
	if(pos < 1 || pos > Counter)
	{
		cout<<"invalid Position"<<"\n";
		return ;
	}

	if(pos == 1)
	{
		DeleteFirst();
	}
	else if(pos == Counter)
	{
		DeleteLast();
	}
	else
	{
		dnode<T> * temp = First;
		for(int Cnt = 1 ; Cnt < pos-1; Cnt++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp; 

		Counter--;
	}
}

template <class T>
void DoublyCircular<T> :: Display()
{
	dnode<T> * temp = First;

	do
	{
		cout<<"|"<<temp->data<<"|<=>";
		temp = temp->next;
	}
	while(temp != Last->next);
	cout<<"\n";
}

template <class T>
int DoublyCircular<T> :: Count()
{
	return Counter;
}


template <class T>
class Stack
{
	public:
		snode<T> * First;
		int Counter;

	Stack();
	bool IsEmptyStack();
	void Push(T);
	T Pop();

	void Display();
	int Count();
};

template <class T>
Stack<T> :: Stack()
{
	First = NULL;
	Counter = 0;
}

template <class T>
bool Stack<T> :: IsEmptyStack()
{
	if(Counter == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <class T>
void Stack<T> :: Push(T no)	//InsertFirst()
{
	snode<T> * newn = new snode<T>;
	newn->data = no;
	newn->next = NULL;

	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		newn->next = First;
		First = newn;
	}

	Counter++;
	cout<<no<<" gets pushed in the Stack succesfully"<<"\n";

}

template <class T>
T Stack<T> :: Pop()
{
	T Value;

	if(First == NULL)
	{
		cout<<"unable to Pop the element as Stack is empty\n";
		return(T) -1;	// (T) typecasting
	}

	else if(First->next == NULL)
	{
		 Value = First->data;
		First = NULL;

		Counter--;
		return Value;
	}
	else
	{
		 Value = First->data;

		snode<T> * temp =  First;

		First = First->next;
		delete temp;

		Counter--;
		return Value;
	}
}
template <class T>
void Stack<T> :: Display()
{
	snode<T> * temp = First;

	cout<<"Elements of Stack are : "<<"\n";
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<"\n";
}

template <class T>
int Stack<T> :: Count()
{
	return Counter;
}

template <class T>
class Queue
{
	public:
		snode<T> * First;
		int Counter;

	Queue();
	bool IsEmptyQueue();
	void EnQueue(T);
	T DeQueue();

	void Display();
	int Count();
};

template <class T>
Queue<T> :: Queue()
{
	First = NULL;
	Counter = 0;
}

template <class T>
bool Queue<T>:: IsEmptyQueue()
{
	if(Counter == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template <class T>
void Queue<T> :: EnQueue(T no)	//InsertLast()
{
	snode<T> * newn = new snode<T>;
	newn->data = no;
	newn->next = NULL;

	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		snode<T> * temp = First;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
	}

	Counter++;
	cout<<no<<" gets pushed in the Queue succesfully"<<"\n";

}

template <class T>
T Queue<T> :: DeQueue() //DeleteFirst()
{
	T Value;

	if(First == NULL)
	{
		cout<<"unable to Pop the element as Queue is empty\n";
		return -1;	
	}

	else if(First->next == NULL)
	{
		Value = First->data;
		First = NULL;

		Counter--;
		return Value;
	}
	else
	{
		 Value = First->data;

		snode<T> * temp =  First;

		First = First->next;
		delete temp;

		Counter--;
		return Value;
	}
}

template <class T>
void Queue<T> :: Display()
{
	snode<T> * temp = First;

	cout<<"Elements of Queue is : "<<"\n";
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout<<"NULL"<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
	return Counter;
}


int main()
{
	int Cnt = 0;
	
	cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Singly Linear Linked List\n";

	cout<<"\nInteger data type\n";

	SinglyLinear<int> slbj;

	slbj.InsertFirst(51);
	slbj.InsertFirst(21);
	slbj.InsertFirst(11);

	slbj.InsertLast(101);
	slbj.InsertLast(111);
	slbj.InsertLast(121);
	slbj.InsertAtPos(105,7);
	slbj.Display();
	slbj.DeleteAtPos(5);
	slbj.Display();
	slbj.DeleteFirst();
	slbj.DeleteLast();
	slbj.Display();
	Cnt = slbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";

	cout<<"\nCharecter data type\n";
	SinglyLinear<char> cslbj;

	cslbj.InsertFirst('c');
	cslbj.InsertFirst('b');
	cslbj.InsertFirst('a');

	cslbj.InsertLast('d');
	cslbj.InsertLast('e');
	cslbj.InsertLast('f');
	cslbj.InsertAtPos('g',7);
	cslbj.Display();
	cslbj.DeleteAtPos(5);
	cslbj.Display();
	cslbj.DeleteFirst();
	cslbj.DeleteLast();
	cslbj.Display();
	Cnt = cslbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";	
	
	cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<"Singly Circular Linked List\n";

	cout<<"\nInteger data type\n";

	SinglyCircular<int> scbj;

	scbj.InsertFirst(51);
	scbj.InsertFirst(21);
	scbj.InsertFirst(11);

	scbj.InsertLast(101);
	scbj.InsertLast(111);
	scbj.InsertLast(121);
	scbj.InsertAtPos(105,7);
	scbj.Display();
	scbj.DeleteAtPos(5);
	scbj.Display();
	scbj.DeleteFirst();
	scbj.DeleteLast();
	scbj.Display();
	Cnt = scbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";

	cout<<"\nCharecter data type\n";

	SinglyCircular<char> cscbj;

	cscbj.InsertFirst('c');
	cscbj.InsertFirst('b');
	cscbj.InsertFirst('a');

	cscbj.InsertLast('d');
	cscbj.InsertLast('e');
	cscbj.InsertLast('f');
	cscbj.InsertAtPos('g',7);
	cscbj.Display();
	cscbj.DeleteAtPos(5);
	cscbj.Display();
	cscbj.DeleteFirst();
	cscbj.DeleteLast();
	cscbj.Display();
	Cnt = cscbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";


	cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<" Doubly Linear Linked List\n\n";

	cout<<"\nInteger data type\n";

	DoublyLinear<int> dlbj;

	dlbj.InsertFirst(51);
	dlbj.InsertFirst(21);
	dlbj.InsertFirst(11);

	dlbj.InsertLast(101);
	dlbj.InsertLast(111);
	dlbj.InsertLast(121);
	dlbj.InsertAtPos(105,7);
	dlbj.Display();
	dlbj.DeleteAtPos(5);
	dlbj.Display();
	dlbj.DeleteFirst();
	dlbj.DeleteLast();
	dlbj.Display();
	Cnt = dlbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";

	cout<<"\nCharecter data type\n";
	DoublyLinear<char> cdlbj;

	cdlbj.InsertFirst('c');
	cdlbj.InsertFirst('b');
	cdlbj.InsertFirst('a');

	cdlbj.InsertLast('d');
	cdlbj.InsertLast('e');
	cdlbj.InsertLast('f');
	cdlbj.InsertAtPos('g',7);
	cdlbj.Display();
	cdlbj.DeleteAtPos(5);
	cdlbj.Display();
	cdlbj.DeleteFirst();
	cdlbj.DeleteLast();
	cdlbj.Display();
	Cnt = cdlbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";


	cout<<"\n\n----------------------------------------------------------------\n\n";
	cout<<" Doubly Circular Linked List\n";

	cout<<"\nInteger data type\n";

	DoublyCircular<int> dcbj;

	dcbj.InsertFirst(51);
	dcbj.InsertFirst(21);
	dcbj.InsertFirst(11);

	dcbj.InsertLast(101);
	dcbj.InsertLast(111);
	dcbj.InsertLast(121);
	dcbj.InsertAtPos(105,7);
	dcbj.Display();
	dcbj.DeleteAtPos(5);
	dcbj.Display();
	dcbj.DeleteFirst();
	dcbj.DeleteLast();
	dcbj.Display();
	Cnt = dcbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";

	cout<<"\nCharecter data type\n";

	DoublyCircular<char> cdcbj;

	cdcbj.InsertFirst('c');
	cdcbj.InsertFirst('b');
	cdcbj.InsertFirst('a');

	cdcbj.InsertLast('d');
	cdcbj.InsertLast('e');
	cdcbj.InsertLast('f');
	cdcbj.InsertAtPos('g',7);
	cdcbj.Display();
	cdcbj.DeleteAtPos(5);
	cdcbj.Display();
	cdcbj.DeleteFirst();
	cdcbj.DeleteLast();
	cdcbj.Display();
	Cnt = cdcbj.Count();
	cout<<"Number of elements in Linked list : "<<Cnt<<"\n";

	cout<<"\n\n----------------------------------------------------------------\n\n";

	cout<<"Stack Data Structure\n";

	cout<<"\nInteger data type\n";

	Stack<int> siobj;

	siobj.Push(40);
	siobj.Push(30);
	siobj.Push(20);
	siobj.Push(10);
	siobj.Display();
	int iRet = siobj.Count();
	cout<<"Number of Elements in Stack is : "<<iRet<<"\n";

	iRet = siobj.Pop();
	cout<<"Removed element from Stack is  : "<<iRet<<"\n";
	siobj.Display();
	iRet = siobj.Count();
	cout<<"Number of Elements in Stack is : "<<iRet<<"\n";

	cout<<"\nCharecter data type\n";

	Stack<char> scobj;

	scobj.Push('d');
	scobj.Push('c');
	scobj.Push('b');
	scobj.Push('a');
	scobj.Display();
	iRet = scobj.Count();
	cout<<"Number of Elements in Stack is : "<<iRet<<"\n";

	char cRet = scobj.Pop();
	cout<<"Removed element from Stack is  : "<<cRet<<"\n";
	scobj.Display();
	iRet = scobj.Count();
	cout<<"Number of Elements in Stack is : "<<iRet<<"\n";

	cout<<"\n\n----------------------------------------------------------------\n\n";

	cout<<"Queue Data Structure\n";

	cout<<"\nInteger data type\n";
	Queue<int> qobj;

	qobj.EnQueue(10);
	qobj.EnQueue(20);
	qobj.EnQueue(30);
	qobj.EnQueue(40);

	qobj.Display();

	iRet = qobj.DeQueue();
	cout<<"Removed element from Queue is  : "<<iRet<<"\n";
	qobj.Display();

	iRet = qobj.Count();
	cout<<"Number of elements in Queue is : "<<iRet<<"\n";



	cout<<"\nCharecter data type\n";

	Queue<char> qcobj;

	qcobj.EnQueue('a');
	qcobj.EnQueue('b');
	qcobj.EnQueue('c');
	qcobj.EnQueue('d');

	qcobj.Display();

	cRet = qcobj.DeQueue();
	cout<<"Removed element from Queue is  : "<<cRet<<"\n";
	qcobj.Display();

	iRet = qcobj.Count();
	cout<<"Number of elements in Queue is : "<<iRet<<"\n";

	return 0;
}
#include <iostream>
using namespace std;

struct MaxMin {
	int max;
	int min;
};

class Node2 {
public:
	Node2* prev;
	int data;
	Node2* next;
};

class circularDoublyLinkedList {
private:
	Node2* head;
public:
	circularDoublyLinkedList() { head = NULL; }
	circularDoublyLinkedList(int A[], int n);
	~circularDoublyLinkedList();
	int countNodes();
	void insert(int pos, int x);
	void Delete(int pos);
	void reverse();
	void Display();
};


circularDoublyLinkedList::circularDoublyLinkedList(int A[], int n) {
	head = new Node2;
	head->prev = head;
	head->data = A[0];
	head->next = head;

	Node2* t;
	Node2* last = head;

	for (int i = 1; i < n; i++) {
		t = new Node2;
		t->prev = last;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}

	head->prev = last;
	last->next = head;
}

circularDoublyLinkedList::~circularDoublyLinkedList() {
	Node2* t = head;
	Node2* q = head;

	do {
		q = q->next;
	} while (q->next != head);
	
	while (head != q) {
		head = head->next;
		delete t;
		t = head;
	}
	delete q;
}

void circularDoublyLinkedList::Display() {
	Node2* t = head;
	do {
		cout << t->data << " ";
		t = t->next;
	} while (t != head);
}

void circularDoublyLinkedList::reverse() {
	Node2* p = head;
	Node2* temp;

	while (p) {

		if (p->next == NULL) {
			head = p;
		}
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;

	}
}

int circularDoublyLinkedList::countNodes() {
	Node2* t = head;
	if (head != NULL) {
		int count{ 0 };
		do {
			count += 1;
			t = t->next;
		} while (t != head);
		return count;
	}
	else {
		return 0;
	}
}

void circularDoublyLinkedList::insert(int pos, int x) {
	Node2* p = head;
	Node2* q = head;
	Node2* t = new Node2;
	t->data = x;

	int count = countNodes();

	if (pos == 0) {
		
		if (head != NULL)
		{
			t->next = head;
			head->prev = t;
			head = t;
			do {
				q = q->next;
			} while (q != head);
			t->prev = q;
			q->next = head;
		}
		else {
			t->next = head;
			t->prev = head;
			head = t;
			
		}
	}

	else if (pos > 0 && pos <= count) {
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		t->prev = p;
		t->next = p->next;
		p->next = t;
		if (t->next != NULL) {
			t->next->prev = t;
		}
	}

	else {
		cout << "\n Invalid Position" << endl;
	}

}

void circularDoublyLinkedList::Delete(int pos) {
	Node2* p = head;
	Node2* q = head;
	int count = countNodes();
	if (pos == 1) {
		if (head->next != NULL) {
			do {
				q = q->next;
			} while (q != head);
			head = head->next;
			q->next = head;
			head->prev = q;
		}
		delete p;
	}
	else if (pos <= count) {
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		if (p->next != NULL) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		else {
			p->prev->next = NULL;
		}
		delete p;
	}
	else {
		cout << "\n Invalid Position" << endl;
	}

}

class DoublyLinkedList {
private:
	Node2* first;
public:
	DoublyLinkedList() { first = NULL; }
	DoublyLinkedList(int A[], int n);
	~DoublyLinkedList();
	int countNodes();
	void insert(int pos, int x);
	void Delete(int pos);
	void reverse();
	void Display();
};

DoublyLinkedList::DoublyLinkedList(int A[], int n) {
	first = new Node2;
	first->prev = NULL;
	first->data = A[0];
	first->next = NULL;

	Node2* t ;
	Node2* last = first;

	for (int i = 1; i < n; i++) {
		t = new Node2;
		t->prev = last;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

DoublyLinkedList::~DoublyLinkedList() {
	Node2* t = first;

	while (first != NULL){
		first = first->next;
		delete t;
		t = first;
	}
}

void DoublyLinkedList::Display() {
	Node2* t = first;
	while (t) {
		cout << t->data << " ";
		t = t->next;
	}
}

void DoublyLinkedList::reverse() {
	Node2* p = first;
	Node2* temp;

	while (p) {

		if (p->next == NULL) {
			first = p;
		}
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		
	}
}

int DoublyLinkedList::countNodes() {
	Node2* t = first;
	if (first != NULL) {
		int count{ 0 };
		while (t) {
			count += 1;
			t = t->next;
		}
		return count;
	}
	else {
		return 0;
	}
}

void DoublyLinkedList::insert(int pos,int x) {
	Node2* p  = first;
	Node2* t = new Node2;
	t->data = x;

	int count = countNodes();
	
	if (pos == 0) {
		t->prev = NULL;
		if(first!=NULL)
		{
			t->next = first;
			first->prev = t;
			first = t;
		}
		else {
			t->next = NULL;
			first = t;
		}
	}
	
	else if (pos > 0 && pos <= count) {
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		t->prev = p;
		t->next = p->next;
		p->next = t;
		if (t->next != NULL) {
			t->next->prev = t;
		}
	}

	else {
		cout << "\n Invalid Position" << endl;
	}

}

void DoublyLinkedList::Delete(int pos) {
	Node2* p = first;
	int count = countNodes();
	if (pos == 1) {
		if (first->next != NULL) {
			first = first->next;
		}
		delete p;
	}
	else if(pos<=count){
		for (int i = 0; i < pos; i++) {
			p = p->next;
		}
		if (p->next != NULL) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		else {
			p->prev->next = NULL;
		}
		delete p;
	}
	else {
		cout << "\n Invalid Position" << endl;
	}

}

class Node
{
public:
	int data;
	Node* next;
};

class circularLinkedList {
private:
	Node* head;
public:
	circularLinkedList() { head=NULL; }
	circularLinkedList(int A[], int n);
	Node* gethead();
	void insert(int pos, int x);
	void Delete(int pos);
	void Display();
	int countNodes();
	~circularLinkedList();
};

circularLinkedList::circularLinkedList(int A[], int n) {
	Node* last,*t;
	head = new Node;
	head->data = A[0];
	head->next = head;
	last = head;
	for (int i = 1; i < n; i++) {
			t = new Node;
			t->data = A[i];
			t->next = last->next;
			last->next = t;
			last = t;
	}
}

circularLinkedList::~circularLinkedList() {
	Node* p = head;
	if(head->next!=NULL) {
		head = head->next;
		delete p;
		p = head;
	}
}

int circularLinkedList::countNodes() {
	Node* p = head;
	if (head != NULL) {
		int count{ 1 };
		while (p->next != head) {
			count += 1;
			p = p->next;
		}
		return count;
	}
	else return 0;
}

void circularLinkedList::Delete(int pos) {
	Node* p = head, *q = new Node;
	int count = countNodes();
	if (pos > 1 && pos < count +1) {
		for (int i = 1; i < pos; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		delete p;
	}
	else if (pos == 1) {
		if (head->next != NULL) {
			head = head->next;
		}
		delete p;
	}
	else {
		cout << "\n INVALID POSITION" << endl;
	}
}

void circularLinkedList::insert(int pos, int x) {
	Node* p = head;
	Node* t = new Node;
	int count = countNodes();
	t->data = x;
	if (pos == 0 ) {

		if (head != NULL) {
			while (p->next != head) {
				p = p->next;
			}
			t->next = head;
			p->next = t;
		}
		else {
			t->next = NULL;
			head = t;
		}
	}
	else if (pos>0 && pos<=count){
		for (int i = 1; i < pos; i++) {
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
	else {
		cout << "\nInvalid Index" << endl;
	}
}

Node* circularLinkedList::gethead() {
	return head;
}

void circularLinkedList::Display() {
	Node* t = head;
	do {
		cout << t->data << " ";
		t = t->next;
	} while (t != head);
}

class LinkedList {
private:
	Node* first;
public:
	LinkedList() { first = NULL; }
	LinkedList(int A[], int n);
	Node* getfirst();
	void setfirstToNull();
	int sum();
	int countNodes();
	int Max();
	MaxMin maxmin();
	void Lsearch(int key);
	int Rmax(Node *p);
	void insert(int pos, int x);
	void insertLast(int x);
	void insertSorted(int x);
	void Delete(int pos);
	bool isSorted();
	void removeDuplicate();
	void reverse();
	void Rreverse(Node* q, Node* p);
	void concat(Node* p, Node* second);
	void merge(Node *f,Node *s);
	void Display();
	bool isLOOP();
	~LinkedList();
};

LinkedList::LinkedList(int A[], int n) {
	Node* last, * t;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (int i = 1; i < n; i++) {
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

LinkedList::~LinkedList() {
	Node* p = first;
	while (first) {
		first = first->next;
		delete p;
		p = first;
	}
}

Node* LinkedList::getfirst() {
	return first;
}

void LinkedList::setfirstToNull() {
	first = NULL;
}
void LinkedList::Display() {
	Node* t = first;
	while (t) {
		cout << t->data << " ";
		t = t->next;
	}
}

int LinkedList::sum() {
	int sum{ 0 };
	Node* p = first;
	while (p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int LinkedList::countNodes() {
	int count = 0;
	Node* p = first;
	while (p) {
		count += 1;
		p = p->next;
	}
	return count;
}

int LinkedList::Max() {
	int max = INT_MIN;
	Node* p = first;
	while (p) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int LinkedList::Rmax(Node *p) {
	int x = 0;
	if (p == NULL)
		return INT_MIN;
	else {
		x = Rmax(p->next);
		if (x > p->data) {
			return x;
		}
		else return p->data;
	}
		
}

MaxMin LinkedList::maxmin() {
	MaxMin m;
	Node* p = first;
	m.max = INT_MIN;
	m.min = INT_MAX;

	while (p) {
		if (m.max < p->data) {
			m.max = p->data;
		}
		if (m.min > p->data) {
			m.min = p->data;
		}
		p = p->next;
	}

	return m;

}

void LinkedList::Lsearch(int key) {
	int flag = 0;
	Node* q = NULL;
	Node* p = first;
	while (p) {
		if (p->data == key) {
			flag = 1;
			q->next = p->next;
			p->next = first;
			first = p;
		}
		q = p;
		p = p->next;
	}

	if (flag == 1) {
		cout << "\nElement found!!" << endl;
	}
	else {
		cout << "Element Not Found" << endl;
	}
}

void LinkedList::insert(int pos, int x) {
	Node* p,*t;
	if (pos == 0) {
		t = new Node;
		t->data = x;
		t->next = first;
		first = t;
	}
	else if (pos > 0) {
		p = first;
		for (int i = 0; i < pos; i++) {
			p = p->next;
		}
		t = new Node;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
	
}

void LinkedList::insertLast(int x) {
	Node *t,*last;
	last = first;
	t = new Node;
	t->data = x;
	t->next = NULL;
	if(!first){
		last = t;
		first = t;
	}
	else {
		while (last->next!=NULL) {
			last = last->next;
		}
		last->next = t;
		last = t;
	}
	cout << "Element Inserted!" << endl;
	Display();
}

void LinkedList::insertSorted(int x) {
	Node* t = new Node;
	t->data = x;
	Node* p = first;
	Node* last=new Node;
	if (p == NULL) {
		t->next = NULL;
		p =last= t;
		first = p;
	}
	else if (p) {
		while (p && p->data<x) {
			last = p;
			p = p->next;
		}
		if (x == 0) {
			t->next = p;
			first=last = t;
		}
		else {
			t->next = p;
			last->next = t;
		}
	}
	Display();
}

void LinkedList::Delete(int pos) {
	int x;
	Node* p = first;
	Node* last = new Node;
	if (pos == 1) {
		first = first->next;
		x = p->data;
		delete p;
	}
	else if (pos > 1) {
		for (int i = 0; i < pos-1 && p; i++) {
			last = p;
			p = p->next;
		}
		last->next = p->next;
		x = p->data;
		delete p;
	}

	cout << "Element " << x << " deleted successfully !!" << endl;
	Display();
}

bool LinkedList::isSorted() {
	Node* p = first;
	int x = INT_MIN;
	while (p) {
		if (p->data >= x) {
			x = p->data;
			p = p->next;
		}
		else {
			return false;
		}
	}
	return true;

}

void LinkedList::removeDuplicate() {
	Node* p = first;
	Node* q = p->next;

	while(q){

		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			delete q;
			q = p->next;
		}
			
	}

	Display();

}

void LinkedList::reverse() {
	Node* p = first;
	Node* q = NULL;
	Node* r = NULL;
	while (p!=NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	first = q;
	Display();
}

void LinkedList::Rreverse(Node* q, Node* p) {
	if (p != NULL) {
		Rreverse(p, p->next);
		p->next = q;
	}
	else {
		first = q;
	}

}

void LinkedList::concat(Node* p, Node* second) {
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = second;
}

void LinkedList::merge(Node *f,Node *s) {
	Node* third = NULL, * last = NULL;
	if (f->data < s->data) {
		third = last = first;
		f = f->next;
		last->next = NULL;
	}
	else if (f->data > s->data) {
		third = last = s;
			s = s->next;
			last->next = NULL;
	}

	while (f && s) {
		if (f->data < s->data) {
			last->next = f;
			last = f;
			f = f->next;
			last->next = NULL;
		}
		else if (f->data > s->data) {
			last->next = s;
			last = s;
			s = s->next;
			last->next = NULL;
		}
	}

	if (f) {
		last->next = f;
		f = f->next;
	}
	else {
		last->next = s;
		s = s->next;
	}

	Display();
}

bool LinkedList::isLOOP() {
	Node* p, * q;
	p = q = first;

	do {
		p = p->next;
		q = q->next;
		q = q != NULL ? q->next : q;
	} while (p && q && p != q);

	if (p == q) {
		return true;
	}
	else {
		return false;
	}
}
struct choice {
	int main_choice;
	int sub_choice;
};

int subchoices(choice &c) {
	do {
		cout << "\nEnter the operation, you want to perform on this LinkedList" << endl;
		cout << "[1]- Sum of elements of the LinkedList" << endl;
		cout << "[2]- Count Number of Nodes of the LinkedList" << endl;
		cout << "[3]- Get the Maximum and Minimum element of the LinkedList" << endl;
		cout << "[4]- Search an element in the LinkedList" << endl;
		cout << "[5]- Insert an element in the LinkedList" << endl;
		cout << "[6]- Insert an element at the end of the LinkedList" << endl;
		cout << "[7]- Insert the element in a sorted LinkedList" << endl;
		cout << "[8]- Delete an element in the LinkedList" << endl;
		cout << "[9]- Check if the LinkedList is Sorted?" << endl;
		cout << "[10]- Remove Duplicate elements in the LinkedList" << endl;
		cout << "[11]- Reverse the LinkedList" << endl;
		cout << "[12]- Concat a new LinkedList to the existing one" << endl;
		cout << "[13]- Merge a new LinkedList to the existing one" << endl;
		cout << "[14]- Display the LinkedList" << endl;
		cout << "[15]- Check if the LinkedList is loop" << endl;
		cout << "[0] - GO to Main Menu" << endl;
		cout << "\n Enter your choice : ";
		cin >> c.sub_choice;
		return c.sub_choice;
	} while (c.sub_choice != 0);
}

int subchoices2(choice& c) {
	do {
		cout << "\nEnter the operation, you want to perform on this LinkedList" << endl;
		cout << "[1]- Count Number of Nodes of the LinkedList" << endl;
		cout << "[2]- Insert an element in the LinkedList" << endl;
		cout << "[3]- Delete an element in the LinkedList" << endl;
		cout << "[4]- Display the LinkedList" << endl;
		cout << "[0] - GO to Main Menu" << endl;
		cout << "\n Enter your choice : ";
		cin >> c.sub_choice;
		return c.sub_choice;
	} while (c.sub_choice != 0);

}

int subchoices3(choice& c) {
	do {
		cout << "\nEnter the operation, you want to perform on this LinkedList" << endl;
		cout << "[1]- Count Number of Nodes of the LinkedList" << endl;
		cout << "[2]- Insert an element in the LinkedList" << endl;
		cout << "[3]- Delete an element in the LinkedList" << endl;
		cout << "[4]- Display the LinkedList" << endl;
		cout << "[5]- Reverse the LinkedList" << endl;
		cout << "[0] - GO to Main Menu" << endl;
		cout << "\n Enter your choice : ";
		cin >> c.sub_choice;
		return c.sub_choice;
	} while (c.sub_choice != 0);

}
int main() {
	choice ch;
	cout << "########## LINKED LIST ############" << endl;
	cout << "\nEnter the type of Linkedlist you want to create" << endl;
	do {
		cout << "[1]- Singly LinkedList" << endl;
		cout << "[2]- Circular Singly LinkedList" << endl;
		cout << "[3]- Doubly LinkedList" << endl;
		cout << "[4]- Circular Doubly LinkedList" << endl;
		cout << "[0] - Quit the App" << endl;
		cout << "\nEnter Your choice : ";
		cin >> ch.main_choice;

		if (ch.main_choice == 1) {
			int* A;
			int n;
			cout << "\nEnter the Number of element you want to enter in the LinkedList : ";
			cin >> n;
			A = new int[n];
			cout << "Enter the elements : " << endl;
			for (int i = 0; i < n; i++) {
				cout << "\nEnter element " << i + 1 << " : ";
				cin >> A[i];
			}
			cout << endl;

			LinkedList L(A, n);
			do {
				subchoices(ch);
				if (ch.sub_choice == 1) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					cout << "\nAnd the sum of the list is : " << L.sum() << endl << endl;
				}
				else if (ch.sub_choice == 2) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					cout << "The Number of Nodes : " << L.countNodes() << endl << endl;
				}
				else if (ch.sub_choice == 3) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					MaxMin M = L.maxmin();
					cout << "MAX : " << M.max << " and MIN : " << M.min << endl << endl;
				}
				else if (ch.sub_choice == 4) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					int key{ 0 };
					cout << "Enter the element, you want to search : ";
					cin >> key;
					cout << endl;
					L.Lsearch(key);
					cout << endl;
				}
				else if (ch.sub_choice == 5) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
					int elem;
					int pos;

					cout << "Enter the element you want to enter in the List : ";
					cin >> elem;
					cout << "At which position do you want to enter this element : ";
					cin >> pos;
					L.insert(pos, elem);

					cout << "\nInserted element Successfully" << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 6) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

					int elem;
					cout << "Enter the element you want to enter in the List : ";
					cin >> elem;

					L.insertLast(elem);

					cout << "\nInserted element Successfully" << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

				}
				else if (ch.sub_choice == 7) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

					int elem;
					cout << "Enter the element you want to enter in the List : ";
					cin >> elem;
					if (L.isSorted()) {
						L.insertSorted(elem);

						cout << "\nInserted element Successfully" << endl;
						cout << "\nThe Linked List is : " << endl;
						L.Display();
					}
					else {
						cout << "List is not sorted!!";
					}

					cout << endl << endl;
				}
				else if (ch.sub_choice == 8) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

					int pos;
					cout << "Enter the position of the element you want to delete : ";
					cin >> pos;

					L.Delete(pos);
					cout << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

				}
				else if (ch.sub_choice == 9) {
					cout << "\nThe Linked List is : " << endl;
					if (L.isSorted()) {
						cout << "List is sorted!!";
					}
					else {
						cout << "List is not sorted!!";
					}
					cout << endl << endl;
				}
				else if (ch.sub_choice == 10) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					L.removeDuplicate();
					cout << "\nThe Updated Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 11) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					L.reverse();
					cout << "\nThe Reversed Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

				}
				else if (ch.sub_choice == 12) {
					int* B;
					cout << "\nEnter the Number of element you want to enter in the LinkedList : ";
					cin >> n;
					B = new int[n];
					cout << "Enter the elements : " << endl;
					for (int i = 0; i < n; i++) {
						cout << "\nEnter element " << i + 1 << " : ";
						cin >> B[i];
					}
					cout << endl;

					LinkedList L1(B, n);

					cout << "\nThe Concatenated Linked List is : " << endl;
					L.concat(L.getfirst(), L1.getfirst());
					L1.setfirstToNull();
					L.Display();
					cout << endl << endl;
					delete[] B;

				}
				else if (ch.sub_choice == 13) {
					int* B;
					cout << "\nEnter the Number of element you want to enter in the LinkedList : ";
					cin >> n;
					B = new int[n];
					cout << "Enter the elements : " << endl;
					for (int i = 0; i < n; i++) {
						cout << "\nEnter element " << i + 1 << " : ";
						cin >> B[i];
					}
					cout << endl;

					LinkedList L1(B, n);

					cout << "\nThe Concatenated Linked List is : " << endl;
					L.merge(L.getfirst(), L1.getfirst());
					L1.setfirstToNull();
					L.Display();
					cout << endl << endl;
					delete[] B;
				}
				else if (ch.sub_choice == 14) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 15) {
					if (L.isLOOP()) {
						cout << "The List is a Loop" << endl << endl;
					}
					else {
						cout << "The List is Not a Loop" << endl << endl;
					}
				}
			} while (ch.sub_choice != 0);
			delete[] A;
		}
		else if (ch.main_choice == 2) {
			int* A;
			int n;
			cout << "\nEnter the Number of element you want to enter in the LinkedList : ";
			cin >> n;
			A = new int[n];
			cout << "Enter the elements : " << endl;
			for (int i = 0; i < n; i++) {
				cout << "\nEnter element " << i + 1 << " : ";
				cin >> A[i];
			}
			cout << endl;

			circularLinkedList L(A, n);

			do {
				subchoices2(ch);
				if (ch.sub_choice == 1) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					cout << "The Number of Nodes : " << L.countNodes() << endl << endl;
				}
				else if (ch.sub_choice == 2) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
					int elem;
					int pos;

					cout << "Enter the element you want to enter in the List : ";
					cin >> elem;
					cout << "At which position do you want to enter this element : ";
					cin >> pos;
					L.insert(pos, elem);

					cout << "\nInserted element Successfully" << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 3) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

					int pos;
					cout << "Enter the position of the element you want to delete : ";
					cin >> pos;

					L.Delete(pos);
					cout << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 4) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
			} while (ch.sub_choice != 0);
		}
		else if (ch.main_choice == 3) {
			int* A;
			int n;
			cout << "\nEnter the Number of element you want to enter in the LinkedList : ";
			cin >> n;
			A = new int[n];
			cout << "Enter the elements : " << endl;
			for (int i = 0; i < n; i++) {
				cout << "\nEnter element " << i + 1 << " : ";
				cin >> A[i];
			}
			cout << endl;

			DoublyLinkedList L(A, n);

			do {
				subchoices3(ch);
				if (ch.sub_choice == 1) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl;
					cout << "The Number of Nodes : " << L.countNodes() << endl << endl;
				}
				else if (ch.sub_choice == 2) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
					int elem;
					int pos;

					cout << "Enter the element you want to enter in the List : ";
					cin >> elem;
					cout << "At which position do you want to enter this element : ";
					cin >> pos;
					L.insert(pos, elem);

					cout << "\nInserted element Successfully" << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 3) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;

					int pos;
					cout << "Enter the position of the element you want to delete : ";
					cin >> pos;

					L.Delete(pos);
					cout << endl;
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 4) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
				else if (ch.sub_choice == 5) {
					cout << "\nThe Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
					L.reverse();
					cout << "\nThe Reversed Linked List is : " << endl;
					L.Display();
					cout << endl << endl;
				}
			} while (ch.sub_choice != 0);
				delete[] A;
		}
		else if (ch.main_choice == 4) {
		int* A;
		int n;
		cout << "\nEnter the Number of element you want to enter in the LinkedList : ";
		cin >> n;
		A = new int[n];
		cout << "Enter the elements : " << endl;
		for (int i = 0; i < n; i++) {
			cout << "\nEnter element " << i + 1 << " : ";
			cin >> A[i];
		}
		cout << endl;

		circularDoublyLinkedList L(A, n);

		do {
			subchoices3(ch);
			if (ch.sub_choice == 1) {
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl;
				cout << "The Number of Nodes : " << L.countNodes() << endl << endl;
			}
			else if (ch.sub_choice == 2) {
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl << endl;
				int elem;
				int pos;

				cout << "Enter the element you want to enter in the List : ";
				cin >> elem;
				cout << "At which position do you want to enter this element : ";
				cin >> pos;
				L.insert(pos, elem);

				cout << "\nInserted element Successfully" << endl;
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl << endl;
			}
			else if (ch.sub_choice == 3) {
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl << endl;

				int pos;
				cout << "Enter the position of the element you want to delete : ";
				cin >> pos;

				L.Delete(pos);
				cout << endl;
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl << endl;
			}
			else if (ch.sub_choice == 4) {
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl << endl;
			}
			else if (ch.sub_choice == 5) {
				cout << "\nThe Linked List is : " << endl;
				L.Display();
				cout << endl << endl;
				L.reverse();
				cout << "\nThe Reversed Linked List is : " << endl;
				L.Display();
				cout << endl << endl;
			}
		} while (ch.sub_choice != 0);
		delete[] A;
		}

		} while (ch.main_choice != 0);

}
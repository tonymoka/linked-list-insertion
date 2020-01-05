#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* link;
};

Node* head;

void Insert(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->link = head;
	head = temp;
	/*if (head != NULL)
		temp->link = head;
	head = temp;*/
}
void Print() {
	Node* temp = head;
	cout << ("List is: ");
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->link;
	}
	printf("\n");
}
void addnode1(Node* new_node)
{ 
	Node* temp = head;
	while (temp != NULL)
	{
		//cout << temp->data;
		temp = temp->link;
	}
	new_node->link = head;
	head = new_node;
}
void addnodemid(int pos, int new_data)
{
	Node* insert = new Node();
	insert->data = new_data;
	//insert->link = prev_node->link;
	//prev_node->link = insert;
	//cout << prev_node->data;
	Node* temp = head;
	int count = 0;
	while (count != pos-1)
	{
		temp = temp->link;
		count++;
	}
	insert->link = temp->link;
	temp->link = insert;
}
void Insert2(int data, int n)
{
	Node* temp1 = new Node(); //creating the new node
	temp1->data = data; // putting data in my node
	temp1->link = NULL; // assgin a Null address
	if (n == 1) // if the nth postion is at the begging of the linked list
	{
		temp1->link = head; // assgin the address in head node to temp.link
		head = temp1;// assgin the temp1 add to head
		return;
	}
	Node* temp2 = head; // copy of the head node to traverse the linked list
	int count = 0;// if using while loop will need a counter to know which postion are we at
	/*while (count != n - 1) // the "-1" is b/c we start counting for 0
	{
		temp2 = temp2->link; //moving from node to the next
		count++;// counting each node
	}*/
	for (int i = 0; i < n - 2; i++) //another way to travers the linkedlist
	{
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}


int main() {
	head = NULL;
	cout << "How many numbers? \n";
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the number \n";
		cin >> x;
		Insert(x);
	}
	Print();
	cout << "Head->link " << head->link<< endl;
	Insert2(5, 2);// list 5: 5 4 3 2 1 -> 1 5 2 3 4 5
	//addnodemid(1, 5);
		Print();
}
/*Node* temp = new Node();
temp->data = 2;
temp->link = Null;
A = temp;
Node* temp1 = A;
while (temp1 != NULL)
{
	temp1 = temp->link;
}*/
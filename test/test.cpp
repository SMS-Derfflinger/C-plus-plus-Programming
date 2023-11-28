#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val, Node* link) : data(val), next(link) {}
};

int size(Node* head)
{
	int num = 0;
	Node* cur = head;
	while (cur != nullptr)
	{
		num++;
		cur = cur->next;
	}
	return num;
}

void prepend(Node*& head, int num)
{
	Node* newNode = new Node(num, head);
	head = newNode;
}

void insert(Node*& head, int seat, int num)
{
	Node* newNode = new Node(num, nullptr);
	if (seat < 0 || size(head) < seat)
		return;
	Node* cur = head;
	for (int i = 0; i < seat - 1; i++)
		cur = cur->next;
	newNode->next = cur->next;
	cur->next = newNode;
}

void remove(Node*& head, int seat)
{
	Node* tmp = head;
	Node* cur = tmp;
	if (seat < 0 || size(head) < seat)
		return;
	if (seat == 1)
	{
		head = head->next;
		delete tmp;
		return;
	}
	for (int i = 0; i < seat - 1; i++)
	{
		cur = tmp;
		tmp = tmp->next;
	}
	cur->next = tmp->next;
	delete tmp;
}

void add(Node*& head, int num)
{
	Node* newNode = new Node(num,nullptr);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	Node* end = head;
	while (end->next != nullptr)
		end = end->next;
	end->next = newNode;
}

void free(Node*& head)
{
	while (head != nullptr)
	{
		Node* next = head->next;
		delete head;
		head = next;
	}
}

void printRev(Node* head)
{
	if (head == nullptr)
		return;
	cout << head->data << endl;
	printRev(head->next);
}

void print(Node* head)
{
	Node* cur = head;
	while (cur != nullptr)
	{
		cout << cur->data << endl;
		cur = cur->next;
	}
}

Node* reverse(Node* head)
{
	Node* cur, * prev, * next;
	prev = nullptr;
	cur = head;
	while (cur != nullptr)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
	return head;
}

int main()
{
	Node* head = new Node(1, nullptr);
	add(head, 2);
	add(head, 3);
	/*insert(head, 1, 300);
	prepend(head, 0);
	print(head);
	cout << "length:" << size(head) << endl;
	remove(head, 1);*/
	print(head);
	head = reverse(head);
	print(head);
	return 0;
}


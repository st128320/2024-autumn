#include<iostream>
struct Node
{
	int data;
	Node* next;
	Node (int data,Node* next=nullptr):data(data),next(next)
	{ }
	~Node()
	{
		data = 0;
		next = nullptr;
	}
};
class LinkedList
{
private:
	Node* head;
	void Clear()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			Node* t = temp;
			temp = temp->next; 
			delete t;
			
		}
	}
	void InsertHeadNode(Node* node)
	{
		node->next = head;
		head = node;
	}
	void InsertTailNode(Node* node)
	{
		if (IsEmpty())
		{
			return InsertHeadNode(node);
		}
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = node;
		node->next = nullptr;
	}
	void InsertNode(Node* node, int index)
	{
		if (index == 0)
		{
			return InsertHeadNode(node);
		}
		Node* temp = head;
		for (int i = 0; i < index && temp != nullptr; ++i)
		{
			temp = temp->next;
		}
		if (temp != nullptr)
		{
			node->next = temp->next;
			temp->next = node;
		}
		else
		{
			delete node;
		}
	}
	Node* ExtractHeadNode()
	{
		if (IsEmpty())
		{
			return nullptr;
		}
		Node* res = head;
		head = head->next;
		res->next = nullptr;
		return res;
	}
	Node* ExtractTailNode()
	{
		if (IsEmpty())
		{
			return nullptr;
		}
		if (head->next == nullptr)
		{
			return ExtractHeadNode();
		}
		Node* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		Node* res = temp;
		temp->next = nullptr;
		return res;
	}
	Node* ExtractNode(int index)
	{
		if (IsEmpty())
		{
			return nullptr;
		}
		if (index == 0)
		{
			return ExtractHeadNode();
		}
		Node* temp = head;
		for (int i = 0; i < index - 1 && temp->next != nullptr; ++i)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			return nullptr;
		}
		Node* res = temp->next;
		temp->next = temp->next->next;
		res->next = nullptr;
		return res;
	}
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { Clear(); }
	bool IsEmpty()
	{
		return(head == nullptr);
	}
	int lenght()
	{
		int res = 0;
		Node* temp = head;
		while (temp != nullptr)
		{
			++res;
			temp = temp->next;
		}
		return res;
	}
	void swap(int ind1, int ind2)
	{
		if (ind1 == ind2)
		{
			return;
		}
		if (ind1 > ind2)
		{
			return swap(ind2, ind1);
		}
		Node* node2 = ExtractNode(ind2);
		Node* node1 = ExtractNode(ind1);
		InsertNode(node2, ind1);
		InsertNode(node1, ind2);
	}
	int get(int index)
	{
		Node* temp = head;
		for (int i = 0; i < index && temp != nullptr; ++i)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			return -1;
		}
		else
		{
			return temp->data;
		}
	}
	void sort()
	{
		for (int i = 0; i < lenght(); ++i)
		{
			for (int j = 0; j < lenght(); ++j)
			{
				if (get(i) > get(j))
				{
					swap(i, j);
				}
			}
		}
	}
	void Insert(int element, int index)
	{
		return InsertNode(new Node(element), index);
	}
	void print()
	{
		Node* temp = head;
		while(temp!=nullptr)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
			
		}
		return;
	}
	void InsertHead(int element)
	{
		return Insert(element, 0);
	}
	void InsertTail(int element)
	{
		return InsertTailNode(new Node(element));
	}
	int ExtractHead()
	{
		
		if (IsEmpty())
		{
			return 0;
		}
		Node* res = head;
		head = head->next;
		res->next = nullptr;
		return res->data;
		
	}
	int ExtractTail()
	{
		if (IsEmpty())
		{
			return 0;
		}
		if (head->next == nullptr)
		{
			return ExtractHead();
		}
		Node* temp = head;
		while (temp->next->next !=nullptr)
		{
			temp = temp->next;
		}
		Node* res = temp->next;
		temp-> next= nullptr;
		return res->data;


	}
	int Extract(int index)
	{
		if (index == 0)
		{
			return ExtractHead();
		}
		Node* temp = head;
		for (int i = 0; i < index - 1 && temp->next!=nullptr; ++i)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr) 
		{
			return -1;
		}
		Node* res = temp->next;
		temp->next = temp->next->next;
		res->next = nullptr;
		return res->data;
	}

};
int main(int argc, char* argv[])
{
	LinkedList list;

	return 0;

}
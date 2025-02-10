#include <iostream>
#include <func01.hpp>



int main()
{    
	AAA::Node* head;
	Make(head);
	PushBack(head, 1);
	PushBack(head, 3);
	PushBack(head, 5);
	print(head);
	//remov(head, 0);
	//print(head);
	clear(head);

	/*AAA::Node* head = new AAA::Node {0, nullptr};

	//void PushBack(Node* head, int value)

	AAA::Node* q = new AAA::Node;
	q->data = 100500;
	q->next = nullptr;
	head->next = q; 
    
	std::cout << q->data << std::endl;*/

	return 0;
}

#include <iostream>
#include <func.hpp>

namespace AAA
{
    void PushBack(Node* head, int value)
    {
        while(head->next != nullptr)
            head = head->next;
    
        Node* q = new Node;
        q->data = value;
        q->next = nullptr;
        head->next = q; 
    
    }
    
    void print(Node* head)
    {
        while(head != nullptr)
        {
            std::cout << head->data << std::endl;
            head = head->next;
        }
    }

    void remov(Node* head, int index)
    {
        int i = 0;
        while((head->next != nullptr) && (i!=index))
        {
            i++;
            head = head->next;
        }

        if(head->next == nullptr)
            return;
        
        Node* tmp = head->next;
        head->next = head->next->next;
        delete tmp;
    }

    void clear(Node* head)
    {
        while(head->next != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void Make(Node*& head)
    {
        head = new Node {0, nullptr};
    }
}

#include <iostream>
#include <func01.hpp>

namespace mt
{
    void AddBack(Node* sent, int data) 
    {
        Node* p = new Node;
        p->data = data;
        p->next = sent;
        p->prev = sent->prev;
        sent->prev->next = p;
        sent->prev = p;
    }

    void Print(Node* sent) 
    {
        std::cout << "--- --- ---" << std::endl;
        Node* p = sent->next;
        while(p != sent) {
            std::cout << p->data << std::endl;
            p = p->next;
        }
    }
    
    void Clear(Node* sent) 
    {
        Node* p = sent->next;
        while(p != sent) {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
    }

    bool ContainsThree(int data) 
    {
        while(data > 0) {
            if(data%10 == 3)
                return true;
            data = data / 10;
        }
        return false;
    }

    void DeleteThree(Node* sent) 
    {
        Node* p = sent->next;
        while(p != sent) {
            if(ContainsThree(p->data)) {
                Node* tmp = p;
                p->prev->next = p->next;
                p->next->prev = p->prev;
                p = p->prev;
                delete tmp;
            }
            p = p->next;
        }
    }

    bool ContainsSeven(int data) 
    { 
        while(data > 0) {
            if(data%10 == 7)
                return true;
            data = data / 10;
        }
        return false;
    }
    
    void DuplicateSeven(Node* sent) 
    {
        Node* p = sent->next;
        while(p != sent) {
            if(ContainsSeven(p->data)) {
                Node* q = new Node;
                q->data = p->data;
                q->prev = p;
                q->next = p->next;
                p->next->prev = q;
                p->next = q;
                p = p->next;
            }
            p = p->next;
        }
    }

    bool TwoEqualDatas(Node* sent, int n) 
    {
        Node* p = sent->next; 
        for(int i=0;i<n-1;i++) {
            
            Node* q = p->next;
    
            for(int j=i+1;j<n;j++) {
                if(q->data == p->data) { 
                    return true;
                    break;
                } 
                q = q->next;
            }
            p = p->next;
        }
        return false;
    }

    void SortByLastDigit(Node* sent, int n) 
    {
        Node* p = sent->next; 
        for(int i=0;i<n-1;i++) {

            Node* q = p->next;
    
            for(int j=i+1;j<n;j++) {
                if((q->data)%10 > (p->data)%10) { 
                    int tmp = p->data;
                    p->data = q->data;
                    q->data = tmp;
                }
                q = q->next;
            }
            p = p->next;
        }
    }
}

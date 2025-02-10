# pragma once


namespace AAA
{
    #pragma pack(push, 1)
    struct Node
    {
        int data;
        Node* next;
    };
    #pragma pack(pop)
    
    void PushBack(Node* head, int value);
    void print(Node* head);
    void remov(Node* head);
    void clear(Node* head);
    void Make(Node*& head);
}

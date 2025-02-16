#pragma once

namespace mt
{
    struct Node {
        int data; // 4 + 4
        Node* prev; // 8
        Node* next; // 8
    };

    void AddBack(Node* sent, int data);

    void Print(Node* sent);
    void Clear(Node* sent);

    bool ContainsThree(int data);
    void DeleteThree(Node* sent);
    
    bool ContainsSeven(int data);
    void DuplicateSeven(Node* sent);
    
    bool TwoEqualDatas(Node* sent, int n);

    void Sort(Node* sent, int n);
    //void Sort();
    
}

//
// Created by Bulut Gözübüyük on 20.05.2020.
// Taken from Carrano book
//

#ifndef CS201HW4_STACK_H
#define CS201HW4_STACK_H

const int MAX_STACK = 100;

template<class ItemType>
class Stack{
private:
    ItemType items[MAX_STACK];
    int top;

public:
    Stack();
    bool isEmpty() const;

    bool push(const ItemType &newEntry);

    bool pop();

    ItemType peek() const;
};

#endif //CS201HW4_STACK_H

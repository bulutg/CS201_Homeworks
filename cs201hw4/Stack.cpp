//
// Created by Bulut Gözübüyük on 20.05.2020.
// Taken from Carrano book
//
#include <cassert>
#include "Stack.h"

template<class ItemType>
Stack<ItemType>::Stack() : top(-1) {
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const {
    return top < 0;
}

template<class ItemType>
bool Stack<ItemType>::push(const ItemType &newEntry) {
    bool result = false;
    if (top < MAX_STACK - 1)
    {
        top++;
        items[top] = newEntry;
        result = true;
    }
    return result;
}

template<class ItemType>
bool Stack<ItemType>::pop() {
    bool result = false;
    if (!isEmpty()) {
        top--;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType Stack<ItemType>::peek() const {
    assert(!isEmpty());
    return items[top];
}

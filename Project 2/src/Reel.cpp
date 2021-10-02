#include "Reel.hpp"
#include <iostream>

void Reel::MakeEmpty() {
    ReelNode* temp = nullptr;
    ReelNode* temp2 = head;
    while(head->next != nullptr){
        temp = head;
        if(head->next == temp2) {
            head->next = nullptr;
        } else {
            head = head->next;
        }
        delete temp;
    }
    length = 0;

}

void Reel::DeleteItem(Item item) {
// Empty case
    if(head == nullptr)
        return;
    
    ReelNode* temp;
    // Deleting head
    if(head->data == item){
        temp = head->next;
        ReelNode* temp2 = new ReelNode();
        temp2 = head->next;
        while(temp2->next != head) { //Find the node that points to the head
            temp2 = temp2->next;
        }
        
        temp2->next = temp;
        delete head;
        head = temp;
        length--;
        return;
    }
    
    // Deleting further in the list
    temp = head;
    while(temp->next != head){
        if(temp->next->data == item){
            ReelNode* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            length--;
            return;
        }
        temp = temp->next;
    }

}

void Reel::PutItem(Item item) {
    ReelNode* temp = new ReelNode;
    temp -> data = item;
    if(length == 0) { //First Item
        temp->next = temp;
        head = temp;
    } else if(length == 1) { //Second Item
        head->next = temp;
        temp->next = head;
    } else if(length > 1) { //All Items past second Item
        ReelNode* temp2 = head->next;
        head->next = temp;
        temp->next = temp2;
    }
    length++;
}

Item Reel::GetItem(Item item) {
    ReelNode* temp = head;
    if(temp->data == item){
        return temp->data;
    }
    temp = temp->next;
    while(temp != head){
        if(temp->data == item){
            return temp->data;
        }
        temp = temp->next;
    }
    throw "not found";
    
}

void Reel::ResetList() {
    currentPos = head;
}

Item Reel::GetNextItem() {
    if((currentPos == nullptr)) {
        currentPos = head;
    }      //The reel is messed up
    
    Item data = currentPos -> data;
    currentPos = currentPos -> next;
    return data;
}

int Reel::GetLength() {
        return length;
}

Reel::~Reel() {
    MakeEmpty();
}

std::ostream& operator<<(std::ostream& os, Reel& o){
    o.ResetList();
    os << "List: [";
    for(int i = 0; i < o.GetLength(); ++i){
        os << "(" << o.GetNextItem() << ")";
        if (i < o.GetLength() - 1) os << ", ";
    }
    os << "]";
    return os;
}
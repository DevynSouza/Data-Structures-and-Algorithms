//
//  UnorderedLinkedList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2020 Eugene Lymar. All rights reserved.
//

#include "UnorderedLinkedList.hpp"
void UnorderedLinkedList::MakeEmpty(){
	Node* temp = nullptr; 
	while(head != nullptr){
		temp = head;
		head = head->next;
		delete temp;  
	}
	length = 0; 
}

void UnorderedLinkedList::PutItem(Item item){
	Node* temp = new Node;
	temp->data = item; 
	temp->next = head; 
	head = temp; 
	length++; 
}

Item UnorderedLinkedList::GetItem(Item item){
	Node* temp = head;
	while(temp != nullptr){
		if(temp->data == item){
			return temp->data;
		}
		temp = temp->next; 
	} 
	throw "not found"; 
}

void UnorderedLinkedList::DeleteItem(Item item){
	// Empty case 
	if(head == nullptr)
		return; 

	Node* temp;
	// Deleting head
	if(head->data == item){
		temp = head->next;
		delete head; 
		head = temp;
		length--; 
		return; 
	}

	// Deleting further in the list
	temp = head; 
	while(temp->next != nullptr){
		if(temp->next->data == item){
			Node* temp2 = temp->next; 
			temp->next = temp->next->next; 
			delete temp2; 
			length--; 
			return; 
		}
		temp = temp->next;
	}
}

void UnorderedLinkedList::ResetList(){
	currentPos = head;
}

Item UnorderedLinkedList::GetNextItem(){
	if(currentPos == nullptr)
		throw "Out of range"; 

	Item data = currentPos->data; 
	currentPos = currentPos->next; 
	return data; 
}

int UnorderedLinkedList::GetLength(){
	return length;
}

UnorderedLinkedList::~UnorderedLinkedList(){
	MakeEmpty(); 
}

Item UnorderedLinkedList::LookUp(Item item) {
	Node* temp = head;
	while(temp != nullptr) {
		if(temp -> data == item) {
				return temp -> data;
		}	
		temp = temp -> next;
	}
	
}

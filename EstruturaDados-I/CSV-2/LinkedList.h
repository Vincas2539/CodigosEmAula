// LinkedList.h
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "NodeLL.h"
#include <string>

class LinkedList{
	private:
		NodeLL *head;
    NodeLL *tail;
    int qtd;
	public:	
		LinkedList();
		~LinkedList();
		bool isEmpty();
		bool isFull();
		bool insertHead(std::string linha);
		bool insertTail(std::string linha);
		NodeLL *search(std::string linha);
		bool remove(std::string linha);
		void clear();
		void print();	


    NodeLL *getTail(void){return tail;}
		NodeLL *getHead(void){return head;}
    int getQtd(void){return qtd;}

    void setTail(NodeLL *tail){this->tail = tail;}
		void setHead(NodeLL *head){this->head = head;}

};

#endif

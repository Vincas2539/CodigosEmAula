#ifndef __Lista_Encadeada_C__
#define __Lista_Encadeada_C__

#include <iostream>
#include <string>

#include "NodeLLC.h"

class LinkedListC{
  private:
    NodeLLC *head;
    int qtd;
  public:
    LinkedListC();
    ~LinkedListC();
    bool isEmpty();
    bool isFull();
    bool insert(std::string nome);
    bool remove(std::string nome);
    std::string rmvSorteado(int n);
    void clear();
    void print();

    NodeLLC* getHead(void){return head;};
    void setHead(NodeLLC *head){this->head = head;};

    void addQtd(){qtd = qtd + 1;};
    void rmvQtd(){qtd = qtd - 1;};
    int getQtd(){return qtd;};
    void clearQtd(){qtd = 0;};

};

#endif


// NodeLL.h
#ifndef __NODE_LL_H__
#define __NODE_LL_H__

#include <string>

class NodeLL{  // ll = linked List
  private:
    std::string linha;
  	NodeLL *prox;
  public:
  	NodeLL(){ linha = ""; prox = nullptr;	};
  	NodeLL(std::string linha, NodeLL* prox){
  			this->linha = linha;
  			this->prox = prox;
  	};
  	~NodeLL();
  
  	NodeLL *getProx() { return prox; };
  	std::string getLinha(){ return linha; };
  	
  	void setProx(NodeLL *prox) { this->prox = prox; };
  	void setLinha(std::string linha) { this->linha = linha;	};

};

#endif

#ifndef __NODE_LL_C__
#define __NODE_LL_C__

#include <iostream>
#include <string>


class NodeLLC {
	private:
		std::string nome;
		NodeLLC *prox;
	
	public:
		NodeLLC(){nome = "";prox = nullptr;};
		NodeLLC(std::string nome, NodeLLC *prox){
			this->prox = prox;
      this->nome = nome;
		};
		~NodeLLC(){
      prox = nullptr;
    };
		
		NodeLLC *getProx(){return this->prox;};
    void setProx(NodeLLC *prox){this->prox = prox;};
      
    std::string setNome(std::string nome){this->nome = nome;};
      
    std::string getNome(){return nome;};
};

#endif
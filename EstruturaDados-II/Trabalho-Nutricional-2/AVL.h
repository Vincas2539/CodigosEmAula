/*
Lucas Gasparetto Narcizo de Morais | TIA: 41715233
Luiz Gabriel Profirio Mendes | TIA: 42082293
Victor Silva Fernandes | TIA: 32163967
Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/
#ifndef __AVL_H__
#define __AVL_H__

#include "NodeAVL.h"
#include "Alimento.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

class AVL {
public:
  AVL();
  ~AVL();

  NodeAVL *GetRoot() const;

  bool IsEmpty() const;
  void Clear();

  int GetDegree() const;
  int GetHeight() const;

  std::string TraverseInOrder() const;
  std::string TraversePreOrder() const;
  std::string TraversePostOrder() const;

  NodeAVL *FindMin() const;
  NodeAVL *FindMax() const;

  NodeAVL *Predecessor(string id) const;
  NodeAVL *Successor(string id) const;

  NodeAVL *Search(string id) const;
  NodeAVL *Insert(string id, Alimento *alimento);
  void Remove(string id);

// ---------- novo ----------
  void imprimeEscolha(NodeAVL *no, char tipo, vector<string> *lista);
  void imprimeTudo(NodeAVL *no, vector<string> *lista);
  string imprimePorcao(NodeAVL *no, string nome);
  void Save(ofstream &arquivo);




// private
private:
  NodeAVL *m_Root;

  void Destroy(NodeAVL *node);

  int GetDegreeInternal(const NodeAVL *node) const;

  std::string TraverseInOrderInternal(const NodeAVL *node) const;
  std::string TraversePreOrderInternal(const NodeAVL *node) const;
  std::string TraversePostOrderInternal(const NodeAVL *node) const;

  NodeAVL *FindMinInternal(NodeAVL *node) const;
  NodeAVL *FindMaxInternal(NodeAVL *node) const;

  NodeAVL *PredecessorInternal(NodeAVL *node) const;
  NodeAVL *SuccessorInternal(NodeAVL *node) const;

  NodeAVL *SearchInternal(NodeAVL *node, string &id) const;
  NodeAVL *InsertInternal(NodeAVL *node, NodeAVL *parent, string id, Alimento *alimento);
  NodeAVL *RemoveInternal(NodeAVL *node, string id);
  NodeAVL *RemoveNode(NodeAVL *node);
  void UpdateParentChild(NodeAVL *parent, const NodeAVL *child, NodeAVL *newChild);

  NodeAVL *RotateLeft(NodeAVL *node);
  NodeAVL *RotateRight(NodeAVL *node);
  NodeAVL *RotateLeftRight(NodeAVL *node);
  NodeAVL *RotateRightLeft(NodeAVL *node);

  NodeAVL *Balance(NodeAVL *node);

// ---------- novo ----------
  void SaveInternal(NodeAVL *no, ofstream &arquivo);
};

#endif
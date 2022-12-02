/*
Lucas Gasparetto Narcizo de Morais | TIA: 41715233
Luiz Gabriel Profirio Mendes | TIA: 42082293
Victor Silva Fernandes | TIA: 32163967
Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/
#ifndef __NODE_AVL_H__
#define __NODE_AVL_H__

#include "Alimento.h"
#include <string>

class NodeAVL {
private:
  string m_ID;
  Alimento *m_Data;

  NodeAVL *m_Parent;
  NodeAVL *m_Left;
  NodeAVL *m_Right;

  int m_BalanceFactor;

  int GetDepthInternal(const NodeAVL *node) const;
  int GetHeightInternal(const NodeAVL *node) const;

public:
  NodeAVL(string id, Alimento *alimento, NodeAVL *parent = nullptr, NodeAVL *left = nullptr, NodeAVL *right = nullptr);
  ~NodeAVL();

  void CopyDataFrom(const NodeAVL *node);

  string GetID() const;

  Alimento *GetData() const;
  void SetData(Alimento *alimento);

  NodeAVL *GetParent() const;
  void SetParent(NodeAVL *parent);

  NodeAVL *GetLeft() const;
  void SetLeft(NodeAVL *left);

  NodeAVL *GetRight() const;
  void SetRight(NodeAVL *right);

  bool IsRoot() const;
  bool IsLeaf() const;

  int GetDegree() const;
  int GetDepth() const;
  int GetHeight() const;

  int GetBalanceFactor() const;
  void UpdateBalanceFactor();

  std::string ToString() const;
  std::string ToFile() const;
};

#endif
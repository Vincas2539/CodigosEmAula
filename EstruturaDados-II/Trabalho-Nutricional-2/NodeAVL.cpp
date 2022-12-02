/*
Lucas Gasparetto Narcizo de Morais | TIA: 41715233
Luiz Gabriel Profirio Mendes | TIA: 42082293
Victor Silva Fernandes | TIA: 32163967
Vincenzo Sivero Ferreira Alberice | TIA: 32135661
*/
#include "NodeAVL.h"
#include "Alimento.h"
#include "Utils.h"
#include <sstream>

NodeAVL::NodeAVL(string id, Alimento *alimento, NodeAVL *parent, NodeAVL *left,
                 NodeAVL *right)
    : m_ID(id), m_Data(alimento), m_Parent(parent), m_Left(left),
      m_Right(right), m_BalanceFactor(0) {}

NodeAVL::~NodeAVL() {
  m_Parent = nullptr;
  m_Left = nullptr;
  m_Right = nullptr;
}

void NodeAVL::CopyDataFrom(const NodeAVL *node) {
  m_ID = node->GetID();
  m_Data = node->GetData();
}

string NodeAVL::GetID() const { return m_ID; }

Alimento *NodeAVL::GetData() const { return m_Data; }
void NodeAVL::SetData(Alimento *alimento) { m_Data = alimento; }

NodeAVL *NodeAVL::GetParent() const { return m_Parent; }
void NodeAVL::SetParent(NodeAVL *parent) { m_Parent = parent; }

NodeAVL *NodeAVL::GetLeft() const { return m_Left; }
void NodeAVL::SetLeft(NodeAVL *left) { m_Left = left; }

NodeAVL *NodeAVL::GetRight() const { return m_Right; }
void NodeAVL::SetRight(NodeAVL *right) { m_Right = right; }

bool NodeAVL::IsRoot() const { return m_Parent == nullptr; }
bool NodeAVL::IsLeaf() const { return m_Left == nullptr && m_Right == nullptr; }

int NodeAVL::GetDegree() const {
  int degree = 0;

  if (m_Left != nullptr)
    ++degree;
  if (m_Right != nullptr)
    ++degree;

  return degree;
}

int NodeAVL::GetDepth() const { return GetDepthInternal(this); }

int NodeAVL::GetDepthInternal(const NodeAVL *node) const {
  if (node->IsRoot()) {
    return 0;
  } else {
    return 1 + GetDepthInternal(node->GetParent());
  }
}

int NodeAVL::GetHeight() const { return GetHeightInternal(this); }

int NodeAVL::GetHeightInternal(const NodeAVL *node) const {
  if (node == nullptr || node->IsLeaf()) {
    return 0;
  } else {
    return 1 + Utils::Max(GetHeightInternal(node->GetLeft()),
                          GetHeightInternal(node->GetRight()));
  }
}

int NodeAVL::GetBalanceFactor() const { return m_BalanceFactor; }

void NodeAVL::UpdateBalanceFactor() {
  int leftHeight = m_Left == nullptr ? -1 : GetHeightInternal(m_Left);
  int rightHeight = m_Right == nullptr ? -1 : GetHeightInternal(m_Right);
  m_BalanceFactor = rightHeight - leftHeight;

  // Read the comments inside AVL::Balance().
  // m_BalanceFactor = leftHeight - rightHeight;
}

std::string NodeAVL::ToString() const {
  std::ostringstream oss;

  oss << m_ID << endl;

return oss.str();
}

std::string NodeAVL::ToFile() const {
  std::ostringstream oss;

  oss << m_ID << "," << m_Data->getPorcao() << "," << m_Data->getCalorias() << "," << m_Data->getCalGordura() << ","
      << m_Data->getGordurasTot() << "," << m_Data->getSodio() << ","
      << m_Data->getPotassio() << "," << m_Data->getCarbTot() << ","
      << m_Data->getFibras() << "," << m_Data->getAcucar() << ","
      << m_Data->getProteina() << "," << m_Data->getVitA() << ","
      << m_Data->getVitC() << "," << m_Data->getCalcio() << ","
      << m_Data->getFerro() << "," << m_Data->getGordSat() << ","
      << m_Data->getColesterol() << "," << m_Data->getTipo();

  return oss.str();
}
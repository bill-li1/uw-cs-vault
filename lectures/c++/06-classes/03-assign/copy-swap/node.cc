#include "node.h"
#include <utility>

Node::Node(int data, Node *next): data{data}, next{next} {}

Node::Node(const Node &n)
  : data{n.data}, next{n.next ? new Node{*n.next} : nullptr} {}

Node::~Node() {
  delete next;
}

void Node::swap(Node &other) {
  std::swap( data, other.data );
  std::swap( next, other.next );
}

Node &Node::operator=(const Node &other) {
  Node tmp{ other };
  swap(tmp);
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << "," << *n.next;
  }
  return out;
}

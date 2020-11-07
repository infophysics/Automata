#include "Set.h"
#include <iostream>
#include <map>

Set::Set() {
    elements = 0;
    sets = 0;
}

Node* Set::MakeSet(int i) {
    if (elements + 1 > Nodes.size()) {
      Nodes.push_back(new Node);
    }
    Nodes[elements]->parent = Nodes[elements];
    Nodes[elements]->rank = 0;
    Nodes[elements]->value = i;

    elements++;
    sets++;

    return Nodes[elements - 1];
}

Node* Set::Find(Node* a) {
    if (a->parent != a) {
      a->parent = Find(a->parent);
      return a->parent;
    } else {
      return a;
    }
}

Node* Set::FindByValue(int i) {
  Node* a;

  for (auto node : Nodes) {
    if (node->value == i) {
      a = node;
    }
  }

  if (a != NULL) {
    return Find(a);
  } else {
    return NULL;
  }

}

void Set::Union(Node* a, Node* b) {
    Node* x = Find(a);
    Node* y = Find(b);

    if (x == y) {
      return;
    }

    if (x->rank < y->rank) {
      x->parent = y;
      if (y->parent == x->parent) {
        y->rank = y->rank + 1;
      }

    } else {
      y->parent = x;
      if (x->parent == y->parent) {
        x->rank = x->rank + 1;
      }
    }
    sets--;
}

void Set::UnionByValues(int a, int b) {
  Node* x = FindByValue(a);
  Node* y = FindByValue(b);
  Union(x, y);
}

int Set::ElementCount() {
  return elements;
}

int Set::SetCount() {
  return sets;
}

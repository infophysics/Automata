#include <vector>

struct Node {
    Node *parent;
    int value;
    int rank;
};

// Integer Set Class
class Set {
  private:
    std::vector<Node*> Nodes;
    int elements;
    int sets;

  protected:

  public:
    Set();
    // ~cDisjointSet();

    Node* MakeSet(int i);

    Node* Find(Node* a);
    Node* FindByValue(int i);

    void Union(Node* a0, Node* a1);
    void UnionByValues(int a, int b);

    int ElementCount();
    int SetCount();

};

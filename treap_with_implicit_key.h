#ifndef TREAP_WITH_IMPLICIT_KEY_H_
#define TREAP_WITH_IMPLICIT_KEY_H_

#include <cstdlib>
#include <memory>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

template <typename T>
struct NullMaintainer;

template <typename T>
struct NullPropagator;

template <typename T,
          class Maintain = NullMaintainer<T>,
          class LazyPropagation = NullPropagator<T>>
class Treap {
 public:
  Treap() = default;

  template <typename It = T*>
  Treap(It first, It last) {
    std::stack<Node*> stack;
    for (It it = first; it != last; ++it) {
      Node *node = new Node(*it);
      while (!stack.empty() && stack.top()->priority < node->priority) {
        node->left = stack.top();
        stack.pop();
      }
      (stack.empty() ? root_ : stack.top()->right) = node;
      stack.push(node);
    }
  }

  ~Treap() {
    std::default_delete<Node> deleter;
    PreorderTraversal(deleter);
  }

  void Erase(size_t pos, size_t count = 1) {
    Node *left, *right, *nodes;
    std::tie(left, right) = Split(root_, pos + count);
    std::tie(left, nodes) = Split(left, pos);
    root_ = Merge(left, right);
    std::default_delete<Node> deleter;
    PreorderTraversal(nodes, deleter);
  }

  T Get(size_t pos) {
    return Query(pos, 1);
  }

  template <typename U = T>
  void Insert(size_t pos, U value) {
    Node *left, *right, *node = new Node(value);
    std::tie(left, right) = Split(root_, pos);
    root_ = Merge(Merge(left, node), right);
  }

  T Query(size_t pos, size_t count) {
    Node *left, *right, *nodes;
    std::tie(left, right) = Split(root_, pos + count);
    std::tie(left, nodes) = Split(left, pos);
    T result = nodes->data;
    root_ = Merge(Merge(left, nodes), right);
    return result;
  }

  void Rotate(size_t pos) {
    Node *left, *right;
    std::tie(left, right) = Split(root_, pos);
    root_ = Merge(right, left);
  }

  template <typename U = T>
  void Set(size_t pos, U value) {
    Update(pos, 1, value);
  }

  template <typename U>
  void Update(size_t pos, size_t count, U metadata) {
    Node *left, *right, *nodes;
    std::tie(left, right) = Split(root_, pos + count);
    std::tie(left, nodes) = Split(left, pos);
    nodes->data = metadata;
    root_ = Merge(Merge(left, nodes), right);
  }

  size_t Size() const { return Size(root_); }

  template <class Visitor>
  Visitor& PreorderTraversal(Visitor& visitor) {
    return PreorderTraversal(root_, visitor);
  }

  template <class Visitor>
  Visitor& InorderTraversal(Visitor& visitor) {
    return InorderTraversal(root_, visitor);
  }

  template <class Visitor>
  Visitor& PostorderTraversal(Visitor& visitor) {
    return PostorderTraversal(root_, visitor);
  }

#ifndef INTRUSIVE
 private:
#else
 public:
#endif
  struct Node {
    template <typename U = T>
    Node(U value):
        data(value),
        priority(std::rand())
    {}

    Node *left = nullptr;
    Node *right = nullptr;
    T data;
    size_t priority;
    size_t size = 1;
  };

 private:
  static Node* Merge(Node* left, Node* right);

  static std::pair<Node*, Node*> Split(Node* root, size_t id);

  template <class Visitor>
  static Visitor& PreorderTraversal(Node* root, Visitor& visitor);

  template <class Visitor>
  static Visitor& InorderTraversal(Node* root, Visitor& visitor);

  template <class Visitor>
  static Visitor& PostorderTraversal(Node* root, Visitor& visitor);

 private:
  static size_t Size(Node* v) { return v ? v->size : 0; }
  static T* Data(Node* v) { return v ? &v->data : nullptr; }
  
  static void Push(Node* v) {
#ifndef INTRUSIVE
    LazyPropagation()(v->data, Data(v->left), Data(v->right));
#else
    LazyPropagation()(v, v->left, v->right);
#endif
  }

  static void Recalc(Node* v) {
    v->size = 1 + Size(v->left) + Size(v->right);
#ifndef INTRUSIVE
    Maintain()(v->data, Data(v->left), Data(v->right));
#else
    Maintain()(v, v->left, v->right);
#endif
  }

 private:
  Node* root_ = nullptr;
};

template <typename T>
struct NullMaintainer {
#ifndef INTRUSIVE
  using Data = T;
  void operator()(Data& root, const Data* left, const Data* right) {}
#else
  using Node = T;
  void operator()(Node* root, const Node* left, const Node* right) {}
#endif
};

template <typename T>
struct NullPropagator {
#ifndef INTRUSIVE
  using Data = T;
  void operator()(Data& root, const Data* left, const Data* right) {}
#else
  using Node = T;
  void operator()(Node* root, const Node* left, const Node* right) {}
#endif
};

template <typename T, class Mn, class LPn>
auto Treap<T, Mn, LPn>::Merge(Node* left, Node* right) -> Node* {
  if (left) Push(left);
  if (right) Push(right);
  if (!left)
    return right;
  if (!right)
    return left;
  Node* root;
  if (left->priority > right->priority) {
    root = left;
    root->right = Merge(root->right, right);
  } else {
    root = right;
    root->left = Merge(left, root->left);
  }
  Recalc(root);
  return root;
}

template <typename T, class Mn, class LPn>
auto Treap<T, Mn, LPn>::Split(Node* root, size_t id) -> std::pair<Node*, Node*> {
  if (!root)
    return {nullptr, nullptr};
  Push(root);
  Node *left, *right;
  size_t root_id = Size(root->left);
  if (root_id < id) {
    std::tie(left, right) = Split(root->right, id - (root_id + 1));
    root->right = left;
    Recalc(root);
    return {root, right};
  } else {
    std::tie(left, right) = Split(root->left, id);
    root->left = right;
    Recalc(root);
    return {left, root};
  }
}

template <typename T, class Mn, class LPn>
template <class Visitor>
Visitor& Treap<T, Mn, LPn>::PreorderTraversal(Node* root, Visitor& visitor) {
  if (!root)
    return visitor;
  PreorderTraversal(root->left, visitor);
  PreorderTraversal(root->right, visitor);
  visitor(root);
  return visitor;
}

template <typename T, class Mn, class LPn>
template <class Visitor>
Visitor& Treap<T, Mn, LPn>::InorderTraversal(Node* root, Visitor& visitor) {
  if (!root)
    return visitor;
  InorderTraversal(root->left, visitor);
  visitor(root);
  InorderTraversal(root->right, visitor);
  return visitor;
}

template <typename T, class Mn, class LPn>
template <class Visitor>
Visitor& Treap<T, Mn, LPn>::PostorderTraversal(Node* root, Visitor& visitor) {
  if (!root)
    return visitor;
  visitor(root);
  PostorderTraversal(root->left, visitor);
  PostorderTraversal(root->right, visitor);
  return visitor;
}

#endif  // TREAP_WITH_IMPLICIT_KEY_H_

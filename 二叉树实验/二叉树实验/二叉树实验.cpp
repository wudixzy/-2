#include<iostream>
using namespace std;
#include <queue>

template <class T>
class BinaryTree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
        Node() { data = 0; left = nullptr; right = nullptr; }
    };

    Node* root;

public:
    BinaryTree() : root(nullptr) {}
    bool IsEmpty() const;
    BinaryTree(const BinaryTree<T>& bt1, const T& item, const BinaryTree<T>& bt2);
    BinaryTree<T> LeftSubtree() const;
    BinaryTree<T> RightSubtree() const;
    T RootData() const;
    Node* getRoot()const { return root; }
    void PreOrder() const;
    void InOrder() const;
    void PostOrder() const;
    void LevelOrder() const;

private:
    void PreOrderTraversal(Node* node) const;
    void InOrderTraversal(Node* node) const;
    void PostOrderTraversal(Node* node) const;
    void LevelOrderTraversal(Node* node) const;
};
template <class T>
bool BinaryTree<T>::IsEmpty() const
{
    return (root == nullptr);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& bt1, const T& item, const BinaryTree<T>& bt2)
{
    root = new Node(item);
    if (bt1.getRoot() != nullptr)root->left = new Node(bt1.RootData());
    else root->left = new Node();
    if (bt2.getRoot() != nullptr)root->right = new Node(bt2.RootData());
    else root->right = new Node();
}

template <class T>
BinaryTree<T> BinaryTree<T>::LeftSubtree() const
{
    BinaryTree<T> leftSubtree;
    leftSubtree.root = root->left;
    return leftSubtree;
}

template <class T>
BinaryTree<T> BinaryTree<T>::RightSubtree() const
{
    BinaryTree<T> rightSubtree;
    rightSubtree.root = root->right;
    return rightSubtree;
}

template <class T>
T BinaryTree<T>::RootData() const
{
    return root->data;
}

template <class T>
void BinaryTree<T>::PreOrderTraversal(Node* node) const
{
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    PreOrderTraversal(node->left);
    PreOrderTraversal(node->right);
}

template <class T>
void BinaryTree<T>::InOrderTraversal(Node* node) const
{
    if (node == nullptr)
        return;

    InOrderTraversal(node->left);
    std::cout << node->data << " ";
    InOrderTraversal(node->right);
}

template <class T>
void BinaryTree<T>::PostOrderTraversal(Node* node) const
{
    if (node == nullptr)
        return;

    PostOrderTraversal(node->left);
    PostOrderTraversal(node->right);
    std::cout << node->data << " ";
}

template <class T>
void BinaryTree<T>::LevelOrderTraversal(Node* root) const
{
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        std::cout << node->data << " ";

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

template <class T>
void BinaryTree<T>::PreOrder() const
{
    PreOrderTraversal(root);
}

template <class T>
void BinaryTree<T>::InOrder() const
{
    InOrderTraversal(root);
}

template <class T>
void BinaryTree<T>::PostOrder() const
{
    PostOrderTraversal(root);
}

template <class T>
void BinaryTree<T>::LevelOrder() const
{
    LevelOrderTraversal(root);
}

int main()
{
    BinaryTree<int> leftSubtree(
        BinaryTree<int>(),
        2,
        BinaryTree<int>()
    );

    BinaryTree<int> rightSubtree(
        BinaryTree<int>(),
        4,
        BinaryTree<int>()
    );

    BinaryTree<int> bt(
        leftSubtree,
        1,
        rightSubtree
    );

    if (bt.IsEmpty())
    {
        std::cout << "Binary tree is empty." << std::endl;
    }
    else
    {
        std::cout << "Binary tree is not empty." << std::endl;
    }

    std::cout << "Root data: " << bt.RootData() << std::endl;

    auto left = bt.LeftSubtree();
    auto right = bt.RightSubtree();

    std::cout << "Left subtree: ";
    left.InOrder();
    std::cout << std::endl;

    std::cout << "Right subtree: ";
    right.PreOrder();
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    bt.PreOrder();
    std::cout << std::endl;

    std::cout << "Inorder traversal: ";
    bt.InOrder();
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    bt.PostOrder();
    std::cout << std::endl;

    std::cout << "Level order traversal: ";
    bt.LevelOrder();
    std::cout << std::endl;

    return 0;
}
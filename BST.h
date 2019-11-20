#ifndef ASSIGNMENT4_BST_H
#define ASSIGNMENT4_BST_H

using namespace std;

template<class T>
class BST
{
private:
    struct Node
    {
        T Data;
        struct Node* Left;
        struct Node* Right;
        Node()
        {
            this->Left = nullptr;
            this->Right = nullptr;
        }
        explicit Node(const T &Data)
        {
            this->Data = Data;
            this->Left = nullptr;
            this->Right = nullptr;
        }
        ~Node()
        {
            this->Left = nullptr;
            this->Right = nullptr;
        }
        T* getDataPtr()
        {
            return &Data;
        }
    };
    using Node = struct Node;
    Node* Root;

public:
    BST();
    explicit BST(const T &RootItem);
    ~BST();

    bool isEmpty() const;
    int getHeight() const;
    Node* getRoot() const;
    bool add(const T &Item);
    bool remove(const T &Item);
    void clear();
    bool contains(const T &Item) const;
    void inOrderTraverse(Node* Root);
};

#endif //ASSIGNMENT4_BST_H

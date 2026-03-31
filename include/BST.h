#ifndef BST_H
#define BST_H

#include "NotFoundException.h"

template <class T>
class BST
{
private:
    template <class U>
    struct Node
    {
        U data;
        Node<U>* left;
        Node<U>* right;

        Node(const U& newData)
        {
            data = newData;
            left = nullptr;
            right = nullptr;
        }
    };

    Node<T>* root;

    Node<T>* addRecursive(Node<T>* nodePtr, const T& newData, bool& success)
    {
        if (nodePtr == nullptr)
        {
            success = true;
            return new Node<T>(newData);
        }

        if (newData < nodePtr->data)
        {
            nodePtr->left = addRecursive(nodePtr->left, newData, success);
        }
        else if (nodePtr->data < newData)
        {
            nodePtr->right = addRecursive(nodePtr->right, newData, success);
        }
        else
        {
            success = false;
        }

        return nodePtr;
    }

    bool containsRecursive(Node<T>* nodePtr, const T& target) const
    {
        if (nodePtr == nullptr)
        {
            return false;
        }

        if (target == nodePtr->data)
        {
            return true;
        }

        if (target < nodePtr->data)
        {
            return containsRecursive(nodePtr->left, target);
        }
        else
        {
            return containsRecursive(nodePtr->right, target);
        }
    }

    Node<T>* findNode(Node<T>* nodePtr, const T& target) const
    {
        if (nodePtr == nullptr)
        {
            return nullptr;
        }

        if (target == nodePtr->data)
        {
            return nodePtr;
        }

        if (target < nodePtr->data)
        {
            return findNode(nodePtr->left, target);
        }
        else
        {
            return findNode(nodePtr->right, target);
        }
    }

    int getHeightRecursive(Node<T>* nodePtr) const
    {
        if (nodePtr == nullptr)
        {
            return 0;
        }

        int leftHeight = getHeightRecursive(nodePtr->left);
        int rightHeight = getHeightRecursive(nodePtr->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }

    int getNumberOfNodesRecursive(Node<T>* nodePtr) const
    {
        if (nodePtr == nullptr)
        {
            return 0;
        }

        return 1 + getNumberOfNodesRecursive(nodePtr->left)
                 + getNumberOfNodesRecursive(nodePtr->right);
    }

    void clearRecursive(Node<T>* nodePtr)
    {
        if (nodePtr != nullptr)
        {
            clearRecursive(nodePtr->left);
            clearRecursive(nodePtr->right);
            delete nodePtr;
        }
    }

    void preorderRecursive(Node<T>* nodePtr, void visit(T&)) const
    {
        if (nodePtr != nullptr)
        {
            T temp = nodePtr->data;
            visit(temp);

            preorderRecursive(nodePtr->left, visit);
            preorderRecursive(nodePtr->right, visit);
        }
    }

    void inorderRecursive(Node<T>* nodePtr, void visit(T&)) const
    {
        if (nodePtr != nullptr)
        {
            inorderRecursive(nodePtr->left, visit);

            T temp = nodePtr->data;
            visit(temp);

            inorderRecursive(nodePtr->right, visit);
        }
    }

    void postorderRecursive(Node<T>* nodePtr, void visit(T&)) const
    {
        if (nodePtr != nullptr)
        {
            postorderRecursive(nodePtr->left, visit);
            postorderRecursive(nodePtr->right, visit);

            T temp = nodePtr->data;
            visit(temp);
        }
    }

    Node<T>* findMin(Node<T>* nodePtr) const
    {
        if (nodePtr == nullptr)
        {
            return nullptr;
        }

        while (nodePtr->left != nullptr)
        {
            nodePtr = nodePtr->left;
        }

        return nodePtr;
    }

    Node<T>* removeRecursive(Node<T>* nodePtr, const T& target, bool& success)
    {
        if (nodePtr == nullptr)
        {
            success = false;
            return nullptr;
        }

        if (target < nodePtr->data)
        {
            nodePtr->left = removeRecursive(nodePtr->left, target, success);
        }
        else if (nodePtr->data < target)
        {
            nodePtr->right = removeRecursive(nodePtr->right, target, success);
        }
        else
        {
            success = true;

            if (nodePtr->left == nullptr && nodePtr->right == nullptr)
            {
                delete nodePtr;
                return nullptr;
            }

            if (nodePtr->left == nullptr)
            {
                Node<T>* temp = nodePtr->right;
                delete nodePtr;
                return temp;
            }

            if (nodePtr->right == nullptr)
            {
                Node<T>* temp = nodePtr->left;
                delete nodePtr;
                return temp;
            }

            Node<T>* successor = findMin(nodePtr->right);
            nodePtr->data = successor->data;

            bool dummy = false;
            nodePtr->right = removeRecursive(nodePtr->right, successor->data, dummy);
        }

        return nodePtr;
    }

    bool isBalancedRecursive(Node<T>* nodePtr) const
    {
        if (nodePtr == nullptr)
        {
            return true;
        }

        int leftHeight = getHeightRecursive(nodePtr->left);
        int rightHeight = getHeightRecursive(nodePtr->right);

        int diff = leftHeight - rightHeight;
        if (diff < 0)
        {
            diff = diff * -1;
        }

        if (diff > 1)
        {
            return false;
        }

        return isBalancedRecursive(nodePtr->left) &&
               isBalancedRecursive(nodePtr->right);
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        clear();
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    bool add(const T& newData)
    {
        bool success = false;
        root = addRecursive(root, newData, success);
        return success;
    }

    bool remove(const T& data)
    {
        bool success = false;
        root = removeRecursive(root, data, success);
        return success;
    }

    void clear()
    {
        clearRecursive(root);
        root = nullptr;
    }

    T getEntry(const T& anEntry) const
    {
        Node<T>* foundNode = findNode(root, anEntry);

        if (foundNode == nullptr)
        {
            throw NotFoundException("entry was not found");
        }

        return foundNode->data;
    }

    bool contains(const T& anEntry) const
    {
        return containsRecursive(root, anEntry);
    }

    void preorderTraverse(void visit(T&)) const
    {
        preorderRecursive(root, visit);
    }

    void inorderTraverse(void visit(T&)) const
    {
        inorderRecursive(root, visit);
    }

    void postorderTraverse(void visit(T&)) const
    {
        postorderRecursive(root, visit);
    }

    int getHeight() const
    {
        return getHeightRecursive(root);
    }

    int getNumberOfNodes() const
    {
        return getNumberOfNodesRecursive(root);
    }

    bool isBalanced() const
    {
        return isBalancedRecursive(root);
    }
};

#endif
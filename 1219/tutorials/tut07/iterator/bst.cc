#include <iostream>
#include <stack>
using namespace std;

class Tree {
    struct Node {
        int data;
        Node * left, * right;
        Node( int data, Node * left = nullptr, Node * right = nullptr ) 
          : data{data}, left{left}, right{right} {}
        void add( int elem );
    };

    Node * root;

    
public:

    class Iterator {
        Node * element;
        stack<Node*> myStack;

        explicit Iterator( Node *element );

    public:
        Iterator & operator++();
        bool operator!=( const Iterator & other ) const;
        int & operator*();
        
        friend class Tree;
    };

    Iterator begin();
    Iterator end();
    Tree();
    ~Tree();
    void add( int elem );
};

int main() {
    Tree bst;
    cout << "empty tree\n";
    for ( int & i : bst ) {
        cout << i << endl;
    } 

#if 0
    bst.add( 30 );
    bst.add( 40 );
    bst.add( 32 );
    bst.add( 45 );
    bst.add( 20 );
    bst.add( 10 );
    bst.add( 15 );
    bst.add( 25 );
    bst.add( 1 );
#endif
    bst.add( 1 );
    bst.add( 10 );
    bst.add( 15 );
    bst.add( 20 );
    bst.add( 25 );
    bst.add( 30 );

    cout << "\nnon-empty tree\n";
    for ( int & i : bst ) {
        cout << i << " ";
    } 
    cout << endl;
    return 0;
}

Tree::Tree() : root{nullptr} {}
Tree::~Tree() { delete root; }
Tree::Iterator Tree::begin() { return Tree::Iterator{ root }; }
Tree::Iterator Tree::end() { return Tree::Iterator{ nullptr }; }

void Tree::add( int elem ) {
    if ( root == nullptr ) {
        root = new Node{ elem };
        return;
    }
    if ( elem < root->data ) {
        if ( root->left == nullptr ) {
            root->left = new Node{ elem };
            return;
        } 
        root->left->add( elem );
    } else {
        if ( root->right == nullptr ) {
            root->right = new Node{ elem };
            return;
        } 
        root->right->add( elem );
    }
}

void Tree::Node::add( int elem ) {
    if ( left == nullptr ) {
        left = new Node{ elem };
        return;
    }
    if ( elem < data ) {
        if ( left == nullptr ) {
            left = new Node{ elem };
            return;
        } 
        left->add( elem );
    } else {
        if ( right == nullptr ) {
            right = new Node{ elem };
            return;
        } 
        right->add( elem );
    }
} // Tree::add

Tree::Iterator::Iterator( Node * root ) {
    if ( root == nullptr ) {
        element = nullptr;
        return;
    }
    element = root;
    if ( element->right != nullptr ) {
        myStack.push( element->right );
    }
    if ( element->left != nullptr ) {
        myStack.push( element->left );
    }
} // Tree::Iterator::Iterator

Tree::Iterator & Tree::Iterator::operator++() {
    if ( myStack.empty() && element == nullptr ) return *this;
    if ( ! myStack.empty() ) {
        element = myStack.top();
        myStack.pop();
        if ( element->right != nullptr ) {
            myStack.push( element->right );
        }
        if ( element->left != nullptr ) {
            myStack.push( element->left );
        }
    } else {
        element = nullptr;
    }
    return * this;
} // Tree::Iterator::operator++

bool Tree::Iterator::operator!=( const Iterator & other ) const {
    return element != other.element;
} 
      
int & Tree::Iterator::operator*() {
    return element->data;
} 

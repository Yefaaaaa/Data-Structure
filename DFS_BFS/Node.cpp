#include "Node.h"

Node::Node(string &data)
{
    this->left = nullptr;
    this->right = nullptr;
    this->data = data;
}


Node::Node(string &data, Node *left, Node *right){
    this->left = left;
    this->right = right;
    this->data = data;

}


Node::~Node()
{
    cout<<"destructor called"<<endl;
}

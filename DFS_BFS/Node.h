#ifndef NODE_H
#define NODE_H
#include <string.h>
#include <iostream>

using namespace std;

class Node
{
    public:
        Node *left;
        Node *right;
        string data;
        Node(string &data);
        Node(string &data, Node *left, Node *right);
        virtual ~Node();

    protected:

    private:
};

#endif // NODE_H

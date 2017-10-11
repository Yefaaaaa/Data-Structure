#include <iostream>
#include <queue>
#include "Node.h"
#include "bfs.cpp"

using namespace std;


void dfs_traversal(Node *node);
void bfs_traversal(Node *node);

Node *sample_tree(){
    string A("A"),B("B"),C("C"),D("D"),E("E"),F("F"),H("H"),G("G");
    // Create a tree
    /*
          A
      B        E
    C   D    F   G
                H   null
    */
    Node *root = new Node (A,
                           new Node (B,
                                     new Node(C),new Node(D)),
                           new Node (E,
                                     new Node(F),new Node(G,
                                                          new Node(H),nullptr)));

    return root;
}

int main()
{
    Node *tree = sample_tree();

    bfs_traversal(tree);
    cout<<endl;

    dfs_traversal(tree);
    cout<<endl;

    return 0;
}

void bfs_traversal(Node *node){

    std::queue<Node *> q;

    q.push(node);
    while( ! q.empty()){

        node = q.front();
        q.pop();
        cout<<node->data<<" ";

        if (node->left != nullptr)
            q.push(node->left);

        if (node->right != nullptr)
            q.push(node->right);

    }
 }


 void dfs_traversal(Node *node){

    if (node == nullptr)
        return;
    cout << node->data<<" ";
    dfs_traversal(node->left);
    dfs_traversal(node->right);

 }

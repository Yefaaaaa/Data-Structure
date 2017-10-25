#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

#define MAX_LENGTH 20

struct Node {
	char *data;
	Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,char n[]){
	head->data = n;
	head->next =NULL;
}

// appending at the end
void addNode(struct Node *head, char n[]) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
    while(cur) {
       if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertFront(struct Node **head, char n[]) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}
void searchData(struct Node *head,char  n[]){
    Node *cur = head;
    bool checkSearch=false;
    while(cur != NULL){
        if(!(strcmp(cur->data,n))){
            checkSearch=true;
            break;
        }
        cur = cur->next;
    }
    if (checkSearch){
        cout<<endl<<"Found the data on the list."<<endl;
    }else{
        cout<<endl<<"Data is not on the list."<<endl;
    }
}

// Insert data
void insertSpecifiedPosition(struct Node *head,char  n[],int position){
    Node *cur = head;
    int counter=1;
    bool checkNum=true;
    while(cur != NULL){
        if (counter == position){
            Node *temp = new Node;
            temp->data = n;
            temp->next = cur->next;
            cur->next = temp;
            delete temp;
            checkNum=false;
        }
            cur = cur->next;
            counter++;
    }
    if(checkNum){
        cout<<"Linked list is too small, add the data to the end."<<endl;
        addNode(head,n);
    }
}

//   Delete the last one
void deleteLastOne(struct Node *head){
        if(head == NULL)
            return;

        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* currNode = head;
        while (currNode->next && currNode->next->next != NULL)
        {
                currNode = currNode->next;
        }
        delete currNode->next;
        currNode->next = NULL;
}

// Delete the specified data
void deleteNode(struct Node *head, char n[])
{
    bool checkPrintOut = true;
    Node *cur = head;
    while(cur != NULL){
        if(!(strcmp(cur->data,n))){
           if (cur->next==NULL) {
                deleteLastOne(head);
            }else{
                Node *temp = cur->next;
                cur->data = cur->next->data;
                cur->next = temp->next;
                delete temp;
            }
        checkPrintOut = false;
        }
            cur = cur->next;
    }
    if (checkPrintOut) cout<< "Can`t find the data on the list"<<endl;
}

/* reverse the list */
struct Node* reverse(struct Node** head)
{
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;

	/* make parent as tail */
	parent->next = NULL;
	while(child) {
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}


void deleteLinkedList(struct Node **node)
{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

void display(struct Node *head) {
	Node *list = head;
	while(list!=NULL) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

int main()
{
	struct Node *newHead;
	struct Node *head = new Node;

while(true){
	// Pick the choice for linkedList
	int choice;
	cout<<"********************Menu*************************"<<endl;
	cout<<"1.Initial your Linked list."<<endl;
	cout<<"2.Print the linked list"<<endl;
	cout<<"3.Add the data to the linked list End."<<endl;
	cout<<"4.Add the data to the linked list Front."<<endl;
	cout<<"5.Search the data on the list"<<endl;
	cout<<"6.Insert the data after specified position. Position start from 1." <<endl;
	cout<<"7.Delete the specified data to the linked list."<<endl;
    cout<<"8.Reverse the list."<<endl;
    cout<<"9.Delete the list"<<endl;
	cout<<"0.Exit the program"<<endl;
	cout<<"*************************************************"<<endl;
	cout<<endl<<"Pick a choice you want: ";
	cin>>choice;
	switch (choice){
        case 1:{
            cout<< "Initial value to the linked list: ";
            char *input = new char[MAX_LENGTH];
            cin>>input;
            initNode(head,input);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 2:
            cout<<"The linked list: ";
            display(head);
            break;
        case 3:{
            cout<< "Add the data to the linked list: ";
            char *input = new char[MAX_LENGTH];
            cin>>input;
            addNode(head,input);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 4:{
            cout<< "Add the data to the linked list front: ";
            char *input = new char[MAX_LENGTH];
            cin>>input;
            insertFront(&head,input);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 5:{
            cout<<"Input the data you want to search: ";
            char *input = new char[MAX_LENGTH];
            cin>>input;
            searchData(head,input);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 6:{
            cout<<"Insert the position: ";
            int position;
            cin>>position;
            cout<< "Insert the data: ";
            char *input = new char[MAX_LENGTH];
            cin>>input;
            insertSpecifiedPosition(head,input,position);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 7:{
            cout<< "Delete the specified data to the linked list: ";
            char *input = new char[MAX_LENGTH];
            cin>>input;
            deleteNode(head,input);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 8:{
            cout<< "Reverse the list";
            reverse(&head);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 9:{
            cout << "Deleting the list\n";
            deleteLinkedList(&head);
            cout<<"The linked list: ";
            display(head);
            break;
        }
        case 0:
            cout<<"See you!"<<endl;
            return 0;
        default :
            cout<< "Please make a valid choice."<<endl;
	}
}

	return 0;
}

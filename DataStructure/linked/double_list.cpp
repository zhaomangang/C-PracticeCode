#include <iostream>
using namespace std;

#define ELEM int
typedef struct Node{
    ELEM data;
    Node* pre;  //前驱结点
    Node* next; //后继结点

}Node;


Node* createList()
{
    void Print(Node*);
    Node* head = NULL;
    Node* re = NULL;
    ELEM temp = 0;
    cout<<"input:";
    cin>>temp;
    while(temp != -1)
    {
        if(head == NULL)
        {
            head = new Node;
            re = head;
            head->data = temp;
            head->pre = NULL;
            head->next = NULL;
        }else{
            head->next = new Node;
            head->next->pre = head;
            head = head->next;
            head->data = temp;
            head->next = NULL;
        }
       // Print(head);
        cout<<"input: ";
        cin>>temp;
    }
    return re;
}

void Print(Node* head)
{
    while(head->next != NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
    cout<<head->data<<endl;
    cout<<"______逆序_________"<<endl;
    while(head != NULL)
    {
        cout<<head->data<<endl;
        head = head->pre;
    }
}

int getLength(Node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node* findNode(Node* head,int data)
{
    while(head != NULL)
    {
        if(head->data == data)
            return head;
        head = head->next;
    }
    return NULL;

}

Node* insertNode(Node* head,Node* node,int data)
{
    //在node后插入一个结点
    if(node == NULL)
        return head;
    if(node->next == NULL)
    {
        //在末尾插入
        node->next = new Node;
        node->next->data = data;
        node->next->pre = node;
        node->next->next = NULL;
        return head;
    }else
    {
        //中间插入
        Node* temp = new Node;
        temp->data = data;
        temp->next = node->next;
        node->next->pre = temp;
        node->next = temp;
        temp->pre = node;
    }
    return head;
}

Node* deleteNode(Node* head,int data)
{
    Node* p = head;
    if(head == NULL)
        return head;
    if(head->data == data)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        head->pre = NULL;
        return head;
    }else{
        head = head->next;
    }

    while(head != NULL)
    {
        if(head->data == data)
        {
            if(head->next != NULL)
            {
                Node* temp = head;
                head = head->next;
                temp->pre->next = head;
                head->pre = temp->pre;
                delete temp;
                temp = NULL;
                return p;
            }else {
                head->pre->next=NULL;
                delete head;
                return p;
            }
        }
        head = head->next;
    }
    return p;
}


int main()
{
    Node* head = createList();
    Print(head);
    cout<<"length is: "<<getLength(head)<<endl;
   // cout<<findNode(head,3)->data<<endl;
   // cout<<"___________插入————————"<<endl;
   // head = insertNode(head,findNode(head,3),4);
   // Print(head);
   // head = insertNode(head,findNode(head,1),2);
   // Print(head);
   // head = insertNode(head,findNode(head,4),5);
   //bin Print(head);
    cout<<"删除1"<<endl;
    head = deleteNode(head,1);
    Print(head);
    cout<<"删除3\n";
    head = deleteNode(head,3);
    Print(head);
    cout<<"删除5\n";
    head = deleteNode(head,5);
    Print(head);
    return 0;
}

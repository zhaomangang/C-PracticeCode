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
int main()
{
    Node* head = createList();
    Print(head);
    cout<<"length is: "<<getLength(head);
    return 0;
}

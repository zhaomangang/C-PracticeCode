#include <iostream>
using namespace std;
#define ELEM int

typedef struct Node{
    int data;
    Node* next;
}Node;


Node* createRing(int num)
{
    Node* head = NULL;
    Node* p = NULL;
    for(int i = 1; i <= num; i++){
        int temp = 0;
        cout<<"input:";
        cin>>temp;
        if(head == NULL){
            head = new Node;
            head->data = temp;
            head->next = NULL;
            p = head;
            continue;
        }
        p->next = new Node;
        p = p->next;
        p->data = temp;
        p->next = NULL;
    }
    p->next = head;
    return head;
}


void josephRing(Node* head,int m)
{
    Node* bre_head = NULL;
    while(head != NULL)
    {
        for(int i = 1; i < m; i++)
        {
            bre_head = head;
            head = head->next;
        }
        m = head->data;
        cout<<m<<endl;
        bre_head->next = head->next;
        delete head;
        head = bre_head->next;
        if(bre_head == head)
        {
            //剩最后一个结点了
            cout<<head->data<<endl;
            delete head;
            head = NULL;
            bre_head = NULL;
            break;
        }
    }

}


void Print(Node* h,int num)
{
    while(num--)
    {
        cout<<h->data<<endl;
        h = h->next;
    }
}

int main()
{
    Node* head = createRing(7);
   // Print(head,7);
    josephRing(head,3);
    return 0;
}

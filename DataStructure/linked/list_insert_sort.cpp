#include <iostream>
using namespace std;

#define ELEM int

typedef struct Node{
   ELEM data;
   Node* next;
}Node;


Node* InsertSort(void)
{
    void print(Node* head);
    ELEM input = 0;
    Node* head = NULL;
//    Node* point_head = NULL;
    cout<<"input:";
    cin>>input;
    while(input != 0)
    {
        if(head == NULL)
        {
            head = new Node;
            head->data = input;
            head->next = NULL;
           //var point_head = head;
            cout<<"input:";
            cin>>input;
            continue;
        }
        Node* p = head;
        Node* b_p = head; //p的前置节点
        while(p != NULL && p->data < input)
        {
            b_p = p;
            p = p->next;
        }
        if(p == NULL)
        {
            //链表结尾插入，直接插
            Node* q = new Node;
            q->data = input;
            q->next = NULL;
            b_p->next = q;
        }else if(p == head){
            //在头节点前插入
            Node* q = new Node;
            q->data = input;
            q->next = head;
            head = q;
        }else{
            //在链表中间插入，也就是在B_P和p之间插入
            Node* q = new Node;
            q->data = input;
            q->next = p;
            b_p->next = q;
        }
    //    print(head);
        cout<<"input:";
        cin>>input;
    }
    /**
     *测试环
     * 
    Node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = head;
    */

    return head; 
}

void print(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

bool IsLoop(Node* head)
{
    Node* p = head;
    if(head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return false;
    }

    p = head->next->next;
    while(p != NULL && head != p)
    {
        head = head->next;
        p = p->next->next;
    }
    if(head == p)
    {
        return true;
    }
    return false;
}

int Length(Node* head)
{
    int len = 0;
    while(head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

Node* InsertNode(Node* head1,Node* head2)
{
    Node* maxh = NULL;
    Node* minh = NULL;
    if(Length(head1) > Length(head2))
    {
        maxh = head1;
        minh = head2;
    }else{
        maxh = head2;
        minh = head1;
    }
    while(minh != NULL)
    {
        Node* p = maxh;
        Node* bp = p;
        while(p != NULL && p->data < minh->data)
        {
            bp = p;
            p = p->next;
        }
        if(p == NULL)
        {
            //在链表最后插
            bp->next = minh;
            minh = minh->next;
            bp->next->next = NULL;
        }else if(p == maxh) {
            //头节点前插入
            maxh = minh;
            minh = minh->next;
            maxh->next = p;
        }else {
            //中间插
            Node* temp = minh->next;
            minh->next = bp->next;
            bp->next = minh;
            minh = temp;
        }
        print(maxh);
        cout<<"_______"<<endl;
       //var minh = minh->next;
    }

    return maxh;
}

int main()
{
    Node* head1 = InsertSort();
    Node* head2 = InsertSort();
    cout<<"h1\n";
    print(head1);
    cout<<"h2\n";
    print(head2);
    cout<<"insert h\n";
    print(InsertNode(head1,head2));
    // print(head);
   //bin cout<<IsLoop(head);
    return 0;
}

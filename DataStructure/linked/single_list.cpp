#include <iostream>
using namespace std;


#define ELEM int
typedef struct Node{
    ELEM data;  //数据域
    Node *next; //下一节点域
}Node;

Node* CreateSingleList()
{
    //创建单链表
    Node *p = NULL;
    Node *head = NULL;
    ELEM data_temp;
        cout<< "input:";
        cin >> data_temp;
    while(data_temp != 0)
    {
        if(head == NULL)
        {
            head = new Node;
            head->data = data_temp;
            head->next = NULL;
            p = head;
        }else {
            Node *q = new Node;
            q->data = data_temp;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
        cout<<"input:";
        cin>>data_temp;
    }
    return head;

}


void Traverse(Node *head)
{
    
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

int Length(Node *head)
{
    //单链表测长
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *SearchNode(Node *head,int pos)
{
    //查找单链表pos位置节点，返回节点指针
    //pos从0开始
    int index = 0;
    Node *p = head;
    if(pos < 0 || pos >= Length(head))
    {
        cout<<"pos error"<<endl;
        return NULL;
    }
    while(p!=NULL)
    {
     //   cout<<"line 77"<<endl;
        if(index == pos)
        {
            return p;
        }
        p = p->next;
        index++;
    }
  //var  cout<<"line p"<<p->data;
    return NULL;
}

Node* InsertNode(Node* head,int pos,ELEM data)
{
    int index = 0;
    Node *temp = head;
    if(pos<0 || pos > Length(head))
    {
        cout<<"pos error"<<endl;
    }
    while(temp != NULL)
    {
        if(index == pos)
        {
            Node *p = new Node;
            p->data = data;
            p->next = temp->next;
            temp->next = p;
            return head;
        }
        temp = temp->next;
        index++;
    }
    return head;
}

Node* DeleteNode(Node* head,int pos)
{
    if(pos < 0 || pos >= Length(head))
    {
        cout<<"pos error"<<endl;
        return head;
    }
    int index = 0;
    Node *temp = head;
    if(pos == 0)
    {
        //要删除第一个节点
        temp = head->next;
        delete head;
        head = NULL;
        return temp;
    }
    while(temp->next != NULL)
    {
        //删除中间or最后节点
        if(index+1 == pos)
        {
            
            Node *p = temp->next;   //要删的节点
            temp->next = p->next;   //连接要删的节点的前置节点与后置节点
            delete p;   //释放要删的节点的内存
            p = NULL;   //给p置空，预防野指针
            return head;
        }
        index++;
        temp = temp->next;
    }
    return head;
}


Node *Reverse(Node *head)
{
    //反转链表
    Node *temp = NULL;  //指向上次反转第一个节点


    while(head != NULL)
    {
        Node *p = head->next;   //指向当前节点的下一个节点
        Node *q = p->next;  //指向下一个节点的下一个
        head->next = temp;      //连接当前节点与上次反转完成的第一个节点
        p->next = head; //反转当前两个节点
        temp = p;   //记录本次反转完成的第一个节点
        head = q;   //下次循环开始的位置
    }
    return temp;
}

Node *SearchCenter(Node *head)
{
    Node* curret = head;    //当前位置指针
    Node* center = head;    //中间节点指针
    int t_index = 0;    //当前节点指针指向的第几个元素
    int r_index = 0;    //中间节点指针指向的第几个元素
    while(curret != NULL)
    {
        if(t_index/2>r_index)
        {
            center = center->next;
            r_index++;
        }
        curret = curret->next;
        t_index++;
    }
    return center;
}


int main()
{
    Node *head = NULL;
    head = CreateSingleList();
    cout<<head<<endl;
    Traverse(head);
    cout<<head<<endl;
    cout<<Length(head)<<endl;
    cout<<"_______test search_________"<<endl;
    SearchNode(head,-1); 
    cout<<SearchNode(head,3)->data<<endl;
    SearchNode(head,12);
    cout<<"_______test insert_________"<<endl;
    cout<<"inseret -1,3"<<endl;
    Traverse(InsertNode(head,-1,3));
    cout<<"inseret 5,4"<<endl;
    Traverse(InsertNode(head,5,4));
    cout<<"insert 0,45"<<endl;
    head = InsertNode(head,0,45);
    Traverse(head);
    cout<<"InsertNode 2,37"<<endl;
    head = InsertNode(head,2,37);
    Traverse(head);
    cout<<"_______test delete_________"<<endl;
    cout<<"delete -1"<<endl;
    head = DeleteNode(head,-1);
    Traverse(head);
    cout<<"delete "<<Length(head)<<endl;
    head = DeleteNode(head,Length(head));
    Traverse(head);
    cout<<"delete 0"<<endl;
    head = DeleteNode(head,0);
    Traverse(head);
    cout<<"delete 2"<<endl;
    head = DeleteNode(head,2);
    Traverse(head);
    cout<<"delete "<<Length(head)-1<<endl;
    head = DeleteNode(head,Length(head)-1);
    Traverse(head);
    cout<<"________test reversr__________"<<endl;
    head = Reverse(head);
    Traverse(head);
    cout<<"________test SearchCenter________"<<endl;
    cout<<SearchCenter(head)->data<<endl;
    // cout<<"test not return"<<endl;
   // Node *h = NULL;
   // CreateSingleList(h);
   // Traverse(h);

    return 0;
}

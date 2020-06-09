# CppPracticeCode
#### 2020/6/6
- [x] 单链表建立
- [x] 单链表测长
- [x] 单链表打印
- [x] 单链表节点查找
- [x] 单链表节点插入
- [x] 单链表节点删除
- [x] 单链表逆置
- [x] 寻找单链表中间元素<参考书上>
```c++
/*
解决办法(时间复杂度O(n)):
    1.设置两个指针：middle中间元素、current当前遍历的元素，先让两指针指向头节点
    2.设置两个序列记录：index_m(middle指针当前所指的位置)、index_c(current指针当前指的位置)，初始化为0
    3.使用current指针遍历链表同时index_c++
    4.遍历时判断index_m是否小于1/2 * index_c如果是则让middle指针前进并让index_m++直到index_m = 1/2*index_c
    5.遍历结束后current指向的即为中间元素
*/
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

```
- [x] 字符串中各单词的反转<没有实现出来参考了书上方法>
```c++
/*
原字符串:i am mason
反转后：mason am i
我的想法：重新开辟一字符串然后将原字符串边反转边拷贝
反转办法：
    1.将字符串中每个单词进行反转 i ma nosam
        a.设置两个指针end(表示单词结尾)、start(指向单词开始)、temp(用于遍历字符串)三者初始化指向str
        b.遍历字符串,如果temp当前指向' '或者'\0'则让end指向temp-1
        c.反转start至end间的字符
        d.让start指向temp+1(下一个单词的开始位置)
    2.将整个字符串进行反转 mason am i
*/
void RevStr(char *src)
{
    //先将字符串中每个单词的每个字母逆置 i ma nosam
    //再将整个字符串逆置 mason am i
    char *start = src;
    char *end = src;
    char *ptr = src;
    while(*ptr++ != '\0')
    {
        if(*ptr == ' ' || *ptr == '\0')
        {
            end = ptr-1;
            while(start < end)
            {
                char c = *start;
                *start = *end;
                *end = c;
                start++;
                end--;                                                                                          
            }
            start = ptr+1;                                                                        
        }                                    
    }
   // cout<<src<<endl;
    end = ptr-2; 
    start = src;
    while(start < end)
    {
        char c = *start;
        *start = *end;
        *end = c;
        start++;
        end--;                                                                                    
    }
    //cout<<src<<endl;
}

```

#### 2020/6/7
- [x] 创建有序单链表
- [x] 判断单链表是否有环
- [x] 非递归方式实现有序单链表合并

#### 2020/6/8
- [x] 编程判断字符串是否为回文
- [x] strcmp函数实现<参考书上>
    感觉这个函数很奇怪，如果s1比s2长就要出问题....
```c++
int strcmp(const char* s1, const char* s2)
{
    for( ;s1 == s2;++s1,++s2)
        if(*s1=='\0')
            return 0;
    return (*(unsigned char*)s1 < *(unsigned char*)s2 ? -1 : 1);
```

#### 2020/6/9
- [x] 约瑟夫环问题
问题描述：
        编号为1,2,...,N的N个人按顺时针方向围坐一圈，每个人持有一个密码(正整数),一开始任选一个正整数作为报数上限
    值M，从第一个人开始顺时针方向自1开始报数，报到M时停止报数。报M的人出列，将他的密码作为新的M值，从他在顺
    时针方向上的下一个人开始重新从1报数，如此下去，直至所有人全部出列为止。求出列顺序。
解决思路:
    1.建立一循环单链表模拟顺时针围坐一圈的人，并定义指针pre(指向当前结点的前驱结点)，head(当前结点)
    2.从头开始遍历单链表每遍历一部{count++; pre = head; head = head->next;}
    3.当count == M 将当前结点的data域赋值给M并删除当前结点
    4.当pre == head时当前链表只剩下一个结点，删除该结点。跳出循环
    5.结点删除顺序即为出列顺序
```c++
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
```
- [x] 双向链表建立
- [x] 双向链表测长
- [x] 双向链表打印

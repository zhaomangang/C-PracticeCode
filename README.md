# CppPracticeCode
#### 2020/6/7
-[x] 单链表建立
-[x] 单链表测长
-[x] 单链表打印
-[x] 单链表节点查找
-[x] 单链表节点插入
-[x] 单链表节点删除
-[x] 单链表逆置
-[x] 寻找单链表中间元素<参考书上>
```
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
-[x] 字符串中各单词的反转<没有实现出来参考了书上方法>
```
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

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
```c++
/*
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
*/
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

#### 2020/6/10
- [x] 入门shell(echo、变量定义、字符串、数组)
- [x] 复习SQL语法(创建库、创建表、删除表、插入、修改、删除、简单查询数据)
- [x] 冒泡排序
```c++
/*
    它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
*/

void BubbleSort(int* a,int n)
{
    //冒泡排序
    for(int i=0;i<n-1;i++)
    {
        for(int j = 0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}

```
- [x] 选择排序
```c++
/*
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
*/

void SelectSort(int* a,int n)
{
    int index = 0;
    for(int i=0;i<n;i++)
    {
        index = i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<a[index])
            {
                index = j;
            }
        }
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
    }
}


```
- [x] 插入排序
```c++
/*
它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
*/

void InsertionSort(int* a,int n)
{
    void Print(int* a,int n);
    for(int i=0;i<n;i++)
    {
        int temp = a[i];
        int j=i;
        for( ;j>0;j--)
        {
            if(temp<a[j-1])
            {
                a[j] = a[j-1];
            }else{
                break;
            }
        }
        a[j]=temp;
        Print(a,10);

    }
}

```
- [x] vim中从一个文件向另一个文件中复制内容
```
example:从demo.cpp复制23到47行粘贴至test.cpp46行
1、打开demo.cpp
2、复制(命令模式下)23,47 y <注意复制完需要w保存复制不行>
3、打开test.cpp光标移动至46行
4、NORMAL模式下直接按p
```
#### 2020/6/22
为啥停了这么多天？我tm是sb。。。养了个猫就忘了学习今天还是做了招商银行的笔试才发现自己锤子都不会.....
- [x] 查找两个字符串中的最大公共子串

```c++
/*
    解题思路：
    1、首先判断两个字符串是否有空串，如果有返回NULL
    2、找出两个字符串中长字符串。此处使用strlen函数计算长度。strlen计算长度遇到'\0'结束。ex:strlen("mason") = 5
    3、判断短串是否是长串的子串，如果是返回短串。使用strstr判断。example: strstr("mason","son") = "son"
    4、将子串由长到短由前至尾截取看其是否在长串中
*/

//第四步实现
for(int i = strlen(shortstr)-1 ; i > 0 ; i--)
{
    //从长到短
    //exam："mason","maso","mas"...
    for(int j = 0; j < strlen(shortstr)-i; j++)
    {
        //从前到后
        //exam:"mas","aso","son"...
        memcpy(substr,&shortstr[j],i);
        substr[i] = '\0';
        if(strstr(longstr,substr)!=NULL)
            return substr;
    }
}

//完整实现

char *commonstring(char *str1,char *str2)
{
    char *shortstr = NULL;
    char *longstr = NULL;
    char *substr;

    if(NULL == str1 || NULL == str2)
    {
        return NULL;
    }

    if(strlen(str1) <= strlen(str2))
    {
        shortstr = str1;
        longstr = str2;
    }else {
        shortstr = str2;
        longstr = str1;
    }

    if(strstr(longstr,shortstr) != NULL)
    {
        return shortstr;
    }

    substr = new char[sizeof(char)*strlen(shortstr)+1];

    for(int i = strlen(shortstr)-1; i > 0; i--)
    {
        for(int j = 0; j<= strlen(shortstr)-i; j++)
        {
            memcpy(substr,&shortstr[j],i);
            substr[i] = '\0';
            if(strstr(longstr,substr)!=NULL)
                return substr;
        }
    }
    return NULL;
}
```
#### 2020/7/6
- [x] 动态规划问题
```
题目描述
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
输入:
[
    [0,0,0],
    [0,1,0],
    [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```
```c++
/*
解题思路
动态规划问题在于用之前状态推导出当前状态
原矩阵为a。现在定义一二维数组v。用来对应表达a每个位置可到达的路数。由于机器人只能
向右或者向下走。因此如过a[i][j]!=1,v[i][j] = v[i-1][j]+v[i][j-1]
v[i][j]的值即为右下角的路径条数
例如：
a矩阵如下
0 0 0
0 1 0
0 0 0
则对应的v为
1 1 1
1 0 1
1 1 2
*/

class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	vector<vector<int >> num;
	vector<int > temp;
	int i, j;
	int n = 0;
	for (i = 0; i < obstacleGrid.size(); i++)
	{
		for (j = 0; j< obstacleGrid.at(i).size(); j++)
		{
			if (i == 0 && j == 0)
			{
				if (obstacleGrid.at(i).at(j) == 1)
					return 0;
				temp.push_back(1);
				continue;
			}

			if (obstacleGrid.at(i).at(j) == 1)
			{
				n = 0;
			}
			else {
				if (i - 1 >= 0)
				{
					n = n+num.at(i - 1).at(j);
				}
				if (j - 1 >= 0)
				{
					n = n+temp.at(j - 1);
				}
			}
			//cout << n;
			temp.push_back(n);
			n = 0;
		}
		//cout << endl;
		num.push_back(temp);
		temp.clear();
	}
	return num.at(i - 1).at(j - 1);
}
};
```
- [x] 实现strrev 字符串反转

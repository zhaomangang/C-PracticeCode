#!/bin/bash
echo "hello wordl !"
your_name="mason"
echo $your_name 
echo ${your_name} 
#unset your_name 
#echo $your_name
str="hello i am ${your_name}"
echo $str 
p_str="${str},zhao"
echo $p_str
echo ${#p_str}   #输出字符串长度

#数组
array=(1,2,3,5,6,7,8)
value=${array[0]}
echo $value
echo ${array[@]}

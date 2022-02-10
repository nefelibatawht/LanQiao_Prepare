## STL之string的相关用法

### string的引用

- 需要添加<string>头文件
- 只能通过cin和cout来输入输出字符串
- 将字符串转化成字符数组：**str.c_str()**
- vector和string可以使用迭代器+数字的形式
- 迭代器没有类型： **string::iterator it**

### string的常用函数

#### +=

用法和数字加减相同，可以直接进行字符串类型之间的加法

```c++
str=str1+str2;
str1+=str2
```

#### length()和size()

用法类似，都是返回string存放的字符数（包含空格）

#### insert()

1. insert(pos,str)                    在pos位置插入str，pos为下标
2. insert(it,it2,it3)                  it是要插入位置的迭代器，it2和it3分别是要插入字符串的首尾迭代器

#### erase()

1. 删除单个元素：    erase(it)，it是要删字符的迭代器、
2. 删除一个区间的元素：       erase(first,last) ，first和last分别是要删除区间的起始和末尾迭代器的下一个地址，因为删除的区间是左闭右开
3. 删除起始位置确定且定长度的元素：  erase(pos,len),  pos是起始位置，len为要删除的字符串的长度

#### clear()

1. 清空，不必多说

#### substr()

1.  substr(pos,len):  返回pos位置开始len长度的子串

#### string::npos

是一个常数，值是-1，**作为string里find()函数失配的返回值**  

#### find()

1.  str.find(str2):  如果str2是str的子串的时候，返回第一次出现的位置，不是则返回string::npos
2.  str.find(str2,pos):  从pos位置开始匹配str2，道理同上

#### replace()

1. str.replace(pos,len,str1):   从pos位置开始长度为len的子串用str1替换
2. str.replace(it,it2,str1):  把str迭代器对应左闭右开区间的子串用str1替换





- 对应PAT练习：A1060
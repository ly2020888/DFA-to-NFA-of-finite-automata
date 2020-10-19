## 输出格式

第一列为DFA的状态

![QQ截图20201019201550](C:\Users\Administrator\homework\编译原理\代码\NFAtoDFA\QQ截图20201019201550.png)

![20150106120049890](C:\Users\Administrator\homework\编译原理\代码\NFAtoDFA\20150106120049890.jpg)



## ***\*文件结构：\****

1) 状态个数stateNum，约定状态编号0..(stateNum-1)；

2) 字符个数 symbolNum，约定符号编号 1..symbolNum，编号为0的符号为 ***\*e\*******\*；\****

3) 以下若干行是状态转换，一行一个转换，以-1结束；
转换的格式：状态，符号（可以是0），若干个状态，以-1结束；

4) 开始状态集合，-1结束；

5) 终止状态集合，-1结束；

 

## ***\*样例\****

 

### ***\*输入：\****

11

2

 

0 0 1 7 -1

1 0 2 4 -1

2 1 3 -1

3 0 6 -1

4 2 5 -1

5 0 6 -1

6 0 1 7 -1

7 1 8 -1

8 2 9 -1

9 2 10 -1

-1

 

0 -1

10 -1

### ***\*输出：\****

DFA

 状态个数：5

 字符表个数：2

 状态转换：

  (0,1)->1

  (0,2)->2

  (1,1)->1

  (1,2)->3

  (2,1)->1

  (2,2)->2

  (3,1)->1

  (3,2)->4

  (4,1)->1

  (4,2)->2

 开始状态：0

 结束状态集：{ 4 }
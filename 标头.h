#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;
class NFA {
private :
	ifstream* src_File;
	map<char, string> check;//NFA集合与DFA状态的对照表
	int m[100][100];//图的邻接矩阵
	int d[100][100];//最终结果

	void dfs();//深搜闭包
	bool status(string);//判断状态的结果
	void status_append();//添加状态
	char status_return();//已有状态返回
	void fill_table();//根据状态转换函数 填出来一个DFA
public :
	void std_output_result();//将整个结果按标准输出。
};

#pragma once
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<fstream>
using namespace std;
class NFA {
private:
	ifstream src_File = ifstream("input.txt");
	ofstream dst_File = ofstream("output.txt");
	map<string,int> check;//NFA集合与DFA状态的对照表
	int m[100][100];//图的邻接矩阵
	int d[100][100];//最终结果
	int status_n;
	int c_change;
	int start, end;
	void dfs(const int  s, const int& n, set<int>&, const int& c);//深搜闭包
	string closure(string s,int c);//判断状态的结果
	string Sclosure(string b, int c);//起始闭包
	void file_input();
	int status_return(string temp);//已有状态返回
	string findValue(int a);
public:
	void file_output();//将整个结果按标准输出。
	void fill_table();//根据状态转换函数 填出来一个DFA
	NFA();
};

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
	map<string,int> check;//NFA������DFA״̬�Ķ��ձ�
	int m[100][100];//ͼ���ڽӾ���
	int d[100][100];//���ս��
	int status_n;
	int c_change;
	int start, end;
	void dfs(const int  s, const int& n, set<int>&, const int& c);//���ѱհ�
	string closure(string s,int c);//�ж�״̬�Ľ��
	string Sclosure(string b, int c);//��ʼ�հ�
	void file_input();
	int status_return(string temp);//����״̬����
	string findValue(int a);
public:
	void file_output();//�������������׼�����
	void fill_table();//����״̬ת������ �����һ��DFA
	NFA();
};
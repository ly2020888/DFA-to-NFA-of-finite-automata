#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;
class NFA {
private :
	ifstream* src_File;
	map<char, string> check;//NFA������DFA״̬�Ķ��ձ�
	int m[100][100];//ͼ���ڽӾ���
	int d[100][100];//���ս��

	void dfs();//���ѱհ�
	bool status(string);//�ж�״̬�Ľ��
	void status_append();//���״̬
	char status_return();//����״̬����
	void fill_table();//����״̬ת������ �����һ��DFA
public :
	void std_output_result();//�������������׼�����
};
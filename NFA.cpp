#include "NFA.h"
NFA::NFA() {
	for (int i = 0; i <100; i++) {
		for (int j = 0; j < 100; j++) {
			m[i][j] = -1;
			d[i][j] = -1;
		}
	}
	file_input();
}
void NFA::file_input() {
	src_File >> status_n;
	src_File >> c_change;
	int x;
	do {
		src_File >> x;
		int temp;
		if (x != -1) {
			src_File >> temp;
			int y;
			do{
				src_File >> y;
				if(y!=-1)m[x][y] = temp;
			} while (y != -1);
		}
	}while (x != -1);
	int a, b;
	src_File >> start >> a >> end >> b;
	return;
}
void NFA::file_output() {
	for (int i = 0; i < status_n; i++) {
		for (int j = 0; j < status_n; j++) {
			cout << d[i][j]<<" ";

		}
		cout << "\n";
	}
}

void NFA::dfs(const int s, const int &n, set<int> &a, const int& c)//s 开始符号，n是边界条件，ss是状态集合，c是转换符
{	
	//if (a.empty())return;//a开始的时候必然不为空
	for (int i = 0; i < n; i++) {
		
		if (m[s][i] == c|| m[s][i]==0) {
			bool flag = !a.count(i);
			if (s != i)a.insert(i);
			if(flag)dfs(i, n, a, c);
		}
		
	}
	return;
}
string NFA::closure(string b,int c) {//利用上边的深搜返回闭包 集合，转换值
	set<int> a;
	for (int i = 0; i < b.size(); i++) {
		int temp_start = b[i] - '0';
		dfs(temp_start, status_n, a, c);
	}
	string temp = "";
	for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
		if((*it)>=0&&(*it)<=9)temp += ('0'+*it);
	}
	return temp;
}
string NFA::Sclosure(string b, int c) {//利用上边的深搜返回闭包 集合，转换值
	set<int> a;
	for (int i = 0; i < b.size(); i++) {
		int temp_start = b[i] - '0';
		a.insert(temp_start);
		dfs(temp_start, status_n, a, c);
	}
	string temp = "";
	for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
		temp += ('0' + *it);
	}
	return temp;
}
int NFA::status_return(string temp) {
	map<string, int>::iterator it;
	it = check.find(temp);
	pair<string, int> t(temp,check.size());
	if (it == check.end()) {
		check.insert(t);
		return  t.second;//如果这个状态是新状态
	}
	else {
		return it->second;//已有状态
	}
}
string NFA::findValue(int a) {
	map<string, int>::iterator it;
	for (it = check.begin(); it != check.end(); it++) {
		if (it->second == a)
			return it->first;
	}
	return "error";
}
void NFA::fill_table() {
	
	string t = "";
	t += ('0'+start);
	int x = status_return(Sclosure(t, 0));
	d[x][0] = x;

	for (int i = 0,_end = 0; i<=_end;i++) {
		string temp = findValue(d[i][0]);
		for (int j = 1; j <= c_change; j++) {
			string test = closure(temp, j);
			int y = status_return(test);
			d[i][j] = y;
			int flag = 1;
			for (int k = 0; k <= _end; k++) {
				if (d[k][0] == y) flag = 0;
			}
			if (flag)	d[++_end][0] = y;
		}
	}
	return;
}

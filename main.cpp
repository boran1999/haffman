#include<iostream>
#include<fstream>
#include<map>
#include<list>
#include"Node.h"
#include"mySort.h"

using namespace std;

int main(void) {
	ifstream in("Text.txt", ios::binary);
	map<char, int>gur;
	while (!in.eof()) {
		char c = in.get();
		gur[c]++;
	}
	list<Node*> heapNode;
	for (map<char, int>::iterator it = gur.begin(); it != gur.end(); it++) {
		Node* p = new Node;
		p->w = it->second;
		p->c = it->first;
		heapNode.push_back(p);
	}
	while (heapNode.size() != 1) {
		heapNode.sort(mySort());
		Node* sonl = heapNode.front();
		heapNode.pop_front();
		Node* sonr = heapNode.front();
		heapNode.pop_front();
		Node* parent = new Node(sonl, sonr);
		heapNode.push_back(parent);
	}
	Node* root = heapNode.front();
	build_code_table(root);
	system("pause");
	return 0;
}

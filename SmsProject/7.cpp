#include<iostream>
#include<string>
using namespace std;
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
#define FALSE 0
#define TRUE 1
//�ܿ����ң���
struct Tnode
{
	string word;
	int count;
	Tnode* left;
	Tnode* right;
};

typedef Tnode* BiTree;
typedef const string& KeyType;

int SearchBST(BiTree T, KeyType key, BiTree f, BiTree &p) {
	if (!T) { p = f;return FALSE; }
	else if EQ(key, T->word) { p = T;return TRUE; }
	else if LT(key, T->word)return SearchBST(T->left, key, T, p);
	else return SearchBST(T->right, key, T, p);
}


int InsertBST(BiTree &T, KeyType e) {
	BiTree s, p;
	bool x = SearchBST(T, e, NULL, p);
	if (!x) {
		s = new Tnode;
		s->word = e;s->count = 1;s->left = NULL;s->right = NULL;
		if (!p) T = s;
		else if LT(e, p->word) p->left = s;
		else p->right = s;
		return TRUE;
	}
	else {
		p->count++;
		return FALSE;
	}
}
int Delete(BiTree &p) {
	BiTree q, s;
	if (!p->right) {
		q = p;p = p->left;delete q;
	}
	else if (!p->left) {
		q = p;p = p->right;delete q;
	}
	else {
		q = p;s = p->left;
		while (s->right) { q = s; s = s->right; }
		p->word = s->word;
		p->count = s->count;
		if (q = p) q->left = s->left;
		else q->right = s->left;
	}
	return TRUE;
}
int DeleteBST(BiTree &T, KeyType key) {
	if (!T) return FALSE;
	else {
		if (EQ(key, T->word)) return Delete(T);
		else if (LT(key, T->word)) return DeleteBST(T->left, key);
		else return DeleteBST(T->right, key);
	}
}

int print_tree_byorder(BiTree T) {
	if (!T) return 0;
	else {
		print_tree_byorder(T->left);
		cout << T->word << ": " << T->count << endl;
		print_tree_byorder(T->right);
		return 1;
	}
}

int print_tree(BiTree T)
{
	if (!T) return FALSE;
	else
	{
		cout << T->word << ": " << T->count << endl;
		print_tree(T->left);
		print_tree(T->right);
		
	}
	return TRUE;
	
}
int CreateBST(BiTree &T) {
	string name;int value;
	cout << "请输入名字："<<endl;
	while (true) {
		cin >> name; if (!cin) break;
		InsertBST(T, name);
	}
	return 0;
}



int main()
{
	BiTree root;
	root = new Tnode;
	root = NULL;
	CreateBST(root);
	cout << "先序遍历结果为：" << endl;
	print_tree(root);
	cout << "中序遍历结果为：" << endl;
	print_tree_byorder(root);
	return 0;

}

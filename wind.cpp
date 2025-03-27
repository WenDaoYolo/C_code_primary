#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

Status InitList_L(LinkList &L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}

void createList_F(LinkList& L, int a[]) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < 6; i++) {
		LinkList p = new LNode;
		p->data = a[i];
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_L(LinkList& L, int a[]) {
	LNode* r;
	LNode* p;
	L = new LNode;
	L->next = NULL;
	r = L;
	for(int i = 0; i < 6; i++) {
		p = new LNode;
		p->data = a[i];
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

int LengthList(LinkList L){
	LNode* p = L->next;
	int j = 1;
	while (p->next != NULL) {
		p = p->next;
		j++;
	}
		return j;
}

int LocateElem_L(LinkList L, ElemType e) {
	LNode* p;
	int j = 1;
	p = L->next;
	while (p && p->data != e) {
		p = p->next;
		if (p->data == e)
			return j;
		else
			return ERROR;
	}
}

Status GetElem_L(LinkList L, int i, ElemType& e) {//在带头结点的单链表L中查找第i个元素
	int j;
	LNode* p;
	p = L->next;
	j = 1;
	while (j < i && p) {
		p = p->next;
		++j;
		if (!p || j > i)
			e = p->data;
		return OK;
	} 
}

Status ListInsert_L(LinkList L, int i, ElemType& e) {
	int j;
	LNode* p, * s;
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete_L(LinkList L, int i, ElemType &e) {
	LNode* p, * q;
	int j;
	p = L;
	j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		++j;
	}
	if (!(p->next || j > i - 1))
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;
}

void Displist(LinkList L) {
	for (LNode* p = L->next; p; p = p->next) {
		cout << p->data << '\t';
	}
}

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkList;

// 初始化链表（无头结点）
Status InitList_L(LinkList& L) {
	L = NULL;  // 直接初始化为空
	return OK;
}

// 头插法建表（无头结点）
void createList_F(LinkList& L, int a[]) {
	L = NULL;  // 初始化为空链表
	for (int i = 5; i >= 0; i--) {  // 逆序插入保证原顺序
		LNode* p = new LNode;
		p->data = a[i];
		p->next = L;
		L = p;  // 更新头指针
	}
}

// 尾插法建表（无头结点）
void CreateList_L(LinkList& L, int a[]) {
	LNode* r = NULL;  // 尾指针
	L = NULL;         // 初始为空
	for (int i = 0; i < 6; i++) {
		LNode* p = new LNode;
		p->data = a[i];
		p->next = NULL;

		if (L == NULL) {  // 第一个节点
			L = p;
			r = L;
		}
		else {          // 后续节点
			r->next = p;
			r = p;
		}
	}
}

// 求表长（无头结点）
int LengthList(LinkList L) {
	int count = 0;
	LNode* p = L;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}

// 按值查找（无头结点）
int LocateElem_L(LinkList L, ElemType e) {
	LNode* p = L;
	int pos = 1;
	while (p != NULL) {
		if (p->data == e) return pos;
		p = p->next;
		pos++;
	}
	return ERROR;
}

// 按位置查找（无头结点）
Status GetElem_L(LinkList L, int i, ElemType& e) {
	if (i < 1) return ERROR;
	LNode* p = L;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p) return ERROR;
	e = p->data;
	return OK;
}

// 插入元素（无头结点）
Status ListInsert_L(LinkList& L, int i, ElemType e) {
	if (i < 1) return ERROR;

	// 处理头插
	if (i == 1) {
		LNode* s = new LNode;
		s->data = e;
		s->next = L;
		L = s;  // 更新头指针
		return OK;
	}

	LNode* p = L;
	int j = 1;
	while (p && j < i - 1) {  // 找前驱节点
		p = p->next;
		j++;
	}
	if (!p) return ERROR;

	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

// 删除元素（无头结点）
Status ListDelete_L(LinkList& L, int i, ElemType& e) {
	if (i < 1 || L == NULL) return ERROR;

	// 处理头删
	if (i == 1) {
		LNode* q = L;
		e = q->data;
		L = L->next;  // 更新头指针
		delete q;
		return OK;
	}

	LNode* p = L;
	int j = 1;
	while (p && j < i - 1) {  // 找前驱节点
		p = p->next;
		j++;
	}
	if (!p || !p->next) return ERROR;

	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	delete q;
	return OK;
}

// 显示链表（无头结点）
void Displist(LinkList L) {
	for (LNode* p = L; p != NULL; p = p->next) {
		cout << p->data << '\t';
	}
	cout << endl;
}


void MenuLine() {
	cout <<"线性表子系统"<<endl;
	cout << "1建表" << endl;
	cout << "2插入元素" << endl;
	cout << "3删除元素" << endl;
	cout << "4按位置查找" << endl;
	cout << "5按元素值查找" << endl;
	cout << "6求表长" << endl;
	cout << "0返回" << endl;
}





int main() {

	LinkList L=NULL;
	ElemType x;
	int i, n, loc;
	int a[] = { 7,4,9,12,8,15 };
	char ch1, ch2, b;
	ch1 = 'y';
	while (ch1 == 'y' || ch1 == 'Y') {
		MenuLine();
		scanf("%c", &ch2);
		getchar();

		switch (ch2) {
		case '1':
			InitList_L(L);
			CreateList_L(L, a);
			cout << "建立后的线性表为:";
			Displist(L);
			break;
		case '2':
			cout << "请输入要插入的元素位置:";
			cin >> i;
			cout << "请输入要插入的元素值:";
			cin >> x;
			ListInsert_L(L, i, x);
			cout << "插入元素" << x << "后的线性表为:";
			Displist(L);
			break;
		case '3':
			cout << "请输入要删除的元素位置:";
			cin >> i;
			if (ListDelete_L(L, i, x)) {
				cout << "已成功在第" << i << "的位置上删除" << x << "，删除后的线性表为:";
				Displist(L);
			}
			else
				cout << "输入删除的参数错误!" << endl;
			break;
		case '4':
			cout << "请输入查找的元素位置(大于等于1的整数):"; cin >> i;
			if (GetElem_L(L, i, x))cout << "当前线性表第" << i << "个元素的值为:" << x;
			else
				cout << "输入的位置错误!";
			break;
		case '5':
			cout << "请输入查找的整数:";
			cin >> x;
			loc = LocateElem_L(L, x);
			if (loc)
				cout << "査找元素值为" << x << "的位置为:" << loc;
			else
				cout << "该表中无此元素!";
			break;
		case '6':
			cout << "该线性表的长度为:" << LengthList(L);
			break;
		case '0':
			ch1 = 'n';
			break;
		default:
			cout << "输入有误，请输入8-9进行选择!";
		}
		if (ch2 != '0') {
			cout << "\n按回车键继续，按任意键返回主菜单!"<< endl << endl;
			b = getchar();
			if (b != '\xA') {
				getchar();
				ch1 = 'n';
			}

		}
		
	}




	return 0;
}
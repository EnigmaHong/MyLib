#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include <atlstr.h>
#include <assert.h>
#include <stack>

using namespace std;

class person {
public:
	int age;
public:
	person(int _age=0) :age( _age) {
		
	}
	person(int* ps) {
		*this = ps;
	}

};

bool operator == (person &p1, person const &p2) {
	if (p1.age == p2.age) {
		return true;
	}
	return false;
}

class MyCString {
private:
	char *mpData;//只有本身类的成员函数才可以访问
public:
	MyCString(char *pData=nullptr) {
		if (pData == nullptr) {
			mpData = new char[1];
			assert(nullptr != mpData);
			*mpData = '\0';
		}
		else {
			mpData = new char[strlen(pData) + 1];
			assert(nullptr != mpData);
			strcpy(mpData,pData);
		}
	}
	MyCString(const MyCString &Other)
	{
		mpData = new char[strlen(Other.mpData) + 1];
		assert(nullptr != mpData);
		strcpy(mpData, Other.mpData);
	}
	~MyCString()
	{
		if (nullptr != mpData)
		{
			delete[] mpData;
			mpData = nullptr;
		}
	}

	const MyCString& operator =(const MyCString &Other)
	{
		if (this == &Other)
		{
			return *this;
		}
		delete[] mpData;
		mpData = new char[strlen(Other.mpData) + 1];
		assert(nullptr != mpData);
		strcpy(mpData, Other.mpData);
		return *this;
	}
	void Print() {
		if (*mpData != NULL) {
			cout << mpData << endl;
		}
		else {
			cout << "NULL" << endl;
		}
	}

};

int SwapA(int &a, int &b) {
	if (a == b) return 0;
	a = a + b;
	b = a - b;
	a = a - b;
	return (a, b);
}
unsigned SwapB(unsigned &a, unsigned &b) {
	if (a == b) return 0;
	a = a^b;
	b = a^b;
	a = a^b;
	return (a, b);
}

int Myatoi(const char *pString) {
	assert(nullptr != pString);
	const int len = strlen(pString);
	int Value = 0;
	int Time = 1;
	for (int i = len - 1; i >= 0; i--, Time *= 10) {
		Value += (pString[i] - '0')*Time;
	}
	return Value;
}

char *MyInverted(char *pDest) {
	assert(nullptr != pDest);
	const int len = strlen(pDest);
	char T;
	for (int i = 0; i < len / 2; i++) {
		T = pDest[i];
		pDest[i] = pDest[len - i - 1];
		pDest[len - i - 1] = T;
	}
	return pDest;
}

char *MyUpper(char *pDest) {
	assert(nullptr != pDest);
	for (char *i = pDest; *i != '\0'; i++) {
		if (*i < 'a' || *i > 'z') {
			continue;
		}
		*i -= 32;
	}
	return pDest;
}

int BinarySearch(char *Array, int count, int value) {
	assert(nullptr != Array);
	int left = 0;
	int right = count - 1;
	int Mid = 0;
	while (left <= right) {
		Mid = (left + right) / 2;
		if (Array[Mid] > value) {
			left = Mid + 1;
		}
		else if (Array[Mid] < value) {
			right = Mid - 1;
		}
		else {
			return Array[Mid];
		}
	}
	return -1;
}
	
struct Node {
	Node *mpNext;
	Node *head;
	int mData;
	Node(int _data) {
		mData = _data;
		mData = NULL;
	}
};
class LinkList {
private:
	Node *head;
public:
	void Insert(Node *node, int position) {
		if (head == NULL) {
			head = node;
			return;
		}
		if (position == 0) {
			node->mpNext = head;
			head = node;
			return;
		}
		Node *current_node = head;
		int i = 0;
		while (current_node->mpNext != NULL && i < position - 1) {
			current_node = current_node->mpNext;
			i++;
		}
		if (i == position - 1) {
			node->mpNext = current_node->mpNext;
			current_node->mpNext = node;
		}
	}
	void Output() {
		if (head == NULL) {
			return;
		}
		Node *current_node = head;
		while (current_node != NULL) {
			cout << current_node->mData<<"  ";
			current_node = current_node->mpNext;
		}
		cout << endl;
	}
};
void DeleteFromList(Node *pHead, int value) {
	Node *pPrve = pHead;
	Node *pNext = pHead->mpNext;
	while (nullptr != pNext) {
		if (pNext->mData != value) {
			pPrve = pNext;
			pNext = pNext->mpNext;
		}
		else {
			pPrve->mpNext = pNext->mpNext;
			pNext = pPrve->mpNext;
			delete pNext;
		}
	}
}

int main()
{
	LinkList linklist;
	for (int i = 1; i <= 10; i++) {
		Node *node = new Node(i);
		linklist.Insert(node, i-1);
	}
	linklist.Output();
	linklist.Output();
	cin.get();
}
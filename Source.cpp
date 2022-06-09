#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

class list {
private:
	struct node {
		node(int val) {
			value = val;
		}
		~node() {
			cout << value << " was deleted" << endl;
		}
		int value;
		node* next=nullptr;
	};
	node* create_node(int val) {
		node* new_node = new node(val);
		return new_node;
	}
	node* head = nullptr;
	int size = 0;
public:
	~list() {
		clear();
	}
	int get_size() {
		return size;
	}
	void add_first(int value) {
		node* new_first = create_node(value);
		size++;
		if (head == nullptr) {
			head = new_first;
		}
		else {
			new_first->next = head;
			head = new_first;
		}
	}
	void add_last(int value) {
		node* new_first = create_node(value);
		size++;
		if (head == nullptr) {
			head = new_first;
		}
		else {
			node* cur = head;
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = new_first;
		}
	}
	int pop_head() {
		if (head == nullptr) return -1;
		size--;
		int x;
		node* h = head;
		x = head->value;
		head = head->next;
		delete h;
		return x;
	}
	void clear() {
		if (head == nullptr) return;
		while (head->next != nullptr) {
			node* next = head->next;
			delete head;
			head = next;
		}
		delete head;
	}
};
int main() {
	int count;
	list l;
	cin >> count;
	for (int i = 0; i < count; i++) {
		l.add_last(i);
	}
	while (l.get_size() > 0) {
		cout << l.pop_head() << endl;
	}
	return 0;
}
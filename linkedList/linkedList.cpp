#include <iostream>

using namespace std;

struct Node{
	Node * next;
	Node * prev;
	int key;
};


class LinkedList{

public:
	LinkedList(){
		listHead = 0;
		listTail = 0;

	}

	Node * listHead = 0;
	Node * listTail = 0;
	
	void insert(int a){
		Node * curElement = new Node();
		curElement->next = 0;
		curElement->key = a;
		//printf("the point of curElement is: %p\n", curElement);

		if(listHead == 0){
			listHead = curElement;
		}

		curElement->prev = listTail;

		if(listTail != 0){
			listTail->next = curElement;
		}

		listTail = curElement;

	}

	int popOut(){
		if(listHead == 0){
			return 0;
		}
		Node * curElement = listHead;
		Node * next = listHead->next;
		int output = curElement->key;
		if(listTail == listHead){
			listTail = 0;
		}
		delete listHead;
		listHead = next;

		return output;
	}

	void print(){
		Node * curElement = listHead;
		while(curElement != 0){
			cout << curElement->key << endl;
			curElement = curElement->next;	
		}
	}

	void clear(){
		while(listHead != 0){
			int a = popOut();
		}
		
	}
	
};


int main(int argc, char * argv[]){
	LinkedList *list = new LinkedList();	

	int n = 5;
	for(int i = 0; i < n ; i++){
		list->insert(i);
		//printf("the point of listTail is: %p\n", list->listTail);
	}
	cout << endl;
	cout << endl;
	list->print();
	cout << endl;
	cout << endl;
	list->clear();
	while(list->listHead != 0){
		int a = list->popOut();
		cout << a << endl;
	}


	return 0;

}





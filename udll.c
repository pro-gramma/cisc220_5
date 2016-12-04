#include <stdlib.h>
union Data {
	int i;
	int* ip;
	float f;
	float* fp;
};

struct Node {
	union Data data;
	struct Node *prev;
	struct Node *next;
};
typedef struct Node Node;

Node tail;
Node head;

int main() {
	head.data.i = 0;
	head.prev = NULL;
	head.next = &tail;
	tail.prev = &head;
	tail.next = NULL;
}

int length() {
	return (head.data.i);
}

union Data get( int index ) {
	int node_count = 0;
	
	if ( index >= 0 && index < ( length() / 2 ) ) {
		
		for ( Node *i = head.next; (*i).next != NULL; i = (*i).next ) {
			if ( node_count == index ) {
				return ((*i).data);
			};
			node_count++;
		}
	}
	else if ( index <= length() && index >= ( length() / 2 ) ) {
		node_count = length();
		
		for ( Node *i = tail.prev; (*i).prev != NULL; i = (*i).prev ) {
			if ( node_count == index ) {
				return ((*i).data);
			};
			node_count--;
		}
	};
	union Data empty;
	return (empty);
}

void insert( int index, union Data data ) {
	int node_count = 0;
	Node new;
	new.data = data;

	if ( index == 0 ) {
		new.prev  = &head;
		new.next  = head.next;
		head.next = &new;
		(*new.next).prev = &new;
		head.data.i++;
	}
	else if ( index == length() ) {
		new.next  = &tail;
		new.prev  = tail.prev;
		tail.prev = &new;
		(*new.prev).next = &new;
		head.data.i++;
	}
	else if ( index >= 0 && index < ( length() / 2 ) ) {
		
		for ( Node *i = head.next; (*i).next != NULL; i = (*i).next ) {
			if ( node_count == index ) {
				new.prev  = i;
				new.next  = (*i).next;
				(*i).next = &new;
				(*new.next).prev = &new;
				head.data.i++;
				break;
			};
			node_count++;
		}
	}
	else if ( index <= length() && index >= ( length() / 2 ) ) {
		node_count = length();

		for ( Node *i = tail.prev; (*i).prev != NULL; i = (*i).prev ) {
			if ( node_count == index ) {
				new.next  = i;
				new.prev  = (*i).prev;
				(*i).prev = &new;
				(*new.prev).next = &new;
				head.data.i++;
				break;
			};
			node_count--;
		}
	}
}

void remove( int index ) {

	int node_count = 0;

	if ( length() == 0 ) {
		return;
	}
	if ( index == 0 ) {
		head.next = (*head.next).next;
		(*(*head.next).next).prev = &head;
		head.data.i--;
	}
	else if ( index == length() ) {
		tail.prev = (*tail.prev).prev;
		(*(*tail.prev).prev).next = &tail;
		head.data.i--;	
	}
	else if ( index >= 0 && index < ( length() / 2 ) ) {
		
		for ( Node *i = head.next; (*i).next != NULL; i = (*i).next ) {
			if ( node_count == index ) {
				(*(*i).prev).next = (*i).next;
				(*(*i).next).prev = (*i).prev;
				head.data.i--;
				break;
			};
			node_count++;
		}
	}
	else if ( index <= length() && index >= ( length() / 2 ) ) {
		node_count = length();
		
		for ( Node *i = tail.prev; (*i).prev != NULL; i = (*i).prev ) {
			if ( node_count == index ) {
				(*(*i).next).prev = (*i).prev;
				(*(*i).prev).next = (*i).next;
				head.data.i--;
				break;
			};
			node_count--;
		}
	}
}
#include "udll.h"
int main() {
	union Data data;
	data.i = 0;
	insert( 0, data );
	get( 0 );
	remove( 0 );
	length();
	return (0);
}
#ifndef UDLL_H
#define UDLL_H
union Data;
void insert( int index, union Data data );
void remove( int index );
union Data get( int index, union Data data );
int length();
#endif
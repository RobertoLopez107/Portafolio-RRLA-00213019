#include <iostream>
using namespace std;

struct Tpila{
	float elements[5];
	int top;
};
typedef struct Tpila Pila;

void initialize(Pila *s){
	s->top = -1;
}

bool empty(Pila *s){
	return s->top < 0;
}

void push(Pila *s, float e){
	if(s->top < 4){
		(s->top)++;
		s->elements[s->top] = e;
	}
}

void pop(Pila *s, float *e){
	if(s->top >= 0){
		*e = s->elements[s->top];
		(s->top)--;
	}
}

int main()
{
	Pila unaPila;
	initialize(&unaPila);
	
	if(empty(&unaPila))
		cout << "Esta vacia" << endl;
	
	float x= 3, y= 4 ,z= 8,w=3,e= 12;
	
	push(&unaPila, x);
	push(&unaPila, y);
	push(&unaPila, z);
	push(&unaPila, w);
	push(&unaPila, e);
	
	float a=0;
	
	while(!empty(&unaPila)){
		pop(&unaPila,&a);
		if(empty(&unaPila))
		cout<<"El valor del fondo es: "<<a;
		}
	
	
}
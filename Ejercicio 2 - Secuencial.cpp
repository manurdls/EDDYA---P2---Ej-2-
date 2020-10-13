#include <iostream>
#include <stdlib.h>
using namespace std;
class Pila{
	private:
		int *items;
		int indexTop;
		int maxSize;
	public:
		Pila(int maxSize = 10); //si no se pasa como parámetro la cantidad maxima de elementos, por defecto son 10
		int size() const;	    //devuelve la cantidad actual de elementos
		bool empty() const;     //devuelve True si la pila está vacia
		int top() const;	    //devuelve el valor del ultimo elemento agregado
		void push(int dat);     //agrega un elemento a la pila
		void pop();			    //elimina el elemento que está en la posición top de nuestra pila
		~Pila();			    //es el destructor
};

Pila::Pila(int max){
	indexTop = -1;
	maxSize = max;
	items = new int[max];
	
}

int Pila::size() const{
	return indexTop + 1;
}

bool Pila::empty() const{
	return (indexTop == -1);
}

int Pila::top() const{
	return items[indexTop];
}

void Pila::push(int dat){
	if(indexTop + 1 < maxSize)
		items[++indexTop] = dat;
}

void Pila::pop(){
	if(!empty())
		indexTop--;
}
Pila::~Pila(){
	delete[]items;
}

int main(){
	int num, aux, i;
	char numBinario[8];
	
	Pila unaPila(8);
	
	printf("Ingrese un numero decimal: ");
	scanf("%d", &num); fflush(stdin);
	
	aux = num;
	while(aux != 1){
		if (aux % 2 == 0){
			unaPila.push(0);
		}
		else{
			unaPila.push(1);
		}
		aux = aux/2;
	}
	unaPila.push(1);
	
	aux = unaPila.size();
	for (i=0; i<aux; i++){
		printf("%d", unaPila.top());
		unaPila.pop();
	}
}

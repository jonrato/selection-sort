#include <stdio.h>
#include <stdlib.h>

void constroiHeap(int *p_vetor, int tamanho, int indice_raiz){
	int ramificacao, valor;
	valor = p_vetor[indice_raiz];

	while(indice_raiz <= tamanho/2){
		ramificacao=2*indice_raiz;

		if(ramificacao<tamanho && p_vetor[ramificacao] < p_vetor[ramificacao+1])
			ramificacao++;
		if(valor>=p_vetor[ramificacao])
			break;
		p_vetor[indice_raiz] = p_vetor[ramificacao];
		indice_raiz = ramificacao;
	}
	p_vetor[indice_raiz] = valor;
}

void HeapSort(int *p_vetor, int tamanho){
	int indice, troca;
	for(indice=tamanho/2;indice>=0;indice--)
		constroiHeap(p_vetor, tamanho, indice);
	while(tamanho>0){
		troca = p_vetor[0];
		p_vetor[0]=p_vetor[tamanho];
		p_vetor[tamanho]=troca;
		constroiHeap(p_vetor,--tamanho, 0);
	}
}

int main(int argc, char *argv[]){
	int vetor[]={23, 32, 65, 7, 8, 98, 123, 34, 92, 54, 33, 45};
	int tamanho=12;
	int indice;

	HeapSort(vetor,tamanho);

	for(indice=0;indice<=tamanho-1;indice++)
		printf("O valor do indice %d ordenado eh: %d\n",indice, vetor[indice] );
	system("PAUSE");
	return 0;
}
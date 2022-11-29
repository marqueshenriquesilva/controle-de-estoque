#include <stdio.h>
#include <string.h>
#define TF 50

struct produto{
	char descricao[25];
	int codfornecedor;
	int qtdestoque;
	int qtdmin;
	int qtdmax;
};

void preencheprodutos(struct produto vetprodutos[TF], int &tl){
	struct produto a;
	
	strcpy(a.descricao, "Arroz");
	a.codfornecedor = 777;
	a.qtdestoque = 100;
	a.qtdmin = 150;
	a.qtdmax = 200;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Feijao");
	a.codfornecedor = 777;
	a.qtdestoque = 190;
	a.qtdmin = 60;
	a.qtdmax = 100;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Leite condensado");
	a.codfornecedor = 444;
	a.qtdestoque = 45;
	a.qtdmin = 50;
	a.qtdmax = 90;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Macarrao");
	a.codfornecedor = 555;
	a.qtdestoque = 68;
	a.qtdmin = 60;
	a.qtdmax = 100;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Molho tomate");
	a.codfornecedor = 222;
	a.qtdestoque = 24;
	a.qtdmin = 20;
	a.qtdmax = 70;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Acucar");
	a.codfornecedor = 333;
	a.qtdestoque = 67;
	a.qtdmin = 70;
	a.qtdmax = 100;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Bolacha salgada");
	a.codfornecedor = 555;
	a.qtdestoque = 135;
	a.qtdmin = 45;
	a.qtdmax = 90;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Agua mineral 1 litro");
	a.codfornecedor = 987;
	a.qtdestoque = 60;
	a.qtdmin = 40;
	a.qtdmax = 80;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Farinha de trigo");
	a.codfornecedor = 111;
	a.qtdestoque = 230;
	a.qtdmin = 40;
	a.qtdmax = 90;
	vetprodutos[tl] = a;
	tl++;
	
	strcpy(a.descricao, "Leite CX - 12 unidades");
	a.codfornecedor = 666;
	a.qtdestoque = 20;
	a.qtdmin = 30;
	a.qtdmax = 50;
	vetprodutos[tl] = a;
	tl++;
}

void exibeprodutos(struct produto vetprodutos[TF], int tl){
	int i;
	
	for (i=0; i<tl; i++){
		printf("\nDescricao: %25s	Codigo do Fornecedor: %3d	Qtd Estoque: %3d	Qtd Min: %3d	Qtd Max: %3d", vetprodutos[i].descricao, vetprodutos[i].codfornecedor, vetprodutos[i].qtdestoque, vetprodutos[i].qtdmin, vetprodutos[i].qtdmax);
	}
	printf("\n");
}

void exibeprodutosabaixo(struct produto vetprodutos[TF], int tl){
	int i, qtdpedido, qtdestoque, qtdmin, qtdmax;
	for (i=0; i<tl; i++){
		
		qtdestoque = vetprodutos[i].qtdestoque;
		qtdmin = vetprodutos[i].qtdmin;
		qtdmax = vetprodutos[i].qtdmax;
		
		if (qtdestoque < qtdmin){
			qtdpedido = qtdmax - qtdestoque;
			printf("\nDescricao: %25s	Codigo do Fornecedor: %3d	Qtd Max: %3d	Qtd Estoque: %3d	Qtd do Pedido: %d",
			vetprodutos[i].descricao, vetprodutos[i].codfornecedor, qtdmax, qtdestoque, qtdpedido);
		}
	}
	printf("\n");
}

void exibeprodutosacima(struct produto vetprodutos[TF], int tl){
	int i, excedente, qtdestoque, qtdmax;
	for (i=0; i<tl; i++){
		
		qtdestoque = vetprodutos[i].qtdestoque;
		qtdmax = vetprodutos[i].qtdmax;
		
		if (qtdestoque > qtdmax){
			excedente = qtdestoque - qtdmax;
			printf("\nDescricao: %25s	Codigo do Fornecedor: %3d	Qtd Estoque: %3d	Qtd Max: %3d	Excedente: %d",
			vetprodutos[i].descricao, vetprodutos[i].codfornecedor, qtdestoque, qtdmax, excedente);
		}
	}
	printf("\n");
}

int main(void){
	int tl = 0, opcao = 0;
	struct produto vetprodutos[TF];
	
	preencheprodutos(vetprodutos, tl);

	while(opcao != 4){
		printf("\n1 - Exibir produtos");
		printf("\n2 - Exibir produtos abaixo do estoque minimo permitido");
		printf("\n3 - Exibir produtos acima do estoque maximo permitido");
		printf("\n4 - Sair");
		printf("\nOpcao: ");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				exibeprodutos(vetprodutos, tl);
				break;
			case 2:
				exibeprodutosabaixo(vetprodutos, tl);
				break;
			case 3:
				exibeprodutosacima(vetprodutos, tl);
				break;
		}
	}
	
	printf("\nFIM");
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct dadosProduto {
    char nome[200];
    float preco;
    int qntEstoque;
    float desconto;
};

float calcularTotalEstoque (struct dadosProduto produto) {
    return produto.preco * produto.qntEstoque;
}

struct dadosProduto atualizarEstoque (struct dadosProduto produto) {
    int quantidade;

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidade); 

  if (quantidade > 0 && quantidade <= produto.qntEstoque) {
    produto.qntEstoque -= quantidade;
    printf("Compra realizada com sucesso. Total: R$ %.2f\n", quantidade * produto.preco);
    } else {
    printf("Quantidade insuficiente em estoque.\n");
}
   return produto;
}

void consultaEstoque(struct dadosProduto produto) {
    printf("Nome do produto: %s \n", produto.nome);
    printf("Preço: %.2f \n", produto.preco);
    printf("Quantidade em estoque: %d \n", produto.qntEstoque);
    printf("Valor total em estoque: R$ %.2f \n", calcularTotalEstoque(produto));
}

float calculandoDesconto (struct dadosProduto produto) {
    if (produto.preco >= 50) {
       return produto.preco * 0.10;
    }else{
       return produto.preco * 0.15;
    }    
}

struct dadosFabricante {
    char nome[200];
    char data[200];
    char codigo[200];
};

void fabric (struct dadosFabricante fabricante) {
    printf("--- DADOS DO FABRICANTE --- \n");
    fflush(stdin);
    printf("Nome do fabricante: ");
    gets(fabricante.nome);
    printf("Data do fabricante: ");
    gets(fabricante.data);

    printf("Código do fabricante: ");
    gets(fabricante.codigo);
}


int main () {
    setlocale(LC_ALL, "portuguese");

    struct dadosProduto Produto;
    struct dadosFabricante Fabricante;
    int opcao;

    printf("Digite o nome do produto: ");
    gets(Produto.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &Produto.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &Produto.qntEstoque);

    do {
    printf("\n------ MENU ------ \n");
    printf("1 - Realizar uma compra \n");
    printf("2 - Consultar desconto pelo valor que deseja comprar \n");
    printf("3 - Consultar estoque \n");
    printf("4 - Dados fabricante \n");
    printf("5 - Sair do programa. \n");

    printf("Digite a opção escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1 :
        Produto = atualizarEstoque(Produto);
        break;

        case 2 :
        printf("\nDesconto: %.2f \n", calculandoDesconto(Produto));
        break;

        case 3 :
        consultaEstoque(Produto);
        break;

        case 4 :
        fabric(Fabricante);
        break;

        case 5 :
        printf("Saindo do programa... \n");
        break;
    
    default:
    printf("Opção inválida. \n");
        break;
    }
    
    } while (opcao != 5);

    return 0;
}
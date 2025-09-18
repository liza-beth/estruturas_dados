#include <iostream>
using namespace std;

class Celula {
    private:
        int conteudo;

    public:
        Celula *prox;
    Celula(int c) {
        conteudo = c;
        prox = NULL;
    }
    int getConteudo() {
        return conteudo;
    }
};

class ListaEncadeada {
    private:
        Celula *primeira;
        Celula *ultima;
        int tamanho; // guarda o tamanho atual, naão é fixo

    public:
    ListaEncadeada() {
        primeira = NULL;
        ultima = NULL;
        tamanho = 0;
    }

    void inserir(int indiceInserir, int conteudo) {
        if (indiceInserir < 0) {
            cout << "erro ao inserir - índice inválido";
            return;
        }
        Celula *nova = new Celula(conteudo);
        if (primeira == NULL) {
            primeira = nova;
            ultima = nova;
        }
        else if (indiceInserir == 0) {
            nova->prox = primeira; // a proxima celula da nova será a antiga primeira
            primeira = nova;
        }
        else if (indiceInserir == tamanho) { /// ou seja, no fim
            ultima->prox = nova;
            ultima = nova;
        }
        else {
            Celula *atual = primeira;
            for (int i = 0; i < indiceInserir - 1; ++i) {
                atual = atual->prox; // começa da primeira e avançando até chegar na célula que ocupa onde se deseja quer colocar a nova célula
            }
            nova->prox = atual->prox; 
            atual->prox = nova;
        }
        tamanho++;
    }

    void imprimir() {
        if (primeira == NULL){
            cout << "lista vazia";
            return;
        }
        for (Celula *p = primeira; p != NULL; p = p->prox) {
            cout << p->getConteudo() << "\n"; 
        }
    }

    int remover(int indice) {
        if (primeira == NULL) {
            cout << "lista vazia";
            return -1;
        }
        else if (indice < 0 || indice > tamanho) {
            cout << "índice inválido";
            return -1;
        }

        int conteudoRemover = 0;
        Celula *remover = primeira;
        Celula *anterior = primeira; 

        if (indice == 0) {
            conteudoRemover = remover->getConteudo(); // da primeira
            primeira = primeira->prox;
            if (primeira == NULL){  // se a primeira não tem próximo, ou seja, a lista possui apenas um elemento
                ultima = NULL;
            }
        } else {
            for (int i = 0; i < indice - 1; ++i) {
                anterior = anterior->prox; 
            }
            remover = anterior->prox;
            conteudoRemover = remover->getConteudo();
            anterior->prox = remover->prox;
            if (remover == ultima) {
                ultima = anterior;
            }
        }
        tamanho--;
        delete remover;
        return conteudoRemover;
    }
};

int main(int argc, char *argv[]) {
    ListaEncadeada lista;
    lista.inserir(0, 10); 
    lista.inserir(1, 30);     
    lista.inserir(1, 20);    
    lista.inserir(0, 5);  
    lista.imprimir(); // 5, 10, 20, 30

    cout << "Removido: " << lista.remover(2) << endl; // 20
    cout << "Removido: " << lista.remover(0) << endl; // 5                           
    cout << "Removido: " << lista.remover(1) << endl; // 30                               
    cout << "Removido: " << lista.remover(0) << endl; // 10                
    cout << "Removido: " << lista.remover(0) << endl; // lista vazia
    lista.imprimir(); // vazia
    return 0;
}
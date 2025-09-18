#include <iostream>
using namespace std;

class FilaDeArray{ // estrutura de dados fifo
    private:
        int *VET;
        int ProximaPosicaoLivre;
        int MAX;

    public:
    FilaDeArray(int qtde) {
        MAX = qtde;
        VET = new int[MAX];
        ProximaPosicaoLivre = 0;
    }

    ~FilaDeArray() {
        delete[] VET;
    }

    void Inserir(int n){
        if (ProximaPosicaoLivre < MAX)
            VET[ProximaPosicaoLivre++] = n; // adiciona na última posição livre e incrementa ppl
    }

    void Mostra(){
        for (int i = 0; i < ProximaPosicaoLivre; i++){
            cout << VET[i] << "\n";
        }
    }

    int Remover(){
        if (ProximaPosicaoLivre > 0){
            int saiu = VET[0]; // sempre vai ser o primeiro índice que vai sair
            for (int i = 0; i < ProximaPosicaoLivre; i++)
            { // "puxar" todo mundo para cima
                VET[i] = VET[i + 1];
            }
            ProximaPosicaoLivre--;
            return saiu;
        };
    }
};

int main(int argc, char *argv[])
{
    FilaDeArray fila(50);
    fila.Inserir(3);
    fila.Inserir(5);
    fila.Inserir(7);
    fila.Inserir(1);
    fila.Mostra();
    cout << "\nRemover " << fila.Remover() << ".\n"; // 3
    cout << "\nRemover " << fila.Remover() << ".\n"; // 5
    fila.Mostra();
    cout << "\n";
    fila.Inserir(2);
    fila.Inserir(0);
    fila.Mostra(); // 7, 1, 2, 0
}
#include <iostream>
using namespace std;

class ListaDeArray{
    private:
        int *VET;
        int ProximaPosicaoLivre;
        int MAX;

    public:
    ListaDeArray(int qtde) {
        MAX = qtde;
        VET = new int[MAX];
        ProximaPosicaoLivre = 0;
    }

    void InsereFim(int n) {
        if (ProximaPosicaoLivre < MAX) VET[ProximaPosicaoLivre++] = n;
    }

    void InsereInicio(int n) {
        if (ProximaPosicaoLivre < MAX) {
            for (int i = ProximaPosicaoLivre; i >= 0; i--) {
                VET[i] = VET[i - 1];
            }
            VET[0] = n;
            ProximaPosicaoLivre++;
        }
    }

    void Mostra() {
        for (int i = 0; i < ProximaPosicaoLivre; i++) {
            cout << VET[i] << "\n";
        }
    }

    int RetiraInicio() {
        if (ProximaPosicaoLivre > 0) {
            int v = VET[0];
            for (int i = 0; i < ProximaPosicaoLivre; i++){
                VET[i] = VET[i + 1];
            }
            ProximaPosicaoLivre--;
            return v;
        }
    }

    int RetiraFim(){
        if (ProximaPosicaoLivre > 0) return VET[--ProximaPosicaoLivre];
    }
};

int main(int argc, char *argv[]) {
    ListaDeArray lista(50);
    lista.InsereInicio(3);
    lista.InsereInicio(5);
    lista.InsereFim(7);
    lista.InsereFim(1);
    lista.InsereInicio(4);
    lista.Mostra(); // 4, 5, 3, 7, 1
    cout << "\nRemover início " << lista.RetiraInicio() << ".\n\n"; // 4
    cout << "\nRemover fim " << lista.RetiraFim() << ".\n\n";  // 1
    lista.Mostra();  // 5, 3, 7
    cout << "\n";
    lista.InsereFim(2);
    lista.InsereInicio(8);
    lista.Mostra(); // 8, 5, 3, 7, 2
    cout << "\Remover início " << lista.RetiraInicio() << ".\n\n"; // 8
    cout << "\nRemover fim " << lista.RetiraFim() << ".\n\n"; // 2
    return 0;
}
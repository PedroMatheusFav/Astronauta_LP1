#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.
class Astronauta {
    private:
        string cpf;
        string nome;
        int idade;

    public:
        Astronauta(string c, string n, int i){
            cpf = c;
            nome = n;
            idade = i;
        }
};

class Voo {
    private:
        int codigo;

    public:
        Voo(int c){
            codigo = c;
        }
};

class Morte {
    private:
        string cpf;
        int nome;
    public:
        Morte(string c, int v){
            cpf = c;
            nome = v;
        }
};

class Agencia {
    private:
        vector<Astronauta> astronautas;
        vector<Voo> voos;
        vector<Morte> mortos;
    
    public:
        Agencia(){
        }

        string getElemento(){
            return cpf;
        }

        void cadastrarAstronauta(string c, string n, int i){
            astronautas.push_back(Astronauta(c, n, i));
            cout << "OK: astronauta " << c << " cadastrado" << endl;
        }

        void adicionarAstronauta(string cpf, int codigo){
            for(int i = 0; i < astronautas.size(); i++){
                if(astronautas[i].getElemento() == cpf){
                    voos.push_back(Voo(codigo));
                    cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
                    return;
                } else if (i == astronautas.size() - 1){
                cout << "ERRO: astronauta " << cpf << " nao encontrado" << endl;
                return;
                }
            }
        }

        void cadastrarVoo(int codigo){
            voos.push_back(Voo(codigo));
            cout << "OK: voo " << codigo << " cadastrado" << endl;
        }

        void explodirVoo(int codigo){
            voos.push_back(Voo(codigo));
            cout << "OK: voo " << codigo << " cadastrado" << endl;
        }

        void lancarVoo(int codigo){
            for(int i = 0; i < voos.size(); i++){
                if(voos[i] == codigo){
                    cout << "OK: voo " << codigo << " lancado" << endl;
                    return;
                    break;
                } else if (i == voos.size() - 1){
                cout << "ERRO: voo " << codigo << " nao encontrado" << endl;
                return;
                }
            }
        }


};
    

// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

int main() {
    // TODO: criar a Agencia aqui, por exemplo:  Agencia agencia;
    Agencia agencia;
    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos
            cout << agencia.cadastrarAstronauta(cpf, nome, idade) << comando << endl;
            // TODO: agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << agencia.cadastrarVoo(codigo) << comando << endl;
            // TODO: agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            cout << "TODO " << comando << endl;
            // TODO: agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            cout << "TODO " << comando << endl;
            // TODO: agencia.listarMortos();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}

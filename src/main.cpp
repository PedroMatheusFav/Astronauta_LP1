#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const int LIMITE_TRIPULACAO = 5;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.

class Astronauta {
private:
    // ATRIBUTOS
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

public:
    // CONSTRUTOR
    Astronauta(string c, string n, int i) {
        cpf = c;
        nome = n;
        idade = i;
        vivo = true;
        disponivel = true;
    }

    // GETTERS
    string getCpf() const { return cpf; }
    string getNome() const { return nome; }
    int getIdade() const { return idade; }
    bool estaVivo() const { return vivo; }
    bool estaDisponivel() const { return disponivel; }

    void embarcar() { disponivel = false; }
    void desembarcar() { disponivel = true; }
    void morrer() { vivo = false; }
    void setVivo(bool v) { vivo = v; }
    void setDisponivel(bool d) { disponivel = d; }
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------
class Voo {
private:
    int codigo;
    string estado; 
    vector<string> cpfsPassageiros;

public:
    Voo(int co) {
        codigo = co;
        estado = "planejado";
    }

    // GETTERS
    int getCodigo() const { return codigo; }
    string getEstado() const { return estado; }
    const vector<string>& getPassageiros() const { return cpfsPassageiros; }

    // AÇÕES DO VOO
    void adicionarPassageiro(string cpf) {
        cpfsPassageiros.push_back(cpf);
    }

    void removerPassageiro(string cpf) {
        for (int i = 0; i < cpfsPassageiros.size(); i++) {
            if (cpfsPassageiros[i] == cpf) {
                cpfsPassageiros.erase(cpfsPassageiros.begin() + i);
                return;
            }
        }
    }

    void lancar() { estado = "em curso"; }
    void explodir() { estado = "finalizado com explosao"; }
    void finalizarComSucesso() { estado = "finalizado com sucesso"; }
    void setEstado(string e) { estado = e; }
};

//-------------------------------------------------------------------------------------------------------------------------------------------------------
class Agencia {
    private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    int buscarAstronauta(string cpf) {
        for (int i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].getCpf() == cpf) {
                return i;
            }
        }
        return -1;
    }

    int buscarVoo(int codigo) {
        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].getCodigo() == codigo) {
                return i;
            }
        }
        return -1;
    }

    public:
    //SEM CONSTRUTOR 
    Agencia() {}

    // GETTERS
    const vector<Astronauta>& getAstronautas() const { return astronautas; }
    const vector<Voo>& getVoos() const { return voos; }

    // AÇÕES DA AGENCIA
    void cadastrarAstronauta(string cpf, string nome, int idade){
        for (int i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].getCpf() == cpf) {
                cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
                return;
            }
        }
        astronautas.push_back(Astronauta(cpf, nome, idade));
        cout << "OK: astronauta " << cpf << " cadastrado" << endl;
        return;
    }

    void cadastrarVoo(int codigo){
        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].getCodigo() == codigo) {
                cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
                return;
            }
        }
        voos.push_back(Voo(codigo));
        cout << "OK: voo " << codigo << " cadastrado" << endl;
        return;
    }

    void adicionarAstronauta(string cpf, int codigo) {
        int idxAstro = buscarAstronauta(cpf);
        int idxVoo = buscarVoo(codigo);

        if (idxAstro == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        if (idxVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[idxVoo].getEstado() != "planejado") {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return; 
        }

        if (astronautas[idxAstro].estaVivo() == false) {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }

        for (int k = 0; k < voos[idxVoo].getPassageiros().size(); k++) {
            if (voos[idxVoo].getPassageiros()[k] == cpf) {
                cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
                return;
            }
        }

        if (voos[idxVoo].getPassageiros().size() >= LIMITE_TRIPULACAO) {
            cout << "ERRO: voo " << codigo << " lotado" << endl;
            return;
        }

        voos[idxVoo].adicionarPassageiro(cpf);
        cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
    }

    void removerAstronauta(string cpf, int codigo) {
        int idxAstro = buscarAstronauta(cpf);
        int idxVoo = buscarVoo(codigo);

        if (idxAstro == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }
        if (idxVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[idxVoo].getEstado() != "planejado") {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return; 
        }

        bool estaNoVoo = false;
        for (int k = 0; k < voos[idxVoo].getPassageiros().size(); k++) {
            if (voos[idxVoo].getPassageiros()[k] == cpf) {
                estaNoVoo = true;
                break;
            }
        }
        if (estaNoVoo == false) {
            cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
            return;
        }

        voos[idxVoo].removerPassageiro(cpf);
        cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;
    }

    void lancarVoo(int codigo) {
        int idxVoo = buscarVoo(codigo);

        if (idxVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[idxVoo].getEstado() != "planejado") {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }
        if (voos[idxVoo].getPassageiros().empty()) {
            cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
            return;
        }

        for (int i = 0; i < voos[idxVoo].getPassageiros().size(); i++) {
            string cpfPassageiro = voos[idxVoo].getPassageiros()[i];
            int idxAstro = buscarAstronauta(cpfPassageiro);

            if (idxAstro != -1) {
                if (astronautas[idxAstro].estaVivo() == false) {
                    cout << "ERRO: astronauta " << cpfPassageiro << " esta morto" << endl;
                    return;
                }
                if (astronautas[idxAstro].estaDisponivel() == false) {
                    cout << "ERRO: astronauta " << cpfPassageiro << " esta indisponivel" << endl;
                    return;
                }
            }
        }

        for (int i = 0; i < voos[idxVoo].getPassageiros().size(); i++) {
            string cpfPassageiro = voos[idxVoo].getPassageiros()[i];
            int idxAstro = buscarAstronauta(cpfPassageiro);
            
            if (idxAstro != -1) {
                astronautas[idxAstro].embarcar();
            }
        }

        voos[idxVoo].lancar();
        cout << "OK: voo " << codigo << " lancado" << endl;
    }

    void explodirVoo(int codigo) {
        int idxVoo = buscarVoo(codigo);

        // 1. Validações iniciais
        if (idxVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[idxVoo].getEstado() != "em curso") {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }

        voos[idxVoo].explodir();
        cout << "OK: voo " << codigo << " explodiu" << endl;

        for (int i = 0; i < voos[idxVoo].getPassageiros().size(); i++) {
            string cpfPassageiro = voos[idxVoo].getPassageiros()[i];
            int idxAstro = buscarAstronauta(cpfPassageiro);
            
            if (idxAstro != -1) {
                astronautas[idxAstro].morrer(); 
            }
        }
    }

    void finalizarVoo(int codigo) {
        int idxVoo = buscarVoo(codigo);

        if (idxVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }
        if (voos[idxVoo].getEstado() != "em curso") {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }

        voos[idxVoo].finalizarComSucesso();
        cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;

        for (int i = 0; i < voos[idxVoo].getPassageiros().size(); i++) {
            string cpfPassageiro = voos[idxVoo].getPassageiros()[i];
            int idxAstro = buscarAstronauta(cpfPassageiro);
            
            if (idxAstro != -1) {
                astronautas[idxAstro].desembarcar();
            }
        }
    }

    void verificarVoo(int codigo) {
        int idxVoo = buscarVoo(codigo);

        if (idxVoo == -1) {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        int ocupados = voos[idxVoo].getPassageiros().size();
        cout << "Voo " << codigo << ": " << ocupados << "/" << LIMITE_TRIPULACAO << " passageiros - ";

        if (ocupados >= LIMITE_TRIPULACAO) {
            cout << "lotado" << endl;
        } else {
            cout << "disponivel" << endl;
        }
    }

    void listarVoos() {
        cout << "LISTA DE VOOS" << endl;
        
        string estados[4] = {"planejado", "em curso", "finalizado com sucesso", "finalizado com explosao"};

        for (int e = 0; e < 4; e++) {
            cout << "== " << estados[e] << " ==" << endl;
            bool temVooNestaCategoria = false;

            for (int i = 0; i < voos.size(); i++) {
                if (voos[i].getEstado() == estados[e]) {
                    temVooNestaCategoria = true;
                    cout << "Voo " << voos[i].getCodigo() << ": ";

                    if (voos[i].getPassageiros().empty()) {
                        cout << "sem astronautas" << endl;
                    } else {
                        for (int j = 0; j < voos[i].getPassageiros().size(); j++) {
                            string cpfPassageiro = voos[i].getPassageiros()[j];
                            int idxAstro = buscarAstronauta(cpfPassageiro);
                            
                            if (idxAstro != -1) {
                                cout << astronautas[idxAstro].getCpf() << " " << astronautas[idxAstro].getNome();
                                
                                if (j < voos[i].getPassageiros().size() - 1) {
                                    cout << ", "; 
                                }
                            }
                        }
                        cout << endl;
                    }
                }
            }

            if (temVooNestaCategoria == false) {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void listarMortos() {
        cout << "ASTRONAUTAS MORTOS" << endl;

        bool temMortos = false;

        for (int i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].estaVivo() == false) {
                temMortos = true;

                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " - voos:";

                for (int j = 0; j < voos.size(); j++) {
                    
                    if (voos[j].getEstado() != "planejado") {
                        
                        for (int k = 0; k < voos[j].getPassageiros().size(); k++) {
                            if (voos[j].getPassageiros()[k] == astronautas[i].getCpf()) {
                                cout << " " << voos[j].getCodigo();
                                break;
                            }
                        }
                    }
                }
                cout << endl;
            }
        }

        if (temMortos == false) {
            cout << "(nenhum)" << endl;
        }
    }

    void listarAstronautas() {
        cout << "LISTA DE ASTRONAUTAS" << endl;

        string grupos[3] = {"disponiveis", "em voo", "mortos"};

        for (int g = 0; g < 3; g++) {
            cout << "== " << grupos[g] << " ==" << endl;
            bool temAstronautaNestaCategoria = false;

            for (int i = 0; i < astronautas.size(); i++) {
                bool desteGrupo = false;
                int codigoVoo = -1;

                if (grupos[g] == "mortos") {
                    if (astronautas[i].estaVivo() == false) {
                        desteGrupo = true;
                    }
                } else if (astronautas[i].estaVivo() == true) {
                    if (grupos[g] == "em voo") {
                        if (astronautas[i].estaDisponivel() == false) {
                            for (int j = 0; j < voos.size(); j++) {
                                if (voos[j].getEstado() == "em curso") {
                                    for (int k = 0; k < voos[j].getPassageiros().size(); k++) {
                                        if (voos[j].getPassageiros()[k] == astronautas[i].getCpf()) {
                                            codigoVoo = voos[j].getCodigo();
                                            break;
                                        }
                                    }
                                }
                                if (codigoVoo != -1) break;
                            }
                            if (codigoVoo != -1) {
                                desteGrupo = true;
                            }
                        }
                    } else {
                        if (astronautas[i].estaDisponivel() == true) {
                            desteGrupo = true;
                        }
                    }
                }

                if (desteGrupo == true) {
                    temAstronautaNestaCategoria = true;
                    cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " (" << astronautas[i].getIdade() << " anos)";

                    if (codigoVoo != -1) {
                        cout << " - voo " << codigoVoo;
                    }
                    cout << endl;
                }
            }

            if (temAstronautaNestaCategoria == false) {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void salvarDados(string arquivo) {
        ofstream saida(arquivo.c_str());

        if (!saida) {
            cout << "ERRO: nao foi possivel salvar em " << arquivo << endl;
            return;
        }

        saida << "ASTRONAUTAS " << astronautas.size() << endl;
        for (int i = 0; i < astronautas.size(); i++) {
            saida << astronautas[i].getCpf() << " " << astronautas[i].getIdade() << " "
                  << astronautas[i].estaVivo() << " " << astronautas[i].estaDisponivel() << " "
                  << astronautas[i].getNome() << endl;
        }

        saida << "VOOS " << voos.size() << endl;
        for (int i = 0; i < voos.size(); i++) {
            saida << voos[i].getCodigo() << " " << voos[i].getPassageiros().size() << " "
                  << voos[i].getEstado() << endl;
            for (int j = 0; j < voos[i].getPassageiros().size(); j++) {
                saida << voos[i].getPassageiros()[j] << endl;
            }
        }

        saida.close();
        cout << "OK: dados salvos em " << arquivo << endl;
    }

    void carregarDados(string arquivo) {
        ifstream entrada(arquivo.c_str());

        if (!entrada) {
            cout << "ERRO: nao foi possivel carregar de " << arquivo << endl;
            return;
        }

        vector<Astronauta> novosAstronautas;
        vector<Voo> novosVoos;

        string secao;
        int quantidade;

        entrada >> secao >> quantidade;
        for (int i = 0; i < quantidade; i++) {
            string cpf, nome;
            int idade, vivo, disponivel;
            entrada >> cpf >> idade >> vivo >> disponivel;
            getline(entrada >> ws, nome);
            Astronauta a(cpf, nome, idade);
            a.setVivo(vivo == 1);
            a.setDisponivel(disponivel == 1);
            novosAstronautas.push_back(a);
        }

        entrada >> secao >> quantidade;
        for (int i = 0; i < quantidade; i++) {
            int codigo, numPassageiros;
            string estado;
            entrada >> codigo >> numPassageiros;
            getline(entrada >> ws, estado);
            Voo v(codigo);
            v.setEstado(estado);
            for (int j = 0; j < numPassageiros; j++) {
                string cpf;
                entrada >> cpf;
                v.adicionarPassageiro(cpf);
            }
            novosVoos.push_back(v);
        }

        entrada.close();

        astronautas.swap(novosAstronautas);
        voos.swap(novosVoos);

        cout << "OK: dados carregados de " << arquivo << endl;
    }

    void historico(string cpf) {
        int idxAstro = buscarAstronauta(cpf);

        if (idxAstro == -1) {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        cout << "HISTORICO DE " << astronautas[idxAstro].getCpf() << " " << astronautas[idxAstro].getNome() << endl;

        bool temVoo = false;

        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() != "planejado") {
                for (int j = 0; j < voos[i].getPassageiros().size(); j++) {
                    if (voos[i].getPassageiros()[j] == cpf) {
                        temVoo = true;
                        cout << "voo " << voos[i].getCodigo() << ": " << voos[i].getEstado() << endl;
                        break;
                    }
                }
            }
        }

        if (temVoo == false) {
            cout << "(nenhum voo)" << endl;
        }
    }

    void relatorio() {
        cout << "RELATORIO" << endl;

        int planejados = 0;
        int emCurso = 0;
        int sucesso = 0;
        int explosao = 0;

        for (int i = 0; i < voos.size(); i++) {
            if (voos[i].getEstado() == "planejado") {
                planejados++;
            } else if (voos[i].getEstado() == "em curso") {
                emCurso++;
            } else if (voos[i].getEstado() == "finalizado com sucesso") {
                sucesso++;
            } else if (voos[i].getEstado() == "finalizado com explosao") {
                explosao++;
            }
        }

        int vivos = 0;
        int mortos = 0;
        for (int i = 0; i < astronautas.size(); i++) {
            if (astronautas[i].estaVivo() == true) {
                vivos++;
            } else {
                mortos++;
            }
        }

        cout << "voos planejados: " << planejados << endl;
        cout << "voos em curso: " << emCurso << endl;
        cout << "voos finalizados com sucesso: " << sucesso << endl;
        cout << "voos finalizados com explosao: " << explosao << endl;
        cout << "astronautas cadastrados: " << astronautas.size() << endl;
        cout << "astronautas vivos: " << vivos << endl;
        cout << "astronautas mortos: " << mortos << endl;

        int idxExperiente = -1;
        int melhorExperiencia = 0;
        for (int i = 0; i < astronautas.size(); i++) {
            int experiencia = 0;
            for (int j = 0; j < voos.size(); j++) {
                if (voos[j].getEstado() != "planejado") {
                    for (int k = 0; k < voos[j].getPassageiros().size(); k++) {
                        if (voos[j].getPassageiros()[k] == astronautas[i].getCpf()) {
                            experiencia++;
                            break;
                        }
                    }
                }
            }
            if (experiencia > melhorExperiencia) {
                melhorExperiencia = experiencia;
                idxExperiente = i;
            }
        }

        if (idxExperiente == -1) {
            cout << "astronauta mais experiente: (nenhum)" << endl;
        } else {
            cout << "astronauta mais experiente: " << astronautas[idxExperiente].getCpf()
                 << " " << astronautas[idxExperiente].getNome()
                 << " (voos lancados: " << melhorExperiencia << ")" << endl;
        }

        int finalizados = sucesso + explosao;
        if (finalizados == 0) {
            cout << "taxa de sucesso: (nenhum voo finalizado)" << endl;
        } else {
            cout << "taxa de sucesso: " << sucesso * 100 / finalizados << "%" << endl;
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
            agencia.cadastrarAstronauta(cpf, nome, idade);
            // TODO: agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
            // TODO: agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
            // TODO: agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
            // TODO: agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
            // TODO: agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
            // TODO: agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
            // TODO: agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
            // TODO: agencia.listarVoos();
        } else if (comando == "VERIFICAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.verificarVoo(codigo);
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
            // TODO: agencia.listarMortos();
        } else if (comando == "SALVAR") {
            string arquivo;
            cin >> arquivo;
            agencia.salvarDados(arquivo);
        } else if (comando == "CARREGAR") {
            string arquivo;
            cin >> arquivo;
            agencia.carregarDados(arquivo);
        } else if (comando == "LISTAR_ASTRONAUTAS") {
            agencia.listarAstronautas();
        } else if (comando == "HISTORICO") {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        } else if (comando == "RELATORIO") {
            agencia.relatorio();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}

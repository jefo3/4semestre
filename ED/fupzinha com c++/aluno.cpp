#include <iostream>

using namespace std;

struct aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

aluno addAluno(string nome, int matricula, string disciplina, double nota){
    aluno a;
    a.nome = nome;
    a.matricula = matricula;
    a.disciplina = disciplina;
    a.nota = nota;

    return a;
}

void situacao(aluno x){
    cout << x.nome << " "<< ((x.nota >= 7)?"aprovado(a) ":"reprovado(a) ")<< "em "<< x.disciplina << endl;
}

int main(){

    string nome;
    int matricula;
    string disciplina;
    double nota;

    getline(cin, nome);
    cin >> matricula; 
    std::cin.ignore(); 
    getline(cin, disciplina); 
    cin >> nota;
    std::cin.ignore();

    situacao(addAluno(nome,matricula,disciplina,nota));

    return 0;
}
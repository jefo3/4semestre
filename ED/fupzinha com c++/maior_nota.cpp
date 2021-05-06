#include <iostream>
#include <iomanip>

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

void situacao(aluno x, aluno y){
    if(x.nota == y.nota){
        cout << x.nome << " e "<< y.nome << " , "<< std::fixed << setprecision(1) << x.nota << endl;
    }else if(x.nota > y.nota){
        cout << x.nome << " , "<< std::fixed << setprecision(1) << x.nota << endl;
    }else{
        cout << y.nome << " , "<< std::fixed << setprecision(1) << y.nota << endl;
    }
}

int main(){

    aluno alunos[2];

    string nome;
    int matricula;
    string disciplina;
    double nota;

    for(int i = 0; i < 2; i++){
        getline(cin, nome);
        cin >> matricula; 
        std::cin.ignore(); 
        getline(cin, disciplina); 
        cin >> nota;
        std::cin.ignore();

        alunos[i] = addAluno(nome,matricula,disciplina,nota);
    }
    
    situacao(alunos[0], alunos[1]);
    

    return 0;
}
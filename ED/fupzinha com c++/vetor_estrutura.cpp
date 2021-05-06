#include <iostream>
#include <iomanip>

using namespace std;

struct aluno{
    string nome;
    int matricula;
    double nota;
};

int main(){

    int m, matricula, i;
    cin >> m;

    aluno alunos[m];

    for(int i = 0; i < m; i++){ 
        cin >> alunos[i].matricula;
        std::cin.ignore(); 
        getline(cin, alunos[i].nome);
        cin >> alunos[i].nota;
        std::cin.ignore();
    }
    
    cin >> matricula;

    for(i = 0; i < m; i++){
        if(alunos[i].matricula == matricula){
            cout << alunos[i].nome <<endl;
            cout << std::fixed << setprecision(1) << alunos[i].nota << endl;
            break;
        }
    }

    if(m == i){
        cout << "NAO ENCONTRADA" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "src/pessoa.hpp"
#include "src/aluno.hpp"
#include "src/sort.hpp"
#include "src/comparable.hpp"

#define SIZE 5

using namespace std;

void exercicio1() 
{
	// Resposta:
	// Na implementação original o código de Pessoa era chamado em p2.
	// Pois o compilador gera um código com a chamada de p2 como a classe Pessoa pelo seu tipo definido.
    // Para realizar a mudança e chamar o método da classe Aluno você pode optar pela declaração de p2 
	// como Aluno, ou declarar o método toString em Pessoa como virtual, desta forma o compilador irá manter o método
	// do tipo do objeto e não da declaração da variável.
    Pessoa* p1 = new Pessoa("Ana Paula", Pessoa::FEMININO, time(0));
    Pessoa* p2 = new Aluno("Jose Silva", Pessoa::FEMININO, time(0), "01001010", Aluno::GRADUACAO);
    cout << p1->toString();
    cout << p2->toString();
}

void exercicio2()
{
	// Resposta:
	// Para realizar a modificação trocamos o tipo passado como parametro,
	// int para Pessoa*.
	vector<Pessoa*> vetor;
   	int i=0;
	
	for(i = 0; i < SIZE; i++){
      	vetor.push_back(new Pessoa());
  	}

	vector<Pessoa*>::iterator elemento = vetor.begin(); 
	i=0;
	while( elemento != vetor.end()) {
    	cout << " elemento " << i++ << " = " << (*elemento)->toString() << endl;
    	elemento++;
	}
}

void exercicio3()
{
	// Resposta:
	// Para resolver o exercício foi adicionado o tipo virtual ao método toString em Pessoa.
	// Em Java o método é vínculado de maneira dinâmica, para simular o comportamento de um método não virtual em C++
	// é necessário criar uma cópia do objeto Aluno com a classe Pessoa, assim será invocado o método toString da superclasse.
	// Também é possível optar por não sobreescrever o método toString na sub-classe, criando um segundo método
	// para impressão no novo formato, como: String toStringAluno().
	vector<Pessoa*> vetor;
   	int i=0;
 	
	for(i = 0; i < SIZE; i++){
		if (i < SIZE/2) {
      		vetor.push_back(new Pessoa());
		} else {
			vetor.push_back(new Aluno());
		}
  	}

	vector<Pessoa*>::iterator elemento = vetor.begin(); 
	i=0;
	while( elemento != vetor.end()) {
    	cout << " elemento " << i++ << " = " << (*elemento)->toString() << endl;
    	elemento++;
	}
}

void exercicio4()
{
	vector<Pessoa> pessoas;
	
	Pessoa p1("Jose Paula", Pessoa::FEMININO, time(0));
	Pessoa p2("Ana Silva", Pessoa::FEMININO, time(0));
	Pessoa p3("Eduardo Silveira", Pessoa::FEMININO, time(0));
	Pessoa p4("Ana Clara Schneider", Pessoa::FEMININO, time(0));
	Pessoa p5("Pedro Schneider", Pessoa::FEMININO, time(0));

    pessoas.push_back(p1);
	pessoas.push_back(p2);
	pessoas.push_back(p3);
	pessoas.push_back(p4);
	pessoas.push_back(p5);
  	
	sort::quickSort(pessoas);

	for(const auto& pessoa : pessoas)
	{
		cout << pessoa.toString() << endl;
	}
}

int main()
{
	exercicio4();
	return 0;
}
#include "pessoa.hpp"

#include <iostream>

using namespace std;

// Construtor padrão (inicializa atributos com valores default)
// Perceba que ele usa a técnica de delegating constructor (c++11)
// para chamar o construtor alternativo, passando os valores default para os atributos 
Pessoa::Pessoa() : Pessoa("Indefinido", INDEFINIDO, time(0))
{			
	cout << "Construtor Pessoa() chamado"<< endl;
}	

// Construtor alternativo
Pessoa::Pessoa(std::string nome, Pessoa::Sexo sexo, time_t dtnascimento)
   : nome(nome),                 // ":" introduz lista de inicializadores de atributos 			   
	 sexo(sexo),                 // esta lista eh opcional (e a inicializacao poderia ser
     dtnascimento(dtnascimento)  // feita dentro das chaves
			                     // mais detalhes em:
							     // http://en.cppreference.com/w/cpp/language/initializer_list
{			
	cout << "Construtor alternativo de Pessoa chamado" << endl;
}

/* 
// Uma alternativa para os dois acima seria criar um construtor com valores default:
Pessoa(std::string nome = nome, sexo=INDEFINIDO, dtnascimento = time(0)){			
	// o problema é fazer isso funcionar para funções!
}

// outra seria especificar um método privado para a inicialização
// o qual seria chamado por todos os construtores!

*/

// construtor de cópia
Pessoa::Pessoa(const Pessoa& outra) 
   : nome(outra.nome), 
	 dtnascimento(outra.dtnascimento),
	 sexo(outra.sexo)
{
	cout << "Construtor de cópia chamado" << endl;
	// este eh soh um exemplo e pode nao funcionar como esperado
	// substitua pelo seu codigo
}						
		
// Operador de atribuição sobrecarregado para receber uma pessoa
Pessoa& Pessoa::operator=(const Pessoa& outra){
	// este eh soh um exemplo e pode nao funcionar como esperado
	// substitua pelo seu codigo
	this->nome = outra.nome;
	this->dtnascimento = outra.dtnascimento;
	this->sexo = outra.sexo;
	cout << "Operator= chamado" << endl;			
	return *this;
}

time_t Pessoa::get_dtnascimento() const{
	return this->dtnascimento;
}

void Pessoa::set_dtnascimento(time_t dtnascimento){
	this->dtnascimento = dtnascimento;
}

std::string Pessoa::get_nome() const{
	return this->nome;
}

void Pessoa::set_nome(std::string nome){
	this->nome = nome;
}

Pessoa::Sexo Pessoa::get_sexo() const{
	return this->sexo;
}

void Pessoa::set_sexo(Pessoa::Sexo sexo){
	this->sexo = sexo;
}

std::string Pessoa::toString() const {
			time_t dtnascimento = this->get_dtnascimento();			
			std::string tmp = "Pessoa{\n\tNome: ";
			
			std::string sexos[] = { "Indefinido", "Masculino", "Feminino" };
			
			tmp.append(this->get_nome());
			tmp.append("\n\tSexo: ");
			tmp.append(sexos[this->get_sexo()]);
			tmp.append("\n\tNascimento: ");
			tmp.append(ctime(&dtnascimento));
			tmp.append("}\n");
			
			return tmp;
		}

// Sobrecarga do operador << usado em cout
// Permite imprimir strings representativas para a enumeração Sexo
// Do contrário, imprimiria um número inteiro correspondente a cada valor de sexo 
std::ostream& operator<<(std::ostream& os, Pessoa::Sexo s)
{
    switch(s) {
         case Pessoa::INDEFINIDO : os << "INDEFINIDO"; break;
         case Pessoa::MASCULINO  : os << "MASCULINO"; break;
         case Pessoa::FEMININO   : os << "FEMININO"; break;
         default                 : os.setstate(std::ios_base::failbit);
    }
    return os;
}

int Pessoa::compares_to(const Pessoa& pessoa) const
{
	return this->nome.compare(pessoa.nome);
}
#include "aluno.hpp"

#include <iostream>

using namespace std;

// Construtor padrão
Aluno::Aluno() : codigo("INDEFINIDO"),  nivel(Aluno::INDEFINIDO){			  
	cout << "Construtor Aluno() chamado"<< endl;
}	

// construtor de cópia
Aluno::Aluno(const Aluno& outro){			
	set_nome(outro.get_nome());
	set_dtnascimento(outro.get_dtnascimento());
	set_sexo(outro.get_sexo());
	set_codigo(outro.get_codigo());
	set_nivel(outro.get_nivel());
	cout << "Construtor de cópia de Aluno chamado" << endl;
}		

// Construtor alternativo
Aluno::Aluno(std::string nome, Sexo sexo, time_t dtnascimento, std::string codigo, Nivel nivel){	
	this->set_nome(nome);
	this->set_sexo(sexo);
	this->set_dtnascimento(dtnascimento);
	this->set_codigo(codigo);
	this->set_nivel(nivel);
	cout << "Construtor Alternativo Aluno() chamado"<< endl;
}

// Operador de atribuição sobrecarregado para receber uma pessoa
Aluno& Aluno::operator=(const Aluno& outro){
	set_nome(outro.get_nome());
	set_dtnascimento(outro.get_dtnascimento());
	set_sexo(outro.get_sexo());
	this->codigo = outro.get_codigo();
	this->nivel = outro.get_nivel();
	
	cout << "Operator=(Aluno) chamado" << endl;
	
	return *this;
}

const std::string Aluno::get_codigo() const{
	return this->codigo;
}

void Aluno::set_codigo(std::string codigo){
	this->codigo = codigo;
}

const Aluno::Nivel Aluno::get_nivel() const{
	return this->nivel;
}

void Aluno::set_nivel(Nivel nivel){
	this->nivel = nivel;
}

std::string Aluno::toString() const {
	time_t dtnascimento = this->get_dtnascimento();			
	std::string tmp = "Aluno{\n\tNome: ";
	
	std::string sexos[] = { "Indefinido", "Masculino", "Feminino" };
	std::string niveis[] = { "Indefinido", "Graduacao", "Especializacao", "Mestrado", "Doutorado" };
	
	tmp.append(this->get_nome());
	tmp.append("\n\tSexo: ");
	tmp.append(sexos[this->get_sexo()]);
	tmp.append("\n\tNascimento: ");
	tmp.append(ctime(&dtnascimento));
	tmp.append("\n\tCodigo: ");
	tmp.append(this->get_codigo());
	tmp.append("\n\tNivel: ");
	tmp.append(niveis[this->get_nivel()]);
	tmp.append("\n}\n");
	
	return tmp;
}
		
std::ostream& operator<<(std::ostream& os, Aluno::Nivel n){
    switch(n) {
         case Aluno::INDEFINIDO     : os << "INDEFINIDO"; break;
         case Aluno::GRADUACAO      : os << "GRADUACAO"; break;
         case Aluno::ESPECIALIZACAO : os << "ESPECIALIZACAO"; break;
		 case Aluno::MESTRADO       : os << "MESTRADO"; break;
		 case Aluno::DOUTORADO      : os << "DOUTORADO"; break;
         default                    : os.setstate(std::ios_base::failbit);
    }
    return os;
}


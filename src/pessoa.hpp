#ifndef PESSOA
#define PESSOA

#include <string>
#include "comparable.hpp"

class Pessoa: public Comparable<Pessoa>
{
	public:
		enum Sexo { INDEFINIDO, MASCULINO, FEMININO };
		
		Pessoa(); // Construtor padrão		
		Pessoa(std::string, Sexo, time_t); // Construtor alternativo				
		Pessoa(const Pessoa& outra); // // construtor de cópia		
		
		Pessoa& operator=(const Pessoa& outra);
		
		time_t get_dtnascimento() const;		
		void set_dtnascimento(time_t dtnascimento);

		std::string get_nome() const;		
		void set_nome(std::string nome);
		
		Sexo get_sexo() const;
		void set_sexo(Sexo sexo);
		
		// Virtual permite a vinculação dinâmica do método
		virtual std::string toString() const;		

		virtual int compares_to(const Pessoa& t) const;

	private:
		time_t dtnascimento;
		std::string nome;
		Sexo sexo;	
};

std::ostream& operator<<(std::ostream&, const Pessoa&);

#endif
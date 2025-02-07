/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 18:01:09 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
/*
dont forget to ortodox canonical class
*/


class ClapTrap{
	private:
		std::string	_name;
		int			_hit;	// health
		int			_energy;
		int			_attack;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap &other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string&	getName(void){return _name;}
		int&			getHit(void){return _hit;}
		int&			getEnergy(void){return _energy;}
		int&			getAttack(void){return _attack;}
		
};

ClapTrap::ClapTrap()
	: _name("Default"), _hit(10), _energy(10), _attack(0)
	{std::cout << "Default Constructor called" << std::endl;};

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hit(other._hit),_energy(other._energy), _attack(other._attack)
	{std::cout << "copy constructor worked for " << _name << std::endl;}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(0), _attack(10){std::cout << "Constructor called" << std::endl;};
ClapTrap::~ClapTrap(){std::cout << "Destructor called" << std::endl;}


ClapTrap& ClapTrap::operator=(const ClapTrap &other){
			if (this != &other)
			{
				_name = other._name;
				_hit = other._hit;
				_energy = other._energy;
				_attack = other._attack;
			}
			std::cout << "copy operator assgn worked\n";
			return *this;
		}



void ClapTrap::attack(const std::string& target){

	if (_hit <= 0 || _energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " has either energy or health"  << std::endl;
		return;
	}
	_energy -= 1;
	std::cout
	<< "ClapTrap" << _name << " attacks " << target
	<< ", causing " << _attack << " points of damage!" <<
	std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_energy == 0)
	{
		std::cout
		<< "ClapTrap " << _name << "has no energy to attack"
		<< std::endl;
		return;
	}
	_hit -= amount;
	if (_hit <= 0 || _energy <= 0)
	{
		std::cout
		<< "ClapTrap" << _name << " died" <<
		std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energy <= 0)
	{
		std::cout
		<< "ClapTrap" << _name << " has no energy to repair" 
		<< std::endl;
		return;
	}
	_energy -= 1;
	_hit += amount;
	std::cout
	<< "ClapTrap" << _name << "repaired " << amount
	<< " amount, new health is" << _hit <<
	std::endl;
}


int main(){
	ClapTrap baz("taha");
	ClapTrap foo(baz); // copy constructor should call

}
 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:35:46 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 15:39:58 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap()
	: _name("Default"), _hit(10), _energy(10), _attack(0)
	{std::cout << "ClapTrap Constructor called" << std::endl;};
	
// Constructor
ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(0){std::cout << "ClapTrap Constructor called" << std::endl;};
ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack): _name(name), _hit(hit), _energy(energy), _attack(attack){std::cout << "ClapTrap Constructor called" << std::endl;};

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack)
	{std::cout << "ClapTrap Copy Constructor worked" <<  std::endl;}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
		_energy = other._energy;
		_attack = other._attack;
	}
	std::cout << "ClapTrap Copy assignment operator called\n";
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(){std::cout << "ClapTrap Destructor called" << std::endl;}

// Member Functions
void ClapTrap::attack(const std::string& target){

	if (_hit <= 0 || _energy <= 0)
	{
		std::cout << "ClapTrap " << _name << " has either energy or health"  << std::endl;
		return;
	}
	_energy -= 1;
	std::cout
	<< "ClapTrap " << _name << " attacks " << target
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
	std::cout
	<< "ClapTrap " << _name << " took damage, causing " << amount << " points of damage!" <<
	std::endl;
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
	<< "ClapTrap " << _name << " repaired " << amount << " amount of health!"
	<< std::endl;
}

// Getter Functions
std::string	ClapTrap::getName(void) const{return _name;}
int			ClapTrap::getHit(void) const{return _hit;}
int			ClapTrap::getEnergy(void) const{return _energy;}
int			ClapTrap::getAttack(void) const{return _attack;}

// Setter Functions
void		ClapTrap::setName(std::string name){_name = name;}
void		ClapTrap::setHit(int hit){_hit = hit;}
void		ClapTrap::setEnergy(int energy){_energy = energy;}
void		ClapTrap::setAttack(int attack){_attack = attack;}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:35:46 by taha              #+#    #+#             */
/*   Updated: 2025/02/10 12:30:54 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap()
	: _name("Default"), _hit(10), _energy(10), _attack(0)
	{std::cout << "Default Constructor called" << std::endl;};
	
// Constructors
ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(0){std::cout << "Constructor called" << std::endl;};

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack)
	{std::cout << "copy constructor worked" <<  std::endl;}

// Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if (this != &other)
	{
		_name = other._name;
		_hit = other._hit;
		_energy = other._energy;
		_attack = other._attack;
	}
	std::cout << "copy assignment operator worked\n";
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(){std::cout << "Destructor called" << std::endl;}

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
std::string&	ClapTrap::getName(void){return _name;}
int			ClapTrap::getHit(void) const {return _hit;}
int			ClapTrap::getEnergy(void) const {return _energy;}
int			ClapTrap::getAttack(void) const {return _attack;}
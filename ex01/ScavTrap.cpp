/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:02:47 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 16:09:18 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
	: ClapTrap("Default", 100, 50, 20)
	{std::cout << "ScavTrap Constructor called" << std::endl;}
ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20)
	{std::cout << "ScavTrap Constructor called" << std::endl;}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
	{std::cout << "ScavTrap Copy Constructor worked" <<  std::endl;}

ScavTrap::~ScavTrap(){std::cout << "ScavTrap Destructor called" << std::endl;}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target){
	if (getEnergy() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " has no energy to attack"  << std::endl;
		return;
	}
	ClapTrap::attack(target);
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount){
	if (getEnergy() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " has no energy to repair"  << std::endl;
		return;
	}
	ClapTrap::beRepaired(amount);
}
void ScavTrap::takeDamage(unsigned int amount){
	if (getEnergy() <= 0)
	{
		std::cout << "ScavTrap " << getName() << " has no energy to take damage"  << std::endl;
		return;
	}
	ClapTrap::takeDamage(amount);
}
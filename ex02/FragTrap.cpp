/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:52:07 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 18:59:05 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
:ClapTrap("Default", 100, 100, 30)
{std::cout << "FragTrap constructor called" << std::endl;}

FragTrap::FragTrap(std::string name)
:ClapTrap(name, 100, 100, 30)
{std::cout << "FragTrap constructor called" << std::endl;}

FragTrap::FragTrap(const FragTrap &other)
:ClapTrap(other)
{std::cout << "FragTrap Copy Constructor called" << std::endl;}

FragTrap::~FragTrap(){std::cout << "FragTrap Destructor called" << std::endl;}

FragTrap& FragTrap::operator=(const FragTrap &other){
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout
	<< "FragTrap " << _name << " requests a positive high five!"
	<< std::endl;
}
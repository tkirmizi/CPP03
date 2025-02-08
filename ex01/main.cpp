/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 16:08:56 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void objShow(ClapTrap &obj)
{
	std::cout
	<< std::setw(10) << std::right << obj.getName() << "|"
	<< std::setw(10) << std::right << obj.getHit() << "|"
	<< std::setw(10) << std::right << obj.getEnergy() << "|"
	<< std::setw(10) << std::right << obj.getAttack() << "|"
	<< std::endl;
}

int main(){
	
	ScavTrap objA ("Warrior");
	ScavTrap objB = objA;
	ScavTrap objC;
	objC = objB;
	std::cout << "      Name|Hit Points|Energy    |Attack    |" << std::endl;
	objShow(objA);
	objShow(objB);
	objShow(objC);
	std::cout << "------------------------------------------" << std::endl;
	objA.attack("Enemy");
	objShow(objA);
	std::cout << "------------------------------------------" << std::endl;
	objB.takeDamage(15);
	objShow(objB);
	std::cout << "------------------------------------------" << std::endl;
	objC.beRepaired(100);
	objShow(objC);
	std::cout << "------------------------------------------" << std::endl;
	objC.guardGate();
}
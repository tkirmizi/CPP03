/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 12:36:30 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void objShow(ClapTrap &obj);

int main(){
	ClapTrap obj1 ("taha");
	ClapTrap obj2 = obj1;
	ClapTrap obj3;
	obj3 = obj2;
	std::cout
	<< std::setw(10) << std::right << "Name" << "|"
	<< std::setw(10) << std::right << "Health" << "|"
	<< std::setw(10) << std::right << "Energy" << "|"
	<< std::setw(10) << std::right << "Attack" << "|"
	<< std::endl;
	objShow(obj1);
	objShow(obj2);
	objShow(obj3);
	std::cout << std::endl;
	obj1.attack("enemy");
	objShow(obj1);
	std::cout << std::endl;
	obj2.takeDamage(5);
	objShow(obj2);
	std::cout << std::endl;
	obj3.beRepaired(5);
	objShow(obj3);
}

static void objShow(ClapTrap &obj)
{
	std::cout
	<< std::setw(10) << std::right << obj.getName() << "|"
	<< std::setw(10) << std::right << obj.getHit() << "|"
	<< std::setw(10) << std::right << obj.getEnergy() << "|"
	<< std::setw(10) << std::right << obj.getAttack() << "|"
	<< std::endl;
}
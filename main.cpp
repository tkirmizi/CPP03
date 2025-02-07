/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 17:25:51 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
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
		std::string& getName(void){return _name;}
		ClapTrap(const ClapTrap& other): _name(other._name), _hit(other._hit),
			_energy(other._energy), _attack(other._attack) {std::cout << "copy constructor worked for " 
			<< _name << std::endl;};
		ClapTrap& operator=(const ClapTrap &other){
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
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
};

ClapTrap::ClapTrap(): _hit(10), _energy(10), _attack(10){};
ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(10){};
void ClapTrap::attack(const std::string& target){
	if (_hit < 0)
	{
		std::cout << "ClapTrap " << _name << " has no health"  << std::endl;
		// and what to do exit or continue ?
	}
	std::cout
	<< "ClapTrap" << _name << " attacks " << target
	<< ", causing " << _attack << " points of damage!"
	<< std::endl;
}


int main(){
	ClapTrap taha;
	taha.attack("ali");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:05:48 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 12:35:00 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
dont forget to ortodox canonical class
*/




ClapTrap::ClapTrap()
	: _name("Default"), _hit(10), _energy(10), _attack(0)
	{std::cout << "Default Constructor called" << std::endl;};

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name), _hit(other._hit), _energy(other._energy), _attack(other._attack)
	{std::cout << "copy constructor worked" <<  std::endl;}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _energy(10), _attack(0){std::cout << "Constructor called" << std::endl;};
ClapTrap::~ClapTrap(){std::cout << "Destructor called" << std::endl;}


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

void objShow(ClapTrap &obj){
	std::cout
	<< std::setw(10) << std::right << obj.getName() << "|"
	<< std::setw(10) << std::right << obj.getHit() << "|"
	<< std::setw(10) << std::right << obj.getEnergy() << "|"
	<< std::setw(10) << std::right << obj.getAttack() << "|"
	<< std::endl;
}

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


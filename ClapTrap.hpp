/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:34:41 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 12:35:04 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>

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


#endif
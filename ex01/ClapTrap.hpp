/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:34:41 by taha              #+#    #+#             */
/*   Updated: 2025/02/08 18:41:44 by taha             ###   ########.fr       */
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
		int			_hit;
		int			_energy;
		int			_attack;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hit, int energy, int attack);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap &other);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string		getName(void) const;
		int				getHit(void) const;
		int				getEnergy(void) const;
		int				getAttack(void) const;
		void		setName(std::string name);
		void		setHit(int hit);
		void		setEnergy(int energy);
		void		setAttack(int attack);
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:21:57 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 23:37:52 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
   public:
        ScavTrap(std::string name);
        ~ScavTrap();
        //ScavTrap(const ScavTrap &src);
        //ScavTrap &operator=(const ScavTrap &src);

        void attack(std::string const &target);
        void guardGate();
};

#endif
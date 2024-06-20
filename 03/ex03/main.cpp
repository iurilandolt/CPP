/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:44:29 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/21 00:02:59 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap diamond("Mbumbe");

    diamond.whoAmI();
    diamond.printStats();
    diamond.attack("target");
    
    diamond.takeDamage(15);
    diamond.beRepaired(5);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.printStats();
    return (0);
}
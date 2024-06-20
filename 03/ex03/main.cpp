/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:44:29 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/20 16:53:49 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap diamond("Diamond");

    diamond.attack("target");
    diamond.takeDamage(10);
    diamond.beRepaired(5);
    diamond.guardGate();
    diamond.highFivesGuys();
    diamond.whoAmI();
    return (0);
}
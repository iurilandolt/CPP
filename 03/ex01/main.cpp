/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:02:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/21 10:36:24 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

    ScavTrap scav_01("Charlie");
  
    
    scav_01.printStats();
    scav_01.attack("A Garbage Bin");
    scav_01.takeDamage(10);
    scav_01.beRepaired(5);
    scav_01.guardGate();    
    scav_01.printStats();
    return (0);
}
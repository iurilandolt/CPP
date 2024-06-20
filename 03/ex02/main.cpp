/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:02:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/20 22:57:23 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap frag_01("Jonas");
    
    frag_01.printStats();
    frag_01.attack("a Bullymong");
    frag_01.takeDamage(50);
    frag_01.beRepaired(5);
    frag_01.highFivesGuys();
    frag_01.printStats();
    frag_01.takeDamage(100);
    return (0);
}
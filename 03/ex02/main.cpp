/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:02:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 23:41:04 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap frag_01("Jonas");
    
    frag_01.attack("some random dude");
    frag_01.takeDamage(10);
    frag_01.beRepaired(5);
    frag_01.highFivesGuys();
    return (0);
}
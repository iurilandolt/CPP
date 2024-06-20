/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:02:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/20 22:07:18 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("X0B42");
    clap.printStats();
    clap.attack("a bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.printStats();

    for (int i = 0; i < 10; i++)
        clap.attack("a bandit");
    clap.takeDamage(20);
    clap.printStats();
    return (0);
}
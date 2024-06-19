/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:02:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 23:19:35 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("X0B42");
    claptrap.attack("a bandit");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    return (0);
}
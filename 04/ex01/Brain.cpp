/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:48:43 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 16:50:44 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain created" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i].clear();
    }
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(Brain const & src) {
    std::cout << "Brain copied" << std::endl;
    *this = src;
}

Brain & Brain::operator=(Brain const & rhs) {
    std::cout << "Brain assigned" << std::endl;
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    return (*this);
}

void Brain::setIdea(int i, std::string idea) {
    this->ideas[i] = idea;
}

std::string Brain::getIdea(int i) const {
    return (this->ideas[i]);
}
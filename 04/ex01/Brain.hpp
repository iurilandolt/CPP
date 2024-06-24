/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:47:15 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 16:50:42 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(Brain const & src);
        Brain & operator=(Brain const & rhs);
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
};

#endif
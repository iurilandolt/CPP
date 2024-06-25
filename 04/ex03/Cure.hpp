/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:35:05 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 21:35:24 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        ~Cure();
        Cure(Cure const &src);
        Cure &operator=(Cure const &src);

        AMateria *clone() const;
        //void use(ICharacter &target);
};

#endif
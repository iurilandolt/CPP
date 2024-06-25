/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:23:35 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/25 21:32:27 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const &type);
        virtual ~AMateria();
        AMateria(AMateria const &src);
        AMateria &operator=(AMateria const &src);

        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        //virtual void use(ICharacter &target);
};

#endif
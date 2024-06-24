/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:24:03 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/24 14:26:29 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const std::string type);
        WrongCat(const WrongCat &src);
        WrongCat &operator=(const WrongCat &src);
        void makeSound() const;
};

#endif
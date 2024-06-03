/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:39:14 by mortins-          #+#    #+#             */
/*   Updated: 2024/01/04 17:36:52 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <cstdlib>

std::string getInput(const std::string prompt);

bool	isAllWhitespaces(const std::string str);
bool	isValidPhoneNumber(const std::string &number);

#endif
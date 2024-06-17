/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seditor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:06:04 by iurilandolt       #+#    #+#             */
/*   Updated: 2024/06/18 00:01:08 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDITOR_HPP
# define SEDITOR_HPP

#include <iostream>
#include <fstream>

class Seditor {
public:
    Seditor(std::string &filename, const std::string &target, const std::string &value);
    ~Seditor();
private:
    int	    isEmpty(std::ifstream &filename);
    int	    targetFound(std::string &content, const std::string &target);
    int     checkStream(std::ifstream &infile, const std::string &target);
    int	    search(std::ifstream &filename, const std::string &target);
    void    swapString(std::string &content, const std::string &target, const std::string &value);
    void	replace(std::string &filename, const std::string &target, const std::string &value);
};

#endif
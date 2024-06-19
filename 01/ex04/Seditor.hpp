/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seditor.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:36 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:28:37 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDITOR_HPP
# define SEDITOR_HPP

#include <iostream>
#include <fstream>

class Seditor {
public:
    Seditor(const std::string &filename, const std::string &target, const std::string &value);
    ~Seditor();
private:
    int	    isEmpty(std::ifstream &filename);
    int	    targetFound(const std::string &content, const std::string &target);
    int     checkStream(std::ifstream &infile, const std::string &target);
    int	    search(std::ifstream &filename, const std::string &target);
    void    swapString(std::string &content, const std::string &target, const std::string &value);
    void	replace(const std::string &filename, const std::string &target, const std::string &value);
};

#endif
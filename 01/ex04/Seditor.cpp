/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Seditor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:28:24 by rlandolt          #+#    #+#             */
/*   Updated: 2024/06/19 15:28:26 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seditor.hpp"

Seditor::Seditor(const std::string &filename, const std::string &target, const std::string &value) {
    replace(filename, target, value);
}

Seditor::~Seditor() {
}

int	Seditor::isEmpty(std::ifstream &filename) {
    return (filename.peek() == std::ifstream::traits_type::eof() ? 1 : 0);
}

int	Seditor::targetFound(const std::string &content, const std::string &target) {
    return (content.find(target) != std::string::npos ? 1 : 0);
}


int	Seditor::search(std::ifstream &filename, const std::string &target) {
    std::string content;

    while (std::getline(filename, content)) {
        if (targetFound(content, target)) {
            filename.clear();
            filename.seekg(0, std::ios::beg);
            return (1);
        }
    }
    filename.close();
    return (0);
}

void Seditor::swapString(std::string &content, const std::string &target, const std::string &value) {
    size_t pos;

    pos = content.find(target);
    while (pos != std::string::npos) {
        content.erase(pos, target.length());
        content.insert(pos, value);
        pos = content.find(target, pos + value.length());
    }
}

int Seditor::checkStream(std::ifstream &infile, const std::string &target) {
    (void)target;
    if (!infile.is_open() || !infile.good() || infile.bad() || infile.fail()) {
        std::cerr << "Seditor: could not open file : " << std::strerror(errno) << std::endl;
        return (1);
    }
    if (isEmpty(infile)) {
        std::cout << "Seditor: file is empty" << std::endl; // change to cerr
        return (1);
    }
    //if (!search(infile, target)) {
    //    std::cerr << "Seditor: target string not found" << std::endl;
    //    return (1);
    //}
    return (0);
}

void Seditor::replace(const std::string &filename, const std::string &target, const std::string &value) {
    std::string   content;
    std::ifstream infile(filename);
    std::ofstream outfile((filename + ".replace")); 
    
    if (!outfile.is_open()) {
        std::cerr << "Seditor: could not create output file" << std::endl;
        return;
    }
    if (checkStream(infile, target))
        return;
    while (std::getline(infile, content)) {
        swapString(content, target, value);
        outfile << content;
        if (!infile.eof())
            outfile << std::endl;
    }
    infile.close();
    outfile.close();
}
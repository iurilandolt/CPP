/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seditor.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:06:09 by iurilandolt       #+#    #+#             */
/*   Updated: 2024/06/18 00:03:53 by iurilandolt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Seditor.hpp"

Seditor::Seditor(std::string &filename, const std::string &target, const std::string &value) {
    replace(filename, target, value);
}

Seditor::~Seditor() {
}

int	Seditor::isEmpty(std::ifstream &filename) {
    return (filename.peek() == std::ifstream::traits_type::eof() ? 1 : 0);
}

int	Seditor::targetFound(std::string &content, const std::string &target) {
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
    std::cerr << "Seditor: target string not found" << std::endl;
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
    if (!infile.is_open()) {
        std::cerr << "Seditor: could not open file" << std::endl;
            return (1);
    }
    if (!infile.good()) {
        std::cerr << "Seditor: file is corrupted" << std::endl;
        return (1);
    }
    if (isEmpty(infile)) {
        std::cerr << "Seditor: file is empty" << std::endl;
        return (1);
    }
    if (!search(infile, target))
        return (0); // currently not used to mimic the original behavior of sed
    return (0);
}

void Seditor::replace(std::string &filename, const std::string &target, const std::string &value) {
    std::string   content;
    std::ifstream infile(filename);
    std::ofstream outfile((filename + ".replace")); // would not create file before using checkStream
    
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
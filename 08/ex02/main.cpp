/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:10:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/18 11:58:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> mstack;
	MutantStack<int> mstack2(5);

	mstack._deq.push_back(5);
	mstack._deq.push_front(17);
	std::cout << mstack._deq.front() << std::endl;

	return 0;
}
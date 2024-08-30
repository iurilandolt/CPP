/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:51:12 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/30 14:32:24 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &src);
		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form) const;

		
	private:
		std::string const _name;
		int _grade;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj);

#endif
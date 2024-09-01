/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:50 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/01 13:31:40 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

enum FormType
{
	BASE,
	PRESIDENTIAL,
	SHRUBBERY,
	ROBOT
};

class AForm {
	public:
		AForm();
		AForm(std::string const &name, int sign_grade, int exec_grade);
		~AForm();
		AForm(AForm const &src);
		AForm &operator=(AForm const &src);

		std::string const &getName() const;
		std::string getType() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);
	private:
		std::string const _name;
		FormType const _type;
		int const _req_to_sign;
		int const _req_to_exec;
		bool _signed;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	};
	// might need to be virtual if derived class implementation has more member variables
	std::ostream &operator<<(std::ostream &os, AForm const &obj); 


#endif
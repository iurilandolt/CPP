/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:04:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/30 14:28:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	public:
		Form();
		Form(std::string const &name, int sign_grade, int exec_grade);
		~Form();
		Form(Form const &src);
		Form &operator=(Form const &src);

		std::string const &getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat const &bureaucrat);

	private:
		std::string const _name;
		int const _req_to_sign;
		int const _req_to_exec;
		bool _signed;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream &os, Form const &obj);

#endif

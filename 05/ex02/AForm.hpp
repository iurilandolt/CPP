/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:53:50 by rlandolt          #+#    #+#             */
/*   Updated: 2024/09/02 13:28:39 by rlandolt         ###   ########.fr       */
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
	ROBOTOMY,
};

class AForm {
	public:
		AForm();
		AForm(std::string const &name, int sign_grade, int exec_grade);
		virtual ~AForm();
		AForm(AForm const &src);
		AForm &operator=(AForm const &src);

		std::string const &getName() const;
		std::string getType() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool isSigned() const;
		void beSigned(Bureaucrat const &bureaucrat);
		void clearForExecution(Bureaucrat const &executor) const;
		virtual void execute(Bureaucrat const &executor) const;
		FormType _type; // this should maybe be private and const
	private:
		std::string const _name;
		int const _req_to_sign;
		int const _req_to_exec;
		bool _signed;
	protected:
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
	};
	std::ostream &operator<<(std::ostream &os, AForm const &obj); 


#endif
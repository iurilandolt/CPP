/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:04:11 by rlandolt          #+#    #+#             */
/*   Updated: 2024/08/28 15:10:12 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Form {
	public:
		Form();
		Form(std::string const &name, int grade);
		~Form();
		Form(Form const &src);
		Form &operator=(Form const &src);

		std::string const &getName() const;
		int getReqGrade() const;

	private:
		std::string const _name;
		int const _grade;
		int const req_to_sign;
		int const req_to_exec;
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:58:33 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:29:17 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade2sign;
	const int			_grade2exec;
	
public:
	
	Form();
	Form(std::string name, bool is_signed, int grade2sign, int grade2exec);
	Form(Form& origin);
	Form& operator = (Form& origin);
	~Form();

	std::string	getName() const;
	bool		getSigned() const;
	int			getGrade2Sign() const ;
	int			getGrade2Exec() const;

	void 		beSigned(Bureaucrat& bureaucrat);

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class AlreadySignedException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

	std::ostream& operator <<(std::ostream& os, const Form& form);

#endif

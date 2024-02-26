/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:58:33 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:49:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

#define TEXT_NOFORMAT	"\e[0m"
#define TEXT_BOLD		"\e[1m"
#define TEXT_UNDERLINE	"\e[4m"

#define COLOR_STANDARD	"\033[0m"
#define	COLOR_ERROR		"\033[31m"
#define COLOR_WARNING	"\033[33m"
#define COLOR_SUCCESS	"\033[92m"
#define COLOR_FOCUS		"\e[35m"

class Bureaucrat;

class Form
{
protected:
	const std::string	_name;
	bool				_signed;
	const int			_grade2sign;
	const int			_grade2exec;
	
public:
	
	Form();
	Form(std::string name, bool is_signed, int grade2sign, int grade2exec);
	Form(Form& origin);
	Form& operator = (Form& origin);
	virtual ~Form() = 0;

	std::string		getName() const;
	bool			getSigned() const;
	int				getGrade2Sign() const ;
	int				getGrade2Exec() const;

	void 			beSigned(Bureaucrat& bureaucrat);
	virtual void 	execute(Bureaucrat& bureaucrat) const;

	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception{
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

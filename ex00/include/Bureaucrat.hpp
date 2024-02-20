/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:22:09 by jschott           #+#    #+#             */
/*   Updated: 2024/02/20 18:04:46 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator = (const Bureaucrat& copy);
	~Bureaucrat();

	Bureaucrat operator ++(int);
	Bureaucrat& operator ++(void);
	Bureaucrat operator --(int);
	Bureaucrat& operator --(void);

	std::string getName() const;
	int			getGrade() const;

	class GradeTooHighException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Bureaucrat::GradeTooHighException");
			}
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char* what() const throw(){
				return ("Bureaucrat::GradeTooLowException");
			}
	};
};

	std::ostream& operator <<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
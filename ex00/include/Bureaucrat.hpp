/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:22:09 by jschott           #+#    #+#             */
/*   Updated: 2024/02/20 11:47:59 by jschott          ###   ########.fr       */
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
	// Bureaucrat(std::string name);
	// Bureaucrat(int grade);
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
			virtual const std::string msg(int grade) const throw(){
				return ("GradeTooHighException");
			}
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const std::string msg(int grade) const throw(){
				return ("GradeTooLowException");
			}
	};
};

	std::ostream& operator <<(std::ostream& os, const Bureaucrat& bueaucrat);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:43:55 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:59:45 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern& origin);
	Intern& operator= (Intern& origin);
	~Intern();

	Form* makeForm(std::string name, std::string target);

	class CannotCreateFormException : public std::exception{
		public:
			virtual const char* what() const throw();
	};
};

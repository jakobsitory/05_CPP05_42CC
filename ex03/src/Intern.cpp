/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:52:08 by jschott           #+#    #+#             */
/*   Updated: 2024/02/22 11:55:41 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){	
}

Intern::Intern(Intern& origin){
	*this = origin;
}

Intern& Intern::operator= (Intern& origin){
	if (this == &origin)
		return (*this);
	return *this;
}

Intern::~Intern(){
}

Form* Intern::makeForm(std::string name, std::string target){
	std::string form_names[] = {"ShrubberyCreationForm", 
								"RobotomyRequestForm", 
								"PresidentialPardonForm"};
	
	

	int i =0;
	while (i < 4 && form_names[i] != name)
		i++;
	try{
		if (i < 3)
			std::cout << "Intern creates " << TEXT_BOLD << name << TEXT_NOFORMAT << std::endl;
		switch (i) {
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
			default: {
				std::cerr << COLOR_ERROR << "intern cannot create form: " << name << std::endl << COLOR_STANDARD;
				return NULL;
				}
		}
	}
	catch(const std::exception& e){
		std::cerr << COLOR_ERROR << e.what() << std::endl
				<< "Error while creating form " << name << std::endl << COLOR_STANDARD;
	}
	return NULL;
}

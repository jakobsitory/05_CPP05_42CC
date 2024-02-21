/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:42:48 by jschott           #+#    #+#             */
/*   Updated: 2024/02/21 19:34:46 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", false, 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
	: Form("PresidentialPardonForm", false, 25, 5),
		_target(target){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& origin)
	: Form(origin){
		this->_target = origin.getTarget();
		this->_signed = origin.getSigned();
}

PresidentialPardonForm& PresidentialPardonForm::operator = (PresidentialPardonForm& origin){
	if (this == &origin)
		return *this;
	this->_signed = origin.getSigned();
	this->_target = origin.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}

void PresidentialPardonForm::execute(Bureaucrat& bureaucrat) const{
	Form::execute(bureaucrat);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const{
	return this->_target;
}

std::ostream& operator <<(std::ostream& os, const PresidentialPardonForm& form){
	os << "Form:\t\t" << form.getName() << std::endl
		<< "Signed:\t\t" << std::boolalpha << form.getSigned() << std::endl
		<< "Sign grade:\t" << form.getGrade2Sign() << std::endl
		<< "Execute grade:\t" << form.getGrade2Exec() << std::endl
		<< "Target:\t\t" << form.getTarget() << std::endl;
	return os;
}
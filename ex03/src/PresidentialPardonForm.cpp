/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:42:48 by jschott           #+#    #+#             */
/*   Updated: 2024/02/22 10:10:11 by jschott          ###   ########.fr       */
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
	std::cout << TEXT_BOLD 
		<< this->_target << " has been pardoned by Zaphod Beeblebrox."
		<< TEXT_NOFORMAT << std::endl << std::endl;
}

std::string PresidentialPardonForm::getTarget() const{
	return this->_target;
}

std::ostream& operator <<(std::ostream& os, const PresidentialPardonForm& form){
	os << "Form:\t\t" << TEXT_BOLD << form.getName() << std::endl << TEXT_NOFORMAT
		<< "Signed:\t\t" << TEXT_BOLD << std::boolalpha << form.getSigned() << std::endl << TEXT_NOFORMAT
		<< "Sign grade:\t" << TEXT_BOLD << form.getGrade2Sign() << std::endl << TEXT_NOFORMAT
		<< "Execute grade:\t" << TEXT_BOLD << form.getGrade2Exec() << std::endl << TEXT_NOFORMAT
		<< "Target:\t\t" << TEXT_BOLD << form.getTarget() << std::endl << TEXT_NOFORMAT;
	return os;
}
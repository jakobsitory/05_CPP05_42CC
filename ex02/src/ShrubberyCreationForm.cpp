/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:50:17 by jschott           #+#    #+#             */
/*   Updated: 2024/02/21 19:34:52 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", false, 145, 137){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", false, 145, 137),
	_target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& origin)
	: Form(origin){
		this->_target = origin.getTarget();
		this->_signed = origin.getSigned();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (ShrubberyCreationForm& origin){
	if (this == &origin)
		return *this;
	this->_signed = origin.getSigned();
	this->_target = origin.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(Bureaucrat& bureaucrat) const{
	Form::execute(bureaucrat);
	std::cout << "Writing ASCII trees" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->_target;
}

std::ostream& operator <<(std::ostream& os, const ShrubberyCreationForm& form){
	os << "Form:\t\t" << form.getName() << std::endl
		<< "Signed:\t\t" << std::boolalpha << form.getSigned() << std::endl
		<< "Sign grade:\t" << form.getGrade2Sign() << std::endl
		<< "Execute grade:\t" << form.getGrade2Exec() << std::endl
		<< "Target:\t\t" << form.getTarget() << std::endl;
	return os;
}
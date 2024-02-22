/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:50:17 by jschott           #+#    #+#             */
/*   Updated: 2024/02/22 10:41:17 by jschott          ###   ########.fr       */
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
	
	std::string filename = this->_target + "_shrubbery";
	std::ofstream	file_out(filename.c_str());
	if (!file_out.is_open())
		throw ShrubberyCreationForm::OutFileException();

	file_out << COLOR_FOCUS
		<< "888\n"
		<< "888                           \n"
		<< "888                           \n"
		<< "888888 888d88  .d88b.   .d88b.  \n"
		<< "888    888P*  d8P  Y8b d8P  Y8b \n"
		<< "888    888    88888888 88888888 \n"
		<< "Y88b.  888    Y8b.     Y8b.     \n"
		<< " *Y888 888     *Y8888   *Y8888\n" << COLOR_STANDARD;
	;
	file_out.close();
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->_target;
}

std::ostream& operator <<(std::ostream& os, const ShrubberyCreationForm& form){
	os << "Form:\t\t" << TEXT_BOLD << form.getName() << std::endl << TEXT_NOFORMAT
		<< "Signed:\t\t" << TEXT_BOLD << std::boolalpha << form.getSigned() << std::endl << TEXT_NOFORMAT
		<< "Sign grade:\t" << TEXT_BOLD << form.getGrade2Sign() << std::endl << TEXT_NOFORMAT
		<< "Execute grade:\t" << TEXT_BOLD << form.getGrade2Exec() << std::endl << TEXT_NOFORMAT
		<< "Target:\t\t" << TEXT_BOLD << form.getTarget() << std::endl << TEXT_NOFORMAT;
	return os;
}
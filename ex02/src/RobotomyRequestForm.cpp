/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:28:34 by jschott           #+#    #+#             */
/*   Updated: 2024/02/26 09:54:55 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", false, 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", false, 72, 45),
	_target(target){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& origin)
	: Form(origin){
		this->_target = origin.getTarget();
		this->_signed = origin.getSigned();
}

RobotomyRequestForm& RobotomyRequestForm::operator = (RobotomyRequestForm& origin){
	if (this == &origin)
		return *this;
	this->_signed = origin.getSigned();
	this->_target = origin.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(Bureaucrat& bureaucrat) const{
	Form::execute(bureaucrat);
	std::cout << TEXT_BOLD << ">Some Drilling Noises<" << std::endl 
		<< this->_target << " has been robotomized sucessfully 50%% of the time."
		<< TEXT_NOFORMAT << std::endl << std::endl;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->_target;
}

std::ostream& operator <<(std::ostream& os, const RobotomyRequestForm& form){
	os << "Form:\t\t" << TEXT_BOLD << form.getName() << std::endl << TEXT_NOFORMAT
		<< "Signed:\t\t" << TEXT_BOLD << std::boolalpha << form.getSigned() << std::endl << TEXT_NOFORMAT
		<< "Sign grade:\t" << TEXT_BOLD << form.getGrade2Sign() << std::endl << TEXT_NOFORMAT
		<< "Execute grade:\t" << TEXT_BOLD << form.getGrade2Exec() << std::endl << TEXT_NOFORMAT
		<< "Target:\t\t" << TEXT_BOLD << form.getTarget() << std::endl << TEXT_NOFORMAT;
	return os;
}
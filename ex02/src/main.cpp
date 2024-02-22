/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:56:23 by jschott           #+#    #+#             */
/*   Updated: 2024/02/22 10:03:28 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

int	main(){
	
	Bureaucrat TopBureaucrat("TopBureaucrat", 1);
	Bureaucrat FlopBureaucrat("FlopBureaucrat", 150);
	
	std::cout << "Welcome to the bureaucrat simulator!" << std::endl;
	std::cout << "To exit enter " << TEXT_BOLD << "EXIT" << TEXT_NOFORMAT << std::endl;
	std::cout << TEXT_BOLD << "Press Enter" << TEXT_NOFORMAT << " to start simulation" << std::endl;
	std::string input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){
		
		std::string target_scf = "";
		std::string target_rrf = "";
		std::string target_ppf = "";
		
		std::cout << std::endl << "Please enter targets for the following Forms:" << std::endl;
		std::cout << "ShrubberyCreationForm:\t";
		while (target_scf == "")
			std::getline(std::cin, target_scf);
		std::cout << "RobotomyRequestForm:\t";
		while (target_rrf == "")
			std::getline(std::cin, target_rrf);
		std::cout << "PresidentialPardonForm:\t";
		while (target_ppf == "")
			std::getline(std::cin, target_ppf);

		std::cout << std::endl << "Trying to create Forms" << std::endl;

		try{
			ShrubberyCreationForm form_scf (target_scf);
			RobotomyRequestForm form_rrf (target_rrf);
			PresidentialPardonForm form_ppf (target_ppf);
			
			std::cout << COLOR_SUCCESS << "SUCCESS!" << COLOR_STANDARD << std::endl
			<< form_scf << std::endl << form_rrf << std::endl << form_ppf << std::endl;

			std::cout << std::endl << TEXT_BOLD << "Press Enter to Execute before signage" << TEXT_NOFORMAT << std::endl;
			input = "";
			std::getline(std::cin, input);
			TopBureaucrat.executeForm(form_scf);
			TopBureaucrat.executeForm(form_rrf);
			TopBureaucrat.executeForm(form_ppf);
			
			std::cout << std::endl << TEXT_BOLD
				<< "Press Enter to try signing with undergraded Bureaucrat"
				<< TEXT_NOFORMAT << std::endl;
			input = "";
			std::getline(std::cin, input);
			FlopBureaucrat.signForm(form_scf);
			FlopBureaucrat.signForm(form_rrf);
			FlopBureaucrat.signForm(form_ppf);
			
			std::cout << std::endl << TEXT_BOLD
				<< "Press Enter to sign forms successfully"
				<< TEXT_NOFORMAT << std::endl;
			input = "";
			std::getline(std::cin, input);
			TopBureaucrat.signForm(form_scf);
			TopBureaucrat.signForm(form_rrf);
			TopBureaucrat.signForm(form_ppf);
						
			std::cout << std::endl << TEXT_BOLD
				<< "Press Enter to try execute with undergraded Bureaucrat"
				<< TEXT_NOFORMAT << std::endl;
			input = "";
			std::getline(std::cin, input);
			FlopBureaucrat.executeForm(form_scf);
			FlopBureaucrat.executeForm(form_rrf);
			FlopBureaucrat.executeForm(form_ppf);
			
			std::cout << std::endl << TEXT_BOLD
				<< "Press Enter to execute successfully"
				<< TEXT_NOFORMAT << std::endl;
			input = "";
			std::getline(std::cin, input);
			TopBureaucrat.executeForm(form_scf);
			TopBureaucrat.executeForm(form_rrf);
			TopBureaucrat.executeForm(form_ppf);
		}
		catch(const std::exception& e ){
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << std::endl << "Simulation done" << std::endl;
		std::cout << "To exit enter EXIT" << std::endl;
		std::cout << "To restart enter RESTART" << std::endl;
		std::cin >> input;
		while (input != "RESTART" && input != "EXIT")
			std::cin >> input;
	}
	return (0);
}

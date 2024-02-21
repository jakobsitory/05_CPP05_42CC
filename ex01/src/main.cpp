/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:56:23 by jschott           #+#    #+#             */
/*   Updated: 2024/02/21 13:23:57 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

#define GREEN	\033[1;32m
#define CYAN	\033[1;36m
#define YELLOW	\033[1;33m
#define RED		\033[1;31m
#define BOLD	\033[1m

bool num_str(const char* str){
	
	while (str && *str){
		if (*str < '0' || *str > '9')
			return false;
		else if (*str == '\0')
			return true;
		str++;
	}
	return false;
}

int	main(){
	
	std::string input;
	std::string name = "";

	std::srand(static_cast<int>(std::time(NULL)));
	
	std::cout <<"Welcome to the bureaucrat simulator!" << std::endl;
	std::cout << "To exit enter EXIT at any time" << std::endl;
	std::cout << "Press Enter to start simulation" << std::endl;
	input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){
		
		std::string form_name;
		int			form_grade2sign;
		int			form_grade2exec;
		
		std::cout << std::endl << "Enter data for Form:" << std::endl;
		std::cout << "Name:\t\t";
		while (form_name == "")
			std::getline(std::cin, form_name);
		if (form_name == "EXIT")
			return (0);
		
		std::cout << "Enter grades (1 - 150) or R for random, necessary for:" << std::endl;
		std::cout << "Signing:\t";
		input = "";
		while (!std::atoi(input.c_str())){
			std::getline(std::cin, input);
			if (input == "EXIT")
				return (0);	
			else if (input == "R"){
				form_grade2sign = (rand() % 300) - (rand() % 300);
				break ;
			}
			else
				form_grade2sign = std::atoi(input.c_str());
		}

		std::cout << "Executing:\t";
		input = "";
		while (!std::atoi(input.c_str())){
			std::getline(std::cin, input);
			if (input == "EXIT")
				return (0);	
			else if (input == "R"){
				form_grade2exec = (rand() % 300) - (rand() % 300);
				break ;
			}
			else
				form_grade2exec = std::atoi(input.c_str());
		}

		std::cout << std::endl << "Trying to create Form " << form_name << std::endl
								<< " with sign 2 sign" << form_grade2sign << std::endl
								<< " with grade 2 execute" << form_grade2exec << std::endl;

		try {
			Form myform(form_name, false, form_grade2sign, form_grade2exec);
			
			std::cout << std::endl << "SUCCESS!" << std::endl << myform << std::endl;

			std::cout << std::endl << "Press Enter to create Bureaucrats of relevant grade" << std::endl;
			input = "";
			std::getline(std::cin, input);
			Bureaucrat bureau_S("Allowed_to_sign", myform.getGrade2Sign());
			//Bureaucrat bureau_E("Allowed_to_exec", myform.getGrade2Exec());
			Bureaucrat bureau_Sx("Not_Allowed_to_sign", myform.getGrade2Sign() + 1);
			//Bureaucrat bureau_Ex("Not_Allowed_to_exec", myform.getGrade2Exec() + 1);
			std::cout << "SUCCESS!" << std::endl;
			std::cout << bureau_S << std::endl
						<< bureau_Sx << std::endl;
						/* << bureau_E << std::endl
						<< bureau_Ex << std::endl << std::endl;
						*/

			std::cout << std::endl << "Press Enter to test signForm" << std::endl;
			input = "";
			std::getline(std::cin, input);
		
		try {
				bureau_S.signForm(myform);
				bureau_Sx.signForm(myform);
				bureau_S.signForm(myform);
			}
			catch(const std::exception& e ){
				std::cerr << e.what() << std::endl;
			}

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

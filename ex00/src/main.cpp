/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:56:23 by jschott           #+#    #+#             */
/*   Updated: 2024/02/20 17:46:39 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

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
	
	std::cout << "Welcome to the bureaucrat simulator!" << std::endl;
	std::cout << "To exit enter EXIT at any time" << std::endl;
	std::cout << "Press Enter to start simulation" << std::endl;
	input = "";
	std::getline(std::cin, input);
	while (input != "EXIT"){
		
		int x = 'x';
		std::cout << std::endl << "Enter data for Bureaucrat:" << std::endl;
		std::cout << "Name:\t\t\t";
		while (name == "")
			std::getline(std::cin, name);
		if (name == "EXIT")
			return (0);
		
		std::cout << "Grade (1-150) OR" << std::endl << "R for random value:\t";
		while (!std::atoi(input.c_str())){
			std::getline(std::cin, input);
			if (input == "EXIT")
				return (0);	
			else if (input == "R"){
				x = (rand() % 300) - (rand() % 300);
				break ;
			}
			else
				x = std::atoi(input.c_str());
		}

		input = "";
		std::cout << std::endl << "Trying to create Bureaucrat " << name 
								<< " with grade " << x << std::endl;
		try{
			Bureaucrat bureau(name, x);
			
			std::cout<< "SUCCESS: " << bureau << std::endl;
			
			std::cout << std::endl << "Press Enter to test copy constructor" << std::endl;
			input = "";
			std::getline(std::cin, input);
			Bureaucrat copy = Bureaucrat(bureau);
			std::cout 	<< "Result:" << std::endl
						<< "Original:\t" << bureau << " at: " << &bureau << std::endl
						<< "Copy:\t\t" << copy << " at: " << &copy << std::endl;
			
			std::cout << std::endl << "Press enter to promote Bureaucrat to top grade." << std::endl;
			input = "";
			std::getline(std::cin, input);
			if (input == "EXIT")
				return (0);	
			try {
				while (true){
					++bureau;
					std::cout << "PROMITED: " << bureau << std::endl;
				}
			}
			catch(const Bureaucrat::GradeTooHighException& e){
				std::cerr << e.what() << std::endl;
			}
					
			std::cout << std::endl << "Press enter to demote Bureaucrat to worst grade." << std::endl;
			input = "";
			std::getline(std::cin, input);
			if (input == "EXIT")
				return (0);	
			try {
				while (true){
					--bureau;
					std::cout << "DEMOTED: " << bureau << std::endl;
				}
			}
			catch(const Bureaucrat::GradeTooLowException& e){
				std::cerr << e.what() << std::endl;
			}

			std::cout << std::endl << std::endl << "Press Enter to test assignment operator" << std::endl;
			input = "";
			std::getline(std::cin, input);
			Bureaucrat copy2 = Bureaucrat("copy", 75);
			std::cout 	<< "Before assignment:" << std::endl
						<< "Original:\t" << bureau << " at: " << &bureau << std::endl
						<< "Copy:\t\t" << copy2 << " at: " << &copy2 << std::endl;
			copy2 = bureau;
			std::cout 	<< std::endl << "After assignment:" << std::endl
						<< "Original:\t" << bureau << " at: " << &bureau << std::endl
						<< "Copy:\t\t" << copy2 << " at: " << &copy2 << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e){
			std::cerr << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException& e){
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
#ifndef FORM_HPP
# define FORM_HPP

// #include "Bureaucrat.hpp"

# include <iostream>
class Bureaucrat;

class Form {
	private:
		std::string const _name;
		bool _signed;
		unsigned int const _signGradeRequired;
		unsigned int const _execGradeRequired;

	public:
		Form();
		Form(std::string const name, unsigned int signGradeRequired, unsigned int execGradeRequired);
		Form(Form const &obj);
		~Form();

		Form &operator=(Form const &obj);

		std::string const getName() const;
		bool getSigned() const;
		unsigned int getSignGradeRequired() const;
		unsigned int getExecGradeRequired() const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high";
				}
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low";
				}
		};
};

#endif
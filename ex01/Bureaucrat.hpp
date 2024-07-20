#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat {
	private:
		std::string const _name;
		unsigned int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, unsigned int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &obj);

		std::string const getName() const;
		unsigned int getGrade() const;
		void setGrade(unsigned int grade);
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &src);

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif
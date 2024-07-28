#ifndef AFORM_HPP
# define AFORM_HPP

// #include "Bureaucrat.hpp"

# include <iostream>
class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool 				_signed;
		unsigned int const	_signGradeRequired;
		unsigned int const	_execGradeRequired;

	public:
		AForm();
		AForm(std::string const name, unsigned int signGradeRequired, unsigned int execGradeRequired);
		AForm(AForm const &obj);
		virtual ~AForm();

		AForm &operator=(AForm const &obj);

		std::string const	getName() const;
		bool				getSigned() const;
		unsigned int		getSignGradeRequired() const;
		unsigned int		getExecGradeRequired() const;

		void				setSignatureStatus(bool status);

		void				beSigned(Bureaucrat &bureaucrat);
		virtual void    	execute(const Bureaucrat &src) const = 0;

		class FormNotSignedException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Form is not signed";
				}
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &obj);

#endif
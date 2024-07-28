#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string const	_target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &obj);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);

		virtual void execute(const Bureaucrat &executor) const;
		
		class FileNotOpenedException: public std::exception {
			public:
				virtual const char *what() const throw() {
					return "File not opened";
				}
		};
};

#endif
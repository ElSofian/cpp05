#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj), _target(obj._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj) {
	if (this != &obj)
	    setSignatureStatus(obj.getSigned());
	return (*this);	
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::ifstream infile;
	
	if (!getSigned())
		throw FormNotSignedException();
    if (executor.getGrade() >= getExecGradeRequired())
        throw Bureaucrat::GradeTooLowException();
    else
    {
        infile.open("tree.txt");
        if (!infile)
            std::cout << "Couldn't open tree file." << std::endl;
        std::string fileName = this->getName() + "_shrubbery";
        std::ofstream outfile(fileName.c_str());
        if (!outfile)
            std::cout << "Coudln't create shrubbery file." << std::endl;
        std::string line;
        while (getline(infile, line))
            outfile << line << std::endl;
        outfile.close();
        infile.close();
    }
}
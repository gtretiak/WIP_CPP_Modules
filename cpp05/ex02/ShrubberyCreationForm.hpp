#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class   ShrubberyCreationForm : public AForm {
        private:
                std::string     target_;
        protected:
                void    execute2() const;
        public:
                ShrubberyCreationForm(std::string target);
                ShrubberyCreationForm(const ShrubberyCreationForm &Another);
                ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &Another);
                ~ShrubberyCreationForm();
};

#endif

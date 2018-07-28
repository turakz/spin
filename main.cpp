#include "string_c.h"
#include "case_c.h"
#include "algos_c.h"

void test_case();

int main(void){
    
    test_case();
    return 0;
}

void test_case(){
    std::cout << "input\n>> ";
    std::string input = "";
    std::getline(std::cin, input);
    spin::string_c sc1 = input;
    std::cout << "\nspin::transform(spin::string_c):\n\n";
    spin::transform(sc1.begin(), sc1.end(), spin::case_c("titlecase"));
    std::cout << "titlecase: " << sc1 << "\n";
    spin::transform(sc1.begin(), sc1.end(), spin::case_c("uppercase"));
    std::cout << "uppercase: " << sc1 << "\n";
    spin::transform(sc1.begin(), sc1.end(), spin::case_c("lowercase"));
    std::cout << "lowercase: " << sc1 << "\n";
    spin::transform(sc1.begin(), sc1.end(), spin::case_c("snakecase"));
    std::cout << "snakecase: " << sc1 << "\n";
    std::cout << "\nspin::transform(std::string):\n\n";
    spin::transform(input.begin(), input.end(), spin::case_c("titlecase"));
    std::cout << "titlecase: " << input << "\n";
    spin::transform(input.begin(), input.end(), spin::case_c("uppercase"));
    std::cout << "uppercase: " << input << "\n";
    spin::transform(input.begin(), input.end(), spin::case_c("lowercase"));
    std::cout << "lowercase: " << input << "\n";
    spin::transform(input.begin(), input.end(), spin::case_c("snakecase"));
    std::cout << "snakecase: " << input << std::endl;
}

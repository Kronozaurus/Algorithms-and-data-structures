#include <iostream> 
#include "person.h"
#include "student.h"
#include "course.h"
#include "employee.h"

int main() {
    
    std::string name;
    std::string surname; 
    float weight;
    float height; 
    int age; 
    char sex;
    std::string index; 
    int year;
    gender sex_;
    std::string company;
    std::string position;
    float salary;
    float experience;
    
    std::cin >> name;
    Course myCourse(name);

    for(int i = 0; i < 10; i++){
        std::cin >> name >> surname >> weight >> height >> age >> sex >> index >> year;
        if(sex == 'M')
            sex_ = M;
        else
            sex_ = K;
        Student myStudent(name, surname, weight, height, age, sex_, index, year);
        myCourse.addStudent(myStudent);
    }
    
    std::cin >> year;
    
    myCourse.dispTopThree(year);
    
    for(int i = 0; i < 2; i++){
        std::cin >> name >> surname >> weight >> height >> age >> sex 
        >> company >> position >> salary >> experience;
        if(sex == 'M')
            sex_ = M;
        else
            sex_ = K;
        Employee myEmployee(name, surname, weight, height, age, sex_, company, position, salary, experience);
        std::cout << myEmployee.leftToRetirement();
        if(i == 0) std::cout << " ";
    }
    
    return 0;
}
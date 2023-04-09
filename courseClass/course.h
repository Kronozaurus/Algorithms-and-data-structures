#include <iostream>
#include <vector>


class Course{
    public:
        Course() = default;
        Course(std::string);
        ~Course() = default;
        
        void addStudent(Student);
        void removeStudent(Student);
        void studentsUpdate();
        void sortByGrade(int);
        void dispTopThree(int);
        
    private:
        std::string name_;
        std::vector<std::vector<Student>> students_;

        int numberOfStudents_;
};

Course :: Course (std::string name) : name_(name) {
    numberOfStudents_ = 0;
    for(int i = 0; i < 5; i++)
        students_.emplace_back(std::vector<Student>());
}

void Course :: addStudent(Student toAdd){ 
    students_[toAdd.year_ - 1].emplace_back(toAdd);
}

void Course :: removeStudent(Student toRemove){ 
    int position;
    for(int i = 0; i < students_[toRemove.year_ - 1].size(); i++){
        if(students_[toRemove.year_ - 1][i] == toRemove){
            position = i;
            students_[toRemove.year_ - 1].erase(students_[toRemove.year_ - 1].begin() + position);
            break;
        }
    }
}

void Course :: studentsUpdate(){ 
    numberOfStudents_ = 0;
    for(int i = 0; i < students_.size(); i++){
        for(int j = 0; j < students_[i].size(); j++){
            numberOfStudents_++;
        }
    }
}

void Course :: sortByGrade(int year){ 
    for(int i = 0; i < students_[year - 1].size(); i++){
        int minIndex = i;
        for(int j = i + 1; j < students_[year - 1].size(); j++){
            if(students_[year - 1][j].meanCalc() > students_[year - 1][minIndex].meanCalc())
                minIndex = j;
        }
        std::swap(students_[year - 1][i], students_[year - 1][minIndex]);
    }
}

void Course :: dispTopThree(int year){
    sortByGrade(year);
    for(int i = 0; i < students_[year - 1].size(); i++){
        if(i == 3) break;
        std::cout 
        << students_[year - 1][i].index_ << " " 
        << students_[year - 1][i].name_ << " "  
        << students_[year - 1][i].surname_ << " ";
    }
}
// lab_2 c++.cpp: определяет точку входа для приложения.
//

#include "lab_2 c++.h"

using namespace std;

int main() {
    LinkedList<Student> students;
    students.push_tail({ "Ivanov", "Ivan", 3, 4.5 });
    students.push_tail({ "Nikolaev", "Petr", 2, 2.1 });
    students.push_tail({ "Serov", "Alex", 4, 3.8 });

    auto groups = students.divideByCourse();
    LinkedList<Student> seniorStudents = groups.first;
    LinkedList<Student> juniorStudents = groups.second;

    std::cout << "senior students:" << endl;

    for (int i = 0; i < seniorStudents.getSize(); i++) {
        std::cout << seniorStudents[i].lastName << " " << seniorStudents[i].firstName << " " << seniorStudents[i].course << " " << seniorStudents[i].averageGrade << std::endl;
    }

    std::cout << "junior students:" << endl;

    for (int i = 0; i < juniorStudents.getSize(); i++) {
        std::cout << juniorStudents[i].lastName << " " << juniorStudents[i].firstName << " " << juniorStudents[i].course << " " << juniorStudents[i].averageGrade << std::endl;
    }

    return 0;
}

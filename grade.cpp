#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    std::string name;
    double grade;

    // Input student names and grades
    while (true) {
        std::cout << "Enter student name (or 'exit' to finish): ";
        std::cin >> name;

        if (name == "exit") {
            break;
        }

        std::cout << "Enter grade for " << name << ": ";
        std::cin >> grade;

        students.push_back({name, grade});
    }

    // Calculate average grade
    double totalGrade = 0.0;
    for (const auto& student : students) {
        totalGrade += student.grade;
    }
    double averageGrade = totalGrade / students.size();

    // Find highest and lowest grades
    auto highestGradeStudent = std::max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.grade < b.grade;
        }
    );
    auto lowestGradeStudent = std::min_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.grade < b.grade;
        }
    );

    // Display results
    std::cout << "Average grade: " << averageGrade << std::endl;
    std::cout << "Highest grade: " << highestGradeStudent->grade << " (Student: " << highestGradeStudent->name << ")" << std::endl;
    std::cout << "Lowest grade: " << lowestGradeStudent->grade << " (Student: " << lowestGradeStudent->name << ")" << std::endl;

    return 0;
}

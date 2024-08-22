#include <iostream>
#include <string.h>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    int score;

public:
    // Constructor
    Exam(const char* name, const char* date, int score) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        this->score = score;
    }

    // Destructor
    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    void display() const {
        std::cout << "Student Name: " << studentName << std::endl;
        std::cout << "Exam Date: " << examDate << std::endl;
        std::cout << "Score: " << score << std::endl;
    }
};

int main() {
    cout  << "Amna(23k-0066)" << endl << endl; 
    Exam originalExam("John Doe", "2024-08-20", 95);
    Exam shallowCopy = originalExam;
    cout << "Original Exam Details:" << endl;
    originalExam.display();
    cout << "Shallow Copy Exam Details:" << endl;
    shallowCopy.display();
    return 0;
}



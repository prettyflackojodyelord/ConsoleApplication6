#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Course {
public:
    virtual std::string getName() const = 0; 
    virtual void setInstructor(const std::string& instructor) = 0; 
    virtual void printSyllabus() const = 0; 
    virtual ~Course() {}
};

class Enrollable {
public:
    virtual void enroll(const std::string& student) = 0; 
    virtual void dropStudent(const std::string& student) = 0; 
    virtual bool verifyEnrollmentRequirements() = 0; 
    virtual ~Enrollable() {}
};

class Graded {
public:
    virtual void assignGrade(const std::string& grade, const std::string& student) = 0; 
    virtual void publishGrades() = 0; 
    virtual ~Graded() {}
};

class Examable {
public:
    virtual void scheduleExam(const std::string& examDate) = 0; 
    virtual void conductExam() = 0; 
    virtual ~Examable() {}
};

class CertificateIssuable {
public:
    virtual void issueCertificate(const std::string& student) = 0; 
    virtual ~CertificateIssuable() {}
};

class Feedbackable {
public:
    virtual void collectFeedback() = 0; 
    virtual ~Feedbackable() {}
};
class MathCourse : public Course, public Enrollable, public Graded, public Examable, public CertificateIssuable, public Feedbackable {
private:
    std::string name; 
    std::string instructor;
    std::vector<std::string> students; 
    std::map<std::string, std::string> grades;

public:
    MathCourse(const std::string& courseName) : name(courseName) {}

    std::string getName() const override {
        return name;
    }

    void setInstructor(const std::string& instructor) override {
        this->instructor = instructor;
    }

    void printSyllabus() const override {
        std::cout << "Курс " << name << ": Математический анализ, Алгебра." << std::endl;
    }

    void enroll(const std::string& student) override {
        students.push_back(student);
        std::cout << student << " зарегистрирован на курс " << name << std::endl;
    }

    void dropStudent(const std::string& student) override {
        students.erase(std::remove(students.begin(), students.end(), student), students.end());
        std::cout << student << " исключен из курса " << name << std::endl;
    }

    bool verifyEnrollmentRequirements() override {
        return true;
    }

    void assignGrade(const std::string& grade, const std::string& student) override {
        grades[student] = grade;
        std::cout << "Оценка " << grade << " выставлена студенту " << student << std::endl;
    }

    void publishGrades() override {
        std::cout << "Оценки студентов:" << std::endl;
        for (const auto& entry : grades) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    }

    void scheduleExam(const std::string& examDate) override {
        std::cout << "Экзамен запланирован на: " << examDate << std::endl;
    }

    void conductExam() override {
        std::cout << "Экзамен проводится..." << std::endl;
    }

    void issueCertificate(const std::string& student) override {
        std::cout << "Сертификат выдан студенту " << student << std::endl;
    }

    void collectFeedback() override {
        std::cout << "Собираем обратную связь от студентов..." << std::endl;
    }
};
int main() {
    setlocale(LC_ALL, "RUS");
    MathCourse math("Математика"); 
    math.setInstructor("Профессор Иванов"); 
    math.printSyllabus();

    math.enroll("Алексей"); 
    math.enroll("Мария"); 

    math.assignGrade("A", "Алексей"); 
    math.assignGrade("B", "Мария"); 

    math.publishGrades(); 

    math.scheduleExam("2023-12-01"); 
    math.conductExam(); 

    math.issueCertificate("Алексей"); 
    math.collectFeedback(); 

    return 0; 
}
//
// Created by 24502 on 2025/7/12.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>


class Student {
private:
    const int m_id;
    std::string m_address;

public:
    Student();

    explicit Student(int id, std::string address);

    const int get_id() const;
    std::string get_address()  ;


    friend std::ostream &operator<<(std::ostream &os, const Student &s) {
        os << "Student{id=" << s.m_id << "}";
        return os;
    }
};


#endif //STUDENT_H

//
// Created by 24502 on 2025/7/12.
//

#include "student.h"

Student::Student(): m_id(0) {
}

Student::Student(int id, std::string address) : m_id(id), m_address(address) {
}

const int Student::get_id() const {
    return m_id;
}
std::string Student::get_address()  {
    return m_address;
}


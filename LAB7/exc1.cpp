//
// Created by zmfca on 11/01/2022.
//

#include "exc1.h"
#include <iostream>
#include <string>

class person  {
private:
    int pid;
    std::string pname;
public:
    person(int id, const std::string& name)
            : pid(id), pname(name) { }
    int id() const {
        return pid;
    }
    const std::string& name() const {
        return pname;
    }
    virtual  void print(std::ostream& out) const {
        out << "ID: " << pid << std::endl
            << "Name: " << pname << std::endl;
    }
};

class student : public person {
protected :
    std::string course;
public:
    student(int id , const std::string& name,const std::string& course) : person (id , name){
        this->course = course;
    }
    const std::string& getCourse(){
        return course;
    }

    void print(std::ostream& out) {
        person::print(out);
        out << "Course: "<< course << std::endl;
    }
};
class erasmus_student : public student{
protected:
    std::string country;
public:
  erasmus_student(int id, const std::string& name,const std::string& course, const std::string country): student(id,name,course){
      this->country = country;
  }
 const std::string& getCountry(){
      return country;
  }
  void print(std::ostream& out) {
        person::print(out);
        out << "Country: "<< country << std::endl;
    }
};
int main(void) {
    person p(123, "Matias Oliveira");
    student s(124, "Maria Oliveira", "LEIC");
    erasmus_student es(125, "John Zorn", "LEIC", "United States");
    p.print(std::cout);
    s.print(std::cout);
    es.print(std::cout);
    return 0;
}

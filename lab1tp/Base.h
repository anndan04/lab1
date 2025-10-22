#ifndef BASE_H
#define BASE_H

#include <fstream>

class Base {
public:
    virtual void Input() = 0;
    virtual void Show() const = 0;
    virtual void Edit() = 0;
   // virtual void Save(std::ofstream& out) const = 0;
   // virtual void Load(std::ifstream& in) = 0;
    virtual Base* Clone() const = 0;
    virtual ~Base() {}
};

#endif

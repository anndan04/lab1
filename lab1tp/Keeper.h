#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <string>

class Keeper {
private:
    Base** items;  
    int count;

public:
    Keeper();
    ~Keeper();
    Keeper(const Keeper& other);              
    Keeper& operator=(const Keeper& other);   

    void Add(Base* obj);
    void Remove(int index);
    void Edit(int index);
    void ShowAll() const;
    void SaveToFile(const std::string& filename) const;
    void LoadFromFile(const std::string& filename);
    int GetCount() const { return count; }
};

#endif



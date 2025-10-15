#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper {
private:
    Base** items;  
    int count;

public:
    Keeper();
    ~Keeper();

    void Add(Base* obj);
    void Remove(int index);
    void Edit(int index);
    void ShowAll() const;
    void SaveToFile(const char* filename) const;
    void LoadFromFile(const char* filename);
    int GetCount() const { return count; }
};

#endif


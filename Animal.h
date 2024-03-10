//#pragma once
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

class Animal {
private:
    float mass;
    char* sex;
    char* color;
    int age;
public:
    Animal();
    Animal(float mass, const char* sex, const char* color, int age);
    Animal(const Animal& ref);
    Animal(Animal&& ref);
    virtual ~Animal();

    float GetMass() const;
    char* GetSex() const;
    int GetAge() const;
    char* GetColor() const;

    void SetMass(float newMass);
    void SetSex(const char* newSex);
    void SetAge(int newAge);
    void SetColor(const char* newColor);

    Animal& operator=(const Animal& ref);
    Animal& operator=(Animal&& ref);

    virtual void WhatDoesSay() = 0;
    virtual void print();
};

enum class Breed {
    bulldog, labrador,
    poodle, rottweiler,
    corgi, doberman,
    yorkshireTerrier, beagle,
    dashund, germanShepherd
};

class Dog : public Animal {
private:
    char* name;
    Breed race;
public:
    Dog();
    Dog(const char* name, Breed race, float mass, const char* sex, const char* color, int age);
    Dog(const Dog& ref);
    Dog(Dog&& ref);
    ~Dog();
    
    Dog& operator=(const Dog& ref);
    Dog& operator=(Dog&& ref);

    char* GetName() const;
    char* GetRace() const;

    void SetName(const char* newName);
    void SetRace(Breed newRace);

    void WhatDoesSay() override;
    void print() override;
};

enum class TypeFox {
    redFox, capeFox,
    kitFox, swiftFox,
    islandFox, grayFox
};

class Fox: public Animal {
private:
    char* name;
    TypeFox type;
    int numberRabbitsEaten;
public:
    Fox();
    Fox(const char* name, TypeFox type, float mass, const char* sex, const char* color, int age);
    Fox(const Fox& ref);
    Fox(Fox&& ref);
    ~Fox();

    Fox& operator=(const Fox& ref);
    Fox& operator=(Fox&& ref);

    char* GetType() const;
    int GetNumberRabbitsEaten() const;
    char* GetName() const;

    void SetNumberRabbitsEaten(int newNumberRabbitsEaten);
    void SetType(TypeFox newType);
    void SetName(const char* newName);
    void Eat();

    void WhatDoesSay() override;
    void print() override;
};
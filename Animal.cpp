// Copyright 2024 Parfenov Daniil
#include "Animal.h"
#include <utility>
#include <iostream>


Animal::Animal() {
    mass = 0;
    sex = nullptr;
    color = nullptr;
    age = 0;
}

Animal::Animal(float mass, const char* sex, const char* color, int age) {
    this->mass = mass;
    this->age = age;
    int sexLength = strlen(sex) + 1;
    int colorLength = strlen(color) + 1;
    this->sex = new char[sexLength];
    snprintf(this->sex, sexLength, sex);
    this->color = new char[colorLength];
    snprintf(this->color, colorLength, color);
}

Animal::Animal(const Animal& ref) {
    this->age = ref.age;
    this->mass = ref.mass;
    int colorLength = strlen(ref.color) + 1;
    int sexLength = strlen(ref.sex) + 1;
    this->color = new char[colorLength];
    this->sex = new char[sexLength];
    snprintf(this->color, colorLength, ref.color);
    snprintf(this->sex, sexLength, ref.sex);
}

Animal::Animal(Animal&& ref): age(ref.age), mass(ref.mass) {
    this->color = std::move(ref.color);
    this->sex = std::move(ref.sex);
    ref.age = 0;
    ref.color = nullptr;
    ref.sex = nullptr;
    ref.mass = 0;
}

Animal::~Animal() {
    delete[] sex;
    delete[] color;
}

float Animal::GetMass() const {
    return mass;
}

char* Animal::GetSex() const {
    return sex;
}

int Animal::GetAge() const {
    return age;
}

char* Animal::GetColor() const {
    return color;
}

void Animal::SetMass(float newMass) {
    this->mass = newMass;
}

void Animal::SetSex(const char* newSex) {
    delete[] this->sex;
    this->sex = new char[strlen(newSex) + 1];
    snprintf(this->sex, strlen(newSex) + 1, newSex);
}

void Animal::SetAge(int newAge) {
    this->age = newAge;
}

void Animal::SetColor(const char* newColor) {
    delete[] this->color;
    this->color = new char[strlen(newColor) + 1];
    snprintf(this->color, strlen(newColor) + 1, newColor);
}

Animal& Animal::operator=(const Animal& ref) {
    if (this != &ref) {
        this->mass = ref.mass;
        this->age = ref.age;
        this->SetSex(ref.sex);
        this->SetColor(ref.color);
    }
    return *this;
}

Animal& Animal::operator=(Animal&& ref) {
    if (this != &ref) {
        this->mass = ref.mass;
        ref.mass = 0;
        this->age = ref.age;
        ref.age = 0;

        delete[] this->sex;
        this->sex = std::move(ref.sex);
        ref.sex = nullptr;

        delete[] this->color;
        this->color = std::move(ref.color);
        ref.color = nullptr;
    }
    return *this;
}

void Animal::print() {
    std::cout << "Mass: " << this->mass << '\n'
              << "Sex: " << this->sex << '\n'
              << "Age: " << this->age << '\n'
              << "Color: " << this->color << '\n';
}

Dog::Dog(): Animal() {
    name = nullptr;
    race = Breed::bulldog;
}

Dog::Dog(const char* name, Breed race, float mass, const char* sex,
         const char* color, int age): Animal(mass, sex, color, age) {
    int nameLength = strlen(name) + 1;
    this->name = new char[nameLength];
    snprintf(this->name, nameLength, name);
    this->race = race;
}

Dog::Dog(const Dog& ref):Animal(ref) {
    int nameLength = strlen(ref.name) + 1;
    this->name = new char[nameLength];
    snprintf(this->name, nameLength, ref.name);
    this->race = ref.race;
}

Dog::Dog(Dog&& ref) : Animal(std::move(ref)) {
    this->name = std::move(ref.name);
    ref.name = nullptr;
    this->race = ref.race;
}

Dog::~Dog() {
    delete[] name;
}

Dog& Dog::operator=(const Dog& ref) {
    if (this != &ref) {
        this->Animal::operator=(ref);
        this->SetName(ref.name);
        this->race = ref.race;
    }
    return *this;
}

Dog& Dog::operator=(Dog&& ref) {
    if (this != &ref) {
        this->Animal::operator=(std::move(ref));
        delete[] this->name;
        this->name = std::move(ref.name);
        ref.name = nullptr;
        this->race = ref.race;
    }
    return *this;
}

char* Dog::GetName() const {
    return name;
}

char* Dog::GetRace() const {
    char* dogRace = nullptr;
    int maxDogRaceLength = 20;
    dogRace = new char[maxDogRaceLength];
    switch (this->race) {
    case Breed::bulldog:
        snprintf(dogRace, maxDogRaceLength, "Bulldog");
        break;
    case Breed::labrador:
        snprintf(dogRace, maxDogRaceLength, "Labrador");
        break;
    case Breed::poodle:
        snprintf(dogRace, maxDogRaceLength, "Poodle");
        break;
    case Breed::rottweiler:
        snprintf(dogRace, maxDogRaceLength, "Rottweiler");
        break;
    case Breed::corgi:
        snprintf(dogRace, maxDogRaceLength, "Corgi");
        break;
    case Breed::dashund:
        snprintf(dogRace, maxDogRaceLength, "Dashhund");
        break;
    case Breed::doberman:
        snprintf(dogRace, maxDogRaceLength, "Doberman");
        break;
    case Breed::germanShepherd:
        snprintf(dogRace, maxDogRaceLength, "German Shephed");
        break;
    case Breed::beagle:
        snprintf(dogRace, maxDogRaceLength, "Beagle");
        break;
    case Breed::yorkshireTerrier:
        snprintf(dogRace, maxDogRaceLength, "Yorkshire Terrier");
        break;
    default:
        std::cout << "ERROR" << std::endl;
        break;
    }
    return dogRace;
}

void Dog::SetName(const char* newName) {
    delete[] this->name;
    this->name = new char[strlen(newName) + 1];
    snprintf(this->name, strlen(newName) + 1, newName);
}

void Dog::SetRace(Breed newRace) {
    this->race = newRace;
}

void Dog::WhatDoesSay() {
    std::cout << "Woof!";
}

void Dog::print() {
    if (this->name != nullptr) {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Breed: " << this->GetRace() << std::endl;
        this->Animal::print();
    } else {
        std::cout << "This Dog is undefined. Cannot to print" << std::endl;
    }
}

Fox::Fox():Animal() {
    this->name = nullptr;
    this->type = TypeFox::redFox;
    this->numberRabbitsEaten = 0;
}

Fox::Fox(const char* name, TypeFox type, float mass,
         const char* sex, const char* color,
         int age): Animal(mass, sex, color, age) {
    int nameLength = strlen(name) + 1;
    this->name = new char[nameLength];
    snprintf(this->name, nameLength, name);
    this->numberRabbitsEaten = 0;
    this->type = type;
}

Fox::Fox(const Fox& ref):Animal(ref) {
    this->type = ref.type;
    this->numberRabbitsEaten = ref.numberRabbitsEaten;
    this->SetName(ref.name);
}

Fox::Fox(Fox&& ref) : Animal(std::move(ref)) {
    delete[] this->name;
    this->name = std::move(ref.name);
    ref.name = nullptr;
    this->type = ref.type;
}

Fox::~Fox() {
    delete[] name;
}

Fox& Fox::operator=(const Fox& ref) {
    if (this != &ref) {
        this->Animal::operator=(ref);
        this->SetName(ref.name);
        this->type = ref.type;
        this->numberRabbitsEaten = ref.numberRabbitsEaten;
    }
    return *this;
}

Fox& Fox::operator=(Fox&& ref) {
    if (this != &ref) {
        this->Animal::operator=(std::move(ref));
        delete[] this->name;
        this->name = std::move(ref.name);
        ref.name = nullptr;
        this->type = ref.type;
        this->numberRabbitsEaten = ref.numberRabbitsEaten;
        ref.numberRabbitsEaten = 0;
    }
    return *this;
}

int Fox::GetNumberRabbitsEaten() const {
    return numberRabbitsEaten;
}

char* Fox::GetName() const {
    return name;
}

char* Fox::GetType() const {
    int maxFoxTypeLength = 15;
    char* type = new char[maxFoxTypeLength];
    switch (this->type) {
    case TypeFox::redFox:
        snprintf(type, maxFoxTypeLength, "Red Fox");
        break;
    case TypeFox::capeFox:
        snprintf(type, maxFoxTypeLength, "Cape Fox");
        break;
    case TypeFox::kitFox:
        snprintf(type, maxFoxTypeLength, "Kit Fox");
        break;
    case TypeFox::swiftFox:
        snprintf(type, maxFoxTypeLength, "Swift Fox");
        break;
    case TypeFox::islandFox:
        snprintf(type, maxFoxTypeLength, "Island Fox");
        break;
    case TypeFox::grayFox:
        snprintf(type, maxFoxTypeLength, "Gray Fox");
        break;
    default:
        delete[] type;
        return nullptr;
    }
    return type;
}

void Fox::SetNumberRabbitsEaten(int newNumberRabbitsEaten) {
    this->numberRabbitsEaten = newNumberRabbitsEaten;
}

void Fox::SetType(TypeFox newType) {
    this->type = newType;
}

void Fox::SetName(const char* newName) {
    delete[] this->name;
    int newNameLength = strlen(newName) + 1;
    this->name = new char[newNameLength];
    snprintf(this->name, newNameLength, newName);
}

void Fox::Eat() {
    this->numberRabbitsEaten++;
}

void Fox::WhatDoesSay() {
    switch (this->type) {
    case TypeFox::redFox:
        std::cout << "Ring-ding-ding-ding-dingeringeding!";
        break;
    case TypeFox::capeFox:
        std::cout << "Wa-pa-pa-pa-pa-pa-pow!";
        break;
    case TypeFox::grayFox:
        std::cout << "Hatee-hatee-hatee-ho!";
        break;
    case TypeFox::islandFox:
        std::cout << "Joff-tchoff-tchoffo-tchoffo-tchoff!";
        break;
    case TypeFox::kitFox:
        std::cout << "Jacha-chacha-chacha-chow!";
        break;
    case TypeFox::swiftFox:
        std::cout << "Fraka-kaka-kaka-kaka-kow!";
        break;
    default:
        std::cout << "WHAT DOES THE FOX SAY?";
        break;
    }
}

void Fox::print() {
    if (this->name != nullptr) {
        std::cout << "Name: " << this->name << '\n';
        std::cout << "Type: " << this->GetType() << '\n';
        std::cout << "Number of eaten rabbits: "
            << this->numberRabbitsEaten << '\n';
        this->Animal::print();
    } else {
        std::cout << "This Fox is undefined. Cannot to print" << std::endl;
    }
}

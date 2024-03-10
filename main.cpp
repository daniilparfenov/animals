// Copyright 2024 Parfenov Daniil
#include "Animal.h"
#include <iostream>
#include <cstring>


int main() {
    std::cout << "-----CLASS DOG-----" << '\n';
    // Default constructor of class Dog
    Dog undefinedDog;
    undefinedDog.print();
    std::cout << "\n\n";

    // initialization constructor of class Dog
    std::cout << "My Dog:" << '\n';
    Dog myDog("Jack", Breed::corgi, 1.5, "male", "white", 1);
    myDog.print();
    std::cout << "\n\n";

    // Copy constructor of class Dog
    Dog myFamilyDog(myDog);
    std::cout << "Copy of my Dog:" << '\n';
    myFamilyDog.print();
    std::cout << "\n\n";

    // move constructor
    Dog movingDog("move me!", Breed::bulldog, 100, "female", "orange", 25);
    std::cout << "Moving Dog:" << '\n';
    movingDog.print();
    std::cout << "\nMoving..." << '\n';
    std::cout << "\nMoved Dog:" << '\n';
    Dog movedDog(std::move(movingDog));
    movedDog.print();
    std::cout << "\nMovingDog:" << '\n';
    movingDog.print();
    std::cout << "\n\n";

    // copy operator=
    Dog copyDog("copy me!", Breed::poodle, 2.5, "male", "white", 5);
    Dog copiedDog("...", Breed::labrador, 211, "female", "brown", 1002);
    std::cout << "Dogs until copying:" << '\n';
    std::cout << "Dog 1:" << '\n';
    copyDog.print();
    std::cout << "\nDog 2:" << '\n';
    copiedDog.print();
    std::cout << "\nCopying Dog1 to Dog2..." << '\n';
    copiedDog = copyDog;
    std::cout << "\nDog 1:" << '\n';
    copyDog.print();
    std::cout << "\nDog 2:" << '\n';
    copiedDog.print();
    std::cout << "\n\n";

    // move operator=
    Dog movingDog2("Move me one more time",
                    Breed::beagle, 2, "male", "blue", 7);
    Dog movedDog2("...", Breed::labrador, 211, "female", "brown", 1002);
    std::cout << "Dogs until moving:" << '\n';
    std::cout << "Dog 1:" << '\n';
    movingDog2.print();
    std::cout << "\nDog 2:" << '\n';
    movedDog2.print();
    std::cout << "\nMoving Dog1 to Dog2..." << '\n';
    movedDog2 = std::move(movingDog2);
    std::cout << "\nDog 1:" << '\n';
    movingDog2.print();
    std::cout << "\nDog 2:" << '\n';
    movedDog2.print();
    std::cout << "\n\n";

    // Getters of class Dog
    std::cout << "The name of my dog is " << myDog.GetName() << std::endl;
    std::cout << "The color of my dog is " << myDog.GetColor() << std::endl;
    std::cout << "The sex of my dog is " << myDog.GetSex() << std::endl;
    std::cout << "The age of my dog is " << myDog.GetAge() << std::endl;
    std::cout << "The mass of my dog is " << myDog.GetMass() << std::endl;
    std::cout << "The breed of my dog is " << myDog.GetRace() << "\n\n";

    // Setters of class Dog
    std::cout << "My old dog:" << std::endl;
    myDog.print();
    std::cout << "\n";

    myDog.SetAge(2);
    myDog.SetSex("female");
    myDog.SetColor("orange");
    myDog.SetName("Milka");
    myDog.SetRace(Breed::beagle);
    myDog.SetMass(5);

    std::cout << "My new dog:" << std::endl;
    myDog.print();
    std::cout << "\n\n";

    // What does the dog say?
    std::cout << "The dog says: \"";
    myDog.WhatDoesSay();
    std::cout << "\"\n\n\n\n";


    std::cout << "-----CLASS FOX-----" << '\n';
    // Default constructor of class Fox
    Fox undefinedFox;
    undefinedFox.print();
    std::cout << "\n\n";

    // initialization constructor of class Fox
    Fox myFox("Kein", TypeFox::redFox, 1.5, "male", "white", 1);
    std::cout << "My Fox:" << '\n';
    myFox.print();
    std::cout << "\n\n";

    // Copy constructor of class Fox
    Fox myFamilyRedFox(myFox);
    std::cout << "Copy of my Fox:" << '\n';
    myFamilyRedFox.print();
    std::cout << "\n\n";

    // move constructor
    Fox movingGrayFox("move me!", TypeFox::grayFox,
                      100, "female", "orange", 25);
    std::cout << "Moving Fox:" << '\n';
    movingGrayFox.print();
    std::cout << "\nMoving..." << "\n";
    Fox movedGrayFox(std::move(movingGrayFox));

    std::cout << "\nMoving Fox:" << '\n';
    movingGrayFox.print();

    std::cout << "\nMoved Fox : " << '\n';
    movedGrayFox.print();
    std::cout << "\n\n";

    // copy operator=
    Fox copyCapeFox("copy me!", TypeFox::capeFox, 2.5, "male", "white", 5);
    Fox copiedCapeFox("...", TypeFox::swiftFox, 211, "female", "brown", 1002);
    std::cout << "Fox 1:" << '\n';
    copyCapeFox.print();
    std::cout << "\nFox 2:" << '\n';
    copiedCapeFox.print();

    std::cout << "\nCopying Fox 1 to Fox 2..." << '\n';
    copiedCapeFox = copyCapeFox;

    std::cout << "Fox 1:" << '\n';
    copyCapeFox.print();
    std::cout << "\nFox 2:" << '\n';
    copiedCapeFox.print();
    std::cout << "\n\n";

    // move operator=
    Fox movingIslandFox2("Move me one more time", TypeFox::islandFox,
                          2, "male", "blue", 7);
    Fox movedIslandFox2("...", TypeFox::swiftFox, 211, "female", "brown", 1002);
    std::cout << "Fox 1:" << '\n';
    movingIslandFox2.print();
    std::cout << "\nFox 2:" << '\n';
    movedIslandFox2.print();

    std::cout << "\nMoving Fox1 to Fox2..." << '\n';
    movedIslandFox2 = std::move(movingIslandFox2);

    std::cout << "Fox 1:" << '\n';
    movingIslandFox2.print();
    std::cout << "\nFox 2:" << '\n';
    movedIslandFox2.print();
    std::cout << "\n\n";

    // Getters of class Fox
    std::cout << "The name of my Fox is " << myFox.GetName() << std::endl;
    std::cout << "The color of my Fox is " << myFox.GetColor() << std::endl;
    std::cout << "The sex of my Fox is " << myFox.GetSex() << std::endl;
    std::cout << "The age of my Fox is " << myFox.GetAge() << std::endl;
    std::cout << "The mass of my Fox is " << myFox.GetMass() << std::endl;
    std::cout << "The type of my Fox is " << myFox.GetType() << "\n\n";

    // Setters of class Fox
    std::cout << "My old Fox:" << std::endl;
    myFox.print();
    std::cout << "\n\n";

    myFox.SetAge(2);
    myFox.SetSex("female");
    myFox.SetColor("blue");
    myFox.SetName("Redy");
    myFox.SetType(TypeFox::swiftFox);
    myFox.SetMass(5);

    std::cout << "My new Fox:" << std::endl;
    myFox.print();
    std::cout << "\n\n";

    // Rabbits
    std::cout << "My Fox ate " << myFox.GetNumberRabbitsEaten() << " rabbits";
    std::cout << '\n';
    for (int i = 0; i < 5; i++) {
        myFox.Eat();
        std::cout << "Yum!" << "\n";
    }
    std::cout << "My Fox ate ";
    std::cout << myFox.GetNumberRabbitsEaten() << " rabbits now" << "\n\n";

    // What does the Fox say?
    std::cout << "What does the Fox say?\n";
    std::cout << "My swift fox says: \"";
    myFox.WhatDoesSay();
    std::cout << "\"\n";

    std::cout << "The red fox says: \"";
    myFamilyRedFox.WhatDoesSay();
    std::cout << "\"\n";

    std::cout << "The island fox says: \"";
    movedIslandFox2.WhatDoesSay();
    std::cout << "\"\n";

    std::cout << "The cape fox says: \"";
    copiedCapeFox.WhatDoesSay();
    std::cout << "\"\n";

    std::cout << "The gray fox says: \"";
    movedGrayFox.WhatDoesSay();
    std::cout << "\"\n";

    std::cout << "The kit fox says: \"";
    Fox kitFox("kit", TypeFox::kitFox, 12, "male", "yellow", 11);
    kitFox.WhatDoesSay();
    std::cout << "\"\n";

    return 0;
}

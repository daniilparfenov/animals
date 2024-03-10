#include "Animal.h"
#include <iostream>
#include <string.h>



int main()
{
	std::cout << "-----CLASS DOG-----" << '\n';
	// Default constructor of class Dog
	Dog undefinedDog;

	// initialization constructor of class Dog
	Dog myDog("Jack", Breed::corgi, 1.5, "male", "white", 1);

	// Copy constructor of class Dog
	Dog myFamilyDog(myDog);

	// move constructor
	Dog movingDog("move me!", Breed::bulldog, 100, "female", "orange", 25);
	Dog movedDog(std::move(movingDog));

	// copy operator=
	Dog copyDog("copy me!", Breed::poodle, 2.5, "male", "white", 5);
	Dog copiedDog("...", Breed::labrador, 211, "female", "brown", 1002);
	copiedDog = copyDog;

	// move operator=
	Dog movingDog2("Move me one more time", Breed::beagle, 2, "male", "blue", 7);
	Dog movedDog2("...", Breed::labrador, 211, "female", "brown", 1002);
	movedDog2 = std::move(movingDog2);

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
	std::cout << '\n';

	myDog.SetAge(2);
	myDog.SetSex("female");
	myDog.SetColor("orange");
	myDog.SetName("Milka");
	myDog.SetRace(Breed::beagle);
	myDog.SetMass(5);

	std::cout << "My new dog:" << std::endl;
	myDog.print();
	std::cout << '\n';

	// What does the dog say?
	std::cout << "The dog says: \"";
	myDog.WhatDoesSay();
	std::cout << "\"\n\n\n";


	std::cout << "-----CLASS FOX-----" << '\n';
	// Default constructor of class Fox
	Fox undefinedFox;

	// initialization constructor of class Fox
	Fox myFox("Kein", TypeFox::redFox, 1.5, "male", "white", 1);

	// Copy constructor of class Fox
	Fox myFamilyRedFox(myFox);

	// move constructor
	Fox movingGrayFox("move me!", TypeFox::grayFox, 100, "female", "orange", 25);
	Fox movedGrayFox(std::move(movingGrayFox));

	// copy operator=
	Fox copyCapeFox("copy me!", TypeFox::capeFox, 2.5, "male", "white", 5);
	Fox copiedCapeFox("...", TypeFox::swiftFox, 211, "female", "brown", 1002);
	copiedCapeFox = copyCapeFox;

	// move operator=
	Fox movingIslandFox2("Move me one more time", TypeFox::islandFox, 2, "male", "blue", 7);
	Fox movedIslandFox2("...", TypeFox::swiftFox, 211, "female", "brown", 1002);
	movedIslandFox2 = std::move(movingIslandFox2);

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
	std::cout << '\n';

	myFox.SetAge(2);
	myFox.SetSex("female");
	myFox.SetColor("blue");
	myFox.SetName("Redy");
	myFox.SetType(TypeFox::swiftFox);
	myFox.SetMass(5);

	std::cout << "My new Fox:" << std::endl;
	myFox.print();
	std::cout << '\n';

	// Rabbits
	std::cout << "My Fox ate " << myFox.GetNumberRabbitsEaten() << " rabbits" << '\n';
	for (int i = 0; i < 5; i++)
	{
		myFox.Eat();
		std::cout << "Yum!" << '\n';
	}
	std::cout << "My Fox ate " << myFox.GetNumberRabbitsEaten() << " rabbits now" << "\n\n";

	// What does the Fox say?
	std::cout << "What does the Fox say?\n";
	std::cout << "My swift fox says:\"";
	myFox.WhatDoesSay(); 
	std::cout << "\"\n";

	std::cout << "The red fox says:\"";
	myFamilyRedFox.WhatDoesSay(); 
	std::cout << "\"\n";

	std::cout << "The island fox says:\"";
	movedIslandFox2.WhatDoesSay(); 
	std::cout << "\"\n";

	std::cout << "The cape fox says:\"";
	copiedCapeFox.WhatDoesSay(); 
	std::cout << "\"\n";

	std::cout << "The gray fox says:\"";
	movedGrayFox.WhatDoesSay(); 
	std::cout << "\"\n";

	std::cout << "The kit fox says:\"";
	Fox kitFox("kit", TypeFox::kitFox, 12, "male", "yellow", 11);
	kitFox.WhatDoesSay(); 
	std::cout << "\"\n";

	return 0;
}
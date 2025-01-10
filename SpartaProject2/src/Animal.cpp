#include<iostream>
using namespace std;

// 1.

class Animal {
public:
	virtual ~Animal(){}
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	~Dog() {
		cout << "Dog out\n";
	}
	void makeSound()
	{
		cout << "Woof!\n";
	}
};

class Cat : public Animal {
	~Cat() {
		cout << "Cat out\n";
	}
	void makeSound()
	{
		cout << "Meow!\n";
	}
};

class Cow : public Animal {
	~Cow() {
		cout << "Cow out\n";
	}
	void makeSound()
	{
		cout << "Moo!\n";
	}
};

class Zoo {
private:
	Animal** animals;
	int size;		// 동물원크기
	int count;		// 동물수			
public:
	Zoo(int size) : size(size), count(0) {
		animals = new Animal*[size];
	}
	~Zoo() {
		cout << "==================================================\n";

		for (int i = 0; i < count; i++) {
			if (animals[i] != nullptr) {
				delete animals[i];
			}
		}

		cout << "==================================================\n";
		cout << "동물원 닫음\n";

		delete animals;
	}	
	void addAnimal(Animal* animal) {
		if (size < count + 1) {			
			cout << "동물원이 가득찼습니다.\n";
		}
		else {
			animals[count] = animal;
			count++;
			cout << "동물원 크기: " << size << " 현재 동물 수: " << count << "\n";
		}
	}
	void performActions() {
		for (int i = 0; i < count; i++) {
			animals[i]->makeSound();
		}
	};
};

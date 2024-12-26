#include <iostream>
#include <random>
#include <crtdbg.h>		// 메모리누수확인
#include "Animal.cpp"

#if _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#define malloc(s) _malloc_dbg(s,_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

using namespace std;

Animal* createRandomAnimal() {
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, 2);

	int index = distribution(generator);
	
	Animal* animal;

	// Dog : 0 / Cat : 1 / Cow : 2
	switch (index)
	{
	case 1:
		animal = new Cat();
		break;
	case 2:
		animal = new Cow();
		break;
	default:
		animal = new Dog();
		break;
	}

	return animal;
}

int main()
{	
	Animal* animals[3];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Cow();

	for (Animal* item : animals) {
		item->makeSound();
	}

	for (Animal* item : animals) {
		delete item;
	}

	cout << "==================================================\n";

	int zooAnimalCount = 10; // 동물수
	int zooSize = 10; // 동물원 크기

	if (zooAnimalCount > zooSize) {
		cout << "동물 수 초과\n";
		return 0;
	}

	{
		Zoo zoo(zooSize);
		while (zooAnimalCount != 0) {
			zoo.addAnimal(createRandomAnimal());
			zooAnimalCount--;
		}

		cout << "==================================================\n";

		zoo.performActions();
	}

	-_CrtDumpMemoryLeaks();
	return 0;
}
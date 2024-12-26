#include <iostream>
#include <random>
#include <crtdbg.h>		// �޸𸮴���Ȯ��
#include "Animal.h"

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
	int zooAnimalCount = 10; // ������
	int zooSize = 10; // ������ ũ��

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
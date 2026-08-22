#include <iostream>
#include <string>

class Pet {
  protected:
    std::string Name;

  public:
    Pet(std::string n) {
        Name = n;
    }
    void Run(void) {
        std::cout << Name << ": I'm running" << std::endl;
    }
};

class Dog : public Pet {
  public:
    Dog(std::string n) : Pet(n) {};
    void MakeSound(void) {
        std::cout << Name << ": Woof! Woof!" << std::endl;
    }
};

class Cat : public Pet {
  public:
    Cat(std::string n) : Pet(n) {};
    void MakeSound(void) {
        std::cout << Name << ": Meow! Meow!" << std::endl;
    }
};

int main(void) {
    Pet* a_pet1 = new Cat("Tom");
    Pet* a_pet2 = new Dog("Spike");
    a_pet2->Run();
    static_cast<Cat*>(a_pet2)->MakeSound();
    a_pet1->Run();
    static_cast<Dog*>(a_pet1)->MakeSound();

    // TODO 1. static_cast above performs no runtime check, so it happily
    // reinterprets a_pet2 (really a Dog) as a Cat* and vice versa, producing
    // the wrong sound for each pet. Try replacing both static_cast calls with
    // dynamic_cast and compare: what does dynamic_cast return for a mismatched
    // pointer type, and what would you need to add to Pet for dynamic_cast to
    // work at all? Also compare against const_cast and reinterpret_cast — are
    // either of those viable substitutes here, and why or why not?
    return 0;
}

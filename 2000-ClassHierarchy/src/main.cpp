#include <iostream>

class Super {
  public:
    void print_public();

  protected:
    void print_protected();

  private:
    void print_private();
};

void Super::print_public() {
    std::cerr << "calling print_public";
}

void Super::print_protected() {
    std::cerr << "calling print_protected";
}

void Super::print_private() {
    std::cerr << "calling print_private";
}

/**
 * With private inheritance all public Super's components turn into private access
 * and private Super's components aren't accessible in any case
 */
class PrivateInheritanceChild : Super {
  public:
    PrivateInheritanceChild();
};

PrivateInheritanceChild::PrivateInheritanceChild() {
    print_public();

    print_protected();

    // Private Super's methods aren't accessible
    // print_private();
}

/**
 * With public inheritance all public Super's components preserve their access policy
 * and private Super's components aren't accessible anyway.
 */
class PublicInheritanceChild : public Super {
  public:
    PublicInheritanceChild();
};

PublicInheritanceChild::PublicInheritanceChild() {
    print_public();

    print_protected();

    // Private Super's methods aren't accessible
    // print_private();
}

int main() {
    PrivateInheritanceChild child1;
    // Super's public methods become private on a Child class with the default visibility modifier
    // ps.print_public();

    PublicInheritanceChild child2;
    // Super's protected preserves protected policy
    // child2.print_protected();
    child2.print_public();

    std::cout << "done\n";
    return 0;
}

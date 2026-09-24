#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

// Defines void level() -- it always throws a std::string.
void level() {
    throw std::string("a runtime exception");
}

// Defines void function() noexcept -- it calls level(). Because
//   function() is declared noexcept, any exception that tries to leave
//   it -- including one thrown deeper inside level() -- triggers
//   std::terminate() immediately, instead of unwinding further up the
//   call stack looking for a handler.
void function() noexcept {
    level(); // - actually throws which in conjunction with 'noexcept' modifier triggers std::terminate() immediately
}

// Defines void lastgchance() -- the handler passed to
//   std::set_terminate(). It matches std::terminate_handler: a
//   parameterless function returning void. Prints a diagnostic message
//   via std::cout, flushed with std::endl rather than "\n" -- the
//   std::abort() that follows does not flush buffered stdout, so an
//   unflushed message would be lost. Then calls std::abort() explicitly;
//   returning normally from a terminate handler is undefined behavior.
void lastgchance() { // should be 'terminate_handler = void (*)();'
    std::cout << "An exception escaped a noexcept function. Terminating." << std::endl;
    std::cout.flush(); // we have to flush explicitly as termination won't flush std::cout
    std::abort(); // we have to call std::abort explicitly
}

int main() {
    // Calls std::set_terminate(lastgchance); before anything can
    //   throw, so the custom handler is installed in time.

    // Wraps a call to function() in a try block, with a
    //   catch (const std::string&) clause that prints "Caught! ". This
    //   catch clause never runs -- function()'s noexcept violation calls
    //   std::terminate() before unwinding ever reaches it.
    // Output:
    // An exception escaped a noexcept function. Terminating.
    // (the program then aborts abnormally; "Caught!" never prints)
    std::set_terminate(lastgchance);

    try {
        function();
    } catch (const std::string& exc) {
        std::cout << "Caught! " << exc  << "\n";
    }


    return 0;
}

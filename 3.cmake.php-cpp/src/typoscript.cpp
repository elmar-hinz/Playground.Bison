/**
 *  Default Cpp libraries
 */

#include <string>
#include <iostream>

/**
 *  Our own library.
 */
#include <phpcpp.h>

/**
 *  Namespace to use
 */
using namespace std;

Php::Value hello(Php::Parameters &params)
{
    string first = params[0];
    string last = params[1];
    return first + "  " + last;
}

Php::Value sumAll(Php::Parameters &parameters)
{
    int result = 0;
    for(Php::Value &param : parameters) result += param;
    return result;
}

// Symbols are exported according to the "C" language
extern "C"
{
    // export the "get_module" function that will be called by the Zend engine
    PHPCPP_EXPORT void *get_module()
    {
        // create extension
        static Php::Extension extension("elmars", "1.0");
        extension.add("hallo", hello, {
            Php::ByVal("firstname", Php::Type::Numeric),
            Php::ByVal("lastname", Php::Type::String)
        });
        extension.add("sum_all", sumAll);
        // return the extension module
        return extension.module();
    }
}

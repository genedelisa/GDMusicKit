/** @example NoteExample.cpp
 * This is an example of how to use the Note class.
 * More details about this example.
 */

#include <gdmusickit/gdmusickit.h>
#include <iostream>

using namespace gdmusickit;
using std::cout;
using std::endl;

int main() {

    Note n{"C5"};
    cout << n << endl;
    return EXIT_SUCCESS;
}
#include <iostream>
#include "../inc/Monitor.h"
#include "../inc/Monitor2.h"

/**
 * OBSERVATION:
 *      Throws Segmentation fault (core dumped) at every cout 
 *  (I realized that by debbuging and commenting every cout thet threw the error).
 *  The monitor2 object is global, so its constructor (and new Monitor()'s, of course) is called
 *  before main(). But does it get called before the #include <iostream> in monitor.cpp?
 *  This is the only reason, I can think of, why it would throw an error.
 *
 * SOLUTION:
 *      I included the <iostream> header file in main.cpp explicitly and it seems to have fixed the problem
 * 
 * ANSWER:
 *      I found an answer: 
 *  "Looks like typical problem with static initialization order (i.e., cout hasn't been constructed yet)"
 *      But then I found this: 
 *  "libstdc++ ensures that cin/cout/cerr are constructed before they are used, but the scheme fails
 *  when using constructor priorities. Constructors with a priority are run before constructors without a
 *  priority, which is the appropriate behaviour."
 * 
 *  CONCLUSION:
 *      From the previous statements I can conclude this is a static initialization order error,
 *  but I can't understand why it occurs if cout has priority initialisation
 */

Monitor2 monitor2(new Monitor());

int main() { return 0; }
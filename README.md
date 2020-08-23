# CS210-C-

The program displays two different clocks within the console window (12hr and 24hr) the clocks will begin keeping time until
the user presses a key. In this case, a menu will load allowing to user to add an hour,minute or second to the clock. After 
this, the clock will begin counting again.

Rather than use objects and classes, I've created a heircherial pass-by-refrence chain. Since minutes become seconds and seconds become hours
first function as to have all necessary variables. As they are passeed, a parameter is peeled off. This prvents us from accidentally modifying
something we don't want to. Even with private object data, we could still possibly modify something. If the pass-by-refrence chain, a function
can only modify the variables that it was passed, anything else will throw a compilation error.

The code isn't multithreaded, so the clocks stop keeping time when the menu is up. This isn't necessarily a problem but could be fixed by
running the clock in an independant thread. The code uses windows.h to track keypress and use the sleep functions, this is probably the
only protability issue.

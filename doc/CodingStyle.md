Coding Style
============

Preface
-------

Coding style is a very personal set of decisions to make, and
everything in this document is just my personal views and what
I use in my own projects. This is just a document describing
what I would like to see for any of my projects. It's based
somewhat on the Linux kernel coding style, but with some
modifications.

Part I: Indentation
-------------------
Indentations are 8 characters, and tabs are to be replaced
with spaces.

Part II: Placing Braces
-----------------------
Braces are to be done the way Brian Kernighan and Dennis Ritchie
shown: place the opening brace last on the line, and put the closing
brace first, thusly:
        
        if (x is true) {
                we do y
        }

This behavier is also done with functions, even though they cannot
be nested:

        int main(int argc, char *argv[]) {
                function_definition();
        }

When writing do-while statements or else statements, wrap them:

        do {
                do_a_do();
        } while (condition);

        .
        .

        if (x == y) {
                ..
        } else if (x > y) {
                ..
        } else {
                ..
        }

Part III: Naming
----------------
Long and descriptive variable/function names are frowned upon, unless
they are for global variables.

Global variables need to have descriptive
names, as do global functions. The return type should not be included;
the compiler knows what the return type is and can check those.

Local variable names should be short, and to the point. I.e. calling
a temporary, for-loop variable "loop_counter" isn't productive.

Part IV: Functions
------------------
Functions should be short, and do one and only one thing. If a function
you're writing has does something and immediately use the data to do
something else, you're writing functions wrong. The ideal function
should only contain 5-10 local variables.

Part V: Commenting
------------------
Comments are good, but there is also a danger of over-commenting. If
you have to explain how your code works, you did something wrong.
Comment on what a function/class/variable is there for in the first
place, not how the code uses it. If your code is so complex it requires
unusally high levels of comments, see Part IV.

Sidenotes
---------
If using GNU Emacs or something similar that automatically formats code,
format the code yourself. Also, make sure the code actually builds
*before* sending patches.

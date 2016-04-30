2016 04 30:

Created the project directory

Copied the file from: https://en.wikipedia.org/wiki/GNU_bison

    * Expression.c
    * Expression.h
    * Lexer.l
    * Makefile
    * Parser.y
    * main.c

Bison complains. The OS X version 2.3. is to old for "%code" syntax.

Installing bison 3.0.4 with Homebrew. It's keg only. The Makefile won't
work without appropriate symlinks, but the manual build of the file
works with the full file path.

Installing flex and gcc with homebrew.

* I need to call g++-5 in the Makefile.
* brew link --force flex
* brew link --force bison

Now I can compile an run the "test" file.



# minishell
42 School - Level03

A simple shell referencing bash

## Features

+ `'` (single quote) and `"` (double quote) handling
+ `<` `>` `>>` (redirection) and `<<` (here-doc)
+ `|` (pipes)
+ environment variables (`$` followed by a sequence of characters) and `$?`
+ signals: `ctrl + c` `ctrl + d` `ctrl + \`
+ builtin commands:
    + `echo` (with option -n)
    + `cd` (relative or absolute path)
    + `pwd` (no options)
    + `export` (no options)
    + `unset` (no options)
    + `env` (no options or arguments)
    + `exit` (no options)

## Usage

`make` compiles the program.

To run the shell simply type
```
$ ./minishell
```
To exit the shell you can either `ctrl + d` or type
```
$ exit
```

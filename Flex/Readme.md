#### Flex bonus exercise
A simple JohnLang lexical analyser
(as described [here](../Lexical-Analysis__Lab-1-and-2/main.cpp))
implemented using Flex.
<br>
<br>
Tested on Ubuntu

To run:
```
flex -+ helloFlex.l
g++ lex.yy.cc -o johnlang
./johnlang < source.jl
```
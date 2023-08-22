# Printf

A function that can :

- Print a string includes any other types using specific identifiers
- Take an infinite number of arguments

# Prototype

int printf(char *format, arg1, arg2, ...);

# Formats of The specific identifiers

Write The '%' character followded by one of the following characters :

- c -> print a character
- s -> print a string
- i -> print an interger
- f -> print a double or a float
- x -> print a number in hexadecimal (base 16)
- % -> print the '%' character ('\%' can do the same)
- ..., etc. (use man printf to see the other characters)
# Escape character '\\'

There is some identifiers used to do specific functions and to access them
write The '\\' character followded by one of the following characters :

- n -> new line
- t -> multiblie spaces
- ..., etc. (use man printf to see the other characters)

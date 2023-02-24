# Vishwa Venkateshwaran

# Makefile for lab 2.

#change the last dependency for each new lab
all: lab2encrypt lab2decrypt lab2encryptmangled lab2.zip

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab2encrypt: lab2encrypt.o
	gcc -g -o $@ $^

lab2decrypt: lab2decrypt.o
	gcc -g -o $@ $^

lab2encryptmangled: lab2encryptmangled.o
	gcc -g -o $@ $^

#this is where you create an entry to build your zip file
#it will also update with new labs
lab2.zip: makefile *.c *.h lab2readme *.in *.out
	zip lab2.zip makefile *.c *.h lab2readme *.in *.out

# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@


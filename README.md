# look-and-say
Convert the parameter to and from a look-and-say sequence

The resulting executable is called like this:
lookandsay -l 2514 or lookandsay -r 2514
where -l converts the parameter to a look-and-say sequence and -r converts the parameter to the
number it reflects and prints the result.

How to build?
1. Create folder 'build'.
2. Open CMake (any 3.XX should do).
3. Choose folder 'src' for the source code.
4. Choose folder 'build' for built binaries location.
5. Click Generate.
	Note: gcc compiler is enough for compiling the code.
	Note: we use Unix makefiles.
6. If generation is successful then open the folder 'build' and run command 'make'.
The executable 'lookandsay' is now ready for usage as described above.

How to test?
1. Go to 'build'.
2. Execute './test' from command line if using bash or 'test' if using Command Prompt.
3. The test results should be printed.

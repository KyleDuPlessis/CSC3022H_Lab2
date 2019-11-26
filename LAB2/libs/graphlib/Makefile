# DPLKYL002
# Makefile in /libs/graphlib folder to compile a shared library

CPP=g++
CPPFLAGS=-fPIC -shared -std=c++11
LIBNAME=libgraph.so

# first compile - create binary object files
%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)

# then link - link binary object files together to create the shared library
$(LIBNAME): Graph.o Graph.h
	$(CPP) -o $(LIBNAME) Graph.o $(CPPFLAGS)

# other rules
# never submit binary object / shared object files
clean:
	@rm *.o *.so

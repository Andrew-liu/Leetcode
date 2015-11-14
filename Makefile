# find all .h in ../Boost(format: vpath <pattern> <directories>) vpath %.h ../Boost
# search path : VPATH = src:../Boost
objects = RomanToInteger.o

test : $(objects)
	g++ -o test $(objects)

$(objects) : 

# RomanToInteger.o : 

.PHONY : clean
clean : 
	-rm test $(objects)

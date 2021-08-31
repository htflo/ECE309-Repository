# just type make at command line and all four files will compile.
# >> make
# g++ -o swap swap.cpp 
# g++ -o ref ref.cpp 
# g++ -o new new.cpp 
# g++ -o streams streams.cpp 
#
EXE = complex 

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	g++ -o $@ $< 

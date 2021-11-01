# just type make at command line and all four files will compile.
# >> make
#
EXE = list_ex 

all: $(EXE)

test: all

clean:
	rm -f $(EXE) *~ logfile.txt

%: %.cpp
	g++ -o $@ $< -std=c++11

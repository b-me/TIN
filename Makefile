.DEFAULT = all
.PHONY = clean

all: 
	mkdir -p build
	cd build; cmake .. && $(MAKE)
	
clean:
	rm -rf build
test:
	./build/bin/runTests

build:
	mkdir -p bin
	g++ core/*.cpp include/*.h -o bin/out
run:
	./bin/out
install:
clean:
	rm bin/out

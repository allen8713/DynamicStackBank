# Compile driver.cpp for Stack testing
a.out: src/driver.cpp
	g++ src/driver.cpp -o a.out

# Compile main.cpp for Bank system
b.out: src/main.cpp src/account.cpp src/bank.cpp
	g++ src/main.cpp src/account.cpp src/bank.cpp -o b.out

# Clean executables
clean:
	rm -f a.out b.out


#########################
# DO NOT EDIT THIS FILE #
#########################

# But please, feel free to inspect the targets and design for your own learning.

#
CC := g++
CFLAGS := -Wall -Werror -pedantic -g -c -std=c++17
LINKFLAGS := -Wall -Werror -pedantic -g -std=c++17


#
DEPS_PUHP := $(wildcard puhp-tests/*)


# Binary names
BIN_NAME := main
BIN := ./$(BIN_NAME)
#
BIN_TESTS_NAME := main-tests
BIN_TESTS := ./$(BIN_TESTS_NAME)
#
BIN_LEAK_CHECKER_NAME := leak-checker
BIN_LEAK_CHECKER = ./$(BIN_LEAK_CHECKER_NAME)

#
default:	help


#
help:
	@echo "***** Makefile Menu *****"
	@echo
	@echo "make build         ==> Build source files"
	@echo "make run           ==> Run the book store"
	@echo "make run-sim       ==> Run the book store with some simulated data"
	@echo "make debug         ==> Debug the book store with gdb"
	@echo
	@echo "make test          ==> Run tests against your book store"
	@echo "make debug-test    ==> Debug the tests run against your book store"
	@echo
	@echo "make clean         ==> Clean temporary build files"


#
build:	$(BIN) $(BIN_TESTS)
.PHONY: build


#
run:	$(BIN)
	$(BIN)
.PHONY: run


#
run-sim:	$(BIN)
	@echo -ne " \
		\n1\n12345\nBook1\nAuthor1\n200\n10\n `# Add Book 1` \
		\n1\n12346\nBook2\nAuthor2\n100\n17\n `# Add Book 2` \
		\n1\n12347\nBook3\nAuthor3\n275\n11\n `# Add Book 3` \
		\n2\n `# Print inventory` \
		\n1\n12345\n175\n1\n `# Add another of Book 1 (total 11)` \
		\n2\n `# Print inventory again` \
		\n3\n12347\n2000\n7 `# Customer purchases some copies of Book 3` \
		\n2\n `# Print inventory again` \
		\n3\n12347\n2000\n7 `# Customer tries to purchase too many copies of Book 3 (should fail)` \
		\n3\n12347\n2000\n4 `# Customer purchases exactly as many copies as are left` \
		\n2\n `# Print inventory again` \
		\nq\n `# Quit`" \
		| $(BIN) `# Pipe to the main program`
.PHONY: run-sim


#
debug:	$(BIN)
	gdb $(BIN) -ex run
.PHONY: debug


#
gradescope: clean
gradescope:	test
tests:		test
test:		$(BIN_TESTS) $(BIN_LEAK_CHECKER)
	$(BIN_TESTS)
.PHONY: gradescope tests test


#
debug-tests:		debug-test
debug-test:	$(BIN_TESTS) $(BIN_LEAK_CHECKER)
	gdb $(BIN_TESTS) -ex run
.PHONY: debug-tests debug-test


#
$(BIN):	main.o BookStore.o Book.o
	$(CC) $(LINKFLAGS) $^ -o $@


#
$(BIN_TESTS):	CPP_Tests.o BookStore.o Book.o
	$(CC) $(LINKFLAGS) $^ -o $@


# Link the leak checker binary
$(BIN_LEAK_CHECKER):	leak_checker.o
	$(call say,Building: "$@")
	$(CC) $(LINKFLAGS) $^ -o "$@"


#
main.o:	main.cpp DoublyLinkedList.hpp BookStore.hpp Book.hpp DoublyLinkedList.hpp
	$(CC) $(CFLAGS) $< -o $@


#
CPP_Tests.o:	CPP_Tests.cpp DoublyLinkedList.hpp BookStore.hpp Book.hpp DoublyLinkedList.hpp $(DEPS_PUHP)
	$(CC) $(CFLAGS) $< -o $@


#
BookStore.o:	BookStore.cpp BookStore.hpp Book.hpp DoublyLinkedList.hpp
	$(CC) $(CFLAGS) $< -o $@


#
Book.o:			Book.cpp Book.hpp
	$(CC) $(CFLAGS) $< -o $@


#
leak_checker.o:	leak_checker.cpp DoublyLinkedList.hpp
	$(CC) $(CFLAGS) "$<" -o "$@"


#
clean:
	-rm *.o
	-rm *.gch
	-rm $(BIN)
	-rm $(BIN_TESTS)
	-rm $(BIN_LEAK_CHECKER)
	-rm results*.json
.PHONY: clean










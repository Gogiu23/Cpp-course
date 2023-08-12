#Makefile generator authomatic by Gogiu23
#MIT license
CXX = g++-13
CFLAGS = -Wall -Werror -Wextra
BINDIR = bin


SRC_FILE :=

BIN :=

check_bindir:
	@if [[ ! -d "${BINDIR}" ]]; then \
		mkdir -p "${BINDIR}";\
	fi

all: check_bindir generate

generate:
	$(CXX) $(CFLAGS) $(SRC_FILE) -o "$(BINDIR)/$(basename $(SRC_FILE))"

e:
	@./$(BINDIR)/$(basename $(SRC_FILE))

clean:
	rm -rf $(BINDIR)/$(basename $(SRC_FILE))

.PHONY: all clean e

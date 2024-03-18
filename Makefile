# Uncomment lines below if you have problems with $PATH
#SHELL := /bin/bash
#PATH := /usr/local/bin:$(PATH)

all:
	pio -f -c vim run -e release && pio -f -c vim run -e release --target upload
debug:
	pio -f -c vim run -e debug && pio -f -c vim run -e debug --target upload
build:
	pio -f -c vim run -e release
build-debug:
	pio -f -c vim run -e debug
upload:
	pio -f -c vim run --target upload
upload-debug:
	pio -f -c vim run -e debug --target upload
clean:
	pio -f -c vim run --target clean
generate:
	stm32pio generate
program:
	pio -f -c vim run --target program
uploadfs:
	pio -f -c vim run --target uploadfs
update:
	pio -f -c vim update -e release
compiledb:
	pio -f -c vim run --target compiledb

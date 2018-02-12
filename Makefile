all:
	@ninja -C build

.PHONY : test
test :
	@ninja -C build test

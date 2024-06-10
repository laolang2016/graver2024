export MAKE = make -w

ALL:run

.PHONY: build_lib configure build run rerun test retest clean format tidy doc

build_lib:
ifeq ($(OS), Windows_NT)
	mkdir -p build/ninja-release/dist/bin
	mkdir -p build/ninja-debug/dist/bin
	@$(MAKE) -C lib/lua
else
	mkdir -p build/ninja-release/dist/lib
	mkdir -p build/ninja-debug/dist/lib
	@$(MAKE) -C lib/lua
endif

configure:
ifeq ($(OS), Windows_NT)
	cmake --preset=windows-release
else
	cmake --preset=linux-release
endif

build: build_lib configure
ifeq ($(OS), Windows_NT)
	cmake --build --preset=windows-release
else
	cmake --build --preset=linux-release
endif

run: build
	cd build/ninja-release/dist/bin && ./graver

rerun:clean run

test: build
	cd build/ninja-release/dist/test && ./graver_test

retest: clean test

clean:
	rm -rf build

format:
	find src -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -style=file:.clang-format -i {} \;
	find include -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -style=file:.clang-format -i {} \;
	find test -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -exec clang-format -style=file:.clang-format -i {} \;
	cmake-format -c .cmake-format.py -i CMakeLists.txt
	cmake-format -c .cmake-format.py -i src/CMakeLists.txt
	cmake-format -c .cmake-format.py -i src/app/CMakeLists.txt
	cmake-format -c .cmake-format.py -i src/config/CMakeLists.txt
	cmake-format -c .cmake-format.py -i src/util/CMakeLists.txt
	cmake-format -c .cmake-format.py -i test/CMakeLists.txt

tidy: build format
	find src     -type f -name "*.cpp" -print0 | xargs -0 clang-tidy --config-file=.clang-tidy -p=build/ninja-release --quiet 
	find include -type f -name "*.h"   -print0 | xargs -0 clang-tidy --config-file=.clang-tidy -p=build/ninja-release --quiet
	find test    -type f -name "*.cpp" -print0 | xargs -0 clang-tidy --config-file=.clang-tidy -p=build/ninja-release --quiet



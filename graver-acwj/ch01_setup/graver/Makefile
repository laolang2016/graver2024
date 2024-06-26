ALL:run


.PHONY:configure build run rerun clean format tidy doc

configure:
ifeq ($(OS), Windows_NT)
	cmake --preset=windows-release
else
	cmake --preset=linux-release
endif

build: configure
ifeq ($(OS), Windows_NT)
	cmake --build --preset=windows-release
else
	cmake --build --preset=linux-release
endif

run:build
	cd build/ninja-release/dist/bin && ./graver -l -i test.graver

rerun:clean run

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



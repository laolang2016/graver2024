ALL: after_build

.PHONY: configure build clean after_build

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

after_build: build

ifeq ($(OS), Windows_NT)
	cp build/ninja-release/liblua.dll ../../build/ninja-release/dist/bin/
	cp build/ninja-release/liblua.dll ../../build/ninja-debug/dist/bin/
else
	cp build/ninja-release/liblua.so ../../build/ninja-release/dist/lib/
	cp build/ninja-release/liblua.so.* ../../build/ninja-release/dist/lib/
	cp build/ninja-release/liblua.so ../../build/ninja-debug/dist/lib/
	cp build/ninja-release/liblua.so.* ../../build/ninja-debug/dist/lib/
endif

clean:
	rm -rf build



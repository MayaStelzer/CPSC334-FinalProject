build:
	cmake -S . -B build
	cmake --build build

test:
	cd build && ctest

lint:
	clang-tidy PA3.cpp Main.cpp -- -std=c++17

docker-build:
	docker build -t pa3-project .

docker-run:
	docker run --rm pa3-project

clean:
	rm -rf build

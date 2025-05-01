FROM ubuntu:22.04

# Install build tools and dependencies
RUN apt-get update && apt-get install -y \
  build-essential \
  cmake \
  clang-tidy \
  git \
  libgtest-dev \
  && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN cmake -S . -B build && cmake --build build

CMD ["./build/runPA3"]

FROM ubuntu:20.04

# Avoid interaction prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    libgtest-dev \
    && apt-get clean

# GTest needs to be manually built on Ubuntu
RUN cd /usr/src/gtest && \
    cmake . && make && \
    cp lib/*.a /usr/lib

# Create app directory
WORKDIR /app

# Copy all files
COPY . .

# Build the project using CMake
RUN cmake -S . -B build && cmake --build build

# Run the tests
CMD ["./build/tests"]

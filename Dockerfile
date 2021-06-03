# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu:20.04
RUN apt update && apt -y install build-essential make gcc

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /app
WORKDIR /app

# This command compiles your app using make, adjust for your source code
RUN make /app

# This command runs your application, comment out this line to compile only
CMD ["./bin/main"]
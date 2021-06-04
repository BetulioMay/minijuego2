# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM ubuntu:20.04

# These commands copy your files into the specified directory in the image
# and set that as the working location
RUN mkdir /app
COPY . /app
WORKDIR /app

RUN apt-get update && apt-get -y install curl apt-utils

# This command compiles your app using make, adjust for your source code

CMD ["bash install.sh"]

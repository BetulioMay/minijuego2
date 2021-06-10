# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:latest
ENV TZ=Europe/Madrid
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /app
WORKDIR /app

RUN apt-get update && apt-get -y install curl apt-utils
RUN bash install.sh
RUN make
# This command compiles your app using make, adjust for your source code

CMD ["./bin/main", "1"]

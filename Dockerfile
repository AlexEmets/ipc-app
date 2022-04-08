FROM ubuntu:20.04

RUN apt-get update && \
    apt-get -y install gcc mono-mcs vim && \
    apt install -y build-essential cmake


# docker build --tag ubuntu_basic . \
# docker run --rm -it --mount type=bind,source=%cd%\,target=/home/ipc-app ubuntu_basic
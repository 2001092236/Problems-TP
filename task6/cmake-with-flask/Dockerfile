FROM ubuntu:latest

WORKDIR /app

RUN groupadd --gid 2000  techproguser\
  && useradd --uid 2000 --gid techproguser --shell /bin/bash --create-home techproguser

ADD . /app

WORKDIR build

RUN apt-get update && apt-get upgrade -y && apt-get install -y cmake g++ python3 python3-pip
RUN
RUN pip install flask
RUN cmake ..
RUN make


WORKDIR /app
USER techproguser
EXPOSE 5000
CMD python app.py --port 5000 --host "0.0.0.0"
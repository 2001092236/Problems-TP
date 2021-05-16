FROM python:3.6

RUN groupadd --gid 2000  techproguser\
  && useradd --uid 2000 --gid techproguser --shell /bin/bash --create-home techproguser

WORKDIR /app
ADD . /app

WORKDIR build

RUN apt-get update && apt-get install -y cmake
RUN cmake ..
RUN make

WORKDIR /app
USER techproguser
EXPOSE 5000
RUN pip install flask
CMD python app.py --port 5000 --host "0.0.0.0"
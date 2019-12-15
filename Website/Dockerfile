FROM python:3

WORKDIR /usr/src/app

COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt

COPY . .

CMD [ "python", "./your-daemon-or-script.py" ]

#From https://hub.docker.com/_/python

#docker build -t webserver-image:v1
#docker run -d -p 80:80 webserver-image:v1
#docker images
#curl docker

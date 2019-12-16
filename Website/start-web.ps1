docker stop webserver1
docker rm webserver1
docker build -t web1 .
docker run -d -p 80:80 --name webserver1 web1

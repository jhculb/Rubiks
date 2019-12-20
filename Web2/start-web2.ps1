docker stop webserver2
docker rm webserver2
docker build -t web2 .
docker run -d -p 80:80 --name webserver2 web2

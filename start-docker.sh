#!/bin/bash
MONGODB_URI="mongodb+srv://user:freelancemarket@freelancemarket.fzxe0.mongodb.net/FreelanceMarket?retryWrites=true&w=majority"
DOCKER_IMAGE=freelancemarket

if [ -z ${MONGODB_URI} ]
then
    read -p "MONGODB URI (Required): " MONGODB_URI
fi

echo "Executing ... "
docker run -it --rm -e MONGODB_URI=${MONGODB_URI} \
    ${DOCKER_IMAGE}
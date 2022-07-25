# Фриланс Биржа

## План проекта
https://docs.google.com/document/d/1WKB4vqBY14Op4la6XwuOWAu9ZWP7BEW5V5WwFzcc59s/edit#

## Диаграмма UML
Файлы UML.pdf, Entrance Menu.pdf, Main Menu.pdf

## Сборка проекта
```
docker build . -t freelancemarket
```
Образ собирается около 20 минут из-за драйверов для MongoDB (ставлю mongo-cxx-driver и mongo-c-driver)

## Запуск проекта 
Для запуска проекта нужно запустить скрипт start-docker.sh,
в нем настраиваются переменные окружения
```
./start-docker.sh
```
Со включенным VPN-ом не заработает, тк не сможет подключиться к кластеру MongoDB Atlas (он работает 24/7)

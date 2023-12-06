#!/bin/bash

# STOP SERVICES
sudo systemctl stop nginx
# COPIE DES FICHIERS
cp ./annexes/nouvelle_configuration.conf /etc/nginx/sites-enabled/
cp ./annexes/index.html /var/www/html/
# REDEMARRAGE DES SERVICES
sudo systemctl start nginx
# TEST NOUVEL INDEX
curl http://localhost:80
#!/bin/bash

sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/apache-selfsigned.key -out /etc/ssl/certs/apache-selfsigned.crt

echo 'SSLCipherSuite EECDH+AESGCM:EDH+AESGCM:AES256+EECDH:AES256+EDH
SSLProtocol All -SSLv2 -SSLv3 -TLSv1 -TLSv1.1
SSLHonorCipherOrder On
# Disable preloading HSTS for now.  You can use the commented out header line that includes
# the "preload" directive if you understand the implications.
# Header always set Strict-Transport-Security "max-age=63072000; includeSubDomains; preload"
Header always set X-Frame-Options DENY
Header always set X-Content-Type-Options nosniff
# Requires Apache >= 2.4
SSLCompression off
SSLUseStapling on
SSLStaplingCache "shmcb:logs/stapling-cache(150000)"
# Requires Apache >= 2.4.11
SSLSessionTickets Off' | sudo tee /etc/apache2/conf-available/ssl-params.conf

sudo cp /etc/apache2/sites-available/default-ssl.conf /etc/apache2/sites-available/default-ssl.conf.bak
sudo sed -i "s/ServerAdmin webmaster@localhost/ServerAdmin kmoilane@student.hive.fi/g" /etc/apache2/sites-available/default-ssl.conf
sudo sed -i	"4i\		ServerName $1" /etc/apache2/sites-available/default-ssl.conf
sudo sed -i "s/\/etc\/ssl\/certs\/ssl-cert-snakeoil.pem/\/etc\/ssl\/certs\/apache-selfsigned.crt/g" /etc/apache2/sites-available/default-ssl.conf
sudo sed -i "s/SSLCertificateKeyFile \/etc\/ssl\/private\/ssl-cert-snakeoil.key/SSLCertificateKeyFile	\/etc\/ssl\/private\/apache-selfsigned.key/g" /etc/apache2/sites-available/default-ssl.conf
sudo sed -i "13i\ \n\tRedirect permanent \"\/\" \"https:\/\/$1\/\"" /etc/apache2/sites-available/000-default.conf
sudo a2enmod ssl >> /dev/null
sudo a2enmod headers >> /dev/null
sudo a2ensite default-ssl >> /dev/null
sudo a2enconf ssl-params >> /dev/null
sudo apache2ctl configtest
sudo systemctl restart apache2

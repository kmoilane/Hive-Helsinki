#!/bin/bash

sudo apt-get install -y postfix
sudo sed -i 's/inet_interfaces = all/inet_interfaces = loopback-only/g' /etc/postfix/main.cf
sudo systemctl restart postfix

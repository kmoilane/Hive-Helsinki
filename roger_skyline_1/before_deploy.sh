#!/bin/bash

apt-get install -y sudo vim ssh apache2 fail2ban ufw portsentry mailutils >> /dev/null

echo "
Type your non root username for sudo rights:"
read username
sudo usermod -aG sudo $username

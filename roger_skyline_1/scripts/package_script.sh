#!/bin/bash

apt-get install -y sudo vim ssh apache2 fail2ban ufw portsentry mailutils >> /dev/null
sudo usermod -aG sudo karri

#!/bin/bash

sudo sed -i "s/#Port 22/Port $1/g" /etc/ssh/sshd_config
sudo sed -i "s/#PermitRootLogin prohibit-password/PermitRootLogin no/g" /etc/ssh/sshd_config
sudo systemctl restart ssh

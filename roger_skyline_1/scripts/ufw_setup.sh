#!/bin/bash

sudo ufw default deny incoming
sudo ufw default allow outgoing
sudo ufw allow 80
sudo ufw allow 443
sudo ufw allow 55155
sudo ufw enable
sudo ufw reload

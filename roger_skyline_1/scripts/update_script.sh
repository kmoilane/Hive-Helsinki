#!/bin/bash

# Updates all the service packages by first checking
# for available updates, and then upgrades them. All the logs
# will be sent to /var/log/update_script.log

apt-get update -y  &>> /var/log/update_script.log
apt-get upgrade -y  &>> /var/log/update_script.log
apt-get dist-upgrade -y &>> /var/log/update_script.log
apt-get autoclean -y &>> /var/log/update_script.log

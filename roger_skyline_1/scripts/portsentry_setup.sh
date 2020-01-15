#!/bin/bash

sudo sed -i 's/TCP_MODE="tcp"/TCP_MODE="atcp"/g' /etc/default/portsentry
sudo sed -i 's/UDP_MODE="udp"/UDP_MODE="audp"/g' /etc/default/portsentry
sudo sed -i 's/BLOCK_UDP="0"/BLOCK_UDP="1"/g' /etc/portsentry/portsentry.conf
sudo sed -i 's/BLOCK_TCP="0"/BLOCK_TCP="1"/g' /etc/portsentry/portsentry.conf
sudo sed -i 's/KILL_ROUTE="\/sbin\/route add -host $TARGET$ reject"/#KILL_ROUTE="\/sbin\/route add -host $TARGET$ reject"/g' /etc/portsentry/portsentry.conf
sudo sed -i 's/#KILL_ROUTE="\/sbin\/iptables -I INPUT -s $TARGET$ -j DROP"/KILL_ROUTE="\/sbin\/iptables -I INPUT -s $TARGET$ -j DROP"/g' /etc/portsentry/portsentry.conf
sudo systemctl restart portsentry

#!/bin/bash

echo "# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).

source /etc/network/interfaces.d/*

# The loopback network interface
auto lo
iface lo inet loopback

# The primary network interface
auto enp0s3
iface enp0s3 inet static
	address $1
	netmask $2
	network $3
	broadcast $4
	gateway $5" | sudo tee /etc/network/interfaces >> /dev/null

sudo systemctl restart networking
echo "your ip address is now:"
hostname -I
echo "netmask: $2
network: $3
broadcast: $4
gateway: $5"

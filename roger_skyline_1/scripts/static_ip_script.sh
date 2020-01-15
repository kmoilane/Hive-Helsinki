#!/bin/bash

echo '# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).

source /etc/network/interfaces.d/*

# The loopback network interface
auto lo
iface lo inet loopback

# The primary network interface
auto enp0s3
iface enp0s3 inet static
	address 10.13.13.13
	netmask 255.255.255.252
	network 10.13.13.12
	broadcast 10.13.13.15
	gateway 10.13.254.254' | sudo tee /etc/network/interfaces

#!/bin/bash

echo "[sshd]
enabled = true
port    = $1
filter  = sshd
logpath = %(sshd_log)s
maxretry = 5
bantime = 300
banaction = iptables-multiport

[portscan]
enabled	= true
filter	= portscan
logpath	= /var/log/syslog
maxretry = 1
bantime	= 300
findtime = 300

[http-get-dos]
enabled = true
port    = http,https
filter  = http-get-dos
logpath = /var/log/apache2/access.log
maxretry = 50
findtime = 120
bantime =  60
action  = iptables[name=HTTP, port=http, protocol=tcp]" | sudo tee /etc/fail2ban/jail.d/defaults-debian.local >> /dev/null

echo "[Definition]
failregex = ^<HOST> -.*\"(GET|POST).*
ignoreregex =" | sudo tee /etc/fail2ban/filter.d/http-get-dos.conf >> /dev/null

echo "[Definition]
failregex = UFW BLOCK.* SRC=<HOST>
ignoreregex =" | sudo tee /etc/fail2ban/filter.d/portscan.conf >> /dev/null

sudo systemctl restart fail2ban
sudo fail2ban-client status

#!/bin/bash

echo "Please type below static ip that you want, make sure it's valid and in x.x.x.x format!"
IFS=. read -r i1 i2 i3 i4
ip="$i1.$i2.$i3.$i4"

echo "Next type in valid netmask you wan't to use in x.x.x.x format"
IFS=. read -r m1 m2 m3 m4
mask="$m1.$m2.$m3.$m4"

n1=$((i1 & m1))
n2=$((i2 & m2))
n3=$((i3 & m3))
n4=$((i4 & m4))
netw="$n1.$n2.$n3.$n4"

b1=$((n1 | 255-m1))
b2=$((n2 | 255-m2))
b3=$((n3 | 255-m3))
b4=$((n4 | 255-m4))
bcast="$b1.$b2.$b3.$b4"

gway="$i1.$i2.254.254"

sudo scripts/static_ip_script.sh "$ip" "$mask" "$netw" "$bcast" "$gway"

echo "Now enter a number between 49152 and 65535. This will be your SSH port, so make sure you remember it"
read sshport

sudo scripts/ssh_setup1.sh $sshport
echo "Now go to host machine and create a ssh-key pair and copy it to the server with following commands:

ssh-keygen
ssh-copy-id -p $sshport <username>@$ip

after you have successfully done that, press 'enter' to move on with deployment!"
read -p "Press enter to continue"
sudo scripts/ssh_setup2.sh
sudo scripts/ufw_setup.sh
sudo scripts/dos_script.sh $sshport
sudo scripts/portsentry_setup.sh
sudo scripts/stop_services.sh
sudo scripts/mail_setup.sh
sudo scripts/script4scripts.sh
#sudo scripts/ssl_script.sh "$ip"
echo "Deployment Done"

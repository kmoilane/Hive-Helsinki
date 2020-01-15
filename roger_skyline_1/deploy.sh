#!/bin/bash

sudo scripts/static_ip_script.sh
sudo scripts/ssh_setup1.sh
echo "Now go to host machine and create a ssh-key pair and copy it to the server with following commands:

ssh-keygen
ssh-copy-id -p 55155 karri@10.13.13.13

after you have successfully done that, press 'enter' to move on with deployment!"
read -p "Press enter to continue"
sudo scripts/ssh_setup2.sh
sudo scripts/ufw_setup.sh
sudo scripts/dos_script.sh
sudo scripts/portsentry_setup.sh
sudo scripts/stop_services.sh
sudo scripts/mail_setup.sh
sudo scripts/script4scripts.sh
sudo scripts/ssl_script.sh
echo "Deployment Done"

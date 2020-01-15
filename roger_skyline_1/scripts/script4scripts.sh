#!/bin/bash

sudo mkdir /scripts
cp -f /home/karri/Hive-Helsinki/roger_skyline_1/scripts/{update_script.sh,monitor_cron.sh} /scripts
mkdir /scripts/monitor_files
stat -c '%y' /etc/crontab > /scripts/monitor_files/orig
sudo echo '@reboot	root	/scripts/update_script.sh
0 4 * * 1	root	/scripts/update_script.sh
0 0 * * *	root	/scripts/monitor_cron.sh' >> /etc/crontab


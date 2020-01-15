#!/bin/bash

stat -c '%y' /etc/crontab > /scripts/monitor_files/new

if cmp -s /scripts/monitor_files/orig /scripts/monitor_files/new ; then
	rm -f /scripts/monitor_files/new
else
	echo "automatic message when /etc/crontab is modified" | mail -s "crontab modified" root
	cp -f /scripts/monitor_files/new /scripts/monitor_files/orig
	rm -f /scripts/monitor_files/new
fi

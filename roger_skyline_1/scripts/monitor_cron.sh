#!/bin/bash

stat -c '%y' /etc/crontab > /scripts/cronmon/new

if cmp -s /scripts/cronmon/orig /scripts/cronmon/new ; then
	rm -f /scripts/cronmon/new
else
	echo "automatic message when /etc/crontab is modified" | mail -s "crontab modified" root
	cp -f /scripts/cronmon/new /scripts/cronmon/orig
	rm -f /scripts/cronmon/new
fi

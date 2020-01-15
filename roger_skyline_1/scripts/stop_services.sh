#!/bin/bash

sudo systemctl list-unit-files --type=service --state=enabled
sudo systemctl disable console-setup.service
sudo systemctl disable keyboard-setup.service
sudo systemctl list-unit-files --type=service --state=enabled

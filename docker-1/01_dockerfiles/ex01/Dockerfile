# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:26:32 by kmoilane          #+#    #+#              #
#    Updated: 2020/08/06 16:43:37 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian

MAINTAINER kmoilane <kmoilane@student.hive.fi>

ENV TS3SERVER_LICENSE=accept

# Exposing required ports that teamspeak uses
EXPOSE 9987/udp 10011 30033

# Updating and installing required packages, also creating teamspeak user and home folder to use later
RUN apt-get update -y && apt-get upgrade -y && \
	apt-get install wget bzip2 -y && \
	useradd -ms /bin/bash teamspeak

WORKDIR /home/teamspeak

# Installing teamspeak server and opening the tar file, make sure to check that this is the newest version!
RUN wget https://files.teamspeak-services.com/releases/server/3.12.1/teamspeak3-server_linux_amd64-3.12.1.tar.bz2 && \
	tar xvf teamspeak3-server_linux_amd64-3.12.1.tar.bz2

WORKDIR /home/teamspeak/teamspeak3-server_linux_amd64

# We move everything to the teamspeak folder and remove tar file and old folder
RUN mv * /home/teamspeak && \
	rm -rf /home/teamspeak/teamspeak3-server_linux_amd64-3.11.0.tar.bz2 && \
	rm -rf /home/teamspeak/teamspeak3-server_linux_amd64/

WORKDIR /home/teamspeak

# When starting the container we will run this script which launches the server
ENTRYPOINT sh ts3server_minimal_runscript.sh

# To build this image:
#-------------------------------------------------------------------------------------------------#
#		docker build -t ex01 .																	  
#-------------------------------------------------------------------------------------------------#
# To run this (note, will delete later the container aftewrads): 
#-------------------------------------------------------------------------------------------------#
#		docker run -it --name teamspeak --rm -p 9987:9987/udp -p 10011:10011 -p 30033:30033 ex01
#-------------------------------------------------------------------------------------------------#
# To connect to this server use the machines ip and keytoken you get when server launches
#-------------------------------------------------------------------------------------------------#
#		docker-machine ip Char
#-------------------------------------------------------------------------------------------------#
#
#
# SET UP VM SO A USER CAN JOIN YOUR TS3 SERVER:
# Stop the VM Char: docker-machine stop Char
# Go to the VM settings/network/adapter3/enable network adapter/bridge adappter/en0:Ethernet/
# advanced/adapter type /intel pro/1000 MT Desktop/ ok
# Start the machine again: docker-machine start Char and activeted it!
# run this command: docker-machine regenerate-certs Char
# connect via ssh to your VM: docker-machine ssh Char
# ifconfig -a / copy the inet add: 10.13.x.x from eth2.
# exit ssh connection
# Build and Run the Ts3 server
# Connect in the Client with the eth2 IP and the Token you received
# A User can join now your server.

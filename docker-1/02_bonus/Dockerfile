# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 10:07:01 by kmoilane          #+#    #+#              #
#    Updated: 2020/01/28 13:26:06 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian

MAINTAINER	kmoilane <kmoilane@student.hive.fi>

WORKDIR		/

RUN			apt-get update && \
			apt-get upgrade -y && \
			apt-get install -y sudo vim build-essential git openssh-server

# Setting root:s password to Cenv and creating a non root user without password but with sudo rights
RUN			echo "root:Cenv" | chpasswd
RUN 		adduser --disabled-password --gecos "" kmoilane
RUN			sudo usermod -aG sudo kmoilane

# Configuring vim to my taste
RUN			sed -i "s/\"syntax on/syntax on/g" /etc/vim/vimrc && \
			sed -i "s/\"set background=dark/set background=dark/g" /etc/vim/vimrc && \
			sed -i "s/\"filetype plugin indent on/filetype plugin indent on/g" /etc/vim/vimrc
RUN			echo 'set tabstop=4\nset number' >> /etc/vim/vimrc

# Changing ssh port to 55155 and allowing root login
RUN			sed -i "s/#Port 22/Port 55155/g" /etc/ssh/sshd_config && \
			sed -i "s/#PermitRootLogin prohibit-password/PermitRootLogin yes/g" /etc/ssh/sshd_config

WORKDIR		/home/kmoilane

# Cloning my own Hive-Helsinki github repository, where I also have copies of my school work
RUN			git clone https://github.com/kmoilane/Hive-Helsinki.git

# Restarting ssh service and printing welcome message, also setting bash shell to be our entrypoint
ENTRYPOINT	service ssh restart && printf "$(tput setaf 2)Hello and welcome to C developing environment!\nYour ssh port is changed to 55155.\
To connect via ssh, use the following command:\n\tdocker exec -it c-env ssh -p 55155 root@$(hostname -i)\nThe password for root is $(tput setaf 1)Cenv$(tput setaf 3)\nEnjoy!\n$(tput sgr0)" && /bin/bash

# To build this image simply run the following command:
#------------------------------------------------------------------------------
#		docker build -t c-environment .
#------------------------------------------------------------------------------
# Then to run the container:
#------------------------------------------------------------------------------
#		docker run --name c-env -p 55155:55155 -it c-environment
#------------------------------------------------------------------------------
# To connect with ssh (this command will be shown when you run the container):
#------------------------------------------------------------------------------
#		docker exec -it c-env ssh -p 55155 root@<ip>
#------------------------------------------------------------------------------

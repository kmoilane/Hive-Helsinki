# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 03:11:27 by kmoilane          #+#    #+#              #
#    Updated: 2020/08/27 17:37:14 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian

MAINTAINER	kmoilane <kmoilane@student.hive.fi>

WORKDIR		/

# Updating debian and installing required packages
RUN			apt-get update && \
			apt-get upgrade -y && \
			apt-get install -y curl vim openssh-server ca-certificates postfix

# Allowing us to connect with root via ssh and changing root password
RUN			sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN			echo 'root:test1234' | chpasswd

# Installing gitlab community edition
RUN			curl -s https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN			apt-get install -y gitlab-ce

# Generating self signed ssl certificate
RUN			mkdir -p /etc/gitlab/ssl
RUN			chmod 700 /etc/gitlab/ssl
RUN			openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
			-subj /C=FI/ST=Helsinki/L=Helsinki/O=Docker-1/OU=ex03/CN=192.168.99.100/emailAddress=kmoilane@student.hive.fi \
			-keyout /etc/gitlab/ssl/selfsigned.key -out /etc/gitlab/ssl/selfsigned.crt

# Dealing with Grafana authorization taking forever
RUN			sed -i "s/# grafana\['enable'\] = true/grafana['enable'] = false/g" /etc/gitlab/gitlab.rb

# Configuring HTTPS and rerouting
RUN			echo "external_url \"https://192.168.99.100\"" >> /etc/gitlab/gitlab.rb
RUN			echo "nginx['redirect_http_to_https'] = true" >> /etc/gitlab/gitlab.rb
RUN			echo "nginx['ssl_certificate'] = \"/etc/gitlab/ssl/selfsigned.crt\"" >> /etc/gitlab/gitlab.rb
RUN			echo "nginx['ssl_certificate_key'] = \"/etc/gitlab/ssl/selfsigned.key\"" >> /etc/gitlab/gitlab.rb
RUN			echo "gitlab_rails['gitlab_shell_ssh_port'] = 8022" >> /etc/gitlab/gitlab.rb

EXPOSE		22 80 443

# We have to manually start the gitlab and reconfigure the ctl, then we restart ssh and set us to bash shell
ENTRYPOINT	(/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && service ssh restart && /bin/bash


#!!!!!!!!!!!!!! BEFORE BUILDING, CHANGE THE IP's TO MATCH THE CURRENT Char IP IF THEY ARE NOT CORRECT!!!!!!!!!!!!!!!!
# To build this image:
#------------------------------------------------------------------------------
#		docker build -t ex03 .
#------------------------------------------------------------------------------
# Then to run container:
#------------------------------------------------------------------------------
#		docker run -it --name gitlab -p 8022:22 -p 8080:80 -p 8443:443 --privileged ex03
#------------------------------------------------------------------------------
# Go to https://<ip>:8443
# Change password and log in using root and that password

# To clone the repo using https we have to disable ssl verification since our ssl certificate isn't trusted
# To do so use the following git clone:
#------------------------------------------------------------------------------
#		git -c http.sslVerify=false clone <repo URL>
#------------------------------------------------------------------------------
#
# To push, go to the repo and use following command to disable SSL verification:
#------------------------------------------------------------------------------
#		git config --global http.sslVerify false
#------------------------------------------------------------------------------
# Now you can use the repo normally
#
# For the ssh to work, I generated new keygen using:
#------------------------------------------------------------------------------
#		ssh-keygen -t rsa -b 2048 -C "karri.moilanen@gmail.com"
#------------------------------------------------------------------------------
#
# Then paste the .pub key to gitlab settings page, after that I was abled to 
#------------------------------------------------------------------------------
#		git clone ssh://git@192.168.99.100:8022/<repo_name>
#------------------------------------------------------------------------------

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoilane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 14:25:41 by kmoilane          #+#    #+#              #
#    Updated: 2020/08/06 16:53:45 by kmoilane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		ruby:2.5.1

MAINTAINER	kmoilane <kmoilane@student.hive.fi>

# Update and install nodejs so that js app:s work also install rails with the version specified in the app
RUN			apt-get update -y && apt-get install -y nodejs
RUN			gem install rails --version 5.2.0

# Make /opt/app directory with path direcotries and change workdirectory there
RUN			mkdir -p /opt/app
WORKDIR		/opt/app

# Copy the app folder to the /opt/app in our image when image is being used and built
ONBUILD ADD	app /opt/app

# Installs bundle and creates database when using this image for other build, migrates and seeds it. 
ONBUILD RUN	bundle install && \
			rake db:create && \ 
			rake db:migrate && \
			rake db:seed

#
# I'm using https://github.com/RailsApps/rails-signup-thankyou.git as my app, so in case there's
# something wrong with the app folder, remove it and then git clone the address to app folder.
#
#
# To build this parent image run the following command:
#------------------------------------------------------------------------------
#		docker build -t ft-rails:on-build .			
#------------------------------------------------------------------------------
# Then you have to switch to previous folder and run:
#------------------------------------------------------------------------------
#		docker build  -t ex02 .
#------------------------------------------------------------------------------
# Or you can do it from this folder with:
#------------------------------------------------------------------------------
#		docker build -t ex02 ../.
#------------------------------------------------------------------------------
# For the container, run this
#------------------------------------------------------------------------------
#		docker run -it --rm -p 3000:3000 ex02
#------------------------------------------------------------------------------
#
# To view this sample app go to <ip>:3000

This is my automation for the roger-skyline-1

To do this correctly, use debian-10.2.0-amd64-netinst.iso
set network adapter into bridged-adapter

STEP1:
after logging in with your non root user, change to root with:

	su

after typing password and getting in we need to install git, so:

	apt-get update
	apt-get upgrade -y
	apt-get install git -y

after installing git, clone this repo to your root ( / ) using:

	git clone https://github.com/Karrzzaa/Hive-Helsinki.git

then you can go to Hive-Helsinki/roger_skyline_1/

	cd /Hive-Helsinki/roger_skyline_1/

now the first thing we do is install all required packages and give your user sudo rights

to do this execute "before_deploy.sh"

	./before_deploy.sh

after installing everything you can now switch to your non root user

	su - <user>

now we can get everything else done by executing deploy.sh script

	./deploy.sh

it will prompt you your ip and netmask and also the ssh port you want to have

if everything works correctly, you should now have server ready, so reboot your machine and check everything through! :)

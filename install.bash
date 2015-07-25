#!/bin/bash

F=/etc/acpi/powerbtn.sh			# powerbtn.sh file path

if ! [ -f ./autUofMShutdown ] ; then
	echo "Cannot find the autUofMShutdown command"
	exit 1
fi

if [ -f ${F} ] ; then
	mv ${F} ${F}_`date +"%s"`	# Backup
	cp ./autUofMShutdown /sbin
	echo "#!/bin/bash" > ${F}
	echo "/sbin/autUofMShutdown" >> ${F}
	echo "Success!"
else
	echo "Cannot find ${F}"
	exit 2
fi

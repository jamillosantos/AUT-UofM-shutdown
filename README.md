# AUT-UofM-shutdown


## Compilation

For compilation you must use the standard `cmake` procedures, it may vary conform your preference. However, it is how
this program was tested:

A `bin/release` folder was created inside of the project. Than the following commands were executed:

	cmake ../.. -DCMAKE_BUILD_TYPE=Release
	make

## Installation

Using Debian (or family) we can find the file `/etc/acpi/powerbtn.sh` (may vary between versions or OS).

At the first line you will add the execution of the `autUofMShutdown` command.

A auto install bash script was created `install.bash`. The script make a backup of the current `powerbtn.sh` using the
current time (unix timestamp), then install the `autUofMShutdown` inside of the `/sbin` folder.

IMPORTANT!

The installation script (`install.bash`) must run from the same folder of the compiled version of the project. Eg:
if in `bin/release`, the correct command would be `../../install.bash`.

## Compiling and installing

	mkdir bin
	mkdir bin/release
	cd bin/release
	cmake ../.. -DCMAKE_BUILD_TYPE=Release
	make
	sudo ../../install.bash

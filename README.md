# OpenSoku
An -open source- implementation of the fighting game Touhou Hisoutensoku 12.3, developed by Twilight Frontier.

## Getting started

Follow the instructions below to get a working copy of the still in progress project below.

### Prerequisites

* You will need all the .dat files from both Touhou 10.5 (Scarlet Weather Rhapsody) and Touhou 12.3 (Hisoutensoku)
###       1. In order to make this work, you will need to take all the .dat files.
```
  th105a.dat
  th105b.dat
  th105c.dat
  th123a.dat
  th123b.dat
  th123c.dat
```
Once you get them, just put them inside **build**. They will have to be in there since the executable is created inside the **build** folder.
          
###         2.You'll need to have a **build/profile** directory in order to be able to control the characters.
Just take these from your own Hisoutensoku **profile** folder, and rename them accordingly to
```
profile1.pf
profile2.pf
```
Then, put them inside the **build/profile** folder, and you're set.
(This may most likely change later on.)

###			3. Prerequisites


## 	Linux, -nix systems:

* You will need SFML 2.0 (or above).
###     1. Installing SFML 2.0 (or above)
* On debian systems, simply open up a terminal and type the following
```
sudo apt-get install libsfml-dev
```
* On arch linux, open up a terminal and type the following
```
sudo pacman -S sfml
```
All the above commands will install the required files for SFML.

## Windows:

(Tested on Windows 10, 64 bit)
###		1. 	Getting SFML
			
* Go to the site of SFML, and in the Download section, find "MinGW (DW2) - 32-bit".
			Download the file, move it in the root directory of OpenSoku and extract the **lib**, **bin** and **include** folders. Make sure the **lib** and **include** folders are in the root directory of the project.

* From the **bin** folder, take all the **.dll** files (ONLY take the files that end in `-2.dll`, i.e. `sfml-audio-2.dll`), and put them all inside the **build** folder.
###		2. Getting mingw-w64 (32 bit) [(Link)](http://mingw-w64.org/doku.php/download)
* Click the link above. You will see multiple downloads, but look specifically for `MingW-W64-builds`. (It should be located just below `MacPorts` and above `Msys2`.) Click on it, then in the following page click on `Sourceforge`. The file should start downloading automatically. When it's finished, execute it. An installer will pop up.
* Once the installer pops up, click on `Next>`, and then you should see several settings. The only one you should change is `Threads`; Click on `posix`, and change it to `win32`. Then click `Next>`.

* It is preferable to change the installation directory to `C:\mingw-w64`, but if you wish, you can install it wherever else you want. For this installation, I will assume you have installed mingw-w64 under the directory `C:\mingw-w64`. After you set the install destination, click `Next>`, and finish off the setup.
* After this, press the Windows key, and type "edit environment". `Edit environment variables for your account` should show up. Click on that.
* In the window that appears, look at the top part of the window for `Path`, and double click on it. Another window should pop up. Click on the `New` button on the right side.

* At this point, I will still assume that you installed mingw-w64 under `C:\mingw-w64`. Therefore, you should copy the following:
```
C:\mingw-w64\mingw32\bin
```
* And then, after you've clicked the `New` button, paste the line above, and press enter. Click OK, and that should be all.
* Do note however, if you've installed `mingw-w64` under a different directory, then please make sure that you copy and paste the path where you've installed `mingw-w64` and edit it accordingly so that it points towards `\mingw32\bin`, then paste that in instead.

### Compiling

## Linux

1. To compile for linux, run the following in a terminal, while present in the root directory:
```
make -f Makefile.linux
```

## Windows

1. To compile for windows, run the following command in a powershell/command-prompt/etc. while present in the root directory:
```
mingw32-make -f Makefile.win
```
Assuming you followed the prerequisites correctly, an executable will appear in the `build` folder.


The above commands should build openSoku for the respective operating systems.

# License

This project is licensed under GPLv2. For more details, check the file [LICENSE.md](LICENSE.md)

# Authors
The initial work for this project was done by [Marisa-Chan](https://github.com/Marisa-Chan) .

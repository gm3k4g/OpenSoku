# OpenSoku
An -open source- implementation of the fighting game Touhou Hisoutensoku 12.3, developed by Twilight Frontier.

## Getting started

Follow the instructions below to get a --working-- copy of this project up and running.
(Note: I'm only working on the linux build for the moment.)

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
Once you get them, just put them inside **src/build**. They will have to be in there since the executable is created inside the **src/build** folder.
          
###         2.You'll need to have a **src/build/profile** directory in order to be able to control the characters.
Just take these from your own Hisoutensoku **profile** folder, and rename them accordingly to
```
profile1.pf
profile2.pf
```
Then, put them inside the **src/build/profile** folder, and you're set.
(This may most likely change later on.)

* You will need SFML 2.0 (or above).
###     1. Installing SFML 2.0 (or above)
* On debian systems, simply open up a terminal and type the following
```
sudo apt-get install libsfml-dev
```
This will install the required files for SFML.

### Compiling

## Linux

1. In order to compile the project, you first cd in the src directory,
```
cd src
```
2. Afterwards, you simply run make.
```
make
```
This will build opensoku for linux.

## Windows
(coming soon?)

# License

This project is licensed under GPLv2. For more details, check the file [LICENSE.md](LICENSE.md)

# Authors
The initial work for this project was done by [Marisa-Chan](https://github.com/Marisa-Chan) .

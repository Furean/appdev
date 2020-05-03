# appdev project 2020

# This project is for I-IT-1N students to understand what procedure and 
# what tools are needed in an application development.

General Description of the Application

	This application allows one to test audio files, by displaying their peaks as well as max dB value.

Table of Contents
1. Configuration instructions
2. Installation instructions
3. Operating insturctions
4. File manifest
5. Copyright and licensing information
6. Contact information
7. Credits and acknowledgements

1. Configuration instructions

	In order to run this application, you will need to acquire a SSH client
	in order to access the school's network. Clients such as Putty and WinSCP
	can be used for this purpose.

	The network information is as follows:
	Host: shell.vamk.fi
	Port: 22

	You should use your own account when it prompts for login details.

2. Installation instructions

	In order to install this application, you should first create a directory
	for the source code files. Github is then to be used to download the files.

	For example, the wget command could be utilized for this purpose.

	wget https://github.com/Furean/appdev

3. Operating instructions

	Once you have downloaded the files, you will need to compile the
	application. For this purpose, we have a make file.

	Simply use the command "make file", in order to compile the application.
	Once this is done, you will have a executable called "sound".
	
	Type ./sound to run the program.

	If you wish to analyse a different sound file, simply download a new wav
	file to directory, and rename it to test.wav in order to replace the old
	file. After that, you can simply run the program to see the different
	results.

4. File manifest

	README.md : 		this file

	screen.c : 			contains screen manipulation functions

	screen.h : 			contains screen function declarations and related 
	constants

	comm.c : 			contains functions for client-server communications

	comm.h : 			contains comm function declarations and related 
	constants

	testcurl.c : 		contains functions for transferring data.

	sound.c : 			contains the application utilizing the above functions.

	sound.h :			contains the sound function delcarations.

	sound.php :			contains the necessary php code for uploading
	the application data.

5. Copyright and licensing information

	This application follows GPLv2 license.

6. Contact information

	email: e1901099@edu.vamk.fi

7. Credits and acknowledgements

	Application by Patrik Vuorinen
	
	Acknowledgements: Chao Gao.


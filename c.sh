#Compiling Script..
qmake -o Makefile installer.pro
rm moc_Mainwindow.o
rm mainwindow.o
rm main.o
make
./wgetgui

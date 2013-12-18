#!/usr/bin/bash
rm -f battleship > /dev/null 2>&1
echo "Compiling..."
sudo make
echo "Installing battleship..."
sudo make install
sudo cp data/launcher/battleship.desktop /usr/share/applications
sudo mkdir /usr/share/battleship
sudo mkdir /usr/share/battleship/icon
sudo cp data/launcher/battleship.png /usr/share/battleship/icon
sudo xdg-desktop-menu forceupdate
echo "done."

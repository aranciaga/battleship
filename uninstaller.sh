#!/usr/bin/bash
echo "Uninstalling battleship..."
sudo make uninstall
sudo rm /usr/share/applications/battleship.desktop
sudo rm -r /usr/share/battleship
sudo xdg-desktop-menu forceupdate 
echo "done."

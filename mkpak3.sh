#!/bin/bash

if [ -f etmod/pak3.pk3 ]; then
  rm etmod/pak3.pk3
fi

cd resource-pak3

zip -r ../etmod/pak3.pk3 pak2.dat ui/menus.txt ui/assets/*tga \
    ui/popup_serverredirect.menu ui/ingame_vote_players.menu \
    ui/mods.menu ui/credits_et260.menu ui/credits_additional.menu \
    ui/main.menu maps/*

cd ..

# EOF

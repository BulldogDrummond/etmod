#!/bin/bash

if [ -f etmod/pak2.pk3 ]; then
  rm etmod/pak2.pk3
fi

cd resource-pak2

zip -r ../etmod/pak2.pk3 pak2.dat ui/menus.txt ui/assets/*tga \
    ui/popup_serverredirect.menu ui/ingame_vote_players.menu \
    ui/mods.menu ui/credits_et260.menu ui/credits_additional.menu \
    ui/main.menu maps/*

cd ..

# EOF

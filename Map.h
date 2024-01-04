#pragma once

#include "types.h"





void initMap(ptrMap mappa);

void drawMap(ptrMap mappa);

void updateMap(ptrMap mappa, ptrCharacter personaggio);

ptrRoom createRoom(ptrMap mappa);

void positionDoor(ptrRoom stanza);


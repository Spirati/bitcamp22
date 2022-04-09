#include <nds/arm9/sprite.h>
#include "sprite.h"

Sprite* createSprite(OamState *oam, int x, int y) {
    u16 *gfx = oamAllocateGfx(oam, SpriteSize_16x16, SpriteColorFormat_256Color);
    for(int i = 0; i < 16*16/2; i++) {
        gfx[i] = 1 | (1 << 8);
    }

    Sprite *sp = malloc(sizeof(Sprite));
    sp->gfx = gfx;
    sp->x = x;
    sp->y = y;

    return sp;
}

void renderSprite(Sprite *sprite, OamState *oam, int oamId) {
    oamSet(
        oam, oamId, sprite->x, sprite->y, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, sprite->gfx, -1, false, false, false, false, false
    );
}
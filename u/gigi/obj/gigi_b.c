// /clone/board/kedian_b.c

#include <ansi.h>  
inherit BULLETIN_BOARD;

void create()
{
        set_name(RED "相思石" NOR, ({ "stone" }) );
        set("location", "/u/gigi/workroom");
        set("board_id", "gigi_b");
        set("long", CYN "飛雲過盡，歸鴻無信，何處寄書得？\n漸寫到別來，此情深處，紅箋為無色。\n" NOR );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}


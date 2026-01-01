#include <ansi.h>
#include <music.h>

inherit ITEM;
inherit MI_QIN;

void create()
{
        set_name(HIY "檀木胡琴" NOR, ({ "tanmu huqin", "qin", "huqin", "tanmu" }));
        set_weight(800);

        set("unit", "把");
                set("long", HIY "一把精緻的檀木胡琴。\n" NOR);
                set("value", 1000);
                set("material", "wood");
        setup();
}

void init()
{
        add_action("play_qin", "play");
}

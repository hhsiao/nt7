// Obj: /d/ruzhou/npc/obj/marry-book.c 結婚須知
#include <ansi.h>
#include <command.h>

inherit ITEM;

void init()
{
        add_action("do_read", "fan");
}

void create()
{
        set_name("《結婚須知》", ({ "jiehun xuzhi", "xuzhi"}));
        set("weight", 600);
        set("unit", "本");
                set("value", 500);
                set("material", "paper");
                set("long", "這本書上寫著本MUD結婚的程序，你可以翻閱(fan)它。\n");
        setup();
}

int do_read(string arg)
{
    if (!arg||(arg!="jiehun xuzhi"&&arg!="xuzhi"))
        return notify_fail("你沒有這本書，亂翻口袋幹什麼？\n");
    return HELP_CMD->main(this_player(), "marry");
}

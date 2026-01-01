// shanshen.c 老山參

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
}

void create()
{
        set_name(YEL"老山參"NOR, ({"laoshan shen", "shen"}));
        set("taskobj", 1);
        set("unit", "株");
                set("long", "這是一株沾滿山泥的長白老山參。\n");
                set("value", 0);
        setup();
}

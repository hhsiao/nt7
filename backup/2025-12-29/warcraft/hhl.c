// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m極品玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "男性");                
        set("long", "$HIW$極品玄武[2;37;0m
它是黃鶴樓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hhl");
        set("owner_name", "黃鶴樓");
        set_temp("owner", "hhl");
        set_temp("owner_name", "黃鶴樓");
        ::setup();
}

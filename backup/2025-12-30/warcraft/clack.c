// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m小龜龜[2;37;0m[2;37;0m", ({"xuanwushou"}));        
        set("gender", "男性");                
        set("long", "可愛的小龜[2;37;0m
它是高爾夫的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "clack");
        set("owner_name", "高爾夫");
        set_temp("owner", "clack");
        set_temp("owner_name", "高爾夫");
        ::setup();
}

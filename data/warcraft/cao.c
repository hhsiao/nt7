// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m浴血鳳凰[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "男性");                
        set("long", "浴血鳳凰[2;37;0m
它是氧化鈣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cao");
        set("owner_name", "氧化鈣");
        set_temp("owner", "cao");
        set_temp("owner_name", "氧化鈣");
        ::setup();
}

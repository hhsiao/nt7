// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m英靈[2;37;0m[2;37;0m", ({"archer"}));        
        set("gender", "女性");                
        set("long", "這是一個披著紅色外衣的英靈，面貌隱隱約約看不大清楚[2;37;0m
它是遠坂凜的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "rin");
        set("owner_name", "遠坂凜");
        set_temp("owner", "rin");
        set_temp("owner_name", "遠坂凜");
        ::setup();
}

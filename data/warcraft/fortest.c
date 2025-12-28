// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m試管[2;37;0m[2;37;0m", ({"shiguan"}));        
        set("gender", "女性");                
        set("long", "試管裡面有很多不明液體[2;37;0m
它是試一下的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fortest");
        set("owner_name", "試一下");
        set_temp("owner", "fortest");
        set_temp("owner_name", "試一下");
        ::setup();
}

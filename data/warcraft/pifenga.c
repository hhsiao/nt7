// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("礦石[2;37;0m[2;37;0m", ({"pifengalong"}));        
        set("gender", "男性");                
        set("long", "喔唷[2;37;0m
它是披風之庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pifenga");
        set("owner_name", "披風之庫");
        set_temp("owner", "pifenga");
        set_temp("owner_name", "披風之庫");
        ::setup();
}

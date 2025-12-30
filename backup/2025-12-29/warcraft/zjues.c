// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m玄武大帝[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "女性");                
        set("long", "厲害的神獸[2;37;0m
它是張雲祥的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "zjues");
        set("owner_name", "張雲祥");
        set_temp("owner", "zjues");
        set_temp("owner_name", "張雲祥");
        ::setup();
}

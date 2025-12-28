// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("可謂我去[2;37;0m[2;37;0m", ({"yudqinga"}));        
        set("gender", "男性");                
        set("long", "可謂我去[2;37;0m
它是司馬玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yudqing");
        set("owner_name", "司馬玉");
        set_temp("owner", "yudqing");
        set_temp("owner_name", "司馬玉");
        ::setup();
}

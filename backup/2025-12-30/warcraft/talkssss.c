// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m哈雷摩托[2;37;0m[2;37;0m", ({"halei"}));        
        set("gender", "男性");                
        set("long", "哈雷摩托車[2;37;0m
它是美國隊長的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "talkssss");
        set("owner_name", "美國隊長");
        set_temp("owner", "talkssss");
        set_temp("owner_name", "美國隊長");
        ::setup();
}

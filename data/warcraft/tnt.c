// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m戚長髮[2;37;0m[2;37;0m", ({"tut"}));        
        set("gender", "男性");                
        set("long", "戚老闆最近是爆發橫財，所謂是三年不開張，開張管三年。[2;37;0m
它是重慶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tnt");
        set("owner_name", "重慶");
        set_temp("owner", "tnt");
        set_temp("owner_name", "重慶");
        ::setup();
}

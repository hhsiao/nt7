// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m棗紅馬[2;37;0m[2;37;0m", ({"zaohongma"}));        
        set("gender", "男性");                
        set("long", "棗紅馬[2;37;0m
它是段譽的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "duanyu");
        set("owner_name", "段譽");
        set_temp("owner", "duanyu");
        set_temp("owner_name", "段譽");
        ::setup();
}

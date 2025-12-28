// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("謎幻樂團[2;37;0m[2;37;0m", ({"imaginedragon"}));        
        set("gender", "男性");                
        set("long", "美國新秀[2;37;0m
它是笑話的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "joke");
        set("owner_name", "笑話");
        set_temp("owner", "joke");
        set_temp("owner_name", "笑話");
        ::setup();
}

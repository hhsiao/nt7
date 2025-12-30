// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大白豬[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "男性");                
        set("long", "$HIW$大白豬[2;37;0m
它是葫蘆水娃的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huluc");
        set("owner_name", "葫蘆水娃");
        set_temp("owner", "huluc");
        set_temp("owner_name", "葫蘆水娃");
        ::setup();
}

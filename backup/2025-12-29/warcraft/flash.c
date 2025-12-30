// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[34m藍狐[2;37;0m[2;37;0m", ({"bluefox"}));        
        set("gender", "女性");                
        set("long", "$BLU$藍狐[2;37;0m
它是動漫兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "flash");
        set("owner_name", "動漫兒");
        set_temp("owner", "flash");
        set_temp("owner_name", "動漫兒");
        ::setup();
}

// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("五色金龍[2;37;0m[2;37;0m", ({"dex"}));        
        set("gender", "女性");                
        set("long", "沒得描述[2;37;0m
它是聖騎士的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pal");
        set("owner_name", "聖騎士");
        set_temp("owner", "pal");
        set_temp("owner_name", "聖騎士");
        ::setup();
}

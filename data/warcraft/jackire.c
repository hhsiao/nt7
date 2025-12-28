// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("初晴微雨[1;35m[2;37;0m[2;37;0m", ({"chy"}));        
        set("gender", "女性");                
        set("long", "問世間情為何物    直教人生死相許[2;37;0m
它是予以更換的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jackire");
        set("owner_name", "予以更換");
        set_temp("owner", "jackire");
        set_temp("owner_name", "予以更換");
        ::setup();
}

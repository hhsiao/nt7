// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火[2;37;0m[2;37;0m", ({"huo"}));        
        set("gender", "男性");                
        set("long", "這是一隻千年火龍王 實力非常的強悍![2;37;0m
它是陌陌的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "momo");
        set("owner_name", "陌陌");
        set_temp("owner", "momo");
        set_temp("owner_name", "陌陌");
        ::setup();
}

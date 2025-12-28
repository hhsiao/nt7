// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("太白虎[2;37;0m[2;37;0m", ({"feifei"}));        
        set("gender", "女性");                
        set("long", "好大隻白虎[2;37;0m
它是何處歸的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "bugui");
        set("owner_name", "何處歸");
        set_temp("owner", "bugui");
        set_temp("owner_name", "何處歸");
        ::setup();
}

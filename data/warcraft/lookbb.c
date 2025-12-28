// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m張蝽龍[2;37;0m[2;37;0m", ({"loncly"}));        
        set("gender", "男性");                
        set("long", "瞄人縫大王的座騎，不要亂騎。[2;37;0m
它是瞄人縫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lookbb");
        set("owner_name", "瞄人縫");
        set_temp("owner", "lookbb");
        set_temp("owner_name", "瞄人縫");
        ::setup();
}

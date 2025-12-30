// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神龍翼翼[2;37;0m[2;37;0m", ({"shenlongaaa"}));        
        set("gender", "男性");                
        set("long", "神龍翼翼[2;37;0m
它是神龍號一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shenlongid");
        set("owner_name", "神龍號一");
        set_temp("owner", "shenlongid");
        set_temp("owner_name", "神龍號一");
        ::setup();
}

// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"klkdd"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是段劍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "klkd");
        set("owner_name", "段劍");
        set_temp("owner", "klkd");
        set_temp("owner_name", "段劍");
        ::setup();
}

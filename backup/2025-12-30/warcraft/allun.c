// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("沙沙[2;37;0m[2;37;0m", ({"shasha"}));        
        set("gender", "男性");                
        set("long", "沙沙的最愛[2;37;0m
它是蕭寒的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "allun");
        set("owner_name", "蕭寒");
        set_temp("owner", "allun");
        set_temp("owner_name", "蕭寒");
        ::setup();
}

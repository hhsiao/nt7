// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬可夫[2;37;0m[2;37;0m", ({"lichyaozhu"}));        
        set("gender", "男性");                
        set("long", "豬可夫[2;37;0m
它是獨孤香豬的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lichyao");
        set("owner_name", "獨孤香豬");
        set_temp("owner", "lichyao");
        set_temp("owner_name", "獨孤香豬");
        ::setup();
}

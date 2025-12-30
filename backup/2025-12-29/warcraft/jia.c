// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m制[33m錢[33m[2;37;0m[2;37;0m", ({"money"}));        
        set("gender", "男性");                
        set("long", "長得跟制錢一樣喜人的老虎[2;37;0m
它是賈有錢的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jia");
        set("owner_name", "賈有錢");
        set_temp("owner", "jia");
        set_temp("owner_name", "賈有錢");
        ::setup();
}

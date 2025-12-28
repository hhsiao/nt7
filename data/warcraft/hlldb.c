// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("最愛白虎[2;37;0m[2;37;0m", ({"hlldbbh"}));        
        set("gender", "女性");                
        set("long", "最愛白虎[2;37;0m
它是文東二號的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hlldb");
        set("owner_name", "文東二號");
        set_temp("owner", "hlldb");
        set_temp("owner_name", "文東二號");
        ::setup();
}

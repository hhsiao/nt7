// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m怒蛟[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "江雪寒的坐騎——青龍[2;37;0m
它是江雪寒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "drin");
        set("owner_name", "江雪寒");
        set_temp("owner", "drin");
        set_temp("owner_name", "江雪寒");
        ::setup();
}

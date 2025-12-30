// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍貓[2;37;0m[2;37;0m", ({"longcat"}));        
        set("gender", "女性");                
        set("long", "伸開雙手 我就是風 夢是世界 最最不同的時空[2;37;0m
它是阿喵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cat");
        set("owner_name", "阿喵");
        set_temp("owner", "cat");
        set_temp("owner_name", "阿喵");
        ::setup();
}

// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("乖乖[2;37;0m[2;37;0m", ({"zhs"}));        
        set("gender", "男性");                
        set("long", "乖乖[2;37;0m
它是帥哥啦啦的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzywuwu");
        set("owner_name", "帥哥啦啦");
        set_temp("owner", "zzywuwu");
        set_temp("owner_name", "帥哥啦啦");
        ::setup();
}

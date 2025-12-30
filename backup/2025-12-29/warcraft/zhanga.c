// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大一[2;37;0m[2;37;0m", ({"dayi"}));        
        set("gender", "男性");                
        set("long", "大一新生[2;37;0m
它是張大的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zhanga");
        set("owner_name", "張大");
        set_temp("owner", "zhanga");
        set_temp("owner_name", "張大");
        ::setup();
}

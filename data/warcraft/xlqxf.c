// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m倚天大劍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "這到底是什麼玩意。[2;37;0m
它是子子子子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xlqxf");
        set("owner_name", "子子子子");
        set_temp("owner", "xlqxf");
        set_temp("owner_name", "子子子子");
        ::setup();
}
